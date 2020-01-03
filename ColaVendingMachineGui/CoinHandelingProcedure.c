
#include "CoinHandelingProcedure.h"

void CHP_CheckIfEnough(sim_t* pSim, int whichDrink)
{
	wchar_t bufferEdited[BUFFSIZE];
	drink_t drinks = UDS_Setup(whichDrink);

	if ((drinks.priceInEuros < pSim->moneyInMachineEuros) ||
		(drinks.priceInEuros == pSim->moneyInMachineEuros &&
			drinks.priceInCents == pSim->moneyInMachineCents))
	{
		pSim->moneyInMachineEuros -= drinks.priceInEuros;
		pSim->moneyInMachineCents -= drinks.priceInCents;

		wsprintfW(bufferEdited, L"Enjoy you %s", drinks.drinkName);

		MessageBoxW(NULL, bufferEdited, L"DISPENSE", MB_OK);
	}
	else
	{
		wsprintfW(bufferEdited, L"Sorry, your %s is \uac20%d,%d you have only inserted \uac20%d,%d",
			drinks.drinkName, drinks.priceInEuros, drinks.priceInCents, pSim->moneyInMachineEuros, pSim->moneyInMachineCents);
		MessageBoxW(NULL, bufferEdited, L"DISPENSE", MB_OK);
	}
}

void CHP_CheckCoins(sim_t* pSim, int coinSize)
{
	if (pSim->moneyInWalletEuros != 0 && pSim->moneyInWalletCents != 0)
	{
		if (coinSize >= 100) {
			pSim = CHP_CentsToEuros(pSim, coinSize);
			WTSB_StaticInt(pSim->changeInMachineEuros, H_Change_Cash_Euros);
			WTSB_StaticInt(pSim->changeInMachineCents, H_Change_Cash_Cents);
		}
		else
		{
			pSim->moneyInMachineCents += coinSize;
			WTSB_StaticInt(pSim->changeInMachineEuros, H_Change_Cash_Euros);
			WTSB_StaticInt(pSim->changeInMachineCents, H_Change_Cash_Cents);
		}
	}
}

sim_t* CHP_EurosToCents(sim_t* pSim, int coinSize)
{
	while (pSim->moneyInMachineEuros != 0)
	{
		pSim->moneyInMachineEuros--;
		pSim->moneyInMachineCents += 100;
	}
	return pSim;
}

sim_t* CHP_CentsToEuros(sim_t* pSim, int coinSize)
{
	while (pSim->moneyInMachineCents < 100)
	{
		pSim->moneyInMachineEuros++;
		pSim->moneyInMachineCents -= 100;
	}
	return pSim;
}