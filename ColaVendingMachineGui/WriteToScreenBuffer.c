#include "WriteToScreenBuffer.h"
#include "ColaVendingMachineGui.h"

void WTSB_StaticChar(wchar_t buffer, HWND handler)
{
	wchar_t bufferEdited[BUFFSIZE];

	wsprintfW(bufferEdited, L"DEBUG: %s", buffer);
	SetWindowTextW(handler, bufferEdited);
}

void WTSB_StaticInt(int num, HWND handler)
{
	wchar_t bufferEdited[BUFFSIZE];

	wsprintfW(bufferEdited, L"%d", num);
	SetWindowTextW(handler, bufferEdited);
}
