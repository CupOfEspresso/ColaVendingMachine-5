#ifndef USERDRINKSELECTION_H
#define USERDRINKSELECTION_H

#include "ColaVendingMachineGui.h"
#include "Initialization.h"
#include "CoinHandelingProcedure.h"
#include "WriteToScreenBuffer.h"
#include "WriteToDisplayBuffers.h"

typedef struct {
	wchar_t drinkName[BUFFSIZE];
	int priceTotaalCents;
}drink_t;

void UDS_Setup(int, drink_t*);

#endif // !USERDRINKSELECTION_H