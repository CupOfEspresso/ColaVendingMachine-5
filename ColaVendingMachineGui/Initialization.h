#ifndef INITIALIZATION_H
#define INITIALIZATION_H
#include <time.h>
#include <stdlib.h>

typedef struct sim_t{
	int moneyInWalletCents;
	int moneyInWalletEuros;
	int changeInMachineCents;
	int changeInMachineEuros;
	int moneyInMachineCents;
	int moneyInMachineEuros;
} sim_t;

#include "ColaVendingMachineGui.h"
#include "CoinHandelingProcedure.h"
#include "UserDrinkSelection.h"
#include "WriteToScreenBuffer.h"

int INIT_Button(HWND);
int INIT_Static(HWND);
int INIT_Menu(HWND);
int INIT_Edit(HWND);
sim_t* INIT_Simulations(HWND);



#endif // !INITIALIZATION_H

