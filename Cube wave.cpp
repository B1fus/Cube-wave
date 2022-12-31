// Physics dots.cpp : Определяет точку входа для приложения.
//
#pragma warning(disable : 4996)

#include "framework.h"
#include "Globals.h"
#include "Resource.h"
#include "World scene.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);


World_scene world;
Object a;
Canvas canvas(SCREEN_WIDTH,SCREEN_HEIGHT);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.
    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);


    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CUBEWAVE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CUBEWAVE));

    MSG msg;

    //Mat2<int> a(4, 5);
    ////Mat2<int> b(3, 5);
    //Mat2<int> b(5, 3);

    //a.set_element(0, 2, 12);
    //b.set_element(0, 2, 12);
    //for (int i = 0; i < 10; i++) {
    //    a.set_element(rand() % 4, rand() % 5, rand() % 5);
    //    //b.set_element(rand() % 3, rand() % 5, rand() % 5);
    //    b.set_element(rand() % 5, rand() % 3, rand() % 5);
    //}

    //a.print_in_debug(L"\t%5d ");
    //b.print_in_debug(L"\t%5d ");
    //(a * b).print_in_debug(L"\t%5d ");
    //int arr[] = {1,2,
    //            3,4,
    //            1,2};
    //Mat2<int> c(3, 2, arr);
    //(c).print_in_debug(L"\t%5d ");
    //Vec2<int> df(1,3);
    //df.print_in_debug(L"%d ");

    a.set_vertices(std::vector<Vec3<float>> {
        {1, 1, 1},
        { -1, 1, 1 },
        { -1, -1, 1 },
        { 1, -1, 1 },
        { 1, 1, -1 },
        { -1, 1, -1 },
        { -1, -1, -1 },
        { 1, -1, -1 }
    });
    a.set_polygons(std::vector<int> {
        0, 1, 2,
            0, 2, 3,
            0, 3, 7,
            0, 7, 4,
            0, 5, 1,
            0, 4, 5,
            6, 5, 4,
            6, 4, 7,
            6, 3, 2,
            6, 7, 3,
            6, 1, 5,
            6, 2, 1
    });
    a.set_colors(std::vector<Gdiplus::Color>{
        {80, 230, 90},
        { 80, 230, 90 },
        { 180, 230, 90 },
        { 180, 230, 90 },
        { 80, 230, 190 },
        { 80, 230, 190 },
        { 180, 230, 190 },
        { 180, 230, 190 },
        { 80, 30, 90 },
        { 80, 30, 90 },
        { 80, 30, 190 },
        { 80, 30, 190 }
    });

    a.scale = { 100,100,100 };
    a.rotation = { 45,45,45 };

    world.add_object(a);
    a.rotation = { 0,45,45 };
    a.position = { 100,0,0 };
    world.add_object(a);
    a.position = { -200,0,0 };
    world.add_object(a);

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    Gdiplus::GdiplusShutdown(gdiplusToken);
    return (int)msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDC_CUBEWAVE));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_CUBEWAVE);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        0, 0, SCREEN_WIDTH + 16, SCREEN_HEIGHT + 59, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static bool hasFocus = 1;
    static int win_width, win_height;
    static PAINTSTRUCT ps;
    static HDC hdc = BeginPaint(hWnd, &ps);
    static HDC Memhdc = CreateCompatibleDC(hdc);
    static HBITMAP Membitmap;
    static RECT Client_Rect;
    static Gdiplus::SolidBrush whiteBrush(Gdiplus::Color(255, 255, 255));
    static Gdiplus::SolidBrush redBrush(Gdiplus::Color(255, 0, 0));
    static Gdiplus::FontFamily  fontFamily(L"Times New Roman");
    static Gdiplus::Font font(&fontFamily, 12);
    static Gdiplus::Pen greenPen(Gdiplus::Color(0, 255, 0), 2.);
    static std::chrono::steady_clock::time_point start_time;


    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Разобрать выбор в меню:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_ERASEBKGND:
        return TRUE;
    case WM_KEYDOWN:
    case WM_KEYUP:
    case WM_SYSKEYDOWN:
    case WM_SYSKEYUP: {
        if (hasFocus) {
            static bool keyIsDown, keyWasDown;
            keyIsDown = ((lParam & (1 << 31)) == 0);
            keyWasDown = ((lParam & (1 << 30)) != 0);
            if (keyIsDown != keyWasDown) {
                if (wParam == VK_ESCAPE) {
                    PostQuitMessage(1);
                }
            }
        }
        break;
    }
    case WM_PAINT:
    {
        //wchar_t buffer[200];
        //swprintf(buffer, 200, L"%d %d %d\n", wParam, wParam & (1 << 30), mouse.wheel);
        //OutputDebugString(buffer);

        GetClientRect(hWnd, &Client_Rect);
        win_width = Client_Rect.right - Client_Rect.left;
        win_height = Client_Rect.bottom + Client_Rect.left;
        hdc = BeginPaint(hWnd, &ps);
        Memhdc = CreateCompatibleDC(hdc);
        Membitmap = CreateCompatibleBitmap(hdc, win_width, win_height);
        SelectObject(Memhdc, Membitmap);
        //drawing code goes in here
        start_time = std::chrono::steady_clock::now();
        //static int* img = new int[win_height*win_width];
        //for (int i = 0; i < win_height*win_width; i++) {
        //    if (i > 1000 && i < 100000) {
        //        img[i] = 0xffffff;
        //    }
        //    else {
        //        img[i] = 0;
        //    }
        //}
        
        static float df = 0;
        df += 0.5;

        canvas.draw_line(10-df, 500, 1100, 100-df);
        SetBitmapBits(Membitmap, win_width * win_height * sizeof(canvas.get_bitMap()[0]), canvas.get_bitMap());


        Gdiplus::Graphics gr(Memhdc);
        //gr.FillRectangle(&whiteBrush, 0, 0, win_width, win_height); //clear window

        world.set_gdiGraphics(&gr);

        if (world.get_count_objects() > 1) {
            world.edit_object(0).rotation = { 10,30,40 + df };
            world.edit_object(1).rotation = { 10,30 + df,40 };
        }

        world.update_world();
        world.draw_objects();

        //static float df = 0;
        //df += FPS * DELTA_TIME * 1;
        //a.scale = { 100,100,100 };
        //a.position = { 0 ,0,0 };
        //a.rotation = { a.rotation.x, df, df};
        //a.rotation.x += float(rand() % 180 - 90)/100;
        //a.rotation.y += float(rand() % 180 - 90)/10;
        //a.rotation.z += float(rand() % 180 - 90)/100;
        //a.update_mat_transform();
        //a.draw_vertices(gr);
        //a.draw_polygons(gr);
        //a.draw_edges(gr);
        //a.draw_vertices(gr);

        //GetBitmapBits(Membitmap, 4 * win_height * win_width, img);
        //img[mouse.coords.y*win_width+mouse.coords.x] = 0xff0000;
        //light.get_mat_height(img);

        //SetBitmapBits(Membitmap, sizeof(img[0]) * SCREEN_WIDTH * SCREEN_HEIGHT, img);
        //output to debug panel
        //wchar_t buffer[200];
        //swprintf(buffer, 200, L"22222 %d", 10);
        //OutputDebugString(buffer);

        DELTA_TIME = std::chrono::duration<double>(std::chrono::steady_clock::now() - start_time).count();
        //Sleep(500); if(DELTA_TIME>500) DELTA_TIME -= 500;
        REAL_FPS = 1 / DELTA_TIME;

        gr.DrawString((wchar_t*)std::to_wstring(REAL_FPS).c_str(), 5, &font, Gdiplus::PointF(0, 0), &redBrush);
        BitBlt(hdc, 0, 0, win_width, win_height, Memhdc, 0, 0, SRCCOPY);
        DeleteObject(Membitmap);
        DeleteDC(Memhdc);
        DeleteDC(hdc);
        EndPaint(hWnd, &ps);
        InvalidateRect(hWnd, NULL, false);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);

        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
