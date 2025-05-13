#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

#ifndef _AFXDLL
#define _AFXDLL
#endif

#include "afxwin.h"
#include "windows.h"
#include "vfw.h"
#include "mciapi.h"
#include "mmsystem.h"
#include <afxdlgs.h>
#include <atlstr.h>
#include <tchar.h>
#include <fstream>
#include <cctype>
#include <string.h>
#include <string>
#pragma comment (lib, "winmm")
#pragma comment (lib, "vfw32")
#pragma comment (lib, "Kernel32")

#include <iostream>
using namespace std;

#define BUFFER_MAX_SIZE 32767

enum COMMAND { OPEN = 0, PLAY = 1, PAUSE = 2, RESUME = 3, REPLAY = 4, STOP = 5, CLOSE = 6, SHOWINFO = 7 };

string Uppercase(string);
void PrintUnicodeString(CString);
int OpenMusicFile(CString&, CString&);
void PrintFileName(CString);
UINT PlayThread(LPVOID);
void PlayMusic();
void Pause();
void Resume();
void Stop();
void ReplayBack();
void Close();
void DisplayHelp();
void Exit();

BOOL isOpening = FALSE, isPlaying = FALSE, isPausing = FALSE, isStopped = FALSE, isClosed = FALSE;
CWinThread *pMusicThread = NULL; UINT nMessage = 0;
CString strFilter = L"", strFileName = L"", strFilePath = L"";

// Convert a string to upper
string Uppercase(string strSource)
{
	string strResult;
	int length = strSource.length();
	for (int i = 0; i < length; i++)
		strResult.push_back(toupper((strSource.c_str())[i]));
	return strResult;
}

// Print an unicode string on console window
void PrintUnicodeString(CString strBuffer)
{
	DWORD number = 0;
	WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), strBuffer.GetBuffer(BUFFER_MAX_SIZE), (DWORD)strBuffer.GetLength(), &number, NULL);
}

// Open music file
int OpenMusicFile(CString &strFilePath, CString &strFileName)
{
	if (isOpening)
	{
		cout << "There is a music file opened. You must close it first." << endl << endl;
		return 1;
	}

	// CWnd* pWnd = CWnd::FromHandle(GetConsoleWindow());
	CFileDialog fileDlg(TRUE, L"*.mp3", L"*.mp3", NULL, strFilter, NULL);
	fileDlg.m_ofn.Flags |= OFN_FILEMUSTEXIST;
	fileDlg.m_ofn.lpstrTitle = L"Open Music File";
	if (fileDlg.DoModal() == IDOK)
	{
		strFilePath = fileDlg.GetPathName();
		strFileName = fileDlg.GetFileName();

		CString strCmd;
		strCmd.Format(L"open \"%s\" type mpegvideo alias mp3", strFilePath);
		mciSendString(strCmd.GetBuffer(BUFFER_MAX_SIZE), NULL, 0, NULL);

		cout << "File \'";
		PrintFileName(strFileName);
		cout << "\' is now being opened." << endl << endl;

		isOpening = TRUE; isClosed = FALSE;
		return 0;
	}
	return 1;
}

// Print file name - as same as PrintUnicodeString function
void PrintFileName(CString filename)
{
	// wcout << "Playing music: ";
	DWORD number = 0;
	WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), filename.GetBuffer(BUFFER_MAX_SIZE), (DWORD)filename.GetLength(), &number, NULL);
}

// Definition the playing thread
UINT PlayThread(LPVOID lpvoidParam)
{
	mciSendString(L"play mp3 wait", NULL, 0, NULL);
	//LPUINT uiMsg = (LPUINT)lpvoidParam;
	//if (uiMsg == NULL)
	//	return 1;
	//UINT uiRes = *uiMsg;
	//switch (uiRes)
	//{
	//case PLAY:
	//	break;
	//case PAUSE:
	//	mciSendString(L"pause mp3", NULL, 0, NULL);
	//	break;
	//case RESUME:
	//	mciSendString(L"resume mp3", NULL, 0, NULL);
	//	break;
	//case REPLAY:
	//	mciSendString(L"play mp3 from 0", NULL, 0, NULL);
	//	break;
	//case STOP:
	//	mciSendString(L"stop mp3", NULL, 0, NULL);
	//	break;
	//case CLOSE:
	//	mciSendString(L"close mp3", NULL, 0, NULL);
	//	break;
	//}
	return 0;
}

// Play music - using command: PLAY
void PlayMusic()
{
	//if (!isOpening)
	//{
	//	cout << "There isn't any music file opened. You can not play music now." << endl << endl;
	//	return;
	//}
	//else if (isPlaying)
	//{
	//	cout << "The music file is being played." << endl << endl;
	//	return;
	//}

//	nMessage = PLAY;
	AfxBeginThread(PlayThread, &nMessage);

	cout << "File \'";
	PrintFileName(strFileName);
	cout << "\' is now being played." << endl << endl;
//	isPlaying = TRUE; isPausing = FALSE; isStopped = FALSE;
}

// Pause the current music - using command: PAUSE
void Pause()
{
	if (!isPlaying)
	{
		cout << "There isn't any music file played. You can not pause music now." << endl << endl;
		return;
	}
	else if (isPausing)
	{
		cout << "The music is being paused. This command is invalid." << endl << endl;
		return;
	}

	nMessage = PAUSE;
	AfxBeginThread(PlayThread, &nMessage);

	cout << "File \'";
	PrintFileName(strFileName);
	cout << "\' is now being paused." << endl << endl;
	isPausing = TRUE; isPlaying = FALSE; isStopped = FALSE;
}

// Resume the now-pausing music - using command: RESUME
void Resume()
{
	if (!isPausing && isPlaying)
	{
		cout << "The music file is now playing. This command is invalid." << endl << endl;
		return;
	}
	mciSendString(L"resume mp3", NULL, 0, NULL);
	cout << "File \'";
	PrintFileName(strFileName);
	cout << "\' is now resuming." << endl << endl;
	isPlaying = TRUE; isPausing = FALSE; isStopped = FALSE;
}

// Stop the now-playing music - using command: STOP
void Stop()
{
	if (isStopped)
	{
		cout << "The music file was stopped. This command is invalid." << endl << endl;
		return;
	}
	mciSendString(L"stop mp3", NULL, 0, NULL);
	cout << "File \'";
	PrintFileName(strFileName);
	cout << "\' is now being stopped." << endl << endl;
	isPlaying = FALSE; isPausing = FALSE; isStopped = TRUE;
}

// Replay current song - using command: REPLAY
void ReplayBack()
{
	mciSendString(L"play mp3 from 0", NULL, 0, NULL);
	cout << "File \'";
	PrintFileName(strFileName);
	cout << "\' is now being replayed." << endl << endl;
	isPlaying = TRUE; isPausing = FALSE; isStopped = FALSE;
}

// Close current song - using command: CLOSE
void Close()
{
	mciSendString(L"close mp3", NULL, 0, NULL);
	cout << "File \'";
	PrintFileName(strFileName);
	cout << "\' is now being closed." << endl << endl;
	isClosed = TRUE; isOpening = FALSE;
}

// Display commands list - using command: HELP
void DisplayHelp()
{

}

// Exit console music player - using command: EXIT
void Exit()
{
	HWND hWnd = GetConsoleWindow();
	while (TRUE)
	{
		CString strMsg = L"Bạn có chắc chắn muốn thoát?";
		if (MessageBox(hWnd, strMsg, L"Thoát chương trình", MB_YESNO | MB_ICONQUESTION) == IDNO)
			return;
		strMsg = L"Bấm thiệt à? Chắc chắn chứ?";
		if (MessageBox(hWnd, strMsg, L"Thoát chương trình", MB_YESNO | MB_ICONQUESTION) == IDNO)
			return;
		strMsg = L"Hỏi thế mà vẫn bấm à? Liều vậy? Vẫn muốn thoát?";
		if (MessageBox(hWnd, strMsg, L"Thoát chương trình", MB_YESNO | MB_ICONQUESTION) == IDNO)
			return;
		strMsg = L"Lì vler. Hỏi nhiều vậy thì phải biết là không thoát được đi chứ. Tự trọng tí đi. OK?";
		MessageBox(hWnd, strMsg, L"Thoát chương trình", MB_YESNO | MB_ICONQUESTION);
		strMsg = L"Sao thế? Không muốn thoát nữa à? Thoát đi?";
		if (MessageBox(hWnd, strMsg, L"Thoát chương trình", MB_YESNO | MB_ICONQUESTION) == IDNO)
			return;
	}
}

// Main entry-point
void sound_main()
{
	// Initializing media player console window
	DWORD dwComputerNameSize = BUFFER_MAX_SIZE;
	TCHAR strComputerName[BUFFER_MAX_SIZE];
	strFilter = L"Music Files (*.mp3) |*.mp3|All Files (*.*)|*.*|";
	SetConsoleTitle(L"Console Music Player"); // Set console window title
	cout << "Console Music Player version 1.0.3\n\nCopyright (c) 2017 Stark Lee. All rights reserved." << endl << "On computer: ";
	GetComputerName(strComputerName, &dwComputerNameSize);
	PrintUnicodeString(strComputerName);
	cout << endl << endl;

	// Processing command-line
	string strCommand;
	while (TRUE)
	{
		cout << "PLAYER> ";
		getline(cin, strCommand);
		strCommand = Uppercase(strCommand);
		if (strCommand == "OPEN")
			OpenMusicFile(strFilePath, strFileName);
		else if (strCommand == "PLAY")
			PlaySoundW(strFilePath, 0, SND_FILENAME | SND_ASYNC | SND_MEMORY);
//			mciSendString(L"play mp3 wait", NULL, NULL, NULL);
		else if (strCommand == "PAUSE")
			Pause();
		else if (strCommand == "RESUME")
			Resume();
		else if (strCommand == "STOP")
			Stop();
		else if (strCommand == "REPLAY")
			ReplayBack();
		else if (strCommand == "HELP")
			DisplayHelp();
		else if (strCommand == "CLOSE")
			Close();
		else if (strCommand == "EXIT")
			Exit();
		else if (strCommand == "")
			continue;
		else
			cout << "\'" << strCommand << "\' is not recognized as an internal or external command. Type \'HELP\' for more information." << endl << endl;
	}
}