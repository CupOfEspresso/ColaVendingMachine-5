#include "WriteToScreenBuffer.h"
/// These functions write to the money display sections
void WTSB_StaticInMachine(sim_t* pSim)
{
	/// Display amount of money you have to InMachine buffer
	wchar_t bufferEdited[BUFFSIZE];

	swprintf(bufferEdited, BUFFSIZE, L"\u20AC%.2f", (double)pSim->moneyInMachine / 100);
	SetWindowText(H_Change_Cash, bufferEdited);
}

void WTSB_StaticChange(sim_t* pSim)
{
	/// Display amount of money you have to Change buffer
	wchar_t bufferEdited[BUFFSIZE];

	swprintf(bufferEdited, BUFFSIZE, L"\u20AC%.2f", (double)pSim->changeInMachine / 100.0);
	SetWindowText(H_Change_Change, bufferEdited);
}

void WTSB_StaticWallet(sim_t* pSim)
{
	/// Display amount of money you have to Wallet buffer
	wchar_t bufferEdited[BUFFSIZE];

	swprintf(bufferEdited, BUFFSIZE, L"\u20AC%.2f", (double)pSim->moneyInWallet / 100);
	SetWindowText(H_Change_Wallet, bufferEdited);
}

void WTSB_StaticAccount(sim_t* pSim)
{
	/// Display amount of money you have to Account buffer
	wchar_t bufferEdited[BUFFSIZE];

	swprintf(bufferEdited, BUFFSIZE, L"\u20AC%.2f", (double)pSim->moneyInAccount / 100);
	SetWindowText(H_Change_Account, bufferEdited);
}

void WTSB_Redraw(sim_t* pSim) {
	/// Redraws every buffer
	WTSB_StaticInMachine(pSim);
	WTSB_StaticChange(pSim);
	WTSB_StaticWallet(pSim);
	WTSB_StaticAccount(pSim);
}