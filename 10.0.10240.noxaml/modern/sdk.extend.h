// Modern v1.23 - http://moderncpp.com
// Copyright (c) 2015 Kenny Kerr

#pragma once

namespace Modern { namespace Windows { namespace ApplicationModel { namespace Core {

template <typename T>
struct IFrameworkViewSourceT : ImplementsDefault<IFrameworkViewSource>
{
	virtual HRESULT __stdcall abi_CreateView(AbiArgOut<IFrameworkView> view) noexcept override
	{
		return call([&]
		{
			*view = detach(static_cast<T *>(this)->CreateView());
		});
	}
};

template <typename T>
struct IFrameworkViewT : ImplementsDefault<IFrameworkView>
{
	void Initialize(CoreApplicationView const &) const noexcept
	{
	}

	void SetWindow(UI::Core::CoreWindow const &) const noexcept
	{
	}

	void Load(String const &) const noexcept
	{
	}

	void Run() const
	{
		UI::Core::CoreWindow window = UI::Core::CoreWindow::GetForCurrentThread();
		window.Activate();

		UI::Core::ICoreDispatcher dispatcher = window.Dispatcher();
		dispatcher.ProcessEvents(UI::Core::CoreProcessEventsOption::ProcessUntilQuit);
	}

	void Uninitialize() const noexcept
	{
	}

	HRESULT __stdcall abi_Initialize(AbiArgIn<ICoreApplicationView> view) noexcept
	{
		return call([&]
		{
			static_cast<T *>(this)->Initialize(Lease<CoreApplicationView>(view));
		});
	}

	HRESULT __stdcall abi_SetWindow(AbiArgIn<UI::Core::ICoreWindow> window) noexcept
	{
		return call([&]
		{
			static_cast<T *>(this)->SetWindow(Lease<UI::Core::CoreWindow>(window));
		});
	}

	HRESULT __stdcall abi_Load(HSTRING entryPoint) noexcept
	{
		return call([&]
		{
			static_cast<T *>(this)->Load(Lease<String>(entryPoint));
		});
	}

	HRESULT __stdcall abi_Run() noexcept
	{
		return call([&]
		{
			static_cast<T *>(this)->Run();
		});
	}

	HRESULT __stdcall abi_Uninitialize() noexcept
	{
		return call([&]
		{
			static_cast<T *>(this)->Uninitialize();
		});
	}
};

}}}}
