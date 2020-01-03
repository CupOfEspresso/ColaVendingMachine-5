#include "UserDrinkSelection.h"
#include "ColaVendingMachineGui.h"


drink_t UDS_Price(drink_t drinks, int priceEuro, int priceCents)
{
	drinks.priceInEuros = priceEuro;
	drinks.priceInCents = priceEuro;
	return drinks;
}

drink_t UDS_Drink(drink_t drinks, wchar_t whichDrink[])
{
	int sizeWcs = wcslen(whichDrink);
	wcscpy_s(drinks.drinkName, sizeWcs, whichDrink);
	return drinks;
}

drink_t UDS_Setup(int D_Name)
{
	drink_t drinks = { NULL };
	switch (D_Name) {
	case D_COLA:
		drinks = UDS_Drink(drinks, L"Cola");
		drinks = UDS_Price(drinks, 2, 50);
		break;
	case D_PEPSI:
		drinks = UDS_Drink(drinks, L"Pepsi");
		drinks = UDS_Price(drinks, 2, 30);
		break;
	case D_FANTA:
		drinks = UDS_Drink(drinks, L"Fanta");
		drinks = UDS_Price(drinks, 2, 40);
		break;
	case D_ICE_TEA:
		drinks = UDS_Drink(drinks, L"Ice Tea");
		drinks = UDS_Price(drinks, 2, 70);
		break;
	case D_SPRITE:
		drinks = UDS_Drink(drinks, L"Sprite");
		drinks = UDS_Price(drinks, 2, 60);
		break;
	case D_SPA:
		drinks = UDS_Drink(drinks, L"Spa");
		drinks = UDS_Price(drinks, 2, 20);
		break;
	}

	return drinks;
}