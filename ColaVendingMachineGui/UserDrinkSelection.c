#include "UserDrinkSelection.h"
#include "ColaVendingMachineGui.h"


void UDS_Price(drink_t* pDrink, int priceEuros, int priceCents)
{
	pDrink->priceInEuros = priceEuros;
	pDrink->priceInCents = priceCents;

}

void UDS_Drink(drink_t* pDrink, wchar_t whichDrink[])
{
	wcscpy_s(pDrink->drinkName, BUFF, whichDrink);
}

void UDS_Setup(int D_Name, drink_t* pDrink)
{
	

	switch (D_Name) {
	case D_COLA:
		UDS_Drink(pDrink, L"Cola");
		UDS_Price(pDrink, 2, 50);
		break;
	case D_PEPSI:
		UDS_Drink(pDrink, L"Pepsi");
		UDS_Price(pDrink, 2, 30);
		break;
	case D_FANTA:
		UDS_Drink(pDrink, L"Fanta");
		UDS_Price(pDrink, 2, 40);
		break;
	case D_ICE_TEA:
		UDS_Drink(pDrink, L"Ice Tea");
		UDS_Price(pDrink, 2, 70);
		break;
	case D_SPRITE:
		UDS_Drink(pDrink, L"Sprite");
		UDS_Price(pDrink, 2, 60);
		break;
	case D_SPA:
		UDS_Drink(pDrink, L"Spa");
		UDS_Price(pDrink, 2, 20);
		break;
	}
}