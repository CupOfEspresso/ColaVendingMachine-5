#ifndef COINHANDELINGPROCEDURE_H
#define COINHANDELINGPROCEDURE_H

#include "ColaVendingMachineGui.h"
#include "Initialization.h"
#include "UserDrinkSelection.h"
#include "WriteToScreenBuffer.h"


void CHP_CheckIfEnough(sim_t* pSim, int, HWND);
void CHP_CheckCoins(sim_t* pSim, int);
void CHP_EurosToCents(sim_t* pSim);
void CHP_CentsToEuros(sim_t* pSim);
void CHP_CalculatorEuros(sim_t* pSim, int);
void CHP_CalculatorCents(sim_t* pSim, int);

#endif // !COINHANDELINGPROCEDURE

