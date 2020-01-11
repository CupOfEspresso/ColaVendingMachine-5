#ifndef COLAVENDINGMACHINEGUI_H
#define COLAVENDINGMACHINEGUI_H

#define BUFFSIZE 128

#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "Initialization.h"
#include "CoinHandelingProcedure.h"
#include "UserDrinkSelection.h"
#include "WriteToScreenBuffer.h"
#include "PayWithDebitCard.h"
#include "WriteToDisplayBuffers.h"
#include "resource.h"

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

//! The eumeration of all the commands 
enum {
    CM_MENU_ITEM_ADMIN,
    CM_COIN_BUTTON_PRESSED_1, CM_PIN_BUTTON_PRESSED_0, CM_DRINK_BUTTON_PRESSED_1, CM_CHANGE_BUTTON_PRESSED,
    CM_COIN_BUTTON_PRESSED_2, CM_PIN_BUTTON_PRESSED_1, CM_DRINK_BUTTON_PRESSED_2, CM_DEBITCARD_BUTTON_PRESSED,
    CM_COIN_BUTTON_PRESSED_3, CM_PIN_BUTTON_PRESSED_2, CM_DRINK_BUTTON_PRESSED_3, CM_MENU_ITEM_AUTHOR,
    CM_COIN_BUTTON_PRESSED_4, CM_PIN_BUTTON_PRESSED_3, CM_DRINK_BUTTON_PRESSED_4,
    CM_COIN_BUTTON_PRESSED_5, CM_PIN_BUTTON_PRESSED_4, CM_DRINK_BUTTON_PRESSED_5,
    CM_COIN_BUTTON_PRESSED_6, CM_PIN_BUTTON_PRESSED_5, CM_DRINK_BUTTON_PRESSED_6,
    CM_COIN_BUTTON_PRESSED_7, CM_PIN_BUTTON_PRESSED_6,
    CM_COIN_BUTTON_PRESSED_8, CM_PIN_BUTTON_PRESSED_7,
    CM_COIN_BUTTON_PRESSED_9, CM_PIN_BUTTON_PRESSED_8,
    CM_COIN_BUTTON_PRESSED_10, CM_PIN_BUTTON_PRESSED_9,
    CM_COIN_BUTTON_PRESSED_11, CM_PIN_BUTTON_PRESSED_OK,
    CM_COIN_BUTTON_PRESSED_12, CM_PIN_BUTTON_PRESSED_DEL,
};

//! The eumeration of all the drinks

enum {
    D_COLA, D_PEPSI, D_FANTA, D_ICE_TEA, D_SPRITE, D_SPA
};

//WINDOWS HANDLERS
HMENU           H_MENU;
HWND            H_Change_Cash, H_Change_Change, H_Change_Wallet, H_Change_Account, H_Change_Debug, H_DebitCard, H_Change_Display;
PAINTSTRUCT     ps;
static HBRUSH   hb;

#endif // !COLAVENDINGMACHINEGUI_H
