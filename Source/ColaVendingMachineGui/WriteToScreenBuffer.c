#include "WriteToScreenBuffer.h"

void WTSB_StaticInMachine(sim_t* pSim)
{
	wchar_t bufferEdited[BUFFSIZE];

	double moneyInMachineDouble = pSim->moneyInMachine / 100.0;

	swprintf(bufferEdited, BUFFSIZE, L"\u20AC%.2f", moneyInMachineDouble);
	SetWindowText(H_Change_Cash, bufferEdited);
}

void WTSB_StaticChange(sim_t* pSim)
{
	wchar_t bufferEdited[BUFFSIZE];

	double changeInMachineDouble = pSim->changeInMachine / 100.0;

	swprintf(bufferEdited, BUFFSIZE, L"\u20AC%.2f", changeInMachineDouble);
	SetWindowText(H_Change_Change, bufferEdited);
}

void WTSB_StaticWallet(sim_t* pSim)
{
	wchar_t bufferEdited[BUFFSIZE];

	double moneyInWalletDouble = pSim->moneyInWallet / 100.0;

	swprintf(bufferEdited, BUFFSIZE, L"\u20AC%.2f", moneyInWalletDouble);
	SetWindowText(H_Change_Wallet, bufferEdited);
}

void WTSB_StaticAccount(sim_t* pSim)
{
	wchar_t bufferEdited[BUFFSIZE];

	double moneyInAccountDouble = pSim->moneyInAccount / 100.0;

	swprintf(bufferEdited, BUFFSIZE, L"\u20AC%.2f", moneyInAccountDouble);
	SetWindowText(H_Change_Account, bufferEdited);
}

void WTSB_Redraw(sim_t* pSim) {
	WTSB_StaticInMachine(pSim);
	WTSB_StaticChange(pSim);
	WTSB_StaticWallet(pSim);
	WTSB_StaticAccount(pSim);
}