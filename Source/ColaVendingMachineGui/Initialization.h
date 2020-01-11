#ifndef INITIALIZATION_H
#define INITIALIZATION_H

typedef struct sim_t
{
	int moneyInWallet;
	int moneyInAccount;
	int changeInMachine;
	int moneyInMachine;
	int isDebitCardEntered;
	int postionInCardCode;
	int hasPaid;
	int debitCardCode[4];
	int POINTOFCONCEPTPASSWORD[4];
} sim_t;

typedef const struct valuta_t
{
	const int V_1_CENT;
	const int V_2_CENT;
	const int V_5_CENT;
	const int V_10_CENT;
	const int V_20_CENT;
	const int V_50_CENT;
	const int V_1_EURO;
	const int V_2_EURO;
	const int V_5_EURO;
	const int V_10_EURO;
	const int V_20_EURO;
	const int V_50_EURO;
} valuta_t;

#include "ColaVendingMachineGui.h"
#include "CoinHandelingProcedure.h"
#include "UserDrinkSelection.h"
#include "WriteToScreenBuffer.h"
#include "WriteToDisplayBuffers.h"

int INIT_Button(HWND);
int INIT_Static(HWND, sim_t*);
int INIT_Menu(HWND);
int INIT_Edit(HWND);

#endif // !INITIALIZATION_H

