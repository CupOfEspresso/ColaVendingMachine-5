#ifndef WRITETOSCREENBUFFER_H
#define WRITETOSCREENBUFFER_H

#include <Windows.h>

#include "ColaVendingMachineGui.h"
#include "Initialization.h"
#include "CoinHandelingProcedure.h"
#include "UserDrinkSelection.h"
#include "WriteToDisplayBuffers.h"

void WTSB_StaticInMachine(sim_t*);
void WTSB_StaticChange(sim_t*);
void WTSB_StaticAccount(sim_t*);
void WTSB_StaticWallet(sim_t*);
void WTSB_Redraw(sim_t*);

#endif // !WRITETOSCREENBUFFER_H

