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
/// @date 14-12-2019
///

#include "ColaVendingMachineGui.h"


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
	srand(time(0));
	sim_t simulation = { (rand() % 100), (rand() % 50 + 5), 0, 0, 0, 0 };
	sim_t* pSim = &simulation;



	WNDCLASSW wc = { 0 };

	wc.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = hInst;
	wc.lpszClassName = L"CVM_5_GUI";
	wc.lpfnWndProc = WindowProcedure;
	wc.cbWndExtra = sizeof(pSim);

	if (!RegisterClassW(&wc))
		return -1;

	HWND H_Window = CreateWindowExW(WS_EX_CLIENTEDGE, L"CVM_5_GUI", L"Cola Vending Machine v5", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 1050, 800, NULL, NULL, NULL, pSim);

	SetWindowLongPtr(H_Window, GWLP_USERDATA, (LONG_PTR)pSim);
	
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
	//int Drink = 0;
	sim_t* pSim = GetWindowLongPtr(H_Window, GWLP_USERDATA);

	switch (msg) {

	case WM_CREATE:
	{
		INIT_Button(H_Window);
		INIT_Static(H_Window, pSim);
		INIT_Menu(H_Window);
		INIT_Edit(H_Window);
		break;
	}
	case WM_COMMAND:
	{
		//sim_t* 
		switch (wp) {
		case CM_MENU_ITEM_ADMIN:
			MessageBoxW(H_Window, L"This function is yet to be implemented", L"WIP", MB_OK);
			break;
		case CM_COIN_BUTTON_PRESSED_1:
			CHP_CheckCoins(pSim, V_1_CENTS);
			break;
		case CM_COIN_BUTTON_PRESSED_2:
			CHP_CheckCoins(pSim, V_2_CENTS);
			break;
		case CM_COIN_BUTTON_PRESSED_3:
			CHP_CheckCoins(pSim, V_5_CENTS);
			break;
		case CM_COIN_BUTTON_PRESSED_4:
			CHP_CheckCoins(pSim, V_10_CENTS);
			break;
		case CM_COIN_BUTTON_PRESSED_5:
			CHP_CheckCoins(pSim, V_20_CENTS);
			break;
		case CM_COIN_BUTTON_PRESSED_6:
			CHP_CheckCoins(pSim, V_50_CENTS);
			break;
		case CM_COIN_BUTTON_PRESSED_7:
			CHP_CheckCoins(pSim, V_1_EUR);
			break;
		case CM_COIN_BUTTON_PRESSED_8:
			CHP_CheckCoins(pSim, V_2_EUR);
			break;
		case CM_COIN_BUTTON_PRESSED_9:
			CHP_CheckCoins(pSim, V_5_EUR);
			break;
		case CM_COIN_BUTTON_PRESSED_10:
			CHP_CheckCoins(pSim, V_10_EUR);
			break;
		case CM_COIN_BUTTON_PRESSED_11:
			CHP_CheckCoins(pSim, V_20_EUR);
			break;
		case CM_COIN_BUTTON_PRESSED_12:
			CHP_CheckCoins(pSim, V_50_EUR);
			break;
			//?------------------------------------------------?//
		case CM_DRINK_BUTTON_PRESSED_1:
			CHP_CheckIfEnough(pSim, D_COLA, H_Window);
			break;
		case CM_DRINK_BUTTON_PRESSED_2:
			CHP_CheckIfEnough(pSim, D_PEPSI, H_Window);
			break;
		case CM_DRINK_BUTTON_PRESSED_3:
			CHP_CheckIfEnough(pSim, D_FANTA, H_Window);
			break;
		case CM_DRINK_BUTTON_PRESSED_4:
			CHP_CheckIfEnough(pSim, D_ICE_TEA, H_Window);
			break;
		case CM_DRINK_BUTTON_PRESSED_5:
			CHP_CheckIfEnough(pSim, D_SPRITE, H_Window);
			break;
		case CM_DRINK_BUTTON_PRESSED_6:
			CHP_CheckIfEnough(pSim, D_SPA, H_Window);
			break;

		case CM_CHANGE_BUTTON_PRESSED:

		case CM_PIN_BUTTON_PRESSED_1:

			break;
		case CM_PIN_BUTTON_PRESSED_2:

			break;
		case CM_PIN_BUTTON_PRESSED_3:

			break;
		case CM_PIN_BUTTON_PRESSED_4:

			break;
		case CM_PIN_BUTTON_PRESSED_5:

			break;
		case CM_PIN_BUTTON_PRESSED_6:

			break;
		case CM_PIN_BUTTON_PRESSED_7:

			break;
		case CM_PIN_BUTTON_PRESSED_8:

			break;
		case CM_PIN_BUTTON_PRESSED_9:

			break;
		case CM_PIN_BUTTON_PRESSED_0:

			break;
		}
		break;
	}
	case WM_CTLCOLORSTATIC:
	{
		hb = CreateSolidBrush(RGB(255, 255, 255));
		return (INT_PTR)hb;
	}
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		BeginPaint(H_Window, &ps);
		EndPaint(H_Window, &ps);
		return 0;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProcW(H_Window, msg, wp, lp);
	}
}