#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <thread>
#include <chrono>

using namespace std;


void HideWindow() {
    HWND hwnd = GetForegroundWindow();	//获取程序启动时的窗口
    if (hwnd) {
        ShowWindow(hwnd, SW_HIDE);				//设置指定窗口的显示状态
    }
}

// Get current date/time
int currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80],cuf[80];
    int c=0, b=0;
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%I", &tstruct);
    strftime(cuf, sizeof(cuf), "%M", &tstruct);
    for (int i = 0; i < strlen(buf); i++)
    {
        b = b * 10 + (int(buf[i]) - 48);
    }
    for (int i = 0; i < strlen(cuf); i++)
    {
        c = c * 10 + (int(cuf[i]) - 48);
    }
    return b*60+c;
}

int main() {
//    std::cout << currentDateTime() /60<<":"<< currentDateTime()%60 << std::endl;
//    getchar();  // wait for keyboard input
    int h, m, sum;
    cin >> h >> m;
    HideWindow();
    sum = h * 60 + m;
    while (true)
    {
        if (currentDateTime() >= sum) break;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    system("run.bat");
    return 0;
}
