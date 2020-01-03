#ifndef COINHANDELINGPROCEDURE_H
#define COINHANDELINGPROCEDURE_H

#include "ColaVendingMachineGui.h"
#include "Initialization.h"
#include "UserDrinkSelection.h"
#include "WriteToScreenBuffer.h"


void CHP_CheckIfEnough(sim_t* pSim, int);
void CHP_CheckCoins(sim_t* pSim, int);
sim_t* CHP_EurosToCents(sim_t* pSim, int);
sim_t* CHP_CentsToEuros(sim_t* pSim, int);

#endif // !COINHANDELINGPROCEDURE

