#include "WriteToDisplayBuffers.h"

void WTDB_Debug(wchar_t inFunction[], wchar_t withText[])
{
	wchar_t formatedbuffer[BUFFSIZE], buffTemp[DEBUGBUFFER];
	int lengthDebugBuff = 0;
	static int debugListCounter = 0;

	wsprintf(formatedbuffer, L"[%d] %s: %s\r\n", debugListCounter++, inFunction, withText);

	lengthDebugBuff = GetWindowTextLength(H_Change_Debug) + lstrlen(formatedbuffer) + 1;
	GetWindowText(H_Change_Debug, buffTemp, lengthDebugBuff);
	wcscat_s(buffTemp, lengthDebugBuff, formatedbuffer);
	SetWindowTextW(H_Change_Debug, buffTemp);
}

void ATDB_Remove()
{

}

void WTDB_Display(wchar_t MenuDisplayBuffer[])
{
		wchar_t bufferEdited[BUFFSIZE];

		wsprintf(bufferEdited, L"%s", MenuDisplayBuffer);
		SetWindowText(H_Change_Display, bufferEdited);
}