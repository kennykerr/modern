#include "pch.h"

using namespace Modern;

using namespace Windows::ApplicationModel::Activation;
using namespace Windows::Foundation;
using namespace Windows::UI;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Media;

struct App : ApplicationT<App>
{
public:

    void OnLaunched(LaunchActivatedEventArgs const &)
    {
        TextBlock text;

        text.RegisterPropertyChangedCallback(text.TextProperty(), [](DependencyObject const & object, DependencyProperty const & property)
        {
            IPropertyValue value = object.GetValue(property).As<IPropertyValue>();

            MODERN_TRACE(L"%ls\n", value.GetString().Buffer());
        });

        text.Text(L"Modern C++\nfor the\nWindows Runtime");
        text.FontFamily(FontFamily(L"Segoe UI Semibold"));
        text.FontSize(48.0);
        text.Foreground(SolidColorBrush(Colors::LightGreen()));
        text.VerticalAlignment(VerticalAlignment::Center);
        text.TextAlignment(TextAlignment::Center);

        Window window = Window::Current();
        window.Content(text);
        window.Activate();
    }
};

int __stdcall wWinMain(HINSTANCE, HINSTANCE, PWSTR, int)
{
    Application::Start([](auto const &)
    {
        make<App>();
    });
}