#include "WriteToScreenBuffer.h"


void WTSB_StaticChar(wchar_t buffer, HWND handler)
{
	wchar_t bufferEdited[BUFFSIZE];

	wsprintf(bufferEdited, L"DEBUG: %s", buffer);
	SetWindowText(handler, bufferEdited);
}

void WTSB_StaticCashCents(sim_t* pSim)
{
	wchar_t bufferEdited[BUFFSIZE];

	wsprintf(bufferEdited, L"%d", pSim->moneyInMachineCents);
	SetWindowText(H_Change_Cash_Cents, bufferEdited);
}

void WTSB_StaticCashEuros(sim_t* pSim)
{
	wchar_t bufferEdited[BUFFSIZE];

	wsprintf(bufferEdited, L"%d", pSim->moneyInMachineEuros);
	SetWindowText(H_Change_Cash_Euros, bufferEdited);
}

void WTSB_StaticChangeCents(sim_t* pSim)
{
	wchar_t bufferEdited[BUFFSIZE];

	wsprintf(bufferEdited, L"%d", pSim->changeInMachineCents);
	SetWindowText(H_Change_Change_Cents, bufferEdited);
}

void WTSB_StaticChangeEuros(sim_t* pSim)
{
	wchar_t bufferEdited[BUFFSIZE];

	wsprintf(bufferEdited, L"%d", pSim->changeInMachineEuros);
	SetWindowText(H_Change_Change_Euros, bufferEdited);
}

void WTSB_StaticWalletCents(sim_t* pSim)
{
	wchar_t bufferEdited[BUFFSIZE];

	wsprintf(bufferEdited, L"%d", pSim->moneyInWalletCents);
	SetWindowText(H_Change_Wallet_Cents, bufferEdited);
}

void WTSB_StaticWalletEuros(sim_t* pSim)
{
	wchar_t bufferEdited[BUFFSIZE];

	wsprintf(bufferEdited, L"%d", pSim->moneyInWalletEuros);
	SetWindowText(H_Change_Wallet_Euros, bufferEdited);
}

void WTSB_Redraw(sim_t* pSim) {
	WTSB_StaticCashCents(pSim);
	WTSB_StaticCashEuros(pSim);
	WTSB_StaticChangeCents(pSim);
	WTSB_StaticChangeEuros(pSim);
	WTSB_StaticWalletCents(pSim);
	WTSB_StaticWalletEuros(pSim);
}