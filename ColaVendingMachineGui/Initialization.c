#include "Initialization.h"

int INIT_Button(HWND H_Window)
{
	//# Buttons for inserting the coins
	CreateWindowW(L"button", L"\u20ac0,01", WS_VISIBLE | WS_CHILD | SS_CENTER, 700, 668, 50, 30, H_Window, (HMENU)CM_COIN_BUTTON_PRESSED_1,  NULL, NULL);
	CreateWindowW(L"button", L"\u20ac0,02", WS_VISIBLE | WS_CHILD | SS_CENTER, 755, 668, 50, 30, H_Window, (HMENU)CM_COIN_BUTTON_PRESSED_2,  NULL, NULL);
	CreateWindowW(L"button", L"\u20ac0,05", WS_VISIBLE | WS_CHILD | SS_CENTER, 810, 668, 50, 30, H_Window, (HMENU)CM_COIN_BUTTON_PRESSED_3,  NULL, NULL);
	CreateWindowW(L"button", L"\u20ac0,10", WS_VISIBLE | WS_CHILD | SS_CENTER, 865, 668, 50, 30, H_Window, (HMENU)CM_COIN_BUTTON_PRESSED_4,  NULL, NULL);
	CreateWindowW(L"button", L"\u20ac0,20", WS_VISIBLE | WS_CHILD | SS_CENTER, 920, 668, 50, 30, H_Window, (HMENU)CM_COIN_BUTTON_PRESSED_5,  NULL, NULL);
	CreateWindowW(L"button", L"\u20ac0,50", WS_VISIBLE | WS_CHILD | SS_CENTER, 975, 668, 50, 30, H_Window, (HMENU)CM_COIN_BUTTON_PRESSED_6,  NULL, NULL);
	CreateWindowW(L"button", L"\u20ac1",	WS_VISIBLE | WS_CHILD | SS_CENTER, 700, 703, 50, 30, H_Window, (HMENU)CM_COIN_BUTTON_PRESSED_7,  NULL, NULL);
	CreateWindowW(L"button", L"\u20ac2",	WS_VISIBLE | WS_CHILD | SS_CENTER, 755, 703, 50, 30, H_Window, (HMENU)CM_COIN_BUTTON_PRESSED_8,  NULL, NULL);
	CreateWindowW(L"button", L"\u20ac5",	WS_VISIBLE | WS_CHILD | SS_CENTER, 810, 703, 50, 30, H_Window, (HMENU)CM_COIN_BUTTON_PRESSED_9,  NULL, NULL);
	CreateWindowW(L"button", L"\u20ac10",	WS_VISIBLE | WS_CHILD | SS_CENTER, 865, 703, 50, 30, H_Window, (HMENU)CM_COIN_BUTTON_PRESSED_10, NULL, NULL);
	CreateWindowW(L"button", L"\u20ac20",	WS_VISIBLE | WS_CHILD | SS_CENTER, 920, 703, 50, 30, H_Window, (HMENU)CM_COIN_BUTTON_PRESSED_11, NULL, NULL);
	CreateWindowW(L"button", L"\u20ac50",	WS_VISIBLE | WS_CHILD | SS_CENTER, 975, 703, 50, 30, H_Window, (HMENU)CM_COIN_BUTTON_PRESSED_12, NULL, NULL);

	//# Button for the pin functionality 
	CreateWindowW(L"button", L"1",   WS_VISIBLE | WS_CHILD, 570, 583, 35, 30, H_Window, (HMENU)CM_PIN_BUTTON_PRESSED_1, NULL, NULL);
	CreateWindowW(L"button", L"2",   WS_VISIBLE | WS_CHILD, 610, 583, 35, 30, H_Window, (HMENU)CM_PIN_BUTTON_PRESSED_2, NULL, NULL);
	CreateWindowW(L"button", L"3",   WS_VISIBLE | WS_CHILD, 650, 583, 35, 30, H_Window, (HMENU)CM_PIN_BUTTON_PRESSED_3, NULL, NULL);
	CreateWindowW(L"button", L"4",   WS_VISIBLE | WS_CHILD, 570, 623, 35, 30, H_Window, (HMENU)CM_PIN_BUTTON_PRESSED_4, NULL, NULL);
	CreateWindowW(L"button", L"5",   WS_VISIBLE | WS_CHILD, 610, 623, 35, 30, H_Window, (HMENU)CM_PIN_BUTTON_PRESSED_5, NULL, NULL);
	CreateWindowW(L"button", L"6",   WS_VISIBLE | WS_CHILD, 650, 623, 35, 30, H_Window, (HMENU)CM_PIN_BUTTON_PRESSED_6, NULL, NULL);
	CreateWindowW(L"button", L"7",   WS_VISIBLE | WS_CHILD, 570, 663, 35, 30, H_Window, (HMENU)CM_PIN_BUTTON_PRESSED_7, NULL, NULL);
	CreateWindowW(L"button", L"8",   WS_VISIBLE | WS_CHILD, 610, 663, 35, 30, H_Window, (HMENU)CM_PIN_BUTTON_PRESSED_8, NULL, NULL);
	CreateWindowW(L"button", L"9",   WS_VISIBLE | WS_CHILD, 650, 663, 35, 30, H_Window, (HMENU)CM_PIN_BUTTON_PRESSED_9, NULL, NULL);
	CreateWindowW(L"button", L"DEL", WS_VISIBLE | WS_CHILD, 570, 703, 35, 30, H_Window, (HMENU)CM_PIN_BUTTON_PRESSED_DEL, NULL, NULL);
	CreateWindowW(L"button", L"0",   WS_VISIBLE | WS_CHILD, 610, 703, 35, 30, H_Window, (HMENU)CM_PIN_BUTTON_PRESSED_0, NULL, NULL);
	CreateWindowW(L"button", L"OK",  WS_VISIBLE | WS_CHILD, 650, 703, 35, 30, H_Window, (HMENU)CM_PIN_BUTTON_PRESSED_OK, NULL, NULL);

	//# Buttons for the drink selection
	CreateWindowW(L"button", L"Cola | \u20ac2,50",    WS_CHILD | WS_VISIBLE | SS_CENTER, 20, 20, 110, 30, H_Window,   (HMENU)CM_DRINK_BUTTON_PRESSED_1, NULL, NULL);
	CreateWindowW(L"button", L"Pepsi | \u20ac2,30",   WS_CHILD | WS_VISIBLE | SS_CENTER, 20, 80, 110, 30, H_Window,   (HMENU)CM_DRINK_BUTTON_PRESSED_2, NULL, NULL);
	CreateWindowW(L"button", L"Fanta | \u20ac2,40",   WS_CHILD | WS_VISIBLE | SS_CENTER, 20, 140, 110, 30, H_Window,  (HMENU)CM_DRINK_BUTTON_PRESSED_3, NULL, NULL);
	CreateWindowW(L"button", L"Ice Tea | \u20ac2,70", WS_CHILD | WS_VISIBLE | SS_CENTER, 140, 20, 110, 30, H_Window,  (HMENU)CM_DRINK_BUTTON_PRESSED_4, NULL, NULL);
	CreateWindowW(L"button", L"Sprite | \u20ac2,60",  WS_CHILD | WS_VISIBLE | SS_CENTER, 140, 80, 110, 30, H_Window,  (HMENU)CM_DRINK_BUTTON_PRESSED_5, NULL, NULL);
	CreateWindowW(L"button", L"SPA | \u20ac2,20",     WS_CHILD | WS_VISIBLE | SS_CENTER, 140, 140, 110, 30, H_Window, (HMENU)CM_DRINK_BUTTON_PRESSED_6, NULL, NULL);

	//# Buttons for the Change return
	CreateWindowW(L"button", L"Change | Donate", WS_CHILD | WS_VISIBLE | SS_CENTER, 440, 703, 120, 30, H_Window, (HMENU)CM_CHANGE_BUTTON_PRESSED, NULL, NULL);

	//# Buttons for Entering debit card
	H_DebitCard = CreateWindowW(L"button", L"Enter debitcard", WS_CHILD | WS_VISIBLE | SS_CENTER, 570, 555, 115, 20, H_Window, (HMENU)CM_DEBITCARD_BUTTON_PRESSED, NULL, NULL);

	return 0;
}

int INIT_Static(HWND H_Window, sim_t* pSim)
{
	//# Static for "Coins" text
	CreateWindowW(L"static", L"Coins",  WS_CHILD | WS_VISIBLE | SS_CENTER, 800, 640, 100, 18, H_Window, NULL, NULL, NULL);

	//# Static for "Pin" text
	//CreateWindowW(L"static", L"Pin",    WS_CHILD | WS_VISIBLE | SS_CENTER, 570, 555, 25, 20,  H_Window, NULL, NULL, NULL);

	//# Static for "Debug" text
	CreateWindowW(L"static", L"Debug",  WS_CHILD | WS_VISIBLE | SS_CENTER, 480, 2, 550, 18,   H_Window, NULL, NULL, NULL);

	//# Static for "Cash" text and statics as buffers
	CreateWindowW(L"static", L"Cash",   WS_CHILD | WS_VISIBLE | SS_CENTER, 30, 630, 100, 18,  H_Window, NULL, NULL, NULL);
	H_Change_Cash_Euros = CreateWindowW(L"static", L"0", WS_CHILD | WS_VISIBLE | SS_CENTER | WS_BORDER, 130, 630, 50, 18, H_Window, NULL, NULL, NULL);
	H_Change_Cash_Cents = CreateWindowW(L"static", L"0", WS_CHILD | WS_VISIBLE | SS_CENTER | WS_BORDER, 180, 630, 50, 18, H_Window, NULL, NULL, NULL);

	//# Static for "Change" text and statics as buffers
	CreateWindowW(L"static", L"Change", WS_CHILD | WS_VISIBLE | SS_CENTER, 30, 665, 100, 18,  H_Window, NULL, NULL, NULL);
	H_Change_Change_Euros = CreateWindowW(L"static", L"0", WS_CHILD | WS_VISIBLE | SS_CENTER | WS_BORDER, 130, 665, 50, 18, H_Window, NULL, NULL, NULL);
	H_Change_Change_Cents = CreateWindowW(L"static", L"0", WS_CHILD | WS_VISIBLE | SS_CENTER | WS_BORDER, 180, 665, 50, 18, H_Window, NULL, NULL, NULL);

	//# Static for "Wallet" text and statics as buffers
	CreateWindowW(L"static", L"Wallet", WS_CHILD | WS_VISIBLE | SS_CENTER, 30, 700, 100, 18,  H_Window, NULL, NULL, NULL);
	H_Change_Wallet_Euros = CreateWindowW(L"static", L"0", WS_CHILD | WS_VISIBLE | SS_CENTER | WS_BORDER, 130, 700, 50, 18, H_Window, NULL, NULL, NULL);
	H_Change_Wallet_Cents = CreateWindowW(L"static", L"0", WS_CHILD | WS_VISIBLE | SS_CENTER | WS_BORDER, 180, 700, 50, 18, H_Window, NULL, NULL, NULL);
	



	return 0;
}

int INIT_Menu(HWND H_Window)
{
	H_MENU = CreateMenu();

	//# Menu for admin rights
	AppendMenu(H_MENU, MF_STRING, CM_MENU_ITEM_ADMIN, L"Admin");
	SetMenu(H_Window, H_MENU);

	return 0;
}

int INIT_Edit(HWND H_Window)
{
	//# Edit for the Card, this is simulating a card reader
	//H_Card = CreateWindowW(L"edit", L"Card ID", WS_CHILD | WS_VISIBLE | SS_RIGHT | WS_BORDER, 595, 555, 90, 20, H_Window, NULL, NULL, NULL);

	//# Edit for the debug messsages
	H_Change_Debug = CreateWindowW(L"edit", NULL, WS_CHILD | WS_VISIBLE | SS_LEFT | WS_BORDER, 480, 20, 550, 525, H_Window, NULL, NULL, NULL);

	return 0;
}
