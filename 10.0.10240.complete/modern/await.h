// Modern v1.26 - http://moderncpp.com
// Copyright (c) 2015 Kenny Kerr

#include <ctxtcall.h>

namespace Modern { namespace Windows { namespace Foundation {

template <typename T, typename F>
void impl_suspend(T const & object, F resume)
{
	ComPtr<IContextCallback> context;
	check(CoGetObjectContext(__uuidof(context), reinterpret_cast<void **>(set(context))));

	object.Completed([resume, context](auto const &, AsyncStatus)
	{
		ComCallData data = {};
		data.pUserDefined = resume.to_address();

		check(context->ContextCallback([](ComCallData * data)
		{
			F::from_address(data->pUserDefined)();
			return S_OK;
		},
		&data,
		IID_ICallbackWithNoReentrancyToApplicationSTA,
		5,
		nullptr));
	});
}

template <typename TProgress>
bool await_ready(IAsyncActionWithProgress<TProgress> const & object)
{
	return object.Status() == AsyncStatus::Completed;
}

template <typename TProgress, typename F>
void await_suspend(IAsyncActionWithProgress<TProgress> const & object, F resume)
{
	impl_suspend(object, resume);
}

template <typename TProgress>
void await_resume(IAsyncActionWithProgress<TProgress> const & object)
{
	object.GetResults();
}

template <typename TResult, typename TProgress>
bool await_ready(IAsyncOperationWithProgress<TResult, TProgress> const & object)
{
	return object.Status() == AsyncStatus::Completed;
}

template <typename TResult, typename TProgress, typename F>
void await_suspend(IAsyncOperationWithProgress<TResult, TProgress> const & object, F resume)
{
	impl_suspend(object, resume);
}

template <typename TResult, typename TProgress>
TResult await_resume(IAsyncOperationWithProgress<TResult, TProgress> const & object)
{
	return object.GetResults();
}

template <typename TResult>
bool await_ready(IAsyncOperation<TResult> const & object)
{
	return object.Status() == AsyncStatus::Completed;
}

template <typename TResult, typename F>
void await_suspend(IAsyncOperation<TResult> const & object, F resume)
{
	impl_suspend(object, resume);
}

template <typename TResult>
TResult await_resume(IAsyncOperation<TResult> const & object)
{
	return object.GetResults();
}

inline bool await_ready(IAsyncAction const & object)
{
	return object.Status() == AsyncStatus::Completed;
}

template <typename F>
void await_suspend(IAsyncAction const & object, F resume)
{
	impl_suspend(object, resume);
}

inline void await_resume(IAsyncAction const & object)
{
	object.GetResults();
}

}}}
