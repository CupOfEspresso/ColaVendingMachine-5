
#include "CoinHandelingProcedure.h"
#include "ColaVendingMachineGui.h"

void CHP_CheckIfEnough(sim_t* pSim, int whichDrink, HWND H_Window)
{
	wchar_t bufferEdited[BUFFSIZE] = { 0 };
	drink_t drinks = {L"ERROR", 0, 0};
	drink_t* pDrink = &drinks;
	
	UDS_Setup(whichDrink, &drinks);

	if ((drinks.priceInEuros < pSim->moneyInMachineEuros) ||
		(drinks.priceInEuros == pSim->moneyInMachineEuros &&
			drinks.priceInCents == pSim->moneyInMachineCents))
	{
		pSim->moneyInMachineEuros -= drinks.priceInEuros;
		pSim->moneyInMachineCents -= drinks.priceInCents;

		wsprintf(bufferEdited, L"Enjoy you %s", drinks.drinkName);

		MessageBox(H_Window, bufferEdited, L"DISPENSE", MB_OK);
		WTSB_StaticCashEuros(pSim);
		WTSB_StaticCashCents(pSim);
	}
	else
	{
		wsprintf(bufferEdited, L"Sorry, your %s is \u20ac%d,%d you have only inserted \u20ac%d,%d",
			drinks.drinkName, drinks.priceInEuros, drinks.priceInCents, pSim->moneyInMachineEuros, pSim->moneyInMachineCents);

		MessageBox(H_Window, bufferEdited, L"DISPENSE", MB_OK);
		WTSB_StaticCashEuros(pSim);
		WTSB_StaticCashCents(pSim);
	}
}

void CHP_CheckCoins(sim_t* pSim, int coinSize)
{
	if ((pSim->moneyInWalletEuros > 0 && pSim->moneyInWalletCents > 0) ||
	   (pSim->moneyInWalletEuros >= 0 && pSim->moneyInWalletCents > 0) ||
	   (pSim->moneyInWalletEuros > 0 && pSim->moneyInWalletCents >= 0))
	{
		if (coinSize >= 100) {
			CHP_CalculatorEuros(pSim, coinSize);
		}
		else
		{
			CHP_CalculatorCents(pSim, coinSize);
		}

		WTSB_StaticWalletEuros(pSim);
		WTSB_StaticWalletCents(pSim);
		WTSB_StaticCashEuros(pSim);
		WTSB_StaticCashCents(pSim);
	}
	else
	{
		MessageBoxW(NULL, L"Wow, big spender you have spended all you money", L"Bankroot", MB_ICONWARNING);
	}
}

void CHP_EurosToCents(sim_t* pSim)
{
	while (pSim->moneyInMachineEuros != 0)
	{
		pSim->moneyInMachineEuros--;
		pSim->moneyInMachineCents += 100;
	}

	while (pSim->moneyInWalletEuros != 0)
	{
		pSim->moneyInWalletEuros--;
		pSim->moneyInWalletCents += 100;
 	}
}

void CHP_CentsToEuros(sim_t* pSim)
{
	while (pSim->moneyInMachineCents >= 100)
	{
		pSim->moneyInMachineEuros++;
		pSim->moneyInMachineCents -= 100;
	}

	while (pSim->moneyInWalletCents >= 100)
	{
		pSim->moneyInWalletEuros++;
		pSim->moneyInWalletCents -= 100;
	}
}


void CHP_CalculatorEuros(sim_t* pSim, int coinSize)
{
	CHP_EurosToCents(pSim);

	if (pSim->moneyInWalletCents - coinSize >= 0)
	{
		CHP_CentsToEuros(pSim);
		while (coinSize >= 100)
		{
			pSim->moneyInMachineEuros++;
			pSim->moneyInWalletEuros--;
			coinSize -= 100;
		}

		pSim->moneyInMachineCents += coinSize;

		if (pSim->moneyInMachineCents > 100)
		{
			pSim->moneyInMachineEuros++;
			coinSize -= 100;
		}
		WTSB_StaticCashEuros(pSim);
		WTSB_StaticCashCents(pSim);
	}
	else
	{
		MessageBoxW(NULL, L"You have't got that much money on hand", L"ERROR", MB_ICONWARNING);
		CHP_CentsToEuros(pSim);
	}
}

void CHP_CalculatorCents(sim_t* pSim, int coinSize)
{
	if (pSim->moneyInWalletCents - coinSize >= 0)
	{
		pSim->moneyInMachineCents += coinSize;
		pSim->moneyInWalletCents -= coinSize;
		if (pSim->moneyInMachineCents >= 100)
		{
			pSim->moneyInMachineEuros++;
			pSim->moneyInMachineCents -= 100;
		}
	}
	else if ((pSim->moneyInWalletCents - coinSize <= 0) && (pSim->moneyInWalletEuros >= 0) || (pSim->moneyInWalletEuros == 0))
	{
		CHP_EurosToCents(pSim);
		pSim->moneyInMachineCents += coinSize;
		pSim->moneyInWalletCents -= coinSize;
		CHP_CentsToEuros(pSim);
	}
	WTSB_StaticCashEuros(pSim);
	WTSB_StaticCashCents(pSim);
}