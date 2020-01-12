#include "PayWithDebitCard.h"

PWDC_DebitcardHandeling(sim_t* pSim)
{
	/// This lets you enter or remove your debitcard
	if (pSim->isDebitCardEntered == 0)
	{
		pSim->isDebitCardEntered = 1;
		WTDB_Debug(L"PWDC_DebitcardHandeling", L"Debitcard recogisned");
		SetWindowTextW(H_DebitCard, L"Take debitcard");
	}
	else
	{
		pSim->isDebitCardEntered = 0;
		WTDB_Debug(L"PWDC_DebitcardHandeling", L"Debitcard removed");
		SetWindowTextW(H_DebitCard, L"Enter debitcard");
	}
}


PWDC_AddPincodeBuffer(sim_t* pSim, int pinNumber)
{
	/// This adds a digit to the pincode buffer
	if (pSim->isDebitCardEntered == 1)
	{
		if (pSim->postionInCardCode != 4)
		{
			pSim->debitCardCode[pSim->postionInCardCode] = pinNumber;
			pSim->postionInCardCode++;
		}
		else
		{
			WTDB_Debug(L"PWDC_AddPincodeBuffer", L"Max. number of digits enterd");
			WTDB_Display(L"Please confirm or change you password");
		}
	}
	else
	{
		WTDB_Debug(L"PWDC_AddPincodeBuffer", L"Debitcard not found");
		WTDB_Display(L"Please enter you debitcard");
	}
}

PWDC_RemovePincodeBuffer(sim_t* pSim)
{
	/// this removes a digit from pincode buffer
	if (pSim->isDebitCardEntered == 1)
	{
		if (pSim->postionInCardCode - 1 >= 0)
		{
			pSim->debitCardCode[pSim->postionInCardCode - 1] = 0;
			pSim->postionInCardCode--;
		}
		else
		{
			WTDB_Debug(L"PWDC_RemovePincodeBuffer", L"No digits in buffer");
			WTDB_Display(L"There are no digit in this pincode left");
		}
	}
	else
	{
		WTDB_Debug(L"PWDC_RemovePincodeBuffer", L"Please enter you debitcard");
	}
}

PWDC_CheckPincode(sim_t* pSim)
{
	///this validate the pincode against a database or for this sim the POINTOFCONCEPTPASSWORD
	for (int i = 0; i < 4; i++)
	{
		if (pSim->debitCardCode[i] != pSim->POINTOFCONCEPTPASSWORD[i]) 
		{
			for (int i = 0; i <= 3; ++i)
			{
				pSim->debitCardCode[i] = 0;
			}
			pSim->postionInCardCode = 0;
			WTDB_Debug(L"PWDC_CheckPincode", L"Pincode wasn't valid");
			WTDB_Display(L"Wrong pincode, try again");
			break;
		}
		else if (i == 3)
		{	
			for (int i = 0; i <= 3; ++i)
			{
				pSim->debitCardCode[i] = 0;
			}
			WTDB_Debug(L"PWDC_CheckPincode", L"Pincode valid");
			pSim->hasPaid = 1;
			pSim->postionInCardCode = 0;
			WTDB_Debug(L"PWDC_CheckPincode", L"Sending debitcard transaction");
			WTDB_Display(L"Please choose a drink to complete your transaction");
		}
	}
}