#ifndef USERDRINKSELECTION_H
#define USERDRINKSELECTION_H

#define BUFF 15

#include "ColaVendingMachineGui.h"
#include "Initialization.h"
#include "CoinHandelingProcedure.h"
#include "WriteToScreenBuffer.h"

typedef struct {
	wchar_t drinkName[BUFF];
	int priceInEuros;
	int priceInCents;
}drink_t;

drink_t UDS_Price(drink_t, int, int);
drink_t UDS_Drink(drink_t, wchar_t whichDrink[]);
drink_t UDS_Setup(int);


#endif // !USERDRINKSELECTION_H