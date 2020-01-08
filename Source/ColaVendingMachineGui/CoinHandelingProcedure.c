
#include "CoinHandelingProcedure.h"
#include "ColaVendingMachineGui.h"

void CHP_CheckIfEnough(sim_t* pSim, int whichDrink, HWND H_Window)
{
	    wchar_t bufferEdited[BUFFSIZE] = { 0 };
		drink_t drinks = { L"ERROR", 0, 0 };
		drink_t* pDrink = &drinks;
		
		UDS_Setup(whichDrink, &drinks);
	if (pSim->hasPaid == 0)
	{	
		CHP_EurosToCentsInMachine(pSim);

		if (pSim->moneyInMachineCents >= drinks.priceTotaalCents)
		{
			CHP_CentsToEurosInMachine(pSim);
			pSim->moneyInMachineEuros -= drinks.priceInEuros;

			if (pSim->moneyInMachineCents - drinks.priceInCents < 0)
			{
				pSim->moneyInMachineEuros--;
				pSim->moneyInMachineCents += 100;
				pSim->moneyInMachineCents -= drinks.priceInCents;
			}
			else
			{
				pSim->moneyInMachineCents -= drinks.priceInCents;
			}

			pSim->changeInMachineEuros = pSim->moneyInMachineEuros;
			pSim->changeInMachineCents = pSim->moneyInMachineCents;
			pSim->moneyInMachineEuros = 0;
			pSim->moneyInMachineCents = 0;

			WTSB_Redraw(pSim);

			wsprintf(bufferEdited, L"Enjoy you %s", drinks.drinkName);

			MessageBox(H_Window, bufferEdited, L"DISPENSE", MB_OK);
		}
		else
		{
			CHP_CentsToEurosInMachine(pSim);
			WTSB_Redraw(pSim);

			wsprintf(bufferEdited, L"Sorry, your %s is \u20ac%d,%d you have only inserted \u20ac%d,%d",
				drinks.drinkName, drinks.priceInEuros, drinks.priceInCents, pSim->moneyInMachineEuros, pSim->moneyInMachineCents);

			MessageBox(H_Window, bufferEdited, L"DISPENSE", MB_OK);
		}
	}
	else if (pSim->hasPaid == 1)
	{
		wsprintf(bufferEdited, L"Enjoy you %s", drinks.drinkName);
		MessageBox(H_Window, bufferEdited, L"DISPENSE", MB_OK);

		pSim->hasPaid = 0;
	}
}

void CHP_CheckCoins(sim_t* pSim, int coinSize)
{
	/// This function Calculates the right values for each money related screen buffer
	if ((pSim->moneyInWalletEuros > 0 && pSim->moneyInWalletCents > 0) ||
	   (pSim->moneyInWalletEuros >= 0 && pSim->moneyInWalletCents > 0) ||
	   (pSim->moneyInWalletEuros > 0 && pSim->moneyInWalletCents >= 0))
	{
		if (coinSize >= 100) {
			ATDB_Write(L"CHP_CheckCoins", L"Inserted is a euro value");
			CHP_CalculatorEuros(pSim, coinSize);
		}
		else
		{
			ATDB_Write(L"CHP_CheckCoins", L"Inserted is a cent value");
			CHP_CalculatorCents(pSim, coinSize);
		}
		ATDB_Write(L"CHP_CheckCoins", L"Screenbuffer is changed");
		WTSB_Redraw(pSim);
	}
	else
	{
		ATDB_Write(L"CHP_CheckCoins", L"No money in wallet");
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

void CHP_EurosToCentsInMachine(sim_t* pSim)
{
	while (pSim->moneyInMachineEuros != 0)
	{
		pSim->moneyInMachineEuros--;
		pSim->moneyInMachineCents += 100;
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

void CHP_CentsToEurosInMachine(sim_t* pSim)
{
	while (pSim->moneyInMachineCents >= 100)
	{
		pSim->moneyInMachineEuros++;
		pSim->moneyInMachineCents -= 100;
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
		ATDB_Write(L"CHP_CalculatorEuros", L"Changing euros value");
		WTSB_Redraw(pSim);
	}
	else
	{
		ATDB_Write(L"CHP_CalculatorEuros", L"You don't got that many euros");
		CHP_CentsToEuros(pSim);
		MessageBoxW(NULL, L"You have't got that much money on hand", L"ERROR", MB_ICONWARNING);		
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
	ATDB_Write(L"CHP_CalculatorEuros", L"Changing euros value");
	WTSB_Redraw(pSim);
}

void CHP_ChangeHandeling(sim_t* pSim)
{
	wchar_t bufferEdited[BUFFSIZE];

	if ((pSim->changeInMachineEuros != 0) || (pSim->changeInMachineCents != 0))
	{
		wsprintf(bufferEdited, L"Do you want to donate your \u20ac%d,%d change to a charity?", pSim->changeInMachineEuros, pSim->changeInMachineCents);
		int messageBoxInput = MessageBoxW(NULL, bufferEdited, L"Change for Charity", MB_YESNO);

		if (messageBoxInput == IDYES)
		{
			pSim->changeInMachineEuros;
			pSim->changeInMachineCents;
			MessageBoxW(NULL, L"Thank you for your donation", L"Change for Charity", MB_OK);
			pSim->changeInMachineEuros = 0;
			pSim->changeInMachineCents = 0;
			WTSB_Redraw(pSim);
		}
		else
		{
			pSim->moneyInWalletEuros += pSim->changeInMachineEuros;
			pSim->moneyInWalletCents += pSim->changeInMachineCents;
			pSim->changeInMachineEuros = 0;
			pSim->changeInMachineCents = 0;
			WTSB_Redraw(pSim);
		}
	}
	else
	{
		MessageBoxW(NULL, L"There is no change", L"Change", MB_OK);
	}
}

void CHP_AdminDebugFunctionallity(sim_t* pSim)
{
	pSim->moneyInWalletEuros = 10000;

	MessageBoxW(NULL, L"You chose admin this earns you \u20ac10000", L"admin", MB_OK);

	WTSB_Redraw(pSim);
}