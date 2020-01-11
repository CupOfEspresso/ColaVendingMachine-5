#ifndef COINHANDELINGPROCEDURE_H
#define COINHANDELINGPROCEDURE_H

#include "ColaVendingMachineGui.h"
#include "Initialization.h"
#include "UserDrinkSelection.h"
#include "WriteToScreenBuffer.h"
#include "WriteToDisplayBuffers.h"

void CHP_CheckIfEnough(sim_t* pSim, int, HWND);
void CHP_CheckCoins(sim_t* pSim, int);
void CHP_CalculateValueOfCoin(sim_t* pSim, int);

#endif // !COINHANDELINGPROCEDURE

