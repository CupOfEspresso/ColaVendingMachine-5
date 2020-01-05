#ifndef INITIALIZATION_H
#define INITIALIZATION_H

typedef struct sim_t{
	int moneyInWalletCents;
	int moneyInWalletEuros;
	int changeInMachineCents;
	int changeInMachineEuros;
	int moneyInMachineCents;
	int moneyInMachineEuros;
	int isDebitCardEntered;
	int postionInCardCode;
	int debitCardCode[4];
	int POINTOFCONCEPTPASSWORD[4];
	int hasPaid;
} sim_t;

#include "ColaVendingMachineGui.h"
#include "CoinHandelingProcedure.h"
#include "UserDrinkSelection.h"
#include "WriteToScreenBuffer.h"

int INIT_Button(HWND);
int INIT_Static(HWND, sim_t*);
int INIT_Menu(HWND);
int INIT_Edit(HWND);



#endif // !INITIALIZATION_H

