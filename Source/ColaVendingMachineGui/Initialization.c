#include "Initialization.h"

int INIT_Button(HWND H_Window)
{
	int CoinTrayPosX = 700;
	int CoinTrayPosY = 668;
	/// Buttons for inserting the coins
	CreateWindowW(L"button", L"\u20ac0,01", WS_VISIBLE | WS_CHILD | SS_CENTER, CoinTrayPosX,       CoinTrayPosY, 50, 30, H_Window, (HMENU)CM_COIN_BUTTON_PRESSED_1,  NULL, NULL);
	CreateWindowW(L"button", L"\u20ac0,02", WS_VISIBLE | WS_CHILD | SS_CENTER, CoinTrayPosX += 55, CoinTrayPosY, 50, 30, H_Window, (HMENU)CM_COIN_BUTTON_PRESSED_2,  NULL, NULL);
	CreateWindowW(L"button", L"\u20ac0,05", WS_VISIBLE | WS_CHILD | SS_CENTER, CoinTrayPosX += 55, CoinTrayPosY, 50, 30, H_Window, (HMENU)CM_COIN_BUTTON_PRESSED_3,  NULL, NULL);
	CreateWindowW(L"button", L"\u20ac0,10", WS_VISIBLE | WS_CHILD | SS_CENTER, CoinTrayPosX += 55, CoinTrayPosY, 50, 30, H_Window, (HMENU)CM_COIN_BUTTON_PRESSED_4,  NULL, NULL);
	CreateWindowW(L"button", L"\u20ac0,20", WS_VISIBLE | WS_CHILD | SS_CENTER, CoinTrayPosX += 55, CoinTrayPosY, 50, 30, H_Window, (HMENU)CM_COIN_BUTTON_PRESSED_5,  NULL, NULL);
	CreateWindowW(L"button", L"\u20ac0,50", WS_VISIBLE | WS_CHILD | SS_CENTER, CoinTrayPosX += 55, CoinTrayPosY, 50, 30, H_Window, (HMENU)CM_COIN_BUTTON_PRESSED_6,  NULL, NULL);
	CreateWindowW(L"button", L"\u20ac1",	WS_VISIBLE | WS_CHILD | SS_CENTER, CoinTrayPosX = 700, CoinTrayPosY+= 35, 50, 30, H_Window, (HMENU)CM_COIN_BUTTON_PRESSED_7, NULL, NULL);
	CreateWindowW(L"button", L"\u20ac2",    WS_VISIBLE | WS_CHILD | SS_CENTER, CoinTrayPosX += 55, CoinTrayPosY,  50, 30, H_Window, (HMENU)CM_COIN_BUTTON_PRESSED_8, NULL, NULL);
	CreateWindowW(L"button", L"\u20ac5",    WS_VISIBLE | WS_CHILD | SS_CENTER, CoinTrayPosX += 55, CoinTrayPosY, 50, 30, H_Window, (HMENU)CM_COIN_BUTTON_PRESSED_9, NULL, NULL);
	CreateWindowW(L"button", L"\u20ac10",   WS_VISIBLE | WS_CHILD | SS_CENTER, CoinTrayPosX += 55, CoinTrayPosY, 50, 30, H_Window, (HMENU)CM_COIN_BUTTON_PRESSED_10, NULL, NULL);
	CreateWindowW(L"button", L"\u20ac20",   WS_VISIBLE | WS_CHILD | SS_CENTER, CoinTrayPosX += 55, CoinTrayPosY, 50, 30, H_Window, (HMENU)CM_COIN_BUTTON_PRESSED_11, NULL, NULL);
	CreateWindowW(L"button", L"\u20ac50",   WS_VISIBLE | WS_CHILD | SS_CENTER, CoinTrayPosX += 55, CoinTrayPosY, 50, 30, H_Window, (HMENU)CM_COIN_BUTTON_PRESSED_12, NULL, NULL);

	int PinPosX = 20;
	int PinPosY = 500;
	/// Button for the pin functionality 
	CreateWindowW(L"button", L"1",   WS_VISIBLE | WS_CHILD, PinPosX,	  PinPosY, 35,   30, H_Window, (HMENU)CM_PIN_BUTTON_PRESSED_1, NULL, NULL);
	CreateWindowW(L"button", L"2",   WS_VISIBLE | WS_CHILD, PinPosX + 40, PinPosY, 35,   30, H_Window, (HMENU)CM_PIN_BUTTON_PRESSED_2, NULL, NULL);
	CreateWindowW(L"button", L"3",   WS_VISIBLE | WS_CHILD, PinPosX + 80, PinPosY, 35,   30, H_Window, (HMENU)CM_PIN_BUTTON_PRESSED_3, NULL, NULL);
	CreateWindowW(L"button", L"4",   WS_VISIBLE | WS_CHILD, PinPosX,      PinPosY + 40,  35, 30, H_Window, (HMENU)CM_PIN_BUTTON_PRESSED_4, NULL, NULL);
	CreateWindowW(L"button", L"5",   WS_VISIBLE | WS_CHILD, PinPosX + 40, PinPosY + 40,  35, 30, H_Window, (HMENU)CM_PIN_BUTTON_PRESSED_5, NULL, NULL);
	CreateWindowW(L"button", L"6",   WS_VISIBLE | WS_CHILD, PinPosX + 80, PinPosY + 40,  35, 30, H_Window, (HMENU)CM_PIN_BUTTON_PRESSED_6, NULL, NULL);
	CreateWindowW(L"button", L"7",   WS_VISIBLE | WS_CHILD, PinPosX,      PinPosY + 80,  35, 30, H_Window, (HMENU)CM_PIN_BUTTON_PRESSED_7, NULL, NULL);
	CreateWindowW(L"button", L"8",   WS_VISIBLE | WS_CHILD, PinPosX + 40, PinPosY + 80,  35, 30, H_Window, (HMENU)CM_PIN_BUTTON_PRESSED_8, NULL, NULL);
	CreateWindowW(L"button", L"9",   WS_VISIBLE | WS_CHILD, PinPosX + 80, PinPosY + 80,  35, 30, H_Window, (HMENU)CM_PIN_BUTTON_PRESSED_9, NULL, NULL);
	CreateWindowW(L"button", L"DEL", WS_VISIBLE | WS_CHILD, PinPosX,      PinPosY + 120, 35, 30, H_Window, (HMENU)CM_PIN_BUTTON_PRESSED_DEL, NULL, NULL);
	CreateWindowW(L"button", L"0",   WS_VISIBLE | WS_CHILD, PinPosX + 40, PinPosY + 120, 35, 30, H_Window, (HMENU)CM_PIN_BUTTON_PRESSED_0, NULL, NULL);
	CreateWindowW(L"button", L"OK",  WS_VISIBLE | WS_CHILD, PinPosX + 80, PinPosY + 120, 35, 30, H_Window, (HMENU)CM_PIN_BUTTON_PRESSED_OK, NULL, NULL);

	int DrinkPosX = 20;
	int DrinkPosY = 20;
	/// Buttons for the drink selection
	CreateWindowW(L"button", L"Cola | \u20ac2,50",    WS_CHILD | WS_VISIBLE | SS_CENTER, DrinkPosX,        DrinkPosY,       110, 30, H_Window,   (HMENU)CM_DRINK_BUTTON_PRESSED_1, NULL, NULL);
	CreateWindowW(L"button", L"Pepsi | \u20ac2,30",   WS_CHILD | WS_VISIBLE | SS_CENTER, DrinkPosX,        DrinkPosY += 60, 110, 30, H_Window,   (HMENU)CM_DRINK_BUTTON_PRESSED_2, NULL, NULL);
	CreateWindowW(L"button", L"Fanta | \u20ac2,40",   WS_CHILD | WS_VISIBLE | SS_CENTER, DrinkPosX,        DrinkPosY += 60, 110, 30, H_Window,  (HMENU)CM_DRINK_BUTTON_PRESSED_3, NULL, NULL);
	CreateWindowW(L"button", L"Ice Tea | \u20ac2,70", WS_CHILD | WS_VISIBLE | SS_CENTER, DrinkPosX += 120, DrinkPosY =  20, 110, 30, H_Window,  (HMENU)CM_DRINK_BUTTON_PRESSED_4, NULL, NULL);
	CreateWindowW(L"button", L"Sprite | \u20ac2,60",  WS_CHILD | WS_VISIBLE | SS_CENTER, DrinkPosX,        DrinkPosY += 60, 110, 30, H_Window, (HMENU)CM_DRINK_BUTTON_PRESSED_5, NULL, NULL);
	CreateWindowW(L"button", L"SPA | \u20ac2,20",     WS_CHILD | WS_VISIBLE | SS_CENTER, DrinkPosX,        DrinkPosY += 60, 110, 30, H_Window, (HMENU)CM_DRINK_BUTTON_PRESSED_6, NULL, NULL);

	/// Buttons for the Change return
	CreateWindowW(L"button", L"Change | Donate", WS_CHILD | WS_VISIBLE | SS_CENTER, 440, 703, 120, 30, H_Window, (HMENU)CM_CHANGE_BUTTON_PRESSED, NULL, NULL);

	/// Buttons for Entering debit card
	H_DebitCard = CreateWindowW(L"button", L"Enter debitcard", WS_CHILD | WS_VISIBLE | SS_CENTER, 570, 555, 115, 20, H_Window, (HMENU)CM_DEBITCARD_BUTTON_PRESSED, NULL, NULL);

	return 0;
}

int INIT_Static(HWND H_Window, sim_t* pSim)
{
	/// Static for "Display" text buffer
	CreateWindowW(L"static", L"#===============# Welcome by CVM #================#", WS_CHILD | WS_VISIBLE | SS_CENTER, 20, 200, 410, 30, H_Window, NULL, NULL, NULL);
	H_Change_Display = CreateWindowW(L"static", L"Please Enter a coins or pay with you debitcard", WS_CHILD | WS_VISIBLE | SS_CENTER, 20, 220, 410, 70, H_Window, NULL, NULL, NULL);
	CreateWindowW(L"static", L"#=================================================#", WS_CHILD | WS_VISIBLE | SS_CENTER, 20, 300, 410, 30, H_Window, NULL, NULL, NULL);

	/// Static for "Coins" text
	CreateWindowW(L"static", L"# Coins #",  WS_CHILD | WS_VISIBLE | SS_CENTER, 800, 640, 100, 18, H_Window, NULL, NULL, NULL);

	/// Static for "Debug" text
	CreateWindowW(L"static", L" # Debug #",  WS_CHILD | WS_VISIBLE | SS_CENTER | ES_AUTOVSCROLL, 480, 2, 550, 18,   H_Window, NULL, NULL, NULL);

	int MoneyDisplayPosX = 20;
	int MoneyDisplayPosY = 675;
	/// Static for "Cash" text and statics as buffers
	CreateWindowW(L"static", L"Cash",					    WS_CHILD | WS_VISIBLE | SS_LEFT,			 MoneyDisplayPosX, MoneyDisplayPosY, 100, 18,  H_Window, NULL, NULL, NULL);
	H_Change_Cash_Euros = CreateWindowW(L"static", L"0",    WS_CHILD | WS_VISIBLE | SS_LEFT | WS_BORDER, MoneyDisplayPosX += 100, MoneyDisplayPosY, 50, 18, H_Window, NULL, NULL, NULL);
	H_Change_Cash_Cents = CreateWindowW(L"static", L"0",    WS_CHILD | WS_VISIBLE | SS_LEFT | WS_BORDER, MoneyDisplayPosX += 50,  MoneyDisplayPosY, 50, 18, H_Window, NULL, NULL, NULL);
														    						   
	/// Static for "Change" text and statics as buffers			   							
	CreateWindowW(L"static", L"Change",                     WS_CHILD | WS_VISIBLE | SS_LEFT,	         MoneyDisplayPosX = 20, MoneyDisplayPosY += 35, 100, 18,  H_Window, NULL, NULL, NULL);
	H_Change_Change_Euros = CreateWindowW(L"static", L"0",  WS_CHILD | WS_VISIBLE | SS_LEFT | WS_BORDER, MoneyDisplayPosX += 100, MoneyDisplayPosY, 50, 18, H_Window, NULL, NULL, NULL);
	H_Change_Change_Cents = CreateWindowW(L"static", L"0",  WS_CHILD | WS_VISIBLE | SS_LEFT | WS_BORDER, MoneyDisplayPosX += 50,  MoneyDisplayPosY, 50, 18, H_Window, NULL, NULL, NULL);
														    						   
	/// Static for "Wallet" text and statics as buffers			   							
	CreateWindowW(L"static", L"Wallet",                     WS_CHILD | WS_VISIBLE | SS_LEFT,		     MoneyDisplayPosX = 20, MoneyDisplayPosY += 35, 100, 18,  H_Window, NULL, NULL, NULL);
	H_Change_Wallet_Euros = CreateWindowW(L"static", L"0",  WS_CHILD | WS_VISIBLE | SS_LEFT | WS_BORDER, MoneyDisplayPosX += 100, MoneyDisplayPosY, 50, 18, H_Window, NULL, NULL, NULL);
	H_Change_Wallet_Cents = CreateWindowW(L"static", L"0",  WS_CHILD | WS_VISIBLE | SS_LEFT | WS_BORDER, MoneyDisplayPosX += 50,  MoneyDisplayPosY, 50, 18, H_Window, NULL, NULL, NULL);

	/// Static for "Account" text and statics as buffers
	CreateWindowW(L"static", L"Account",					WS_CHILD | WS_VISIBLE | SS_LEFT,			 MoneyDisplayPosX = 20, MoneyDisplayPosY += 35, 100, 18, H_Window, NULL, NULL, NULL);
	H_Change_Account_Euros = CreateWindowW(L"static", L"0", WS_CHILD | WS_VISIBLE | SS_LEFT | WS_BORDER, MoneyDisplayPosX += 100, MoneyDisplayPosY, 50, 18, H_Window, NULL, NULL, NULL);
	H_Change_Account_Cents = CreateWindowW(L"static", L"0", WS_CHILD | WS_VISIBLE | SS_LEFT | WS_BORDER, MoneyDisplayPosX += 50,  MoneyDisplayPosY, 50, 18, H_Window, NULL, NULL, NULL);

	return 0;
}

int INIT_Menu(HWND H_Window)
{
	H_MENU = CreateMenu();

	/// Menu for admin rights
	AppendMenu(H_MENU, MF_STRING, CM_MENU_ITEM_ADMIN, L"Admin");
	AppendMenu(H_MENU, MF_STRING, CM_MENU_ITEM_AUTHOR, L"About");
	SetMenu(H_Window, H_MENU);

	return 0;
}

int INIT_Edit(HWND H_Window)
{
	/// Edit for the debug messsages also enabling and showing the scrollbar
	H_Change_Debug = CreateWindowW(L"edit", NULL, WS_CHILD | ES_MULTILINE | ES_WANTRETURN | WS_VISIBLE | WS_BORDER | SS_LEFT | ES_MULTILINE | ES_READONLY | ES_AUTOVSCROLL | SB_RIGHT, 480, 20, 550, 525, H_Window, NULL, NULL, NULL);
	EnableScrollBar(H_Change_Debug, SB_VERT, ESB_ENABLE_BOTH);
	ShowScrollBar(H_Change_Debug, SB_VERT, TRUE);
	return 0;
}
