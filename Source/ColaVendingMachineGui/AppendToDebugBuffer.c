#include "AppendToDebugBuffer.h"

void ATDB_Write(wchar_t inFunction[], wchar_t withText[])
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
