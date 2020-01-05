#ifndef PAYWITHDEBITCARD_H
#define PAYWITHDEBITCARD_H

#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "Initialization.h"
#include "CoinHandelingProcedure.h"
#include "ColaVendingMachineGui.h"
#include "UserDrinkSelection.h"
#include "WriteToScreenBuffer.h"

PWDC_EnterAndRemoveDebitCard(sim_t* pSim);
PWDC_AddToDebitCardCodeBuffer(sim_t* pSim, int pinNumber);
PWDC_RemoveFromDebitCardCodeBuffer(sim_t* pSim);
PWDC_CheckDebitCardCode(sim_t* pSim);

#endif // !PAYWITHDEBITCARD_H



