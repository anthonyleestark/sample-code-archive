// sfw_vboxlayout_demo.hpp
// SFW Framework Win32 VBoxLayout Demo
// Một demo cơ bản về VBoxLayout tự động cho Win32 API

#include <windows.h>
#include <vector>
#include <string>

// ---------------- Layout Engine ------------------

struct Control {
    HWND hwnd;
    int preferredHeight; 	// chiều cao mong muốn
    bool expand;          	// có co giãn không
    int margin = 4;       	// khoảng cách giữa control và control kế tiếp
};

struct VBoxLayout {
    std::vector<Control> controls;
    int paddingLeft = 10;
    int paddingRight = 10;

    void apply(HWND parent, RECT clientRect) {
        int totalFixedHeight = 0;
        int expandableCount = 0;

        for (auto& c : controls) {
            totalFixedHeight += c.preferredHeight + c.margin * 2;
            if (c.expand) expandableCount++;
        }

        int available = (clientRect.bottom - clientRect.top);
        int extra = (expandableCount > 0) ? (available - totalFixedHeight) / expandableCount : 0;

        int y = clientRect.top;
        for (auto& c : controls) {
            int h = c.preferredHeight;
            if (c.expand && extra > 0) h += extra;

            MoveWindow(
                c.hwnd,
                clientRect.left + paddingLeft, 											// padding trái
                y + c.margin,
                (clientRect.right - clientRect.left) - (paddingLeft + paddingRight), 	// trừ padding phải
                h,
                TRUE
            );
            y += h + c.margin * 2;
        }
    }
};

// ---------------- Main Window ------------------

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    static VBoxLayout layout;
    static bool initialized = false;

    switch (msg) {
    case WM_CREATE: {
        HWND hLabel = CreateWindow("STATIC", "Username:", WS_CHILD | WS_VISIBLE,
            0, 0, 0, 0, hwnd, nullptr, nullptr, nullptr);
        HWND hEdit = CreateWindow("EDIT", "", WS_CHILD | WS_VISIBLE | WS_BORDER,
            0, 0, 0, 0, hwnd, nullptr, nullptr, nullptr);
        HWND hButton = CreateWindow("BUTTON", "Login", WS_CHILD | WS_VISIBLE,
            0, 0, 0, 0, hwnd, nullptr, nullptr, nullptr);

        layout.controls = {
            { hLabel, 24, false },
            { hEdit, 28, true },
            { hButton, 32, false },
        };

        initialized = true;
        return 0;
    }
    case WM_SIZE: {
        if (initialized) {
            RECT rc;
            GetClientRect(hwnd, &rc);
            layout.apply(hwnd, rc);
        }
        return 0;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
    const wchar_t CLASS_NAME[] = L"VBoxDemoWindow";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0, CLASS_NAME, L"VBox Layout Demo",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 250,
        nullptr, nullptr, hInstance, nullptr);

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
