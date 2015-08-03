#include "pch.h"

using namespace Modern;

using namespace Windows::ApplicationModel::Core;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Numerics;
using namespace Windows::System;
using namespace Windows::UI;
using namespace Windows::UI::Core;
using namespace Windows::UI::Composition;

static float const BlockSize = 100.0f;

struct View : IFrameworkViewT<View>
{
    CompositionTarget m_target = nullptr;
    VisualCollection m_visuals = nullptr;
    Visual m_selected = nullptr;
    Vector2 m_offset = {};

    void SetWindow(CoreWindow const & window)
    {
        Compositor compositor;
        ContainerVisual root = compositor.CreateContainerVisual();
        m_target = compositor.CreateTargetForCurrentView();
        m_target.Root(root);
        m_visuals = root.Children();

        window.PointerPressed([&](auto const &, PointerEventArgs const & args)
        {
            Point point = args.CurrentPoint().Position();

            if (args.KeyModifiers() == VirtualKeyModifiers::Control)
            {
                AddVisual(point);
            }
            else
            {
                SelectVisual(point);
            }
        });

        window.PointerMoved([&](auto const &, PointerEventArgs const & args)
        {
            if (m_selected)
            {
                Point point = args.CurrentPoint().Position();

                m_selected.Offset(Vector3
                {
                    point.X + m_offset.X,
                    point.Y + m_offset.Y
                });
            }
        });

        window.PointerReleased([&](auto const &, auto const &)
        {
            m_selected = nullptr;
        });
    }

    void ScaleVisuals()
    {
        for (Visual const & visual : m_visuals)
        {
            Vector3 offset = visual.Offset();
            Vector2 size = visual.Size();

            visual.Offset(Vector3
            {
                offset.X + size.X / 2.0f - BlockSize / 2.0f,
                offset.Y + size.Y / 2.0f - BlockSize / 2.0f,
            });

            visual.Size(Vector2
            {
                BlockSize,
                BlockSize,
            });
        }
    }

    void AddVisual(Point point)
    {
        Compositor compositor = m_visuals.Compositor();
        SolidColorVisual visual = compositor.CreateSolidColorVisual();

        static Color colors[] =
        {
            { 0xDC, 0x5B, 0x9B, 0xD5 },
            { 0xDC, 0xED, 0x7D, 0x31 },
            { 0xDC, 0x70, 0xAD, 0x47 },
            { 0xDC, 0xFF, 0xC0, 0x00 }
        };

        static unsigned last = 0;
        unsigned next = ++last % _countof(colors);
        visual.Color(colors[next]);

        visual.Size(Vector2
        {
            BlockSize,
            BlockSize
        });

        visual.Offset(Vector3
        {
            point.X - BlockSize / 2.0f,
            point.Y - BlockSize / 2.0f,
        });

        m_visuals.InsertAtTop(visual);
    }

    void SelectVisual(Point point)
    {
        for (Visual const & visual : m_visuals)
        {
            Vector3 offset = visual.Offset();
            Vector2 size = visual.Size();

            if (point.X >= offset.X &&
                point.X < offset.X + size.X &&
                point.Y >= offset.Y &&
                point.Y < offset.Y + size.Y)
            {
                m_selected = visual;
                m_offset.X = offset.X - point.X;
                m_offset.Y = offset.Y - point.Y;
            }
        }

        if (m_selected)
        {
            m_visuals.Remove(m_selected);
            m_visuals.InsertAtTop(m_selected);
        }
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