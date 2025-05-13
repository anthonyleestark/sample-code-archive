#pragma once
#ifndef TPP_LANGUAGE_INCLUDED
#define TPP_LANGUAGE_INCLUDED

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include "windows.h"
using namespace std;

// Define keywords
#define Load_Standard_Kernel
#define Load_Library #include
#define Define #define
#define Start_Program {
#define No_Type void
#define Main_Entrypoint main()
#define Return return
#define Begin	{
#define End		}
#define End_Program }
#define If if
#define Else else
#define Repeat do
#define While while
#define For(init, condition, expression) for(init; condition; expression)
#define Switch switch
#define Case case
#define Default default
#define Break break
#define Skip continue
#define Const const


// Define data types
#define INT int
#define UINT unsigned int
#define SHORT short
#define LONG long
#define ULONG unsigned long
#define CHAR char
#define TCHAR wchar_t
#define FLOAT float
#define DOUBLE double
#define SUPER_LONG long long
#define BOOL bool
#define STRING string
#define STRUCT struct
#define ENUM enum
#define UNION union
#define NOTYPE void
#define Define_Type typedef
#define AUTO auto
#define Template template
#define Static static

// Define operators
#define Out <<
#define With <<
#define Into >>
#define div /
#define mod %


// Define some standard functions
#define Write cout
#define Endline endl
#define Read cin
#define Pause { system("pause"); }
#define ClearScreen { system("cls"); }

#endif
