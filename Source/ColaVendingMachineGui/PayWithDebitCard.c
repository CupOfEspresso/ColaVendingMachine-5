#include "PayWithDebitCard.h"

PWDC_EnterAndRemoveDebitCard(sim_t* pSim)
{
	if (pSim->isDebitCardEntered == 0)
	{
		pSim->isDebitCardEntered = 1;
		SetWindowTextW(H_DebitCard, L"Take debitcard");
	}
	else
	{
		pSim->isDebitCardEntered = 0;
		SetWindowTextW(H_DebitCard, L"Enter debitcard");
	}
}


PWDC_AddToDebitCardCodeBuffer(sim_t* pSim, int pinNumber)
{
	if (pSim->isDebitCardEntered == 1)
	{
		if (pSim->postionInCardCode != 4)
		{
			pSim->debitCardCode[pSim->postionInCardCode] = pinNumber;
			pSim->postionInCardCode++;
		}
		else
		{
			MessageBoxW(NULL, L"Please confirm or change you password", L"PayWithDebitCard", MB_OK);
		}
	}
	else
	{
		MessageBoxW(NULL, L"Please enter you debitcard", L"PayWithDebitCard", MB_OK);
	}
}

PWDC_RemoveFromDebitCardCodeBuffer(sim_t* pSim)
{
	if (pSim->isDebitCardEntered == 1)
	{
		if (pSim->postionInCardCode - 1 >= 0)
		{
			pSim->debitCardCode[pSim->postionInCardCode - 1] = 0;
			pSim->postionInCardCode--;
		}
		else
		{
			MessageBoxW(NULL, L"there are no digit in this code left", L"debitcard", MB_OK);
		}
	}
	else
	{
		MessageBoxW(NULL, L"Please enter you debitcard", L"PayWithDebitCard", MB_OK);
	}
}

PWDC_CheckDebitCardCode(sim_t* pSim)
{
	for (int i = 0; i < 4; i++)
	{
		if (pSim->debitCardCode[i] != pSim->POINTOFCONCEPTPASSWORD[i]) {
			for (int i = 0; i <= 3; ++i)
			{
				pSim->debitCardCode[i] = 0;
			}
			pSim->postionInCardCode = 0;
			MessageBoxW(NULL, L"Wrong password, try again", L"ERROR", MB_OK);
			break;
		}
		else if (i == 3)
		{	
			for (int i = 0; i <= 3; ++i)
			{
				pSim->debitCardCode[i] = 0;
			}
			pSim->hasPaid = 1;
			pSim->postionInCardCode = 0;
			MessageBoxW(NULL, L"Please choose a drink to complete your transaction", L"PAY", MB_OK);
		}
	}
}


