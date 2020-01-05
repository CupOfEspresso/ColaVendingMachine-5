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
			PWDC_CheckDebitCardCode(pSim);
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
		pSim->debitCardCode[pSim->postionInCardCode] = 0;

		if (pSim->postionInCardCode - 1 >= 0)
		{
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
			MessageBoxW(NULL, L"Wrong password, try again", L"ERROR", MB_OK);
			strcpy_s(pSim->debitCardCode, 16, "0000");
			pSim->postionInCardCode = 0;
			break;
		}
		else if (i == 3)
		{
			MessageBoxW(NULL, L"Please choose a drink to complete your transaction", L"PAY", MB_OK);
			pSim->hasPaid = 1;
			strcpy_s(pSim->debitCardCode, 16, "0000");
		}
	}
}


