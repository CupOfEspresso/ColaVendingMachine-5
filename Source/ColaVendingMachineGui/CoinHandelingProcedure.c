
#include "CoinHandelingProcedure.h"
#include "ColaVendingMachineGui.h"

void CHP_CheckIfEnough(sim_t* pSim, int whichDrink, HWND H_Window)
{
	/// This function Checks if there is enough money to by a drink
	wchar_t bufferEdited[BUFFSIZE] = { 0 };
	drink_t drinks = { L"ERROR", 0};
	drink_t* pDrink = &drinks;
	UDS_Setup(whichDrink, &drinks);

	if (pSim->hasPaid == 0)
	{
		if (pSim->moneyInMachine >= drinks.priceTotaalCents)
		{
			WTDB_Debug(L"CHP_CheckIfEnough", L"Was sufficient amount pay for drink");
			pSim->moneyInMachine -= drinks.priceTotaalCents;
			pSim->changeInMachine = pSim->moneyInMachine;
			pSim->moneyInMachine = 0;

			WTSB_Redraw(pSim);

			WTDB_Debug(L"CHP_CheckIfEnough", L"Drink dispensed");
			wsprintf(bufferEdited, L"Enjoy your %s", drinks.drinkName);
			WTDB_Display(bufferEdited);

		}
		else
		{
			WTDB_Debug(L"CHP_CheckIfEnough", L"Wasn't sufficient amount pay for drink");
			swprintf(bufferEdited, 128, L"Sorry, your %s is \u20ac%.2f you have only inserted \u20ac%.2f", drinks.drinkName, (double)drinks.priceTotaalCents / 100, (double)pSim->moneyInMachine / 100);
			WTDB_Display(bufferEdited);
		}
	}
	else if (pSim->hasPaid == 1)
	{
		WTDB_Debug(L"CHP_CheckIfEnough", L"Debit transaction came through");
		WTDB_Debug(L"CHP_CheckIfEnough", L"Payment complete"); 
		pSim->moneyInAccount -= drinks.priceTotaalCents;

		WTSB_Redraw(pSim);

		WTDB_Debug(L"CHP_CheckIfEnough", L"Drink dispensed");
		wsprintf(bufferEdited, L"Enjoy your %s", drinks.drinkName);
		WTDB_Display(bufferEdited);

		pSim->hasPaid = 0;
	}
}

void CHP_CheckCoins(sim_t* pSim, int money)
{
	wchar_t bufferEdited[BUFFSIZE] = { 0 };
	/// This function Writes the right values for each money related screen buffer
	
	if (pSim->moneyInWallet - money >= 0)
	{
		CHP_CalculateValueOfCoin(pSim, money);
		WTDB_Debug(L"CHP_CheckCoins", L"Screenbuffer is changed");

		swprintf(bufferEdited, 128, L"Inserted \u20AC%.2f currently in the machine is \u20AC%.2f", (double)money / 100, (double)pSim->moneyInMachine / 100);
		WTDB_Display(bufferEdited);
		WTSB_Redraw(pSim);
	}
	else
	{
		WTDB_Debug(L"CHP_CheckCoins", L"No money left in wallet");
		WTDB_Display(L"The object you inserted isn't a valid valuta\r\n---\r\n404 Not Found");
	}
}



void CHP_CalculateValueOfCoin(sim_t* pSim, int money)
{
	/// Function calculates the right values regrading money
	wchar_t buffer[BUFFSIZE] = { 0 };
	if (pSim->moneyInWallet - money >= 0)
	{
		swprintf(buffer, BUFFSIZE, L"Adding \u20AC%.2f to internal account", (double)money / 100);
		WTDB_Debug(L"CHP_CalculateValueOfCoin", buffer);
		pSim->moneyInWallet -= money;
		pSim->moneyInMachine += money;
		WTSB_Redraw(pSim);
	}
	else
	{
		WTDB_Debug(L"CHP_CalculateValueOfCoin", L"Invalid money registered");
		WTDB_Display(L"The object you inserted isn't a valid valuta\r\n---\r\n404 Not Found");
		WTSB_Redraw(pSim);
	}
}

void CHP_ChangeHandeling(sim_t* pSim)
{
	/// This function handels the change
	wchar_t bufferEdited[BUFFSIZE];

	if ((pSim->changeInMachine != 0))
	{
		swprintf(bufferEdited, BUFFSIZE, L"Do you want to donate your \u20ac%.2f change to a charity?", (double)pSim->changeInMachine / 100);
		int messageBoxInput = MessageBoxW(NULL, bufferEdited, L"Change for Charity", MB_YESNO);

		if (messageBoxInput == IDYES)
		{
			WTDB_Debug(L"CHP_ChangeHandeling", L"donating authorized by users");
			WTDB_Debug(L"CHP_ChangeHandeling", L"donate complete");
			pSim->changeInMachine;
			WTDB_Display(L"Thank your for your donation");
			pSim->changeInMachine = 0;
			WTSB_Redraw(pSim);
		}
		else
		{
			WTDB_Debug(L"CHP_ChangeHandeling", L"donating denied by users");
			WTDB_Debug(L"CHP_ChangeHandeling", L"change dispensed");
			pSim->moneyInWallet += pSim->changeInMachine;
			pSim->changeInMachine = 0;
			WTSB_Redraw(pSim);
		}
	}
	else
	{
		WTDB_Debug(L"CHP_ChangeHandeling", L"There is no change");
		MessageBoxW(NULL, L"There is no change", L"Change", MB_OK);
	}
}

void CHP_AdminDebugFunctionallity(sim_t* pSim)
{
	/// Admin right for this machine can be used to debug the machine. the rights can be expanded
	pSim->moneyInWallet = 1000000;
	pSim->moneyInAccount = 1000000;

	WTDB_Debug(L"CHP_AdminDebugFunctionallity", L"Token authorized, gaining debug money");
	WTDB_Display(L"DEBUG - Admin mode initiated\r\nEarning \u20ac1000000 debug money");

	WTSB_Redraw(pSim);
}