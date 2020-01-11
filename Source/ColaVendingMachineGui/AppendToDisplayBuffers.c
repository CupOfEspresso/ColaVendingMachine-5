#include "AppendToDisplayBuffers.h"

void ATDB_Debug(wchar_t inFunction[], wchar_t withText[])
{
	wchar_t formatedbuffer[SIZE], buffTemp[BIGSIZE];
	int lengthDebugBuff = 0;

	wsprintf(formatedbuffer, L"DEBUG in %s: %s\r\n", inFunction, withText);

	lengthDebugBuff = GetWindowTextLength(H_Change_Debug) + lstrlen(formatedbuffer) + 1;
	GetWindowText(H_Change_Debug, buffTemp, lengthDebugBuff);
	wcscat_s(buffTemp, lengthDebugBuff, formatedbuffer);
	SetWindowTextW(H_Change_Debug, buffTemp);
}
void ATDB_Read()
{

}
void ATDB_Remove()
{

}

void ATDB_Display(wchar_t MenuDisplayBuffer[])
{

		wchar_t bufferEdited[BUFFSIZE];

		wsprintf(bufferEdited, L"%s", MenuDisplayBuffer);
		SetWindowText(H_Change_Display, bufferEdited);
}
