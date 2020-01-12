#include "WriteToDisplayBuffers.h"

void WTDB_Debug(wchar_t inFunction[], wchar_t withText[])
{
	/// Write to the Debug section in the program. Does this by copying the old buffer and adding the new lines to that buffer and writing it back
	wchar_t formatedbuffer[BUFFSIZE], buffTemp[DEBUGBUFFER];
	int lengthDebugBuff = 0;
	static int debugListCounter = 0;

	wsprintf(formatedbuffer, L"[%d] %s: %s\r\n", debugListCounter++, inFunction, withText);

	lengthDebugBuff = GetWindowTextLength(H_Change_Debug) + lstrlen(formatedbuffer) + 1;
	GetWindowText(H_Change_Debug, buffTemp, lengthDebugBuff);
	wcscat_s(buffTemp, lengthDebugBuff, formatedbuffer);
	SetWindowTextW(H_Change_Debug, buffTemp);
}

void WTDB_Display(wchar_t MenuDisplayBuffer[])
{
	/// Write to display buffer of the machine for promping the user
	wchar_t bufferEdited[BUFFSIZE];

	wsprintf(bufferEdited, L"%s", MenuDisplayBuffer);
	SetWindowText(H_Change_Display, bufferEdited);
}