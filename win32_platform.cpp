#include <windows.h>

bool running = true;

LRESULT CALLBACK window_callback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;
	switch (uMsg)
	{
	case WM_CLOSE:
	case WM_DESTROY:
	{
		running = false;
	} break;
	default:
		result = DefWindowProc(hwnd, uMsg, wParam, lParam);
		break;
	}
	return result;
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	WNDCLASS window_class = {};
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	window_class.lpszClassName =  L"PONG!";
	window_class.lpfnWndProc = window_callback;

	RegisterClass(&window_class);

	HWND window = CreateWindow(window_class.lpszClassName, L"PONG!", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, 0, 0, hInstance, 0);

	while (running)
	{
		MSG message;
		while (PeekMessage(&message, window, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
	}
}