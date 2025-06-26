// Cái này viết lâu rồi
// Chưa test lại nên ko biết còn dùng đc ko

#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

#define STRICT
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN

#include <string>
#include "windows.h"

using namespace std; 

// Xuất chuỗi Unicode
void PrintUnicodeString(CString strBuffer)
{
	DWORD number = 0;
	WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), strBuffer.GetBuffer(BUFFER_MAX_SIZE), (DWORD)strBuffer.GetLength(), &number, NULL);
}

// Nhập chuỗi Unicode
wstring ReadUnicodeString()
{
        const HANDLE stdIn = GetStdHandle(STD_INPUT_HANDLE);
        WCHAR buffer[0x1000];
        DWORD numRead = 0;
        ReadConsoleW(stdIn, buffer, sizeof buffer, &numRead, NULL);
        wstring result(buffer, numRead - 2); // hoặc numRead
        return wstring;
}


/// Usage:

// Xuất
PrintUnicodeString("Xin chào các bạn\n");

// Nhập
wstring str = ReadUnicodeString();