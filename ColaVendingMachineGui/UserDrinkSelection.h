#ifndef USERDRINKSELECTION_H
#define USERDRINKSELECTION_H

#define BUFF 128

#include "ColaVendingMachineGui.h"
#include "Initialization.h"
#include "CoinHandelingProcedure.h"
#include "WriteToScreenBuffer.h"

typedef struct {
	wchar_t drinkName[BUFF];
	int priceInEuros;
	int priceInCents;
}drink_t;

void UDS_Price(drink_t*, int, int);
void UDS_Drink(drink_t*, wchar_t whichDrink[]);
void UDS_Setup(int, drink_t*);


#endif // !USERDRINKSELECTION_H