#include <iostream>
#include <Windows.h>

using namespace std;
int t = 0;

void walk()
{
    t++;
    keybd_event(0x57, 0x39, NULL, NULL);
    Sleep(64);
    keybd_event(0x41, 0x39, NULL, NULL);
    Sleep(1500);
    keybd_event(0x41, 0x39, KEYEVENTF_KEYUP, NULL);
    Sleep(500);
    keybd_event(0x44, 0x39, NULL, NULL);
    Sleep(1500);
    keybd_event(0x44, 0x39, KEYEVENTF_KEYUP, NULL);
    Sleep(64);
    keybd_event(0x57, 0x39, KEYEVENTF_KEYUP, NULL);
    if (t % 4 == 0)
    {
        keybd_event(0x4B, 0x39, NULL, NULL);
        Sleep(32);
        keybd_event(0x4B, 0x39, KEYEVENTF_KEYUP, NULL);
        Sleep(700);
        Sleep(64);
        mouse_event(MOUSEEVENTF_MOVE, 120, -130, 0, 0);
        Sleep(64);
        keybd_event(0x10, 0x39, NULL, NULL);
        Sleep(64);
        mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        Sleep(64);
        keybd_event(0x10, 0x39, KEYEVENTF_KEYUP, NULL);
        Sleep(64);
        keybd_event(0x1B, 0x39, NULL, NULL);
        Sleep(32);
        keybd_event(0x1B, 0x39, KEYEVENTF_KEYUP, NULL);
    }
    if (t % 240 == 0)
    {
        keybd_event(0x4E, 0x39, NULL, NULL);
        Sleep(64);
        keybd_event(0x4E, 0x39, KEYEVENTF_KEYUP, NULL);
        Sleep(1000);
        mouse_event(MOUSEEVENTF_MOVE, -108, 273, 0, 0);
        Sleep(64);
        mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        Sleep(64);
        mouse_event(MOUSEEVENTF_MOVE, 35, 0, 0, 0);
        Sleep(64);
        keybd_event(0x10, 0x39, NULL, NULL);
        Sleep(128);
        mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        Sleep(64);
        mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        Sleep(128);
        keybd_event(0x10, 0x39, KEYEVENTF_KEYUP, NULL);
        Sleep(64);
        mouse_event(MOUSEEVENTF_MOVE, -35, 0, 0, 0);
        Sleep(64);
        mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        Sleep(64);
        keybd_event(0x1B, 0x39, NULL, NULL);
        Sleep(32);
        keybd_event(0x1B, 0x39, KEYEVENTF_KEYUP, NULL);
    }
}

int main()
{
    boolean isPressed = false;
    while (true)
    {
        if (GetAsyncKeyState(0x52))
        {
            isPressed = ~isPressed;
            Sleep(100);
        }

        if (isPressed)
        {
            walk();
            Sleep(100);
        }
    }
}