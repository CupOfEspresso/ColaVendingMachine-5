#ifndef WRITETOSCREENBUFFER_H
#define WRITETOSCREENBUFFER_H

#include <Windows.h>

#include "ColaVendingMachineGui.h"
#include "Initialization.h"
#include "CoinHandelingProcedure.h"
#include "UserDrinkSelection.h"

void WTSB_StaticChar(wchar_t buffer, HWND handler);
void WTSB_StaticCashCents(sim_t*);
void WTSB_StaticCashEuros(sim_t*);
void WTSB_StaticChangeCents(sim_t*);
void WTSB_StaticChangeEuros(sim_t*);
void WTSB_StaticWalletCents(sim_t*);
void WTSB_StaticWalletEuros(sim_t*);

#endif // !WRITETOSCREENBUFFER_H

