#include "UserDrinkSelection.h"
#include "ColaVendingMachineGui.h"

void UDS_Setup(int D_Name, drink_t* pDrink)
{
	/// Sets the right varables depending on which button you pressed
	switch (D_Name) {
	case D_COLA:
		wcscpy_s(pDrink->drinkName, BUFFSIZE, L"Cola");
		pDrink->priceTotaalCents = 250;
		break;
	case D_PEPSI:
		wcscpy_s(pDrink->drinkName, BUFFSIZE, L"Pepsi");
		pDrink->priceTotaalCents = 230;
		break;
	case D_FANTA:
		wcscpy_s(pDrink->drinkName, BUFFSIZE, L"Fanta");
		pDrink->priceTotaalCents = 240;
		break;
	case D_ICE_TEA:
		wcscpy_s(pDrink->drinkName, BUFFSIZE, L"Ice Tea");
		pDrink->priceTotaalCents = 270;
		break;
	case D_SPRITE:
		wcscpy_s(pDrink->drinkName, BUFFSIZE, L"Sprite");
		pDrink->priceTotaalCents = 260;
		break;
	case D_SPA:
		wcscpy_s(pDrink->drinkName, BUFFSIZE, L"Spa");
		pDrink->priceTotaalCents = 220;
		break;
	}
}