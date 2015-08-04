// Modern v1.26 - http://moderncpp.com
// Copyright (c) 2015 Kenny Kerr

#pragma once

namespace Modern { namespace Windows { namespace UI { namespace Xaml {

template <typename T, typename A = ABI::Windows::UI::Xaml::IUIElementOverrides>
struct IUIElementOverridesT : A
{
	Windows::UI::Xaml::Automation::Peers::AutomationPeer OnCreateAutomationPeer()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::IUIElementOverrides>().OnCreateAutomationPeer();
	}

	void OnDisconnectVisualChildren()
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::IUIElementOverrides>().OnDisconnectVisualChildren();
	}

	Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IIterable<Modern::Windows::Foundation::Point>> FindSubElementsForTouchTargeting(Windows::Foundation::Point const & point, Windows::Foundation::Rect const & boundingRect)
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::IUIElementOverrides>().FindSubElementsForTouchTargeting(point, boundingRect);
	}

	virtual HRESULT __stdcall abi_OnCreateAutomationPeer(AbiArgOut<Windows::UI::Xaml::Automation::Peers::IAutomationPeer> returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnCreateAutomationPeer();
		});
	}

	virtual HRESULT __stdcall abi_OnDisconnectVisualChildren() noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnDisconnectVisualChildren();
		});
	}

	virtual HRESULT __stdcall abi_FindSubElementsForTouchTargeting(Windows::Foundation::Point point, Windows::Foundation::Rect boundingRect, AbiArgOut<Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IIterable<Modern::Windows::Foundation::Point>>> returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->FindSubElementsForTouchTargeting(point, boundingRect);
		});
	}
};

template <typename T, typename A = ABI::Windows::UI::Xaml::IVisualStateManagerOverrides>
struct IVisualStateManagerOverridesT : A
{
	bool GoToStateCore(Windows::UI::Xaml::Controls::Control const & control, Windows::UI::Xaml::FrameworkElement const & templateRoot, String const & stateName, Windows::UI::Xaml::VisualStateGroup const & group, Windows::UI::Xaml::VisualState const & state, bool const useTransitions)
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::IVisualStateManagerOverrides>().GoToStateCore(control, templateRoot, stateName, group, state, useTransitions);
	}

	virtual HRESULT __stdcall abi_GoToStateCore(AbiArgIn<Windows::UI::Xaml::Controls::IControl> control, AbiArgIn<Windows::UI::Xaml::IFrameworkElement> templateRoot, HSTRING stateName, AbiArgIn<Windows::UI::Xaml::IVisualStateGroup> group, AbiArgIn<Windows::UI::Xaml::IVisualState> state, boolean useTransitions, boolean * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->GoToStateCore(forward<Windows::UI::Xaml::Controls::Control>(control), forward<Windows::UI::Xaml::FrameworkElement>(templateRoot), forward<String>(stateName), forward<Windows::UI::Xaml::VisualStateGroup>(group), forward<Windows::UI::Xaml::VisualState>(state), useTransitions);
		});
	}
};

template <typename T, typename A = ABI::Windows::UI::Xaml::IFrameworkElementOverrides>
struct IFrameworkElementOverridesT : A
{
	Windows::Foundation::Size MeasureOverride(Windows::Foundation::Size const & availableSize)
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::IFrameworkElementOverrides>().MeasureOverride(availableSize);
	}

	Windows::Foundation::Size ArrangeOverride(Windows::Foundation::Size const & finalSize)
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::IFrameworkElementOverrides>().ArrangeOverride(finalSize);
	}

	void OnApplyTemplate()
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::IFrameworkElementOverrides>().OnApplyTemplate();
	}

	virtual HRESULT __stdcall abi_MeasureOverride(Windows::Foundation::Size availableSize, Windows::Foundation::Size * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->MeasureOverride(availableSize);
		});
	}

	virtual HRESULT __stdcall abi_ArrangeOverride(Windows::Foundation::Size finalSize, Windows::Foundation::Size * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->ArrangeOverride(finalSize);
		});
	}

	virtual HRESULT __stdcall abi_OnApplyTemplate() noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnApplyTemplate();
		});
	}
};

template <typename T, typename A = ABI::Windows::UI::Xaml::IFrameworkElementOverrides2>
struct IFrameworkElementOverrides2T : A
{
	bool GoToElementStateCore(String const & stateName, bool const useTransitions)
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::IFrameworkElementOverrides2>().GoToElementStateCore(stateName, useTransitions);
	}

	virtual HRESULT __stdcall abi_GoToElementStateCore(HSTRING stateName, boolean useTransitions, boolean * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->GoToElementStateCore(forward<String>(stateName), useTransitions);
		});
	}
};

template <typename T, typename A = ABI::Windows::UI::Xaml::IApplicationOverrides>
struct IApplicationOverridesT : A
{
	void OnActivated(Windows::ApplicationModel::Activation::IActivatedEventArgs const & args)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::IApplicationOverrides>().OnActivated(args);
	}

	void OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs const & args)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::IApplicationOverrides>().OnLaunched(args);
	}

	void OnFileActivated(Windows::ApplicationModel::Activation::FileActivatedEventArgs const & args)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::IApplicationOverrides>().OnFileActivated(args);
	}

	void OnSearchActivated(Windows::ApplicationModel::Activation::SearchActivatedEventArgs const & args)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::IApplicationOverrides>().OnSearchActivated(args);
	}

	void OnShareTargetActivated(Windows::ApplicationModel::Activation::ShareTargetActivatedEventArgs const & args)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::IApplicationOverrides>().OnShareTargetActivated(args);
	}

	void OnFileOpenPickerActivated(Windows::ApplicationModel::Activation::FileOpenPickerActivatedEventArgs const & args)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::IApplicationOverrides>().OnFileOpenPickerActivated(args);
	}

	void OnFileSavePickerActivated(Windows::ApplicationModel::Activation::FileSavePickerActivatedEventArgs const & args)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::IApplicationOverrides>().OnFileSavePickerActivated(args);
	}

	void OnCachedFileUpdaterActivated(Windows::ApplicationModel::Activation::CachedFileUpdaterActivatedEventArgs const & args)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::IApplicationOverrides>().OnCachedFileUpdaterActivated(args);
	}

	void OnWindowCreated(Windows::UI::Xaml::WindowCreatedEventArgs const & args)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::IApplicationOverrides>().OnWindowCreated(args);
	}

	virtual HRESULT __stdcall abi_OnActivated(AbiArgIn<Windows::ApplicationModel::Activation::IActivatedEventArgs> args) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnActivated(forward<Windows::ApplicationModel::Activation::IActivatedEventArgs>(args));
		});
	}

	virtual HRESULT __stdcall abi_OnLaunched(AbiArgIn<Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs> args) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnLaunched(forward<Windows::ApplicationModel::Activation::LaunchActivatedEventArgs>(args));
		});
	}

	virtual HRESULT __stdcall abi_OnFileActivated(AbiArgIn<Windows::ApplicationModel::Activation::IFileActivatedEventArgs> args) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnFileActivated(forward<Windows::ApplicationModel::Activation::FileActivatedEventArgs>(args));
		});
	}

	virtual HRESULT __stdcall abi_OnSearchActivated(AbiArgIn<Windows::ApplicationModel::Activation::ISearchActivatedEventArgs> args) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnSearchActivated(forward<Windows::ApplicationModel::Activation::SearchActivatedEventArgs>(args));
		});
	}

	virtual HRESULT __stdcall abi_OnShareTargetActivated(AbiArgIn<Windows::ApplicationModel::Activation::IShareTargetActivatedEventArgs> args) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnShareTargetActivated(forward<Windows::ApplicationModel::Activation::ShareTargetActivatedEventArgs>(args));
		});
	}

	virtual HRESULT __stdcall abi_OnFileOpenPickerActivated(AbiArgIn<Windows::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs> args) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnFileOpenPickerActivated(forward<Windows::ApplicationModel::Activation::FileOpenPickerActivatedEventArgs>(args));
		});
	}

	virtual HRESULT __stdcall abi_OnFileSavePickerActivated(AbiArgIn<Windows::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs> args) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnFileSavePickerActivated(forward<Windows::ApplicationModel::Activation::FileSavePickerActivatedEventArgs>(args));
		});
	}

	virtual HRESULT __stdcall abi_OnCachedFileUpdaterActivated(AbiArgIn<Windows::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs> args) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnCachedFileUpdaterActivated(forward<Windows::ApplicationModel::Activation::CachedFileUpdaterActivatedEventArgs>(args));
		});
	}

	virtual HRESULT __stdcall abi_OnWindowCreated(AbiArgIn<Windows::UI::Xaml::IWindowCreatedEventArgs> args) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnWindowCreated(forward<Windows::UI::Xaml::WindowCreatedEventArgs>(args));
		});
	}
};

}}}}

namespace Modern { namespace Windows { namespace UI { namespace Xaml { namespace Automation { namespace Peers {

template <typename T, typename A = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>
struct IAutomationPeerOverridesT : A
{
	Modern::IInspectable GetPatternCore(Windows::UI::Xaml::Automation::Peers::PatternInterface const patternInterface)
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetPatternCore(patternInterface);
	}

	String GetAcceleratorKeyCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetAcceleratorKeyCore();
	}

	String GetAccessKeyCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetAccessKeyCore();
	}

	Windows::UI::Xaml::Automation::Peers::AutomationControlType GetAutomationControlTypeCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetAutomationControlTypeCore();
	}

	String GetAutomationIdCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetAutomationIdCore();
	}

	Windows::Foundation::Rect GetBoundingRectangleCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetBoundingRectangleCore();
	}

	Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeer> GetChildrenCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetChildrenCore();
	}

	String GetClassNameCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetClassNameCore();
	}

	Windows::Foundation::Point GetClickablePointCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetClickablePointCore();
	}

	String GetHelpTextCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetHelpTextCore();
	}

	String GetItemStatusCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetItemStatusCore();
	}

	String GetItemTypeCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetItemTypeCore();
	}

	Windows::UI::Xaml::Automation::Peers::AutomationPeer GetLabeledByCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetLabeledByCore();
	}

	String GetLocalizedControlTypeCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetLocalizedControlTypeCore();
	}

	String GetNameCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetNameCore();
	}

	Windows::UI::Xaml::Automation::Peers::AutomationOrientation GetOrientationCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetOrientationCore();
	}

	bool HasKeyboardFocusCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().HasKeyboardFocusCore();
	}

	bool IsContentElementCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().IsContentElementCore();
	}

	bool IsControlElementCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().IsControlElementCore();
	}

	bool IsEnabledCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().IsEnabledCore();
	}

	bool IsKeyboardFocusableCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().IsKeyboardFocusableCore();
	}

	bool IsOffscreenCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().IsOffscreenCore();
	}

	bool IsPasswordCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().IsPasswordCore();
	}

	bool IsRequiredForFormCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().IsRequiredForFormCore();
	}

	void SetFocusCore()
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().SetFocusCore();
	}

	Windows::UI::Xaml::Automation::Peers::AutomationPeer GetPeerFromPointCore(Windows::Foundation::Point const & point)
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetPeerFromPointCore(point);
	}

	Windows::UI::Xaml::Automation::Peers::AutomationLiveSetting GetLiveSettingCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>().GetLiveSettingCore();
	}

	virtual HRESULT __stdcall abi_GetPatternCore(Windows::UI::Xaml::Automation::Peers::PatternInterface patternInterface, AbiArgOut<IInspectable> returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->GetPatternCore(patternInterface);
		});
	}

	virtual HRESULT __stdcall abi_GetAcceleratorKeyCore(HSTRING * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->GetAcceleratorKeyCore();
		});
	}

	virtual HRESULT __stdcall abi_GetAccessKeyCore(HSTRING * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->GetAccessKeyCore();
		});
	}

	virtual HRESULT __stdcall abi_GetAutomationControlTypeCore(Windows::UI::Xaml::Automation::Peers::AutomationControlType * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->GetAutomationControlTypeCore();
		});
	}

	virtual HRESULT __stdcall abi_GetAutomationIdCore(HSTRING * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->GetAutomationIdCore();
		});
	}

	virtual HRESULT __stdcall abi_GetBoundingRectangleCore(Windows::Foundation::Rect * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->GetBoundingRectangleCore();
		});
	}

	virtual HRESULT __stdcall abi_GetChildrenCore(AbiArgOut<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeer>> returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->GetChildrenCore();
		});
	}

	virtual HRESULT __stdcall abi_GetClassNameCore(HSTRING * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->GetClassNameCore();
		});
	}

	virtual HRESULT __stdcall abi_GetClickablePointCore(Windows::Foundation::Point * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->GetClickablePointCore();
		});
	}

	virtual HRESULT __stdcall abi_GetHelpTextCore(HSTRING * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->GetHelpTextCore();
		});
	}

	virtual HRESULT __stdcall abi_GetItemStatusCore(HSTRING * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->GetItemStatusCore();
		});
	}

	virtual HRESULT __stdcall abi_GetItemTypeCore(HSTRING * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->GetItemTypeCore();
		});
	}

	virtual HRESULT __stdcall abi_GetLabeledByCore(AbiArgOut<Windows::UI::Xaml::Automation::Peers::IAutomationPeer> returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->GetLabeledByCore();
		});
	}

	virtual HRESULT __stdcall abi_GetLocalizedControlTypeCore(HSTRING * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->GetLocalizedControlTypeCore();
		});
	}

	virtual HRESULT __stdcall abi_GetNameCore(HSTRING * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->GetNameCore();
		});
	}

	virtual HRESULT __stdcall abi_GetOrientationCore(Windows::UI::Xaml::Automation::Peers::AutomationOrientation * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->GetOrientationCore();
		});
	}

	virtual HRESULT __stdcall abi_HasKeyboardFocusCore(boolean * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->HasKeyboardFocusCore();
		});
	}

	virtual HRESULT __stdcall abi_IsContentElementCore(boolean * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->IsContentElementCore();
		});
	}

	virtual HRESULT __stdcall abi_IsControlElementCore(boolean * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->IsControlElementCore();
		});
	}

	virtual HRESULT __stdcall abi_IsEnabledCore(boolean * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->IsEnabledCore();
		});
	}

	virtual HRESULT __stdcall abi_IsKeyboardFocusableCore(boolean * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->IsKeyboardFocusableCore();
		});
	}

	virtual HRESULT __stdcall abi_IsOffscreenCore(boolean * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->IsOffscreenCore();
		});
	}

	virtual HRESULT __stdcall abi_IsPasswordCore(boolean * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->IsPasswordCore();
		});
	}

	virtual HRESULT __stdcall abi_IsRequiredForFormCore(boolean * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->IsRequiredForFormCore();
		});
	}

	virtual HRESULT __stdcall abi_SetFocusCore() noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->SetFocusCore();
		});
	}

	virtual HRESULT __stdcall abi_GetPeerFromPointCore(Windows::Foundation::Point point, AbiArgOut<Windows::UI::Xaml::Automation::Peers::IAutomationPeer> returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->GetPeerFromPointCore(point);
		});
	}

	virtual HRESULT __stdcall abi_GetLiveSettingCore(Windows::UI::Xaml::Automation::Peers::AutomationLiveSetting * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->GetLiveSettingCore();
		});
	}
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2>
struct IAutomationPeerOverrides2T : A
{
	void ShowContextMenuCore()
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2>().ShowContextMenuCore();
	}

	Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Automation::Peers::AutomationPeer> GetControlledPeersCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2>().GetControlledPeersCore();
	}

	virtual HRESULT __stdcall abi_ShowContextMenuCore() noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->ShowContextMenuCore();
		});
	}

	virtual HRESULT __stdcall abi_GetControlledPeersCore(AbiArgOut<Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Automation::Peers::AutomationPeer>> returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->GetControlledPeersCore();
		});
	}
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3>
struct IAutomationPeerOverrides3T : A
{
	Modern::IInspectable NavigateCore(Windows::UI::Xaml::Automation::Peers::AutomationNavigationDirection const direction)
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3>().NavigateCore(direction);
	}

	Modern::IInspectable GetElementFromPointCore(Windows::Foundation::Point const & pointInWindowCoordinates)
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3>().GetElementFromPointCore(pointInWindowCoordinates);
	}

	Modern::IInspectable GetFocusedElementCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3>().GetFocusedElementCore();
	}

	Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation> GetAnnotationsCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3>().GetAnnotationsCore();
	}

	int GetPositionInSetCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3>().GetPositionInSetCore();
	}

	int GetSizeOfSetCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3>().GetSizeOfSetCore();
	}

	int GetLevelCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3>().GetLevelCore();
	}

	virtual HRESULT __stdcall abi_NavigateCore(Windows::UI::Xaml::Automation::Peers::AutomationNavigationDirection direction, AbiArgOut<IInspectable> returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->NavigateCore(direction);
		});
	}

	virtual HRESULT __stdcall abi_GetElementFromPointCore(Windows::Foundation::Point pointInWindowCoordinates, AbiArgOut<IInspectable> returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->GetElementFromPointCore(pointInWindowCoordinates);
		});
	}

	virtual HRESULT __stdcall abi_GetFocusedElementCore(AbiArgOut<IInspectable> returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->GetFocusedElementCore();
		});
	}

	virtual HRESULT __stdcall abi_GetAnnotationsCore(AbiArgOut<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation>> returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->GetAnnotationsCore();
		});
	}

	virtual HRESULT __stdcall abi_GetPositionInSetCore(int * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->GetPositionInSetCore();
		});
	}

	virtual HRESULT __stdcall abi_GetSizeOfSetCore(int * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->GetSizeOfSetCore();
		});
	}

	virtual HRESULT __stdcall abi_GetLevelCore(int * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->GetLevelCore();
		});
	}
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2>
struct IItemsControlAutomationPeerOverrides2T : A
{
	Windows::UI::Xaml::Automation::Peers::ItemAutomationPeer OnCreateItemAutomationPeer(IInspectable const & item)
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2>().OnCreateItemAutomationPeer(item);
	}

	virtual HRESULT __stdcall abi_OnCreateItemAutomationPeer(AbiArgIn<IInspectable> item, AbiArgOut<Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer> returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnCreateItemAutomationPeer(forward<IInspectable>(item));
		});
	}
};

}}}}}}

namespace Modern { namespace Windows { namespace UI { namespace Xaml { namespace Controls {

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::IDataTemplateSelectorOverrides>
struct IDataTemplateSelectorOverridesT : A
{
	Windows::UI::Xaml::DataTemplate SelectTemplateCore(IInspectable const & item, Windows::UI::Xaml::DependencyObject const & container)
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IDataTemplateSelectorOverrides>().SelectTemplateCore(item, container);
	}

	virtual HRESULT __stdcall abi_SelectTemplateCore(AbiArgIn<IInspectable> item, AbiArgIn<Windows::UI::Xaml::IDependencyObject> container, AbiArgOut<Windows::UI::Xaml::IDataTemplate> returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->SelectTemplateCore(forward<IInspectable>(item), forward<Windows::UI::Xaml::DependencyObject>(container));
		});
	}
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::IDataTemplateSelectorOverrides2>
struct IDataTemplateSelectorOverrides2T : A
{
	Windows::UI::Xaml::DataTemplate SelectTemplateCore(IInspectable const & item)
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IDataTemplateSelectorOverrides2>().SelectTemplateCore(item);
	}

	virtual HRESULT __stdcall abi_SelectTemplateForItemCore(AbiArgIn<IInspectable> item, AbiArgOut<Windows::UI::Xaml::IDataTemplate> returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->SelectTemplateCore(forward<IInspectable>(item));
		});
	}
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::IStyleSelectorOverrides>
struct IStyleSelectorOverridesT : A
{
	Windows::UI::Xaml::Style SelectStyleCore(IInspectable const & item, Windows::UI::Xaml::DependencyObject const & container)
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IStyleSelectorOverrides>().SelectStyleCore(item, container);
	}

	virtual HRESULT __stdcall abi_SelectStyleCore(AbiArgIn<IInspectable> item, AbiArgIn<Windows::UI::Xaml::IDependencyObject> container, AbiArgOut<Windows::UI::Xaml::IStyle> returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->SelectStyleCore(forward<IInspectable>(item), forward<Windows::UI::Xaml::DependencyObject>(container));
		});
	}
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::IGroupStyleSelectorOverrides>
struct IGroupStyleSelectorOverridesT : A
{
	Windows::UI::Xaml::Controls::GroupStyle SelectGroupStyleCore(IInspectable const & group, unsigned const level)
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IGroupStyleSelectorOverrides>().SelectGroupStyleCore(group, level);
	}

	virtual HRESULT __stdcall abi_SelectGroupStyleCore(AbiArgIn<IInspectable> group, unsigned level, AbiArgOut<Windows::UI::Xaml::Controls::IGroupStyle> returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->SelectGroupStyleCore(forward<IInspectable>(group), level);
		});
	}
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::IContentPresenterOverrides>
struct IContentPresenterOverridesT : A
{
	void OnContentTemplateChanged(Windows::UI::Xaml::DataTemplate const & oldContentTemplate, Windows::UI::Xaml::DataTemplate const & newContentTemplate)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IContentPresenterOverrides>().OnContentTemplateChanged(oldContentTemplate, newContentTemplate);
	}

	void OnContentTemplateSelectorChanged(Windows::UI::Xaml::Controls::DataTemplateSelector const & oldContentTemplateSelector, Windows::UI::Xaml::Controls::DataTemplateSelector const & newContentTemplateSelector)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IContentPresenterOverrides>().OnContentTemplateSelectorChanged(oldContentTemplateSelector, newContentTemplateSelector);
	}

	virtual HRESULT __stdcall abi_OnContentTemplateChanged(AbiArgIn<Windows::UI::Xaml::IDataTemplate> oldContentTemplate, AbiArgIn<Windows::UI::Xaml::IDataTemplate> newContentTemplate) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnContentTemplateChanged(forward<Windows::UI::Xaml::DataTemplate>(oldContentTemplate), forward<Windows::UI::Xaml::DataTemplate>(newContentTemplate));
		});
	}

	virtual HRESULT __stdcall abi_OnContentTemplateSelectorChanged(AbiArgIn<Windows::UI::Xaml::Controls::IDataTemplateSelector> oldContentTemplateSelector, AbiArgIn<Windows::UI::Xaml::Controls::IDataTemplateSelector> newContentTemplateSelector) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnContentTemplateSelectorChanged(forward<Windows::UI::Xaml::Controls::DataTemplateSelector>(oldContentTemplateSelector), forward<Windows::UI::Xaml::Controls::DataTemplateSelector>(newContentTemplateSelector));
		});
	}
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::IVirtualizingPanelOverrides>
struct IVirtualizingPanelOverridesT : A
{
	void OnItemsChanged(IInspectable const & sender, Windows::UI::Xaml::Controls::Primitives::ItemsChangedEventArgs const & args)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IVirtualizingPanelOverrides>().OnItemsChanged(sender, args);
	}

	void OnClearChildren()
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IVirtualizingPanelOverrides>().OnClearChildren();
	}

	void BringIndexIntoView(int const index)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IVirtualizingPanelOverrides>().BringIndexIntoView(index);
	}

	virtual HRESULT __stdcall abi_OnItemsChanged(AbiArgIn<IInspectable> sender, AbiArgIn<Windows::UI::Xaml::Controls::Primitives::IItemsChangedEventArgs> args) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnItemsChanged(forward<IInspectable>(sender), forward<Windows::UI::Xaml::Controls::Primitives::ItemsChangedEventArgs>(args));
		});
	}

	virtual HRESULT __stdcall abi_OnClearChildren() noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnClearChildren();
		});
	}

	virtual HRESULT __stdcall abi_BringIndexIntoView(int index) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->BringIndexIntoView(index);
		});
	}
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::IVirtualizingStackPanelOverrides>
struct IVirtualizingStackPanelOverridesT : A
{
	void OnCleanUpVirtualizedItem(Windows::UI::Xaml::Controls::CleanUpVirtualizedItemEventArgs const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IVirtualizingStackPanelOverrides>().OnCleanUpVirtualizedItem(e);
	}

	virtual HRESULT __stdcall abi_OnCleanUpVirtualizedItem(AbiArgIn<Windows::UI::Xaml::Controls::ICleanUpVirtualizedItemEventArgs> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnCleanUpVirtualizedItem(forward<Windows::UI::Xaml::Controls::CleanUpVirtualizedItemEventArgs>(e));
		});
	}
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::IControlOverrides>
struct IControlOverridesT : A
{
	void OnPointerEntered(Windows::UI::Xaml::Input::PointerRoutedEventArgs const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IControlOverrides>().OnPointerEntered(e);
	}

	void OnPointerPressed(Windows::UI::Xaml::Input::PointerRoutedEventArgs const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IControlOverrides>().OnPointerPressed(e);
	}

	void OnPointerMoved(Windows::UI::Xaml::Input::PointerRoutedEventArgs const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IControlOverrides>().OnPointerMoved(e);
	}

	void OnPointerReleased(Windows::UI::Xaml::Input::PointerRoutedEventArgs const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IControlOverrides>().OnPointerReleased(e);
	}

	void OnPointerExited(Windows::UI::Xaml::Input::PointerRoutedEventArgs const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IControlOverrides>().OnPointerExited(e);
	}

	void OnPointerCaptureLost(Windows::UI::Xaml::Input::PointerRoutedEventArgs const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IControlOverrides>().OnPointerCaptureLost(e);
	}

	void OnPointerCanceled(Windows::UI::Xaml::Input::PointerRoutedEventArgs const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IControlOverrides>().OnPointerCanceled(e);
	}

	void OnPointerWheelChanged(Windows::UI::Xaml::Input::PointerRoutedEventArgs const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IControlOverrides>().OnPointerWheelChanged(e);
	}

	void OnTapped(Windows::UI::Xaml::Input::TappedRoutedEventArgs const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IControlOverrides>().OnTapped(e);
	}

	void OnDoubleTapped(Windows::UI::Xaml::Input::DoubleTappedRoutedEventArgs const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IControlOverrides>().OnDoubleTapped(e);
	}

	void OnHolding(Windows::UI::Xaml::Input::HoldingRoutedEventArgs const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IControlOverrides>().OnHolding(e);
	}

	void OnRightTapped(Windows::UI::Xaml::Input::RightTappedRoutedEventArgs const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IControlOverrides>().OnRightTapped(e);
	}

	void OnManipulationStarting(Windows::UI::Xaml::Input::ManipulationStartingRoutedEventArgs const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IControlOverrides>().OnManipulationStarting(e);
	}

	void OnManipulationInertiaStarting(Windows::UI::Xaml::Input::ManipulationInertiaStartingRoutedEventArgs const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IControlOverrides>().OnManipulationInertiaStarting(e);
	}

	void OnManipulationStarted(Windows::UI::Xaml::Input::ManipulationStartedRoutedEventArgs const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IControlOverrides>().OnManipulationStarted(e);
	}

	void OnManipulationDelta(Windows::UI::Xaml::Input::ManipulationDeltaRoutedEventArgs const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IControlOverrides>().OnManipulationDelta(e);
	}

	void OnManipulationCompleted(Windows::UI::Xaml::Input::ManipulationCompletedRoutedEventArgs const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IControlOverrides>().OnManipulationCompleted(e);
	}

	void OnKeyUp(Windows::UI::Xaml::Input::KeyRoutedEventArgs const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IControlOverrides>().OnKeyUp(e);
	}

	void OnKeyDown(Windows::UI::Xaml::Input::KeyRoutedEventArgs const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IControlOverrides>().OnKeyDown(e);
	}

	void OnGotFocus(Windows::UI::Xaml::RoutedEventArgs const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IControlOverrides>().OnGotFocus(e);
	}

	void OnLostFocus(Windows::UI::Xaml::RoutedEventArgs const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IControlOverrides>().OnLostFocus(e);
	}

	void OnDragEnter(Windows::UI::Xaml::DragEventArgs const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IControlOverrides>().OnDragEnter(e);
	}

	void OnDragLeave(Windows::UI::Xaml::DragEventArgs const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IControlOverrides>().OnDragLeave(e);
	}

	void OnDragOver(Windows::UI::Xaml::DragEventArgs const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IControlOverrides>().OnDragOver(e);
	}

	void OnDrop(Windows::UI::Xaml::DragEventArgs const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IControlOverrides>().OnDrop(e);
	}

	virtual HRESULT __stdcall abi_OnPointerEntered(AbiArgIn<Windows::UI::Xaml::Input::IPointerRoutedEventArgs> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnPointerEntered(forward<Windows::UI::Xaml::Input::PointerRoutedEventArgs>(e));
		});
	}

	virtual HRESULT __stdcall abi_OnPointerPressed(AbiArgIn<Windows::UI::Xaml::Input::IPointerRoutedEventArgs> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnPointerPressed(forward<Windows::UI::Xaml::Input::PointerRoutedEventArgs>(e));
		});
	}

	virtual HRESULT __stdcall abi_OnPointerMoved(AbiArgIn<Windows::UI::Xaml::Input::IPointerRoutedEventArgs> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnPointerMoved(forward<Windows::UI::Xaml::Input::PointerRoutedEventArgs>(e));
		});
	}

	virtual HRESULT __stdcall abi_OnPointerReleased(AbiArgIn<Windows::UI::Xaml::Input::IPointerRoutedEventArgs> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnPointerReleased(forward<Windows::UI::Xaml::Input::PointerRoutedEventArgs>(e));
		});
	}

	virtual HRESULT __stdcall abi_OnPointerExited(AbiArgIn<Windows::UI::Xaml::Input::IPointerRoutedEventArgs> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnPointerExited(forward<Windows::UI::Xaml::Input::PointerRoutedEventArgs>(e));
		});
	}

	virtual HRESULT __stdcall abi_OnPointerCaptureLost(AbiArgIn<Windows::UI::Xaml::Input::IPointerRoutedEventArgs> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnPointerCaptureLost(forward<Windows::UI::Xaml::Input::PointerRoutedEventArgs>(e));
		});
	}

	virtual HRESULT __stdcall abi_OnPointerCanceled(AbiArgIn<Windows::UI::Xaml::Input::IPointerRoutedEventArgs> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnPointerCanceled(forward<Windows::UI::Xaml::Input::PointerRoutedEventArgs>(e));
		});
	}

	virtual HRESULT __stdcall abi_OnPointerWheelChanged(AbiArgIn<Windows::UI::Xaml::Input::IPointerRoutedEventArgs> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnPointerWheelChanged(forward<Windows::UI::Xaml::Input::PointerRoutedEventArgs>(e));
		});
	}

	virtual HRESULT __stdcall abi_OnTapped(AbiArgIn<Windows::UI::Xaml::Input::ITappedRoutedEventArgs> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnTapped(forward<Windows::UI::Xaml::Input::TappedRoutedEventArgs>(e));
		});
	}

	virtual HRESULT __stdcall abi_OnDoubleTapped(AbiArgIn<Windows::UI::Xaml::Input::IDoubleTappedRoutedEventArgs> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnDoubleTapped(forward<Windows::UI::Xaml::Input::DoubleTappedRoutedEventArgs>(e));
		});
	}

	virtual HRESULT __stdcall abi_OnHolding(AbiArgIn<Windows::UI::Xaml::Input::IHoldingRoutedEventArgs> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnHolding(forward<Windows::UI::Xaml::Input::HoldingRoutedEventArgs>(e));
		});
	}

	virtual HRESULT __stdcall abi_OnRightTapped(AbiArgIn<Windows::UI::Xaml::Input::IRightTappedRoutedEventArgs> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnRightTapped(forward<Windows::UI::Xaml::Input::RightTappedRoutedEventArgs>(e));
		});
	}

	virtual HRESULT __stdcall abi_OnManipulationStarting(AbiArgIn<Windows::UI::Xaml::Input::IManipulationStartingRoutedEventArgs> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnManipulationStarting(forward<Windows::UI::Xaml::Input::ManipulationStartingRoutedEventArgs>(e));
		});
	}

	virtual HRESULT __stdcall abi_OnManipulationInertiaStarting(AbiArgIn<Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnManipulationInertiaStarting(forward<Windows::UI::Xaml::Input::ManipulationInertiaStartingRoutedEventArgs>(e));
		});
	}

	virtual HRESULT __stdcall abi_OnManipulationStarted(AbiArgIn<Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnManipulationStarted(forward<Windows::UI::Xaml::Input::ManipulationStartedRoutedEventArgs>(e));
		});
	}

	virtual HRESULT __stdcall abi_OnManipulationDelta(AbiArgIn<Windows::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnManipulationDelta(forward<Windows::UI::Xaml::Input::ManipulationDeltaRoutedEventArgs>(e));
		});
	}

	virtual HRESULT __stdcall abi_OnManipulationCompleted(AbiArgIn<Windows::UI::Xaml::Input::IManipulationCompletedRoutedEventArgs> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnManipulationCompleted(forward<Windows::UI::Xaml::Input::ManipulationCompletedRoutedEventArgs>(e));
		});
	}

	virtual HRESULT __stdcall abi_OnKeyUp(AbiArgIn<Windows::UI::Xaml::Input::IKeyRoutedEventArgs> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnKeyUp(forward<Windows::UI::Xaml::Input::KeyRoutedEventArgs>(e));
		});
	}

	virtual HRESULT __stdcall abi_OnKeyDown(AbiArgIn<Windows::UI::Xaml::Input::IKeyRoutedEventArgs> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnKeyDown(forward<Windows::UI::Xaml::Input::KeyRoutedEventArgs>(e));
		});
	}

	virtual HRESULT __stdcall abi_OnGotFocus(AbiArgIn<Windows::UI::Xaml::IRoutedEventArgs> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnGotFocus(forward<Windows::UI::Xaml::RoutedEventArgs>(e));
		});
	}

	virtual HRESULT __stdcall abi_OnLostFocus(AbiArgIn<Windows::UI::Xaml::IRoutedEventArgs> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnLostFocus(forward<Windows::UI::Xaml::RoutedEventArgs>(e));
		});
	}

	virtual HRESULT __stdcall abi_OnDragEnter(AbiArgIn<Windows::UI::Xaml::IDragEventArgs> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnDragEnter(forward<Windows::UI::Xaml::DragEventArgs>(e));
		});
	}

	virtual HRESULT __stdcall abi_OnDragLeave(AbiArgIn<Windows::UI::Xaml::IDragEventArgs> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnDragLeave(forward<Windows::UI::Xaml::DragEventArgs>(e));
		});
	}

	virtual HRESULT __stdcall abi_OnDragOver(AbiArgIn<Windows::UI::Xaml::IDragEventArgs> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnDragOver(forward<Windows::UI::Xaml::DragEventArgs>(e));
		});
	}

	virtual HRESULT __stdcall abi_OnDrop(AbiArgIn<Windows::UI::Xaml::IDragEventArgs> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnDrop(forward<Windows::UI::Xaml::DragEventArgs>(e));
		});
	}
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::IContentControlOverrides>
struct IContentControlOverridesT : A
{
	void OnContentChanged(IInspectable const & oldContent, IInspectable const & newContent)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IContentControlOverrides>().OnContentChanged(oldContent, newContent);
	}

	void OnContentTemplateChanged(Windows::UI::Xaml::DataTemplate const & oldContentTemplate, Windows::UI::Xaml::DataTemplate const & newContentTemplate)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IContentControlOverrides>().OnContentTemplateChanged(oldContentTemplate, newContentTemplate);
	}

	void OnContentTemplateSelectorChanged(Windows::UI::Xaml::Controls::DataTemplateSelector const & oldContentTemplateSelector, Windows::UI::Xaml::Controls::DataTemplateSelector const & newContentTemplateSelector)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IContentControlOverrides>().OnContentTemplateSelectorChanged(oldContentTemplateSelector, newContentTemplateSelector);
	}

	virtual HRESULT __stdcall abi_OnContentChanged(AbiArgIn<IInspectable> oldContent, AbiArgIn<IInspectable> newContent) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnContentChanged(forward<IInspectable>(oldContent), forward<IInspectable>(newContent));
		});
	}

	virtual HRESULT __stdcall abi_OnContentTemplateChanged(AbiArgIn<Windows::UI::Xaml::IDataTemplate> oldContentTemplate, AbiArgIn<Windows::UI::Xaml::IDataTemplate> newContentTemplate) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnContentTemplateChanged(forward<Windows::UI::Xaml::DataTemplate>(oldContentTemplate), forward<Windows::UI::Xaml::DataTemplate>(newContentTemplate));
		});
	}

	virtual HRESULT __stdcall abi_OnContentTemplateSelectorChanged(AbiArgIn<Windows::UI::Xaml::Controls::IDataTemplateSelector> oldContentTemplateSelector, AbiArgIn<Windows::UI::Xaml::Controls::IDataTemplateSelector> newContentTemplateSelector) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnContentTemplateSelectorChanged(forward<Windows::UI::Xaml::Controls::DataTemplateSelector>(oldContentTemplateSelector), forward<Windows::UI::Xaml::Controls::DataTemplateSelector>(newContentTemplateSelector));
		});
	}
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::IItemsControlOverrides>
struct IItemsControlOverridesT : A
{
	bool IsItemItsOwnContainerOverride(IInspectable const & item)
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IItemsControlOverrides>().IsItemItsOwnContainerOverride(item);
	}

	Windows::UI::Xaml::DependencyObject GetContainerForItemOverride()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IItemsControlOverrides>().GetContainerForItemOverride();
	}

	void ClearContainerForItemOverride(Windows::UI::Xaml::DependencyObject const & element, IInspectable const & item)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IItemsControlOverrides>().ClearContainerForItemOverride(element, item);
	}

	void PrepareContainerForItemOverride(Windows::UI::Xaml::DependencyObject const & element, IInspectable const & item)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IItemsControlOverrides>().PrepareContainerForItemOverride(element, item);
	}

	void OnItemsChanged(IInspectable const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IItemsControlOverrides>().OnItemsChanged(e);
	}

	void OnItemContainerStyleChanged(Windows::UI::Xaml::Style const & oldItemContainerStyle, Windows::UI::Xaml::Style const & newItemContainerStyle)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IItemsControlOverrides>().OnItemContainerStyleChanged(oldItemContainerStyle, newItemContainerStyle);
	}

	void OnItemContainerStyleSelectorChanged(Windows::UI::Xaml::Controls::StyleSelector const & oldItemContainerStyleSelector, Windows::UI::Xaml::Controls::StyleSelector const & newItemContainerStyleSelector)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IItemsControlOverrides>().OnItemContainerStyleSelectorChanged(oldItemContainerStyleSelector, newItemContainerStyleSelector);
	}

	void OnItemTemplateChanged(Windows::UI::Xaml::DataTemplate const & oldItemTemplate, Windows::UI::Xaml::DataTemplate const & newItemTemplate)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IItemsControlOverrides>().OnItemTemplateChanged(oldItemTemplate, newItemTemplate);
	}

	void OnItemTemplateSelectorChanged(Windows::UI::Xaml::Controls::DataTemplateSelector const & oldItemTemplateSelector, Windows::UI::Xaml::Controls::DataTemplateSelector const & newItemTemplateSelector)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IItemsControlOverrides>().OnItemTemplateSelectorChanged(oldItemTemplateSelector, newItemTemplateSelector);
	}

	void OnGroupStyleSelectorChanged(Windows::UI::Xaml::Controls::GroupStyleSelector const & oldGroupStyleSelector, Windows::UI::Xaml::Controls::GroupStyleSelector const & newGroupStyleSelector)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IItemsControlOverrides>().OnGroupStyleSelectorChanged(oldGroupStyleSelector, newGroupStyleSelector);
	}

	virtual HRESULT __stdcall abi_IsItemItsOwnContainerOverride(AbiArgIn<IInspectable> item, boolean * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->IsItemItsOwnContainerOverride(forward<IInspectable>(item));
		});
	}

	virtual HRESULT __stdcall abi_GetContainerForItemOverride(AbiArgOut<Windows::UI::Xaml::IDependencyObject> returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->GetContainerForItemOverride();
		});
	}

	virtual HRESULT __stdcall abi_ClearContainerForItemOverride(AbiArgIn<Windows::UI::Xaml::IDependencyObject> element, AbiArgIn<IInspectable> item) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->ClearContainerForItemOverride(forward<Windows::UI::Xaml::DependencyObject>(element), forward<IInspectable>(item));
		});
	}

	virtual HRESULT __stdcall abi_PrepareContainerForItemOverride(AbiArgIn<Windows::UI::Xaml::IDependencyObject> element, AbiArgIn<IInspectable> item) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->PrepareContainerForItemOverride(forward<Windows::UI::Xaml::DependencyObject>(element), forward<IInspectable>(item));
		});
	}

	virtual HRESULT __stdcall abi_OnItemsChanged(AbiArgIn<IInspectable> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnItemsChanged(forward<IInspectable>(e));
		});
	}

	virtual HRESULT __stdcall abi_OnItemContainerStyleChanged(AbiArgIn<Windows::UI::Xaml::IStyle> oldItemContainerStyle, AbiArgIn<Windows::UI::Xaml::IStyle> newItemContainerStyle) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnItemContainerStyleChanged(forward<Windows::UI::Xaml::Style>(oldItemContainerStyle), forward<Windows::UI::Xaml::Style>(newItemContainerStyle));
		});
	}

	virtual HRESULT __stdcall abi_OnItemContainerStyleSelectorChanged(AbiArgIn<Windows::UI::Xaml::Controls::IStyleSelector> oldItemContainerStyleSelector, AbiArgIn<Windows::UI::Xaml::Controls::IStyleSelector> newItemContainerStyleSelector) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnItemContainerStyleSelectorChanged(forward<Windows::UI::Xaml::Controls::StyleSelector>(oldItemContainerStyleSelector), forward<Windows::UI::Xaml::Controls::StyleSelector>(newItemContainerStyleSelector));
		});
	}

	virtual HRESULT __stdcall abi_OnItemTemplateChanged(AbiArgIn<Windows::UI::Xaml::IDataTemplate> oldItemTemplate, AbiArgIn<Windows::UI::Xaml::IDataTemplate> newItemTemplate) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnItemTemplateChanged(forward<Windows::UI::Xaml::DataTemplate>(oldItemTemplate), forward<Windows::UI::Xaml::DataTemplate>(newItemTemplate));
		});
	}

	virtual HRESULT __stdcall abi_OnItemTemplateSelectorChanged(AbiArgIn<Windows::UI::Xaml::Controls::IDataTemplateSelector> oldItemTemplateSelector, AbiArgIn<Windows::UI::Xaml::Controls::IDataTemplateSelector> newItemTemplateSelector) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnItemTemplateSelectorChanged(forward<Windows::UI::Xaml::Controls::DataTemplateSelector>(oldItemTemplateSelector), forward<Windows::UI::Xaml::Controls::DataTemplateSelector>(newItemTemplateSelector));
		});
	}

	virtual HRESULT __stdcall abi_OnGroupStyleSelectorChanged(AbiArgIn<Windows::UI::Xaml::Controls::IGroupStyleSelector> oldGroupStyleSelector, AbiArgIn<Windows::UI::Xaml::Controls::IGroupStyleSelector> newGroupStyleSelector) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnGroupStyleSelectorChanged(forward<Windows::UI::Xaml::Controls::GroupStyleSelector>(oldGroupStyleSelector), forward<Windows::UI::Xaml::Controls::GroupStyleSelector>(newGroupStyleSelector));
		});
	}
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::IToggleSwitchOverrides>
struct IToggleSwitchOverridesT : A
{
	void OnToggled()
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IToggleSwitchOverrides>().OnToggled();
	}

	void OnOnContentChanged(IInspectable const & oldContent, IInspectable const & newContent)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IToggleSwitchOverrides>().OnOnContentChanged(oldContent, newContent);
	}

	void OnOffContentChanged(IInspectable const & oldContent, IInspectable const & newContent)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IToggleSwitchOverrides>().OnOffContentChanged(oldContent, newContent);
	}

	void OnHeaderChanged(IInspectable const & oldContent, IInspectable const & newContent)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IToggleSwitchOverrides>().OnHeaderChanged(oldContent, newContent);
	}

	virtual HRESULT __stdcall abi_OnToggled() noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnToggled();
		});
	}

	virtual HRESULT __stdcall abi_OnOnContentChanged(AbiArgIn<IInspectable> oldContent, AbiArgIn<IInspectable> newContent) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnOnContentChanged(forward<IInspectable>(oldContent), forward<IInspectable>(newContent));
		});
	}

	virtual HRESULT __stdcall abi_OnOffContentChanged(AbiArgIn<IInspectable> oldContent, AbiArgIn<IInspectable> newContent) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnOffContentChanged(forward<IInspectable>(oldContent), forward<IInspectable>(newContent));
		});
	}

	virtual HRESULT __stdcall abi_OnHeaderChanged(AbiArgIn<IInspectable> oldContent, AbiArgIn<IInspectable> newContent) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnHeaderChanged(forward<IInspectable>(oldContent), forward<IInspectable>(newContent));
		});
	}
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::IComboBoxOverrides>
struct IComboBoxOverridesT : A
{
	void OnDropDownClosed(IInspectable const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IComboBoxOverrides>().OnDropDownClosed(e);
	}

	void OnDropDownOpened(IInspectable const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IComboBoxOverrides>().OnDropDownOpened(e);
	}

	virtual HRESULT __stdcall abi_OnDropDownClosed(AbiArgIn<IInspectable> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnDropDownClosed(forward<IInspectable>(e));
		});
	}

	virtual HRESULT __stdcall abi_OnDropDownOpened(AbiArgIn<IInspectable> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnDropDownOpened(forward<IInspectable>(e));
		});
	}
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::IAppBarOverrides>
struct IAppBarOverridesT : A
{
	void OnClosed(IInspectable const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IAppBarOverrides>().OnClosed(e);
	}

	void OnOpened(IInspectable const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IAppBarOverrides>().OnOpened(e);
	}

	virtual HRESULT __stdcall abi_OnClosed(AbiArgIn<IInspectable> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnClosed(forward<IInspectable>(e));
		});
	}

	virtual HRESULT __stdcall abi_OnOpened(AbiArgIn<IInspectable> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnOpened(forward<IInspectable>(e));
		});
	}
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::IAppBarOverrides3>
struct IAppBarOverrides3T : A
{
	void OnClosing(IInspectable const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IAppBarOverrides3>().OnClosing(e);
	}

	void OnOpening(IInspectable const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IAppBarOverrides3>().OnOpening(e);
	}

	virtual HRESULT __stdcall abi_OnClosing(AbiArgIn<IInspectable> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnClosing(forward<IInspectable>(e));
		});
	}

	virtual HRESULT __stdcall abi_OnOpening(AbiArgIn<IInspectable> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnOpening(forward<IInspectable>(e));
		});
	}
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::IPageOverrides>
struct IPageOverridesT : A
{
	void OnNavigatedFrom(Windows::UI::Xaml::Navigation::NavigationEventArgs const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IPageOverrides>().OnNavigatedFrom(e);
	}

	void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IPageOverrides>().OnNavigatedTo(e);
	}

	void OnNavigatingFrom(Windows::UI::Xaml::Navigation::NavigatingCancelEventArgs const & e)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::IPageOverrides>().OnNavigatingFrom(e);
	}

	virtual HRESULT __stdcall abi_OnNavigatedFrom(AbiArgIn<Windows::UI::Xaml::Navigation::INavigationEventArgs> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnNavigatedFrom(forward<Windows::UI::Xaml::Navigation::NavigationEventArgs>(e));
		});
	}

	virtual HRESULT __stdcall abi_OnNavigatedTo(AbiArgIn<Windows::UI::Xaml::Navigation::INavigationEventArgs> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnNavigatedTo(forward<Windows::UI::Xaml::Navigation::NavigationEventArgs>(e));
		});
	}

	virtual HRESULT __stdcall abi_OnNavigatingFrom(AbiArgIn<Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs> e) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnNavigatingFrom(forward<Windows::UI::Xaml::Navigation::NavigatingCancelEventArgs>(e));
		});
	}
};

}}}}}

namespace Modern { namespace Windows { namespace UI { namespace Xaml { namespace Controls { namespace Primitives {

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverrides>
struct IFlyoutBaseOverridesT : A
{
	Windows::UI::Xaml::Controls::Control CreatePresenter()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverrides>().CreatePresenter();
	}

	virtual HRESULT __stdcall abi_CreatePresenter(AbiArgOut<Windows::UI::Xaml::Controls::IControl> returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->CreatePresenter();
		});
	}
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverrides>
struct IRangeBaseOverridesT : A
{
	void OnMinimumChanged(double const oldMinimum, double const newMinimum)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverrides>().OnMinimumChanged(oldMinimum, newMinimum);
	}

	void OnMaximumChanged(double const oldMaximum, double const newMaximum)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverrides>().OnMaximumChanged(oldMaximum, newMaximum);
	}

	void OnValueChanged(double const oldValue, double const newValue)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverrides>().OnValueChanged(oldValue, newValue);
	}

	virtual HRESULT __stdcall abi_OnMinimumChanged(double oldMinimum, double newMinimum) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnMinimumChanged(oldMinimum, newMinimum);
		});
	}

	virtual HRESULT __stdcall abi_OnMaximumChanged(double oldMaximum, double newMaximum) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnMaximumChanged(oldMaximum, newMaximum);
		});
	}

	virtual HRESULT __stdcall abi_OnValueChanged(double oldValue, double newValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnValueChanged(oldValue, newValue);
		});
	}
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverrides>
struct IToggleButtonOverridesT : A
{
	void OnToggle()
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverrides>().OnToggle();
	}

	virtual HRESULT __stdcall abi_OnToggle() noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnToggle();
		});
	}
};

template <typename T, typename A = ABI::Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBaseOverrides>
struct IPickerFlyoutBaseOverridesT : A
{
	void OnConfirmed()
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBaseOverrides>().OnConfirmed();
	}

	bool ShouldShowConfirmationButtons()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBaseOverrides>().ShouldShowConfirmationButtons();
	}

	virtual HRESULT __stdcall abi_OnConfirmed() noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnConfirmed();
		});
	}

	virtual HRESULT __stdcall abi_ShouldShowConfirmationButtons(boolean * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->ShouldShowConfirmationButtons();
		});
	}
};

}}}}}}

namespace Modern { namespace Windows { namespace UI { namespace Xaml { namespace Documents {

template <typename T, typename A = ABI::Windows::UI::Xaml::Documents::ITextElementOverrides>
struct ITextElementOverridesT : A
{
	void OnDisconnectVisualChildren()
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Documents::ITextElementOverrides>().OnDisconnectVisualChildren();
	}

	virtual HRESULT __stdcall abi_OnDisconnectVisualChildren() noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnDisconnectVisualChildren();
		});
	}
};

}}}}}

namespace Modern { namespace Windows { namespace UI { namespace Xaml { namespace Media {

template <typename T, typename A = ABI::Windows::UI::Xaml::Media::IGeneralTransformOverrides>
struct IGeneralTransformOverridesT : A
{
	Windows::UI::Xaml::Media::GeneralTransform InverseCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Media::IGeneralTransformOverrides>().InverseCore();
	}

	bool TryTransformCore(Windows::Foundation::Point const & inPoint, Windows::Foundation::Point & outPoint)
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Media::IGeneralTransformOverrides>().TryTransformCore(inPoint, outPoint);
	}

	Windows::Foundation::Rect TransformBoundsCore(Windows::Foundation::Rect const & rect)
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Media::IGeneralTransformOverrides>().TransformBoundsCore(rect);
	}

	virtual HRESULT __stdcall get_InverseCore(AbiArgOut<Windows::UI::Xaml::Media::IGeneralTransform> value) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->InverseCore();
		});
	}

	virtual HRESULT __stdcall abi_TryTransformCore(Windows::Foundation::Point inPoint, Windows::Foundation::Point * outPoint, boolean * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->TryTransformCore(inPoint, );
		});
	}

	virtual HRESULT __stdcall abi_TransformBoundsCore(Windows::Foundation::Rect rect, Windows::Foundation::Rect * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->TransformBoundsCore(rect);
		});
	}
};

}}}}}

namespace Modern { namespace Windows { namespace UI { namespace Xaml { namespace Media { namespace Animation {

template <typename T, typename A = ABI::Windows::UI::Xaml::Media::Animation::INavigationTransitionInfoOverrides>
struct INavigationTransitionInfoOverridesT : A
{
	String GetNavigationStateCore()
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Media::Animation::INavigationTransitionInfoOverrides>().GetNavigationStateCore();
	}

	void SetNavigationStateCore(String const & navigationState)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Media::Animation::INavigationTransitionInfoOverrides>().SetNavigationStateCore(navigationState);
	}

	virtual HRESULT __stdcall abi_GetNavigationStateCore(HSTRING * returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->GetNavigationStateCore();
		});
	}

	virtual HRESULT __stdcall abi_SetNavigationStateCore(HSTRING navigationState) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->SetNavigationStateCore(forward<String>(navigationState));
		});
	}
};

}}}}}}

namespace Modern { namespace Windows { namespace UI { namespace Xaml { namespace Media { namespace Imaging {

template <typename T, typename A = ABI::Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTaskOverrides>
struct IXamlRenderingBackgroundTaskOverridesT : A
{
	void OnRun(Windows::ApplicationModel::Background::IBackgroundTaskInstance const & taskInstance)
	{
		static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTaskOverrides>().OnRun(taskInstance);
	}

	virtual HRESULT __stdcall abi_OnRun(AbiArgIn<Windows::ApplicationModel::Background::IBackgroundTaskInstance> taskInstance) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->OnRun(forward<Windows::ApplicationModel::Background::IBackgroundTaskInstance>(taskInstance));
		});
	}
};

}}}}}}

namespace Modern { namespace Windows { namespace UI { namespace Xaml { namespace Resources {

template <typename T, typename A = ABI::Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderOverrides>
struct ICustomXamlResourceLoaderOverridesT : A
{
	Modern::IInspectable GetResource(String const & resourceId, String const & objectType, String const & propertyName, String const & propertyType)
	{
		return static_cast<T *>(this)->As<Modern::Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderOverrides>().GetResource(resourceId, objectType, propertyName, propertyType);
	}

	virtual HRESULT __stdcall abi_GetResource(HSTRING resourceId, HSTRING objectType, HSTRING propertyName, HSTRING propertyType, AbiArgOut<IInspectable> returnValue) noexcept override
	{
		return call([&]
		{
			static_cast<T *>(this)->GetResource(forward<String>(resourceId), forward<String>(objectType), forward<String>(propertyName), forward<String>(propertyType));
		});
	}
};

}}}}}

namespace Modern { namespace Windows { namespace UI { namespace Xaml {

template <typename T> struct DependencyObjectT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::IDependencyObject;

protected:

	DependencyObjectT()
	{
		GetActivationFactory<DependencyObject, IDependencyObjectFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct RoutedEventArgsT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::IRoutedEventArgs>
{
	using Composable = Windows::UI::Xaml::IRoutedEventArgs;

protected:

	RoutedEventArgsT()
	{
		GetActivationFactory<RoutedEventArgs, IRoutedEventArgsFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct DataTemplateT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IFrameworkTemplate, Windows::UI::Xaml::IDataTemplate>
{
	using Composable = Windows::UI::Xaml::IDataTemplate;

protected:

	DataTemplateT()
	{
		GetActivationFactory<DataTemplate, IDataTemplateFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct FrameworkElementT :
	Overrides<Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::IFrameworkElement;

protected:

	FrameworkElementT()
	{
		GetActivationFactory<FrameworkElement, IFrameworkElementFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct FrameworkTemplateT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IFrameworkTemplate>
{
	using Composable = Windows::UI::Xaml::IFrameworkTemplate;

protected:

	FrameworkTemplateT()
	{
		GetActivationFactory<FrameworkTemplate, IFrameworkTemplateFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct DispatcherTimerT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::IDispatcherTimer>
{
	using Composable = Windows::UI::Xaml::IDispatcherTimer;

protected:

	DispatcherTimerT()
	{
		GetActivationFactory<DispatcherTimer, IDispatcherTimerFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct DataTemplateKeyT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::IDataTemplateKey>
{
	using Composable = Windows::UI::Xaml::IDataTemplateKey;

protected:

	DataTemplateKeyT()
	{
		GetActivationFactory<DataTemplateKey, IDataTemplateKeyFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}

	DataTemplateKeyT(IInspectable const & dataType)
	{
		GetActivationFactory<DataTemplateKey, IDataTemplateKeyFactory>().CreateInstanceWithType(dataType, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct PropertyMetadataT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::IPropertyMetadata>
{
	using Composable = Windows::UI::Xaml::IPropertyMetadata;

protected:

	PropertyMetadataT(IInspectable const & defaultValue)
	{
		GetActivationFactory<PropertyMetadata, IPropertyMetadataFactory>().CreateInstanceWithDefaultValue(defaultValue, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}

	PropertyMetadataT(IInspectable const & defaultValue, Windows::UI::Xaml::IPropertyChangedCallback const & propertyChangedCallback)
	{
		GetActivationFactory<PropertyMetadata, IPropertyMetadataFactory>().CreateInstanceWithDefaultValueAndCallback(defaultValue, propertyChangedCallback, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct DependencyObjectCollectionT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::Foundation::Collections::IObservableVector<Windows::UI::Xaml::DependencyObject>>
{
	using Composable = Windows::Foundation::Collections::IObservableVector<Windows::UI::Xaml::DependencyObject>;

protected:

	DependencyObjectCollectionT()
	{
		GetActivationFactory<DependencyObjectCollection, IDependencyObjectCollectionFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ResourceDictionaryT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IResourceDictionary, Windows::Foundation::Collections::IMap<IInspectable, IInspectable>, Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<IInspectable, IInspectable>>>
{
	using Composable = Windows::UI::Xaml::IResourceDictionary;

protected:

	ResourceDictionaryT()
	{
		GetActivationFactory<ResourceDictionary, IResourceDictionaryFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct StateTriggerBaseT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IStateTriggerBase, Windows::UI::Xaml::IStateTriggerBaseProtected>
{
	using Composable = Windows::UI::Xaml::IStateTriggerBase;

protected:

	StateTriggerBaseT()
	{
		GetActivationFactory<StateTriggerBase, IStateTriggerBaseFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct VisualStateManagerT :
	Overrides<Windows::UI::Xaml::IVisualStateManagerOverridesT<T>>,
	Requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IVisualStateManager, Windows::UI::Xaml::IVisualStateManagerProtected>
{
	using Composable = Windows::UI::Xaml::IVisualStateManager;

protected:

	VisualStateManagerT()
	{
		GetActivationFactory<VisualStateManager, IVisualStateManagerFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct VisualTransitionT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IVisualTransition>
{
	using Composable = Windows::UI::Xaml::IVisualTransition;

protected:

	VisualTransitionT()
	{
		GetActivationFactory<VisualTransition, IVisualTransitionFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct AdaptiveTriggerT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IStateTriggerBase, Windows::UI::Xaml::IStateTriggerBaseProtected, Windows::UI::Xaml::IAdaptiveTrigger>
{
	using Composable = Windows::UI::Xaml::IAdaptiveTrigger;

protected:

	AdaptiveTriggerT()
	{
		GetActivationFactory<AdaptiveTrigger, IAdaptiveTriggerFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ApplicationT :
	Overrides<Windows::UI::Xaml::IApplicationOverridesT<T>>,
	Requires<T, Windows::UI::Xaml::IApplication>
{
	using Composable = Windows::UI::Xaml::IApplication;

protected:

	ApplicationT()
	{
		GetActivationFactory<Application, IApplicationFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

}}}}

namespace Modern { namespace Windows { namespace UI { namespace Xaml { namespace Automation { namespace Peers {

template <typename T> struct AutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IAutomationPeer;

protected:

	AutomationPeerT()
	{
		GetActivationFactory<AutomationPeer, IAutomationPeerFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct FrameworkElementAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer;

protected:

	FrameworkElementAutomationPeerT(Windows::UI::Xaml::FrameworkElement const & owner)
	{
		GetActivationFactory<FrameworkElementAutomationPeer, IFrameworkElementAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ButtonBaseAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer;

protected:

	ButtonBaseAutomationPeerT(Windows::UI::Xaml::Controls::Primitives::ButtonBase const & owner)
	{
		GetActivationFactory<ButtonBaseAutomationPeer, IButtonBaseAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct CaptureElementAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ICaptureElementAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::ICaptureElementAutomationPeer;

protected:

	CaptureElementAutomationPeerT(Windows::UI::Xaml::Controls::CaptureElement const & owner)
	{
		GetActivationFactory<CaptureElementAutomationPeer, ICaptureElementAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ComboBoxItemAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IComboBoxItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IComboBoxItemAutomationPeer;

protected:

	ComboBoxItemAutomationPeerT(Windows::UI::Xaml::Controls::ComboBoxItem const & owner)
	{
		GetActivationFactory<ComboBoxItemAutomationPeer, IComboBoxItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct FlipViewItemAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IFlipViewItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IFlipViewItemAutomationPeer;

protected:

	FlipViewItemAutomationPeerT(Windows::UI::Xaml::Controls::FlipViewItem const & owner)
	{
		GetActivationFactory<FlipViewItemAutomationPeer, IFlipViewItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct GroupItemAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IGroupItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IGroupItemAutomationPeer;

protected:

	GroupItemAutomationPeerT(Windows::UI::Xaml::Controls::GroupItem const & owner)
	{
		GetActivationFactory<GroupItemAutomationPeer, IGroupItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ImageAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IImageAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IImageAutomationPeer;

protected:

	ImageAutomationPeerT(Windows::UI::Xaml::Controls::Image const & owner)
	{
		GetActivationFactory<ImageAutomationPeer, IImageAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ListBoxItemAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IListBoxItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IListBoxItemAutomationPeer;

protected:

	ListBoxItemAutomationPeerT(Windows::UI::Xaml::Controls::ListBoxItem const & owner)
	{
		GetActivationFactory<ListBoxItemAutomationPeer, IListBoxItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct MediaTransportControlsAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IMediaTransportControlsAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IMediaTransportControlsAutomationPeer;

protected:

	MediaTransportControlsAutomationPeerT(Windows::UI::Xaml::Controls::MediaTransportControls const & owner)
	{
		GetActivationFactory<MediaTransportControlsAutomationPeer, IMediaTransportControlsAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct PasswordBoxAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IPasswordBoxAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IPasswordBoxAutomationPeer;

protected:

	PasswordBoxAutomationPeerT(Windows::UI::Xaml::Controls::PasswordBox const & owner)
	{
		GetActivationFactory<PasswordBoxAutomationPeer, IPasswordBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ProgressRingAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IProgressRingAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IProgressRingAutomationPeer;

protected:

	ProgressRingAutomationPeerT(Windows::UI::Xaml::Controls::ProgressRing const & owner)
	{
		GetActivationFactory<ProgressRingAutomationPeer, IProgressRingAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct RichEditBoxAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IRichEditBoxAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IRichEditBoxAutomationPeer;

protected:

	RichEditBoxAutomationPeerT(Windows::UI::Xaml::Controls::RichEditBox const & owner)
	{
		GetActivationFactory<RichEditBoxAutomationPeer, IRichEditBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct RichTextBlockAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IRichTextBlockAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IRichTextBlockAutomationPeer;

protected:

	RichTextBlockAutomationPeerT(Windows::UI::Xaml::Controls::RichTextBlock const & owner)
	{
		GetActivationFactory<RichTextBlockAutomationPeer, IRichTextBlockAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct RichTextBlockOverflowAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IRichTextBlockOverflowAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IRichTextBlockOverflowAutomationPeer;

protected:

	RichTextBlockOverflowAutomationPeerT(Windows::UI::Xaml::Controls::RichTextBlockOverflow const & owner)
	{
		GetActivationFactory<RichTextBlockOverflowAutomationPeer, IRichTextBlockOverflowAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct SettingsFlyoutAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ISettingsFlyoutAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::ISettingsFlyoutAutomationPeer;

protected:

	SettingsFlyoutAutomationPeerT(Windows::UI::Xaml::Controls::SettingsFlyout const & owner)
	{
		GetActivationFactory<SettingsFlyoutAutomationPeer, ISettingsFlyoutAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct TextBlockAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ITextBlockAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::ITextBlockAutomationPeer;

protected:

	TextBlockAutomationPeerT(Windows::UI::Xaml::Controls::TextBlock const & owner)
	{
		GetActivationFactory<TextBlockAutomationPeer, ITextBlockAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct TextBoxAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ITextBoxAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::ITextBoxAutomationPeer;

protected:

	TextBoxAutomationPeerT(Windows::UI::Xaml::Controls::TextBox const & owner)
	{
		GetActivationFactory<TextBoxAutomationPeer, ITextBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ThumbAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IThumbAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IThumbAutomationPeer;

protected:

	ThumbAutomationPeerT(Windows::UI::Xaml::Controls::Primitives::Thumb const & owner)
	{
		GetActivationFactory<ThumbAutomationPeer, IThumbAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct DatePickerAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IDatePickerAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IDatePickerAutomationPeer;

protected:

	DatePickerAutomationPeerT(Windows::UI::Xaml::Controls::DatePicker const & owner)
	{
		GetActivationFactory<DatePickerAutomationPeer, IDatePickerAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct FlyoutPresenterAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IFlyoutPresenterAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IFlyoutPresenterAutomationPeer;

protected:

	FlyoutPresenterAutomationPeerT(Windows::UI::Xaml::Controls::FlyoutPresenter const & owner)
	{
		GetActivationFactory<FlyoutPresenterAutomationPeer, IFlyoutPresenterAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct GridViewItemAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IGridViewItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IGridViewItemAutomationPeer;

protected:

	GridViewItemAutomationPeerT(Windows::UI::Xaml::Controls::GridViewItem const & owner)
	{
		GetActivationFactory<GridViewItemAutomationPeer, IGridViewItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct HubAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IHubAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IHubAutomationPeer;

protected:

	HubAutomationPeerT(Windows::UI::Xaml::Controls::Hub const & owner)
	{
		GetActivationFactory<HubAutomationPeer, IHubAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ListViewBaseHeaderItemAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeer;

protected:

	ListViewBaseHeaderItemAutomationPeerT(Windows::UI::Xaml::Controls::ListViewBaseHeaderItem const & owner)
	{
		GetActivationFactory<ListViewBaseHeaderItemAutomationPeer, IListViewBaseHeaderItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ListViewItemAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IListViewItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IListViewItemAutomationPeer;

protected:

	ListViewItemAutomationPeerT(Windows::UI::Xaml::Controls::ListViewItem const & owner)
	{
		GetActivationFactory<ListViewItemAutomationPeer, IListViewItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct MediaElementAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IMediaElementAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IMediaElementAutomationPeer;

protected:

	MediaElementAutomationPeerT(Windows::UI::Xaml::Controls::MediaElement const & owner)
	{
		GetActivationFactory<MediaElementAutomationPeer, IMediaElementAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct SearchBoxAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ISearchBoxAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::ISearchBoxAutomationPeer;

protected:

	SearchBoxAutomationPeerT(Windows::UI::Xaml::Controls::SearchBox const & owner)
	{
		GetActivationFactory<SearchBoxAutomationPeer, ISearchBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct TimePickerAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ITimePickerAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::ITimePickerAutomationPeer;

protected:

	TimePickerAutomationPeerT(Windows::UI::Xaml::Controls::TimePicker const & owner)
	{
		GetActivationFactory<TimePickerAutomationPeer, ITimePickerAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct GridViewHeaderItemAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::IGridViewHeaderItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IGridViewHeaderItemAutomationPeer;

protected:

	GridViewHeaderItemAutomationPeerT(Windows::UI::Xaml::Controls::GridViewHeaderItem const & owner)
	{
		GetActivationFactory<GridViewHeaderItemAutomationPeer, IGridViewHeaderItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ListViewHeaderItemAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::IListViewHeaderItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IListViewHeaderItemAutomationPeer;

protected:

	ListViewHeaderItemAutomationPeerT(Windows::UI::Xaml::Controls::ListViewHeaderItem const & owner)
	{
		GetActivationFactory<ListViewHeaderItemAutomationPeer, IListViewHeaderItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ButtonAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonAutomationPeer, Windows::UI::Xaml::Automation::Provider::IInvokeProvider, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IButtonAutomationPeer;

protected:

	ButtonAutomationPeerT(Windows::UI::Xaml::Controls::Button const & owner)
	{
		GetActivationFactory<ButtonAutomationPeer, IButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct HyperlinkButtonAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IHyperlinkButtonAutomationPeer, Windows::UI::Xaml::Automation::Provider::IInvokeProvider, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IHyperlinkButtonAutomationPeer;

protected:

	HyperlinkButtonAutomationPeerT(Windows::UI::Xaml::Controls::HyperlinkButton const & owner)
	{
		GetActivationFactory<HyperlinkButtonAutomationPeer, IHyperlinkButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct RepeatButtonAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IRepeatButtonAutomationPeer, Windows::UI::Xaml::Automation::Provider::IInvokeProvider, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IRepeatButtonAutomationPeer;

protected:

	RepeatButtonAutomationPeerT(Windows::UI::Xaml::Controls::Primitives::RepeatButton const & owner)
	{
		GetActivationFactory<RepeatButtonAutomationPeer, IRepeatButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct MenuFlyoutItemAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IMenuFlyoutItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::IInvokeProvider, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IMenuFlyoutItemAutomationPeer;

protected:

	MenuFlyoutItemAutomationPeerT(Windows::UI::Xaml::Controls::MenuFlyoutItem const & owner)
	{
		GetActivationFactory<MenuFlyoutItemAutomationPeer, IMenuFlyoutItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct AppBarButtonAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonAutomationPeer, Windows::UI::Xaml::Automation::Provider::IInvokeProvider, Windows::UI::Xaml::Automation::Peers::IAppBarButtonAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IAppBarButtonAutomationPeer;

protected:

	AppBarButtonAutomationPeerT(Windows::UI::Xaml::Controls::AppBarButton const & owner)
	{
		GetActivationFactory<AppBarButtonAutomationPeer, IAppBarButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ItemsControlAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer;

protected:

	ItemsControlAutomationPeerT(Windows::UI::Xaml::Controls::ItemsControl const & owner)
	{
		GetActivationFactory<ItemsControlAutomationPeer, IItemsControlAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct MenuFlyoutPresenterAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IMenuFlyoutPresenterAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IMenuFlyoutPresenterAutomationPeer;

protected:

	MenuFlyoutPresenterAutomationPeerT(Windows::UI::Xaml::Controls::MenuFlyoutPresenter const & owner)
	{
		GetActivationFactory<MenuFlyoutPresenterAutomationPeer, IMenuFlyoutPresenterAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct RangeBaseAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer, Windows::UI::Xaml::Automation::Provider::IRangeValueProvider, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer;

protected:

	RangeBaseAutomationPeerT(Windows::UI::Xaml::Controls::Primitives::RangeBase const & owner)
	{
		GetActivationFactory<RangeBaseAutomationPeer, IRangeBaseAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ProgressBarAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer, Windows::UI::Xaml::Automation::Provider::IRangeValueProvider, Windows::UI::Xaml::Automation::Peers::IProgressBarAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IProgressBarAutomationPeer;

protected:

	ProgressBarAutomationPeerT(Windows::UI::Xaml::Controls::ProgressBar const & owner)
	{
		GetActivationFactory<ProgressBarAutomationPeer, IProgressBarAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ScrollBarAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer, Windows::UI::Xaml::Automation::Provider::IRangeValueProvider, Windows::UI::Xaml::Automation::Peers::IScrollBarAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IScrollBarAutomationPeer;

protected:

	ScrollBarAutomationPeerT(Windows::UI::Xaml::Controls::Primitives::ScrollBar const & owner)
	{
		GetActivationFactory<ScrollBarAutomationPeer, IScrollBarAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct SliderAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer, Windows::UI::Xaml::Automation::Provider::IRangeValueProvider, Windows::UI::Xaml::Automation::Peers::ISliderAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::ISliderAutomationPeer;

protected:

	SliderAutomationPeerT(Windows::UI::Xaml::Controls::Slider const & owner)
	{
		GetActivationFactory<SliderAutomationPeer, ISliderAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct HubSectionAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IHubSectionAutomationPeer, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IHubSectionAutomationPeer;

protected:

	HubSectionAutomationPeerT(Windows::UI::Xaml::Controls::HubSection const & owner)
	{
		GetActivationFactory<HubSectionAutomationPeer, IHubSectionAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ScrollViewerAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IScrollViewerAutomationPeer, Windows::UI::Xaml::Automation::Provider::IScrollProvider, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IScrollViewerAutomationPeer;

protected:

	ScrollViewerAutomationPeerT(Windows::UI::Xaml::Controls::ScrollViewer const & owner)
	{
		GetActivationFactory<ScrollViewerAutomationPeer, IScrollViewerAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct SelectorAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionProvider, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer;

protected:

	SelectorAutomationPeerT(Windows::UI::Xaml::Controls::Primitives::Selector const & owner)
	{
		GetActivationFactory<SelectorAutomationPeer, ISelectorAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct FlipViewAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionProvider, Windows::UI::Xaml::Automation::Peers::IFlipViewAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IFlipViewAutomationPeer;

protected:

	FlipViewAutomationPeerT(Windows::UI::Xaml::Controls::FlipView const & owner)
	{
		GetActivationFactory<FlipViewAutomationPeer, IFlipViewAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ListBoxAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionProvider, Windows::UI::Xaml::Automation::Peers::IListBoxAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IListBoxAutomationPeer;

protected:

	ListBoxAutomationPeerT(Windows::UI::Xaml::Controls::ListBox const & owner)
	{
		GetActivationFactory<ListBoxAutomationPeer, IListBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ListViewBaseAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionProvider, Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer, Windows::UI::Xaml::Automation::Provider::IDropTargetProvider, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer;

protected:

	ListViewBaseAutomationPeerT(Windows::UI::Xaml::Controls::ListViewBase const & owner)
	{
		GetActivationFactory<ListViewBaseAutomationPeer, IListViewBaseAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct GridViewAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionProvider, Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer, Windows::UI::Xaml::Automation::Provider::IDropTargetProvider, Windows::UI::Xaml::Automation::Peers::IGridViewAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IGridViewAutomationPeer;

protected:

	GridViewAutomationPeerT(Windows::UI::Xaml::Controls::GridView const & owner)
	{
		GetActivationFactory<GridViewAutomationPeer, IGridViewAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ListViewAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionProvider, Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer, Windows::UI::Xaml::Automation::Provider::IDropTargetProvider, Windows::UI::Xaml::Automation::Peers::IListViewAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IListViewAutomationPeer;

protected:

	ListViewAutomationPeerT(Windows::UI::Xaml::Controls::ListView const & owner)
	{
		GetActivationFactory<ListViewAutomationPeer, IListViewAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct SemanticZoomAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ISemanticZoomAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::ISemanticZoomAutomationPeer;

protected:

	SemanticZoomAutomationPeerT(Windows::UI::Xaml::Controls::SemanticZoom const & owner)
	{
		GetActivationFactory<SemanticZoomAutomationPeer, ISemanticZoomAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ToggleSwitchAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IToggleSwitchAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IToggleSwitchAutomationPeer;

protected:

	ToggleSwitchAutomationPeerT(Windows::UI::Xaml::Controls::ToggleSwitch const & owner)
	{
		GetActivationFactory<ToggleSwitchAutomationPeer, IToggleSwitchAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ToggleButtonAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer;

protected:

	ToggleButtonAutomationPeerT(Windows::UI::Xaml::Controls::Primitives::ToggleButton const & owner)
	{
		GetActivationFactory<ToggleButtonAutomationPeer, IToggleButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct CheckBoxAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider, Windows::UI::Xaml::Automation::Peers::ICheckBoxAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::ICheckBoxAutomationPeer;

protected:

	CheckBoxAutomationPeerT(Windows::UI::Xaml::Controls::CheckBox const & owner)
	{
		GetActivationFactory<CheckBoxAutomationPeer, ICheckBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct RadioButtonAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider, Windows::UI::Xaml::Automation::Peers::IRadioButtonAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IRadioButtonAutomationPeer;

protected:

	RadioButtonAutomationPeerT(Windows::UI::Xaml::Controls::RadioButton const & owner)
	{
		GetActivationFactory<RadioButtonAutomationPeer, IRadioButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct AppBarAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAppBarAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider, Windows::UI::Xaml::Automation::Provider::IExpandCollapseProvider, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IAppBarAutomationPeer;

protected:

	AppBarAutomationPeerT(Windows::UI::Xaml::Controls::AppBar const & owner)
	{
		GetActivationFactory<AppBarAutomationPeer, IAppBarAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ToggleMenuFlyoutItemAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IToggleMenuFlyoutItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IToggleMenuFlyoutItemAutomationPeer;

protected:

	ToggleMenuFlyoutItemAutomationPeerT(Windows::UI::Xaml::Controls::ToggleMenuFlyoutItem const & owner)
	{
		GetActivationFactory<ToggleMenuFlyoutItemAutomationPeer, IToggleMenuFlyoutItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct AppBarToggleButtonAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider, Windows::UI::Xaml::Automation::Peers::IAppBarToggleButtonAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IAppBarToggleButtonAutomationPeer;

protected:

	AppBarToggleButtonAutomationPeerT(Windows::UI::Xaml::Controls::AppBarToggleButton const & owner)
	{
		GetActivationFactory<AppBarToggleButtonAutomationPeer, IAppBarToggleButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ComboBoxAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionProvider, Windows::UI::Xaml::Automation::Peers::IComboBoxAutomationPeer, Windows::UI::Xaml::Automation::Provider::IExpandCollapseProvider, Windows::UI::Xaml::Automation::Provider::IValueProvider, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IComboBoxAutomationPeer;

protected:

	ComboBoxAutomationPeerT(Windows::UI::Xaml::Controls::ComboBox const & owner)
	{
		GetActivationFactory<ComboBoxAutomationPeer, IComboBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ItemAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer;

protected:

	ItemAutomationPeerT(IInspectable const & item, Windows::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer const & parent)
	{
		GetActivationFactory<ItemAutomationPeer, IItemAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct SelectorItemAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer;

protected:

	SelectorItemAutomationPeerT(IInspectable const & item, Windows::UI::Xaml::Automation::Peers::SelectorAutomationPeer const & parent)
	{
		GetActivationFactory<SelectorItemAutomationPeer, ISelectorItemAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ComboBoxItemDataAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::Automation::Peers::IComboBoxItemDataAutomationPeer, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IComboBoxItemDataAutomationPeer;

protected:

	ComboBoxItemDataAutomationPeerT(IInspectable const & item, Windows::UI::Xaml::Automation::Peers::ComboBoxAutomationPeer const & parent)
	{
		GetActivationFactory<ComboBoxItemDataAutomationPeer, IComboBoxItemDataAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct FlipViewItemDataAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::Automation::Peers::IFlipViewItemDataAutomationPeer, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IFlipViewItemDataAutomationPeer;

protected:

	FlipViewItemDataAutomationPeerT(IInspectable const & item, Windows::UI::Xaml::Automation::Peers::FlipViewAutomationPeer const & parent)
	{
		GetActivationFactory<FlipViewItemDataAutomationPeer, IFlipViewItemDataAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ListBoxItemDataAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::Automation::Peers::IListBoxItemDataAutomationPeer, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IListBoxItemDataAutomationPeer;

protected:

	ListBoxItemDataAutomationPeerT(IInspectable const & item, Windows::UI::Xaml::Automation::Peers::ListBoxAutomationPeer const & parent)
	{
		GetActivationFactory<ListBoxItemDataAutomationPeer, IListBoxItemDataAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct GridViewItemDataAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::Automation::Peers::IGridViewItemDataAutomationPeer, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IGridViewItemDataAutomationPeer;

protected:

	GridViewItemDataAutomationPeerT(IInspectable const & item, Windows::UI::Xaml::Automation::Peers::GridViewAutomationPeer const & parent)
	{
		GetActivationFactory<GridViewItemDataAutomationPeer, IGridViewItemDataAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ListViewItemDataAutomationPeerT :
	Overrides<Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<T>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<T>>,
	Requires<T, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::Automation::Peers::IListViewItemDataAutomationPeer, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Automation::Peers::IListViewItemDataAutomationPeer;

protected:

	ListViewItemDataAutomationPeerT(IInspectable const & item, Windows::UI::Xaml::Automation::Peers::ListViewBaseAutomationPeer const & parent)
	{
		GetActivationFactory<ListViewItemDataAutomationPeer, IListViewItemDataAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

}}}}}}

namespace Modern { namespace Windows { namespace UI { namespace Xaml { namespace Controls {

template <typename T> struct ListViewBaseT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IItemsControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IListViewBase, Windows::UI::Xaml::Controls::ISemanticZoomInformation, Windows::UI::Xaml::Controls::IListViewBase2, Windows::UI::Xaml::Controls::IListViewBase3, Windows::UI::Xaml::Controls::IListViewBase4, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IListViewBase;

protected:

	ListViewBaseT()
	{
		GetActivationFactory<ListViewBase, IListViewBaseFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ControlT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IControl;

protected:

	ControlT()
	{
		GetActivationFactory<Control, IControlFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct PanelT :
	Overrides<Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IPanel;

protected:

	PanelT()
	{
		GetActivationFactory<Panel, IPanelFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ContentPresenterT :
	Overrides<Windows::UI::Xaml::Controls::IContentPresenterOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IContentPresenter, Windows::UI::Xaml::Controls::IContentPresenter2, Windows::UI::Xaml::Controls::IContentPresenter3, Windows::UI::Xaml::Controls::IContentPresenter4, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IContentPresenter;

protected:

	ContentPresenterT()
	{
		GetActivationFactory<ContentPresenter, IContentPresenterFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ContentControlT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IContentControl;

protected:

	ContentControlT()
	{
		GetActivationFactory<ContentControl, IContentControlFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ItemsControlT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IItemsControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IItemsControl;

protected:

	ItemsControlT()
	{
		GetActivationFactory<ItemsControl, IItemsControlFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct CanvasT :
	Overrides<Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::ICanvas, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::ICanvas;

protected:

	CanvasT()
	{
		GetActivationFactory<Canvas, ICanvasFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct DataTemplateSelectorT :
	Overrides<Windows::UI::Xaml::Controls::IDataTemplateSelectorOverridesT<T>, Windows::UI::Xaml::Controls::IDataTemplateSelectorOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IDataTemplateSelector, Windows::UI::Xaml::Controls::IDataTemplateSelector2>
{
	using Composable = Windows::UI::Xaml::Controls::IDataTemplateSelector;

protected:

	DataTemplateSelectorT()
	{
		GetActivationFactory<DataTemplateSelector, IDataTemplateSelectorFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct StyleSelectorT :
	Overrides<Windows::UI::Xaml::Controls::IStyleSelectorOverridesT<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IStyleSelector>
{
	using Composable = Windows::UI::Xaml::Controls::IStyleSelector;

protected:

	StyleSelectorT()
	{
		GetActivationFactory<StyleSelector, IStyleSelectorFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct GroupStyleT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::Controls::IGroupStyle, Windows::UI::Xaml::Data::INotifyPropertyChanged, Windows::UI::Xaml::Controls::IGroupStyle2>
{
	using Composable = Windows::UI::Xaml::Controls::IGroupStyle;

protected:

	GroupStyleT()
	{
		GetActivationFactory<GroupStyle, IGroupStyleFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct GroupStyleSelectorT :
	Overrides<Windows::UI::Xaml::Controls::IGroupStyleSelectorOverridesT<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IGroupStyleSelector>
{
	using Composable = Windows::UI::Xaml::Controls::IGroupStyleSelector;

protected:

	GroupStyleSelectorT()
	{
		GetActivationFactory<GroupStyleSelector, IGroupStyleSelectorFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct FlyoutT :
	Overrides<Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverridesT<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase, Windows::UI::Xaml::Controls::IFlyout, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Controls::IFlyout;

protected:

	FlyoutT()
	{
		GetActivationFactory<Flyout, IFlyoutFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct MenuFlyoutT :
	Overrides<Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverridesT<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase, Windows::UI::Xaml::Controls::IMenuFlyout, Windows::UI::Xaml::Controls::IMenuFlyout2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Controls::IMenuFlyout;

protected:

	MenuFlyoutT()
	{
		GetActivationFactory<MenuFlyout, IMenuFlyoutFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct SelectionChangedEventArgsT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::Controls::ISelectionChangedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
	using Composable = Windows::UI::Xaml::Controls::ISelectionChangedEventArgs;

protected:

	SelectionChangedEventArgsT(Windows::Foundation::Collections::IVector<IInspectable> const & removedItems, Windows::Foundation::Collections::IVector<IInspectable> const & addedItems)
	{
		GetActivationFactory<SelectionChangedEventArgs, ISelectionChangedEventArgsFactory>().CreateInstanceWithRemovedItemsAndAddedItems(removedItems, addedItems, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct GridT :
	Overrides<Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IGrid, Windows::UI::Xaml::Controls::IGrid2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IGrid;

protected:

	GridT()
	{
		GetActivationFactory<Grid, IGridFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct RelativePanelT :
	Overrides<Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IRelativePanel, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IRelativePanel;

protected:

	RelativePanelT()
	{
		GetActivationFactory<RelativePanel, IRelativePanelFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct StackPanelT :
	Overrides<Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IStackPanel, Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo, Windows::UI::Xaml::Controls::IStackPanel2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IStackPanel;

protected:

	StackPanelT()
	{
		GetActivationFactory<StackPanel, IStackPanelFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct InkCanvasT :
	Overrides<Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IInkCanvas, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IInkCanvas;

protected:

	InkCanvasT()
	{
		GetActivationFactory<InkCanvas, IInkCanvasFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct BitmapIconT :
	Overrides<Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IIconElement, Windows::UI::Xaml::Controls::IBitmapIcon, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IBitmapIcon;

protected:

	BitmapIconT()
	{
		GetActivationFactory<BitmapIcon, IBitmapIconFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct FontIconT :
	Overrides<Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IIconElement, Windows::UI::Xaml::Controls::IFontIcon, Windows::UI::Xaml::Controls::IFontIcon2, Windows::UI::Xaml::Controls::IFontIcon3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IFontIcon;

protected:

	FontIconT()
	{
		GetActivationFactory<FontIcon, IFontIconFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct PathIconT :
	Overrides<Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IIconElement, Windows::UI::Xaml::Controls::IPathIcon, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IPathIcon;

protected:

	PathIconT()
	{
		GetActivationFactory<PathIcon, IPathIconFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct SwapChainBackgroundPanelT :
	Overrides<Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IGrid, Windows::UI::Xaml::Controls::IGrid2, Windows::UI::Xaml::Controls::ISwapChainBackgroundPanel, Windows::UI::Xaml::Controls::ISwapChainBackgroundPanel2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::ISwapChainBackgroundPanel;

protected:

	SwapChainBackgroundPanelT()
	{
		GetActivationFactory<SwapChainBackgroundPanel, ISwapChainBackgroundPanelFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct SwapChainPanelT :
	Overrides<Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IGrid, Windows::UI::Xaml::Controls::IGrid2, Windows::UI::Xaml::Controls::ISwapChainPanel, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::ISwapChainPanel;

protected:

	SwapChainPanelT()
	{
		GetActivationFactory<SwapChainPanel, ISwapChainPanelFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct MediaTransportControlsT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IMediaTransportControls, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IMediaTransportControls;

protected:

	MediaTransportControlsT()
	{
		GetActivationFactory<MediaTransportControls, IMediaTransportControlsFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct RichEditBoxT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IRichEditBox, Windows::UI::Xaml::Controls::IRichEditBox2, Windows::UI::Xaml::Controls::IRichEditBox3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IRichEditBox;

protected:

	RichEditBoxT()
	{
		GetActivationFactory<RichEditBox, IRichEditBoxFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct TextBoxT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::ITextBox, Windows::UI::Xaml::Controls::ITextBox2, Windows::UI::Xaml::Controls::ITextBox3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::ITextBox;

protected:

	TextBoxT()
	{
		GetActivationFactory<TextBox, ITextBoxFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct UserControlT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IUserControl, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IUserControl;

protected:

	UserControlT()
	{
		GetActivationFactory<UserControl, IUserControlFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct GroupItemT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IGroupItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IGroupItem;

protected:

	GroupItemT()
	{
		GetActivationFactory<GroupItem, IGroupItemFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct SettingsFlyoutT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::ISettingsFlyout, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::ISettingsFlyout;

protected:

	SettingsFlyoutT()
	{
		GetActivationFactory<SettingsFlyout, ISettingsFlyoutFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ToolTipT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IToolTip, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IToolTip;

protected:

	ToolTipT()
	{
		GetActivationFactory<ToolTip, IToolTipFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ComboBoxItemT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IComboBoxItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IComboBoxItem;

protected:

	ComboBoxItemT()
	{
		GetActivationFactory<ComboBoxItem, IComboBoxItemFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct FlipViewItemT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IFlipViewItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IFlipViewItem;

protected:

	FlipViewItemT()
	{
		GetActivationFactory<FlipViewItem, IFlipViewItemFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ListBoxItemT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IListBoxItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IListBoxItem;

protected:

	ListBoxItemT()
	{
		GetActivationFactory<ListBoxItem, IListBoxItemFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ProgressBarT :
	Overrides<Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverridesT<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::IRangeBase, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IProgressBar, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IProgressBar;

protected:

	ProgressBarT()
	{
		GetActivationFactory<ProgressBar, IProgressBarFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct SliderT :
	Overrides<Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverridesT<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::IRangeBase, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::ISlider, Windows::UI::Xaml::Controls::ISlider2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::ISlider;

protected:

	SliderT()
	{
		GetActivationFactory<Slider, ISliderFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ButtonT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IButton, Windows::UI::Xaml::Controls::IButtonWithFlyout, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IButton;

protected:

	ButtonT()
	{
		GetActivationFactory<Button, IButtonFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct HyperlinkButtonT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IHyperlinkButton, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IHyperlinkButton;

protected:

	HyperlinkButtonT()
	{
		GetActivationFactory<HyperlinkButton, IHyperlinkButtonFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ComboBoxT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IItemsControlOverridesT<T>, Windows::UI::Xaml::Controls::IComboBoxOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IComboBox, Windows::UI::Xaml::Controls::IComboBox2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IComboBox;

protected:

	ComboBoxT()
	{
		GetActivationFactory<ComboBox, IComboBoxFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct FlipViewT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IItemsControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IFlipView, Windows::UI::Xaml::Controls::IFlipView2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IFlipView;

protected:

	FlipViewT()
	{
		GetActivationFactory<FlipView, IFlipViewFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ListBoxT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IItemsControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IListBox, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IListBox;

protected:

	ListBoxT()
	{
		GetActivationFactory<ListBox, IListBoxFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct CheckBoxT :
	Overrides<Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::ICheckBox, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::ICheckBox;

protected:

	CheckBoxT()
	{
		GetActivationFactory<CheckBox, ICheckBoxFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct RadioButtonT :
	Overrides<Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IRadioButton, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IRadioButton;

protected:

	RadioButtonT()
	{
		GetActivationFactory<RadioButton, IRadioButtonFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct CalendarViewT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::ICalendarView, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::ICalendarView;

protected:

	CalendarViewT()
	{
		GetActivationFactory<CalendarView, ICalendarViewFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct CalendarViewDayItemT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::ICalendarViewDayItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::ICalendarViewDayItem;

protected:

	CalendarViewDayItemT()
	{
		GetActivationFactory<CalendarViewDayItem, ICalendarViewDayItemFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct HubSectionT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IHubSection, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IHubSection;

protected:

	HubSectionT()
	{
		GetActivationFactory<HubSection, IHubSectionFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct AppBarSeparatorT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IAppBarSeparator, Windows::UI::Xaml::Controls::ICommandBarElement, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IAppBarSeparator;

protected:

	AppBarSeparatorT()
	{
		GetActivationFactory<AppBarSeparator, IAppBarSeparatorFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct CalendarDatePickerT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::ICalendarDatePicker, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::ICalendarDatePicker;

protected:

	CalendarDatePickerT()
	{
		GetActivationFactory<CalendarDatePicker, ICalendarDatePickerFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct DatePickerT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IDatePicker, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IDatePicker;

protected:

	DatePickerT()
	{
		GetActivationFactory<DatePicker, IDatePickerFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct HubT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IHub, Windows::UI::Xaml::Controls::ISemanticZoomInformation, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IHub;

protected:

	HubT()
	{
		GetActivationFactory<Hub, IHubFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct SearchBoxT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::ISearchBox, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::ISearchBox;

protected:

	SearchBoxT()
	{
		GetActivationFactory<SearchBox, ISearchBoxFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct SplitViewT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::ISplitView, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::ISplitView;

protected:

	SplitViewT()
	{
		GetActivationFactory<SplitView, ISplitViewFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct TimePickerT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::ITimePicker, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::ITimePicker;

protected:

	TimePickerT()
	{
		GetActivationFactory<TimePicker, ITimePickerFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct AppBarT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::Controls::IAppBarOverridesT<T>, Windows::UI::Xaml::Controls::IAppBarOverrides3T<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IAppBar, Windows::UI::Xaml::Controls::IAppBar2, Windows::UI::Xaml::Controls::IAppBar3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IAppBar;

protected:

	AppBarT()
	{
		GetActivationFactory<AppBar, IAppBarFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct CommandBarOverflowPresenterT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IItemsControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::ICommandBarOverflowPresenter, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::ICommandBarOverflowPresenter;

protected:

	CommandBarOverflowPresenterT()
	{
		GetActivationFactory<CommandBarOverflowPresenter, ICommandBarOverflowPresenterFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ContentDialogT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IContentDialog, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IContentDialog;

protected:

	ContentDialogT()
	{
		GetActivationFactory<ContentDialog, IContentDialogFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct FlyoutPresenterT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IFlyoutPresenter, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IFlyoutPresenter;

protected:

	FlyoutPresenterT()
	{
		GetActivationFactory<FlyoutPresenter, IFlyoutPresenterFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct FrameT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IFrame, Windows::UI::Xaml::Controls::INavigate, Windows::UI::Xaml::Controls::IFrame2, Windows::UI::Xaml::Controls::IFrame3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IFrame;

protected:

	FrameT()
	{
		GetActivationFactory<Frame, IFrameFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct MenuFlyoutItemT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IMenuFlyoutItemBase, Windows::UI::Xaml::Controls::IMenuFlyoutItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IMenuFlyoutItem;

protected:

	MenuFlyoutItemT()
	{
		GetActivationFactory<MenuFlyoutItem, IMenuFlyoutItemFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct MenuFlyoutPresenterT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IItemsControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IMenuFlyoutPresenter, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IMenuFlyoutPresenter;

protected:

	MenuFlyoutPresenterT()
	{
		GetActivationFactory<MenuFlyoutPresenter, IMenuFlyoutPresenterFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct MenuFlyoutSeparatorT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IMenuFlyoutItemBase, Windows::UI::Xaml::Controls::IMenuFlyoutSeparator, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IMenuFlyoutSeparator;

protected:

	MenuFlyoutSeparatorT()
	{
		GetActivationFactory<MenuFlyoutSeparator, IMenuFlyoutSeparatorFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct PageT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IPageOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IUserControl, Windows::UI::Xaml::Controls::IPage, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IPage;

protected:

	PageT()
	{
		GetActivationFactory<Page, IPageFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct CommandBarT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::Controls::IAppBarOverridesT<T>, Windows::UI::Xaml::Controls::IAppBarOverrides3T<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IAppBar, Windows::UI::Xaml::Controls::IAppBar2, Windows::UI::Xaml::Controls::IAppBar3, Windows::UI::Xaml::Controls::ICommandBar, Windows::UI::Xaml::Controls::ICommandBar2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::ICommandBar;

protected:

	CommandBarT()
	{
		GetActivationFactory<CommandBar, ICommandBarFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct GridViewHeaderItemT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IListViewBaseHeaderItem, Windows::UI::Xaml::Controls::IGridViewHeaderItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IGridViewHeaderItem;

protected:

	GridViewHeaderItemT()
	{
		GetActivationFactory<GridViewHeaderItem, IGridViewHeaderItemFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct GridViewItemT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IGridViewItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IGridViewItem;

protected:

	GridViewItemT()
	{
		GetActivationFactory<GridViewItem, IGridViewItemFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ListViewHeaderItemT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IListViewBaseHeaderItem, Windows::UI::Xaml::Controls::IListViewHeaderItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IListViewHeaderItem;

protected:

	ListViewHeaderItemT()
	{
		GetActivationFactory<ListViewHeaderItem, IListViewHeaderItemFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ListViewItemT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IListViewItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IListViewItem;

protected:

	ListViewItemT()
	{
		GetActivationFactory<ListViewItem, IListViewItemFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ToggleMenuFlyoutItemT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IMenuFlyoutItemBase, Windows::UI::Xaml::Controls::IMenuFlyoutItem, Windows::UI::Xaml::Controls::IToggleMenuFlyoutItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IToggleMenuFlyoutItem;

protected:

	ToggleMenuFlyoutItemT()
	{
		GetActivationFactory<ToggleMenuFlyoutItem, IToggleMenuFlyoutItemFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct AppBarButtonT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IButton, Windows::UI::Xaml::Controls::IButtonWithFlyout, Windows::UI::Xaml::Controls::IAppBarButton, Windows::UI::Xaml::Controls::ICommandBarElement, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IAppBarButton;

protected:

	AppBarButtonT()
	{
		GetActivationFactory<AppBarButton, IAppBarButtonFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct AppBarToggleButtonT :
	Overrides<Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IAppBarToggleButton, Windows::UI::Xaml::Controls::ICommandBarElement, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IAppBarToggleButton;

protected:

	AppBarToggleButtonT()
	{
		GetActivationFactory<AppBarToggleButton, IAppBarToggleButtonFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct GridViewT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IItemsControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IListViewBase, Windows::UI::Xaml::Controls::ISemanticZoomInformation, Windows::UI::Xaml::Controls::IListViewBase2, Windows::UI::Xaml::Controls::IListViewBase3, Windows::UI::Xaml::Controls::IListViewBase4, Windows::UI::Xaml::Controls::IGridView, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IGridView;

protected:

	GridViewT()
	{
		GetActivationFactory<GridView, IGridViewFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ListViewT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IItemsControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IListViewBase, Windows::UI::Xaml::Controls::ISemanticZoomInformation, Windows::UI::Xaml::Controls::IListViewBase2, Windows::UI::Xaml::Controls::IListViewBase3, Windows::UI::Xaml::Controls::IListViewBase4, Windows::UI::Xaml::Controls::IListView, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IListView;

protected:

	ListViewT()
	{
		GetActivationFactory<ListView, IListViewFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct PivotT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IItemsControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IPivot, Windows::UI::Xaml::Controls::IPivot2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IPivot;

protected:

	PivotT()
	{
		GetActivationFactory<Pivot, IPivotFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct PivotItemT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IPivotItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::IPivotItem;

protected:

	PivotItemT()
	{
		GetActivationFactory<PivotItem, IPivotItemFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

}}}}}

namespace Modern { namespace Windows { namespace UI { namespace Xaml { namespace Controls { namespace Primitives {

template <typename T> struct FlyoutBaseT :
	Overrides<Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverridesT<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Controls::Primitives::IFlyoutBase;

protected:

	FlyoutBaseT()
	{
		GetActivationFactory<FlyoutBase, IFlyoutBaseFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct DragCompletedEventArgsT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::IDragCompletedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
	using Composable = Windows::UI::Xaml::Controls::Primitives::IDragCompletedEventArgs;

protected:

	DragCompletedEventArgsT(double const horizontalChange, double const verticalChange, bool const canceled)
	{
		GetActivationFactory<DragCompletedEventArgs, IDragCompletedEventArgsFactory>().CreateInstanceWithHorizontalChangeVerticalChangeAndCanceled(horizontalChange, verticalChange, canceled, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct DragDeltaEventArgsT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::IDragDeltaEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
	using Composable = Windows::UI::Xaml::Controls::Primitives::IDragDeltaEventArgs;

protected:

	DragDeltaEventArgsT(double const horizontalChange, double const verticalChange)
	{
		GetActivationFactory<DragDeltaEventArgs, IDragDeltaEventArgsFactory>().CreateInstanceWithHorizontalChangeAndVerticalChange(horizontalChange, verticalChange, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct DragStartedEventArgsT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::IDragStartedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
	using Composable = Windows::UI::Xaml::Controls::Primitives::IDragStartedEventArgs;

protected:

	DragStartedEventArgsT(double const horizontalOffset, double const verticalOffset)
	{
		GetActivationFactory<DragStartedEventArgs, IDragStartedEventArgsFactory>().CreateInstanceWithHorizontalOffsetAndVerticalOffset(horizontalOffset, verticalOffset, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct CarouselPanelT :
	Overrides<Windows::UI::Xaml::Controls::IVirtualizingPanelOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::ICarouselPanel, Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IVirtualizingPanel, Windows::UI::Xaml::Controls::IVirtualizingPanelProtected, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::Primitives::ICarouselPanel;

protected:

	CarouselPanelT()
	{
		GetActivationFactory<CarouselPanel, ICarouselPanelFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct GridViewItemPresenterT :
	Overrides<Windows::UI::Xaml::Controls::IContentPresenterOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter, Windows::UI::Xaml::Controls::IContentPresenter, Windows::UI::Xaml::Controls::IContentPresenter2, Windows::UI::Xaml::Controls::IContentPresenter3, Windows::UI::Xaml::Controls::IContentPresenter4, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter;

protected:

	GridViewItemPresenterT()
	{
		GetActivationFactory<GridViewItemPresenter, IGridViewItemPresenterFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ListViewItemPresenterT :
	Overrides<Windows::UI::Xaml::Controls::IContentPresenterOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter, Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter2, Windows::UI::Xaml::Controls::IContentPresenter, Windows::UI::Xaml::Controls::IContentPresenter2, Windows::UI::Xaml::Controls::IContentPresenter3, Windows::UI::Xaml::Controls::IContentPresenter4, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter;

protected:

	ListViewItemPresenterT()
	{
		GetActivationFactory<ListViewItemPresenter, IListViewItemPresenterFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct SelectorItemT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::Primitives::ISelectorItem;

protected:

	SelectorItemT()
	{
		GetActivationFactory<SelectorItem, ISelectorItemFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct RangeBaseT :
	Overrides<Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverridesT<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::IRangeBase, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::Primitives::IRangeBase;

protected:

	RangeBaseT()
	{
		GetActivationFactory<RangeBase, IRangeBaseFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ButtonBaseT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::Primitives::IButtonBase;

protected:

	ButtonBaseT()
	{
		GetActivationFactory<ButtonBase, IButtonBaseFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ToggleButtonT :
	Overrides<Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<T>, Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::Primitives::IToggleButton;

protected:

	ToggleButtonT()
	{
		GetActivationFactory<ToggleButton, IToggleButtonFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct PickerFlyoutBaseT :
	Overrides<Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverridesT<T>, Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBaseOverridesT<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase, Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBase;

protected:

	PickerFlyoutBaseT()
	{
		GetActivationFactory<PickerFlyoutBase, IPickerFlyoutBaseFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct PivotHeaderItemT :
	Overrides<Windows::UI::Xaml::Controls::IControlOverridesT<T>, Windows::UI::Xaml::Controls::IContentControlOverridesT<T>, Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::Controls::Primitives::IPivotHeaderItem, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3>
{
	using Composable = Windows::UI::Xaml::Controls::Primitives::IPivotHeaderItem;

protected:

	PivotHeaderItemT()
	{
		GetActivationFactory<PivotHeaderItem, IPivotHeaderItemFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

}}}}}}

namespace Modern { namespace Windows { namespace UI { namespace Xaml { namespace Data {

template <typename T> struct CurrentChangingEventArgsT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::Data::ICurrentChangingEventArgs>
{
	using Composable = Windows::UI::Xaml::Data::ICurrentChangingEventArgs;

protected:

	CurrentChangingEventArgsT()
	{
		GetActivationFactory<CurrentChangingEventArgs, ICurrentChangingEventArgsFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}

	CurrentChangingEventArgsT(bool const isCancelable)
	{
		GetActivationFactory<CurrentChangingEventArgs, ICurrentChangingEventArgsFactory>().CreateWithCancelableParameter(isCancelable, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct PropertyChangedEventArgsT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::Data::IPropertyChangedEventArgs>
{
	using Composable = Windows::UI::Xaml::Data::IPropertyChangedEventArgs;

protected:

	PropertyChangedEventArgsT(String const & name)
	{
		GetActivationFactory<PropertyChangedEventArgs, IPropertyChangedEventArgsFactory>().CreateInstance(name, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct BindingBaseT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::Data::IBindingBase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Data::IBindingBase;

protected:

	BindingBaseT()
	{
		GetActivationFactory<BindingBase, IBindingBaseFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct RelativeSourceT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::Data::IRelativeSource, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Data::IRelativeSource;

protected:

	RelativeSourceT()
	{
		GetActivationFactory<RelativeSource, IRelativeSourceFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct BindingT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::Data::IBindingBase, Windows::UI::Xaml::Data::IBinding, Windows::UI::Xaml::Data::IBinding2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Data::IBinding;

protected:

	BindingT()
	{
		GetActivationFactory<Binding, IBindingFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ItemIndexRangeT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::Data::IItemIndexRange>
{
	using Composable = Windows::UI::Xaml::Data::IItemIndexRange;

protected:

	ItemIndexRangeT(int const firstIndex, unsigned const length)
	{
		GetActivationFactory<ItemIndexRange, IItemIndexRangeFactory>().CreateInstance(firstIndex, length, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

}}}}}

namespace Modern { namespace Windows { namespace UI { namespace Xaml { namespace Documents {

template <typename T> struct BlockT :
	Overrides<Windows::UI::Xaml::Documents::ITextElementOverridesT<T>>,
	Requires<T, Windows::UI::Xaml::Documents::ITextElement, Windows::UI::Xaml::Documents::ITextElement2, Windows::UI::Xaml::Documents::IBlock, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Documents::IBlock;

protected:

	BlockT()
	{
		GetActivationFactory<Block, IBlockFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct InlineT :
	Overrides<Windows::UI::Xaml::Documents::ITextElementOverridesT<T>>,
	Requires<T, Windows::UI::Xaml::Documents::ITextElement, Windows::UI::Xaml::Documents::ITextElement2, Windows::UI::Xaml::Documents::IInline, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Documents::IInline;

protected:

	InlineT()
	{
		GetActivationFactory<Inline, IInlineFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct SpanT :
	Overrides<Windows::UI::Xaml::Documents::ITextElementOverridesT<T>>,
	Requires<T, Windows::UI::Xaml::Documents::ITextElement, Windows::UI::Xaml::Documents::ITextElement2, Windows::UI::Xaml::Documents::IInline, Windows::UI::Xaml::Documents::ISpan, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Documents::ISpan;

protected:

	SpanT()
	{
		GetActivationFactory<Span, ISpanFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

}}}}}

namespace Modern { namespace Windows { namespace UI { namespace Xaml { namespace Input {

template <typename T> struct ManipulationStartedRoutedEventArgsT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
	using Composable = Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs;

protected:

	ManipulationStartedRoutedEventArgsT()
	{
		GetActivationFactory<ManipulationStartedRoutedEventArgs, IManipulationStartedRoutedEventArgsFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

}}}}}

namespace Modern { namespace Windows { namespace UI { namespace Xaml { namespace Interop {

template <typename T> struct NotifyCollectionChangedEventArgsT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::Interop::INotifyCollectionChangedEventArgs>
{
	using Composable = Windows::UI::Xaml::Interop::INotifyCollectionChangedEventArgs;

protected:

	NotifyCollectionChangedEventArgsT(Windows::UI::Xaml::Interop::NotifyCollectionChangedAction const action, Windows::UI::Xaml::Interop::IBindableVector const & newItems, Windows::UI::Xaml::Interop::IBindableVector const & oldItems, int const newIndex, int const oldIndex)
	{
		GetActivationFactory<NotifyCollectionChangedEventArgs, INotifyCollectionChangedEventArgsFactory>().CreateInstanceWithAllParameters(action, newItems, oldItems, newIndex, oldIndex, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

}}}}}

namespace Modern { namespace Windows { namespace UI { namespace Xaml { namespace Media {

template <typename T> struct FontFamilyT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::Media::IFontFamily>
{
	using Composable = Windows::UI::Xaml::Media::IFontFamily;

protected:

	FontFamilyT(String const & familyName)
	{
		GetActivationFactory<FontFamily, IFontFamilyFactory>().CreateInstanceWithName(familyName, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct BrushT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::Media::IBrush, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Media::IBrush;

protected:

	BrushT()
	{
		GetActivationFactory<Brush, IBrushFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct CacheModeT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::Media::ICacheMode, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Media::ICacheMode;

protected:

	CacheModeT()
	{
		GetActivationFactory<CacheMode, ICacheModeFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct GeneralTransformT :
	Overrides<Windows::UI::Xaml::Media::IGeneralTransformOverridesT<T>>,
	Requires<T, Windows::UI::Xaml::Media::IGeneralTransform, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Media::IGeneralTransform;

protected:

	GeneralTransformT()
	{
		GetActivationFactory<GeneralTransform, IGeneralTransformFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ProjectionT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::Media::IProjection, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Media::IProjection;

protected:

	ProjectionT()
	{
		GetActivationFactory<Projection, IProjectionFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct GradientBrushT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::Media::IBrush, Windows::UI::Xaml::Media::IGradientBrush, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Media::IGradientBrush;

protected:

	GradientBrushT()
	{
		GetActivationFactory<GradientBrush, IGradientBrushFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct TileBrushT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::Media::IBrush, Windows::UI::Xaml::Media::ITileBrush, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Media::ITileBrush;

protected:

	TileBrushT()
	{
		GetActivationFactory<TileBrush, ITileBrushFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

}}}}}

namespace Modern { namespace Windows { namespace UI { namespace Xaml { namespace Media { namespace Animation {

template <typename T> struct ColorKeyFrameT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::Media::Animation::IColorKeyFrame, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Media::Animation::IColorKeyFrame;

protected:

	ColorKeyFrameT()
	{
		GetActivationFactory<ColorKeyFrame, IColorKeyFrameFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct DoubleKeyFrameT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::Media::Animation::IDoubleKeyFrame, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Media::Animation::IDoubleKeyFrame;

protected:

	DoubleKeyFrameT()
	{
		GetActivationFactory<DoubleKeyFrame, IDoubleKeyFrameFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct NavigationTransitionInfoT :
	Overrides<Windows::UI::Xaml::Media::Animation::INavigationTransitionInfoOverridesT<T>>,
	Requires<T, Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo;

protected:

	NavigationTransitionInfoT()
	{
		GetActivationFactory<NavigationTransitionInfo, INavigationTransitionInfoFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct ObjectKeyFrameT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::Media::Animation::IObjectKeyFrame, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Media::Animation::IObjectKeyFrame;

protected:

	ObjectKeyFrameT()
	{
		GetActivationFactory<ObjectKeyFrame, IObjectKeyFrameFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct PointKeyFrameT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::Media::Animation::IPointKeyFrame, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Media::Animation::IPointKeyFrame;

protected:

	PointKeyFrameT()
	{
		GetActivationFactory<PointKeyFrame, IPointKeyFrameFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct TimelineT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::Media::Animation::ITimeline, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Media::Animation::ITimeline;

protected:

	TimelineT()
	{
		GetActivationFactory<Timeline, ITimelineFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

}}}}}}

namespace Modern { namespace Windows { namespace UI { namespace Xaml { namespace Media { namespace Imaging {

template <typename T> struct XamlRenderingBackgroundTaskT :
	Overrides<Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTaskOverridesT<T>>,
	Requires<T, Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTask>
{
	using Composable = Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTask;

protected:

	XamlRenderingBackgroundTaskT()
	{
		GetActivationFactory<XamlRenderingBackgroundTask, IXamlRenderingBackgroundTaskFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct BitmapSourceT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::Media::IImageSource, Windows::UI::Xaml::Media::Imaging::IBitmapSource, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Media::Imaging::IBitmapSource;

protected:

	BitmapSourceT()
	{
		GetActivationFactory<BitmapSource, IBitmapSourceFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct SurfaceImageSourceT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::Media::IImageSource, Windows::UI::Xaml::Media::Imaging::ISurfaceImageSource, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Media::Imaging::ISurfaceImageSource;

protected:

	SurfaceImageSourceT(int const pixelWidth, int const pixelHeight)
	{
		GetActivationFactory<SurfaceImageSource, ISurfaceImageSourceFactory>().CreateInstanceWithDimensions(pixelWidth, pixelHeight, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}

	SurfaceImageSourceT(int const pixelWidth, int const pixelHeight, bool const isOpaque)
	{
		GetActivationFactory<SurfaceImageSource, ISurfaceImageSourceFactory>().CreateInstanceWithDimensionsAndOpacity(pixelWidth, pixelHeight, isOpaque, Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

}}}}}}

namespace Modern { namespace Windows { namespace UI { namespace Xaml { namespace Media { namespace Media3D {

template <typename T> struct Transform3DT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::Media::Media3D::ITransform3D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
	using Composable = Windows::UI::Xaml::Media::Media3D::ITransform3D;

protected:

	Transform3DT()
	{
		GetActivationFactory<Transform3D, ITransform3DFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

}}}}}}

namespace Modern { namespace Windows { namespace UI { namespace Xaml { namespace Printing {

template <typename T> struct PrintDocumentT :
	Overrides<::IInspectable>,
	Requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Printing::IPrintDocument>
{
	using Composable = Windows::UI::Xaml::Printing::IPrintDocument;

protected:

	PrintDocumentT()
	{
		GetActivationFactory<PrintDocument, IPrintDocumentFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

}}}}}

namespace Modern { namespace Windows { namespace UI { namespace Xaml { namespace Resources {

template <typename T> struct CustomXamlResourceLoaderT :
	Overrides<Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderOverridesT<T>>,
	Requires<T, Windows::UI::Xaml::Resources::ICustomXamlResourceLoader>
{
	using Composable = Windows::UI::Xaml::Resources::ICustomXamlResourceLoader;

protected:

	CustomXamlResourceLoaderT()
	{
		GetActivationFactory<CustomXamlResourceLoader, ICustomXamlResourceLoaderFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

}}}}}

namespace Modern { namespace Windows { namespace UI { namespace Xaml { namespace Shapes {

template <typename T> struct ShapeT :
	Overrides<Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Shapes::IShape>
{
	using Composable = Windows::UI::Xaml::Shapes::IShape;

protected:

	ShapeT()
	{
		GetActivationFactory<Shape, IShapeFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

template <typename T> struct PathT :
	Overrides<Windows::UI::Xaml::IUIElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverridesT<T>, Windows::UI::Xaml::IFrameworkElementOverrides2T<T>>,
	Requires<T, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::Shapes::IShape, Windows::UI::Xaml::Shapes::IPath>
{
	using Composable = Windows::UI::Xaml::Shapes::IPath;

protected:

	PathT()
	{
		GetActivationFactory<Path, IPathFactory>().CreateInstance(Lease<Modern::Windows::IInspectable>(this), m_inner);
	}
};

}}}}}

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
