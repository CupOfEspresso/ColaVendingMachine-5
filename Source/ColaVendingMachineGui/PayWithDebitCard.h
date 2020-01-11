#ifndef PAYWITHDEBITCARD_H
#define PAYWITHDEBITCARD_H

#include "Initialization.h"
#include "CoinHandelingProcedure.h"
#include "ColaVendingMachineGui.h"
#include "UserDrinkSelection.h"
#include "WriteToScreenBuffer.h"

PWDC_DebitcardHandeling(sim_t* pSim);
PWDC_AddPincodeBuffer(sim_t* pSim, int pinNumber);
PWDC_RemovePincodeBuffer(sim_t* pSim);
PWDC_CheckPincode(sim_t* pSim);

#endif // !PAYWITHDEBITCARD_H



