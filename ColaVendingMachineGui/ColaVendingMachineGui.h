#ifndef COLAVENDINGMACHINEGUI_H
#define COLAVENDINGMACHINEGUI_H

#define BUFFSIZE 100

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

#include "Initialization.h"
#include "CoinHandelingProcedure.h"
#include "UserDrinkSelection.h"
#include "WriteToScreenBuffer.h"

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);



//! The CoMmand(CM_) Enum
enum {
    CM_MENU_ITEM_ADMIN,
    CM_COIN_BUTTON_PRESSED_1, CM_PIN_BUTTON_PRESSED_0, CM_DRINK_BUTTON_PRESSED_1,
    CM_COIN_BUTTON_PRESSED_2, CM_PIN_BUTTON_PRESSED_1, CM_DRINK_BUTTON_PRESSED_2,
    CM_COIN_BUTTON_PRESSED_3, CM_PIN_BUTTON_PRESSED_2, CM_DRINK_BUTTON_PRESSED_3,
    CM_COIN_BUTTON_PRESSED_4, CM_PIN_BUTTON_PRESSED_3, CM_DRINK_BUTTON_PRESSED_4,
    CM_COIN_BUTTON_PRESSED_5, CM_PIN_BUTTON_PRESSED_4, CM_DRINK_BUTTON_PRESSED_5,
    CM_COIN_BUTTON_PRESSED_6, CM_PIN_BUTTON_PRESSED_5, CM_DRINK_BUTTON_PRESSED_6,
    CM_COIN_BUTTON_PRESSED_7, CM_PIN_BUTTON_PRESSED_6,
    CM_COIN_BUTTON_PRESSED_8, CM_PIN_BUTTON_PRESSED_7,
    CM_COIN_BUTTON_PRESSED_9, CM_PIN_BUTTON_PRESSED_8,
    CM_COIN_BUTTON_PRESSED_10, CM_PIN_BUTTON_PRESSED_9,
    CM_COIN_BUTTON_PRESSED_11,
    CM_COIN_BUTTON_PRESSED_12
};
//! The Value(V_) Enum
enum {
    V_1_CENTS = 1, V_2_CENTS, V_5_CENTS = 5, V_10_CENTS = 10, V_20_CENTS = 20, V_50_CENTS = 50,
    V_1_EUR = 100, V_2_EUR = 200, V_5_EUR = 500, V_10_EUR = 1000, V_20_EUR = 2000, V_50_EUR = 5000
};

enum {
    D_COLA = 10000, D_PEPSI, D_FANTA, D_ICE_TEA, D_SPRITE, D_SPA
};

//?-------------------------------------WINDOWS HANDLERS--------------------------------------?//
HMENU H_MENU;

HWND H_Change_Cash_Euros, H_Change_Cash_Cents, H_Change_Change_Euros, H_Change_Change_Cents, H_Change_Wallet_Euros, H_Change_Wallet_Cents,
H_Cola_Image, H_Change_Debug, H_Card;

HBITMAP HBIT_Cola;

HDC hdcStatic;

PAINTSTRUCT ps;

static HBRUSH hb;
//?-------------------------------------------------------------------------------------------?//


#endif // !COLAVENDINGMACHINEGUI_H
