#ifndef APPENDTODEBUGBUFFER
#define APPENDTODEBUGBUFFER

#include "Initialization.h"
#include "CoinHandelingProcedure.h"
#include "ColaVendingMachineGui.h"
#include "UserDrinkSelection.h"
#include "WriteToScreenBuffer.h"
#include "PayWithDebitCard.h"

#define SIZE 1000
#define BIGSIZE 100000

void ATDB_Write(wchar_t[], wchar_t[]);
void ATDB_Read();
void ATDB_Remove();

#endif // !APPENDTODEBUGBUFFER

