#ifndef WRITETOSCREENBUFFER_H
#define WRITETOSCREENBUFFER_H

#include "ColaVendingMachineGui.h"
#include "Initialization.h"
#include "CoinHandelingProcedure.h"
#include "UserDrinkSelection.h"

void WTSB_StaticChar(wchar_t buffer, HWND handler);
void WTSB_StaticInt(int num, HWND handler);

#endif // !WRITETOSCREENBUFFER_H

