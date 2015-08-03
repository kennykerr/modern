#include "pch.h"

using namespace Modern;

using namespace Windows::ApplicationModel::Core;
using namespace Windows::UI::Core;
using namespace Windows::UI::Popups;

struct View : IFrameworkViewT<View>
{
    void SetWindow(CoreWindow const & window)
    {
        window.KeyUp([](CoreWindow const &, KeyEventArgs const & args)
        {
            MODERN_TRACE(L"key: %c\n", args.VirtualKey());
        });

        MessageDialog dialog(L"Modern C++ for the Windows Runtime", L"Hello World!");

        dialog.ShowAsync().Completed([](auto const &, AsyncStatus)
        {
            // CoreApplication::Exit();
        });
    }
};

struct ViewSource : IFrameworkViewSourceT<ViewSource>
{
    IFrameworkView CreateView()
    {
        return make<View>();
    }
};

int __stdcall wWinMain(HINSTANCE, HINSTANCE, PWSTR, int)
{
    CoreApplication::Run(make<ViewSource>());
}