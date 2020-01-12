/// GUI version of CVM-4 alias CVM-5
///
/// D_ are the functions that handel the Drinks
/// A_ are the functions that add the controls to screen
/// M_ are the functions that handel the Money related functionallity
/// P_ are the functions that handel the Pin functionallity
/// H_ are the WINAPI handlers
/// CM_ are command msg
///
///
/// This is based on Jos Onokiewicz CVM-4 
/// @author Youri Claes
/// @version 1.1
/// @date 8-1-2020
///

#include "ColaVendingMachineGui.h"



int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
	srand(time(0));

	int change = 0.0;

	/// Easteregg, there is a 1 in 100 change there is still some left over change in the change tray
	if ((rand() % 100) == 42)
	{
		change = (rand() % 500 + 1);
	}
	else
	{
		change = 0;
	}
	 
	/// This struct contains all system infomation
	sim_t simulation = {      
	(rand() % 5000 + 500),    //moneyInWallet
	(rand() % 100000),		  //moneyInAccount
	change,					  //changeInMachine
	0,						  //moneyInMachine
	0,						  //isDebitCardEntered
	0,						  //postionInCardCode
	0,                        //hasPaid
	{0, 0, 0, 0},             //debitCardCode[4]
	{1, 3, 3, 7}              //POINTOFCONCEPTPASSWORD[4]
	};

	sim_t* pSim = &simulation;


	WNDCLASSW wc = { 0 };

	wc.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = hInst;
	wc.hIcon = LoadIcon(hInst, IDI_ICON1);
	wc.lpszClassName = L"CVM_5_GUI";
	wc.lpfnWndProc = WindowProcedure;
	wc.cbWndExtra = sizeof(pSim);

	if (!RegisterClassW(&wc))
		return -1;

	HWND H_Window = CreateWindowExW(WS_EX_CLIENTEDGE, L"CVM_5_GUI", L"Cola Vending Machine v5", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 1000, 600, NULL, NULL, NULL, pSim);

	SetWindowLongPtr(H_Window, GWLP_USERDATA, (LONG_PTR)pSim);

	WTSB_Redraw(pSim);

	MSG msg = { 0 };

	while (GetMessageW(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT CALLBACK WindowProcedure(HWND H_Window, UINT msg, WPARAM wp, LPARAM lp)
{
	/// this struct contain all money value they are const and are given in cents
	valuta_t valuta = {
	1,  //V_1_CENT
	2,  //V_2_CENT
	5,  //V_5_CENT
	10,  //V_10_CENT
	20,  //V_20_CENT
	50,  //V_50_CENT
	100,  //V_1_EURO
	200,  //V_2_EURO
	500,  //V_5_EURO
	1000, //V_10_EURO
	2000, //V_20_EURO
	5000  //V_50_EURO
	};

	sim_t* pSim = GetWindowLongPtr(H_Window, GWLP_USERDATA);
	valuta_t* pValuta = &valuta;


	switch (msg) {
	/// this INIT's all onscreen objects
	case WM_CREATE:
	{
		INIT_Button(H_Window);
		INIT_Static(H_Window, pSim);
		INIT_Menu(H_Window);
		INIT_Edit(H_Window);
		break;
	}
	/// Here is the state machine it react upon a button click
	case WM_COMMAND:
	{
		switch (wp) {
		case CM_MENU_ITEM_ADMIN:
			WTDB_Debug(L"ADMIN", L"Admin test money granted");
			CHP_AdminDebugFunctionallity(pSim);
			break;
		case CM_MENU_ITEM_AUTHOR:
			MessageBoxW(NULL, L"Author: Youri Claes\r\nVersion: 1.8", L"About CVM_GUI", MB_OK);
		case CM_COIN_BUTTON_PRESSED_1:
			WTDB_Debug(L"COIN_1", L"Attempt to insert 1 cent");
			CHP_CheckCoins(pSim, pValuta->V_1_CENT);
			break;
		case CM_COIN_BUTTON_PRESSED_2:
			WTDB_Debug(L"COIN_2", L"Attempt to insert 2 cent");
			CHP_CheckCoins(pSim, valuta.V_2_CENT);
			break;
		case CM_COIN_BUTTON_PRESSED_3:
			WTDB_Debug(L"COIN_3", L"Attempt to insert 5 cent");
			CHP_CheckCoins(pSim, valuta.V_5_CENT);
			break;
		case CM_COIN_BUTTON_PRESSED_4:
			WTDB_Debug(L"COIN_4", L"Attempt to insert 10 cent");
			CHP_CheckCoins(pSim, valuta.V_10_CENT);
			break;
		case CM_COIN_BUTTON_PRESSED_5:
			WTDB_Debug(L"COIN_5", L"Attempt to insert 20 cent");
			CHP_CheckCoins(pSim, valuta.V_20_CENT);
			break;
		case CM_COIN_BUTTON_PRESSED_6:
			WTDB_Debug(L"COIN_6", L"Attempt to insert 50 cent");
			CHP_CheckCoins(pSim, valuta.V_50_CENT);
			break;
		case CM_COIN_BUTTON_PRESSED_7:
			WTDB_Debug(L"COIN_7", L"Attempt to insert 1 euro");
			CHP_CheckCoins(pSim, valuta.V_1_EURO);
			break;
		case CM_COIN_BUTTON_PRESSED_8:
			WTDB_Debug(L"COIN_8", L"Attempt to insert 2 euro");
			CHP_CheckCoins(pSim, valuta.V_2_EURO);
			break;
		case CM_COIN_BUTTON_PRESSED_9:
			WTDB_Debug(L"COIN_9", L"Attempt to insert 5 euro");
			CHP_CheckCoins(pSim, valuta.V_5_EURO);
			break;
		case CM_COIN_BUTTON_PRESSED_10:
			WTDB_Debug(L"COIN_10", L"Attempt to insert 10 euro");
			CHP_CheckCoins(pSim, valuta.V_10_EURO);
			break;
		case CM_COIN_BUTTON_PRESSED_11:
			WTDB_Debug(L"COIN_11", L"Attempt to insert 20 euro");
			CHP_CheckCoins(pSim, valuta.V_20_EURO);
			break;
		case CM_COIN_BUTTON_PRESSED_12:
			WTDB_Debug(L"COIN_12", L"Attempt to insert 50 euro");
			CHP_CheckCoins(pSim, valuta.V_50_EURO);
			break;
			//?------------------------------------------------?//
		case CM_DRINK_BUTTON_PRESSED_1:
			WTDB_Debug(L"DRINK_1", L"Attempt to buy Cola");
			CHP_CheckIfEnough(pSim, D_COLA, H_Window);
			break;
		case CM_DRINK_BUTTON_PRESSED_2:
			WTDB_Debug(L"DRINK_2", L"Attempt to buy Pepsi");
			CHP_CheckIfEnough(pSim, D_PEPSI, H_Window);
			break;
		case CM_DRINK_BUTTON_PRESSED_3:
			WTDB_Debug(L"DRINK_3", L"Attempt to buy Fanta");
			CHP_CheckIfEnough(pSim, D_FANTA, H_Window);
			break;
		case CM_DRINK_BUTTON_PRESSED_4:
			WTDB_Debug(L"DRINK_4", L"Attempt to buy Ice Tea");
			CHP_CheckIfEnough(pSim, D_ICE_TEA, H_Window);
			break;
		case CM_DRINK_BUTTON_PRESSED_5:
			WTDB_Debug(L"DRINK_5", L"Attempt to buy Sprite");
			CHP_CheckIfEnough(pSim, D_SPRITE, H_Window);
			break;
		case CM_DRINK_BUTTON_PRESSED_6:
			WTDB_Debug(L"DRINK_6", L"Attempt to buy SPA");
			CHP_CheckIfEnough(pSim, D_SPA, H_Window);
			break;
			//?------------------------------------------------?//
		case CM_CHANGE_BUTTON_PRESSED:
			WTDB_Debug(L"CHANGE", L"Prompting change menu");
			CHP_ChangeHandeling(pSim);
			break;
			//?------------------------------------------------?//
		case CM_DEBITCARD_BUTTON_PRESSED:
			WTDB_Debug(L"DEBITCARD", L"Insert debitcard");
			PWDC_DebitcardHandeling(pSim);
			break;
		case CM_PIN_BUTTON_PRESSED_1:
			WTDB_Debug(L"PIN_1", L"Enter digit of pin | 1 |");
			PWDC_AddPincodeBuffer(pSim, 1);
			break;
		case CM_PIN_BUTTON_PRESSED_2:
			WTDB_Debug(L"PIN_2", L"Enter digit of pin | 2 |");
			PWDC_AddPincodeBuffer(pSim, 2);
			break;
		case CM_PIN_BUTTON_PRESSED_3:
			WTDB_Debug(L"PIN_3", L"Enter digit of pin | 3 |");
			PWDC_AddPincodeBuffer(pSim, 3);
			break;
		case CM_PIN_BUTTON_PRESSED_4:
			WTDB_Debug(L"PIN_4", L"Enter digit of pin | 4 |");
			PWDC_AddPincodeBuffer(pSim, 4);
			break;
		case CM_PIN_BUTTON_PRESSED_5:
			WTDB_Debug(L"PIN_5", L"Enter digit of pin | 5 |");
			PWDC_AddPincodeBuffer(pSim, 5);
			break;
		case CM_PIN_BUTTON_PRESSED_6:
			WTDB_Debug(L"PIN_6", L"Enter digit of pin | 6 |");
			PWDC_AddPincodeBuffer(pSim, 6);
			break;
		case CM_PIN_BUTTON_PRESSED_7:
			WTDB_Debug(L"PIN_7", L"Enter digit of pin | 7 |");
			PWDC_AddPincodeBuffer(pSim, 7);
			break;
		case CM_PIN_BUTTON_PRESSED_8:
			WTDB_Debug(L"PIN_8", L"Enter digit of pin | 8 |");
			PWDC_AddPincodeBuffer(pSim, 8);
			break;
		case CM_PIN_BUTTON_PRESSED_9:
			WTDB_Debug(L"PIN_9", L"Enter digit of pin | 9 |");
			PWDC_AddPincodeBuffer(pSim, 9);
			break;
		case CM_PIN_BUTTON_PRESSED_0:
			WTDB_Debug(L"PIN_0", L"Enter digit of pin | 0 |");
			PWDC_AddPincodeBuffer(pSim, 0);
			break;
		case CM_PIN_BUTTON_PRESSED_OK:
			WTDB_Debug(L"PIN_OK", L"Validating pin");
			PWDC_CheckPincode(pSim);
			break;
		case CM_PIN_BUTTON_PRESSED_DEL:
			WTDB_Debug(L"PIN_DEL", L"Remove pin digit from buffer");
			PWDC_RemovePincodeBuffer(pSim, 0);
			break;
		}
		break;
	}
	/// Sets color of all static
	case WM_CTLCOLORSTATIC:
	{
		hb = CreateSolidBrush(RGB(255, 255, 255));
		return (INT_PTR)hb;
	}
	case WM_SETFONT:
	{

	}
	/// This Exits the program and clears the memory used
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		break;
	}
	default:
		return DefWindowProcW(H_Window, msg, wp, lp);
	}
}