#include "UserDrinkSelection.h"
#include "ColaVendingMachineGui.h"


void UDS_Price(drink_t* pDrink, int priceTotaal)
{
	pDrink->priceTotaalCents = priceTotaal;
	while (priceTotaal >= 100)
	{
		priceTotaal -= 100;
		pDrink->priceInEuros++;
	}
	pDrink->priceInCents = priceTotaal;

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
		UDS_Price(pDrink, 250);
		break;
	case D_PEPSI:
		UDS_Drink(pDrink, L"Pepsi");
		UDS_Price(pDrink, 230);
		break;
	case D_FANTA:
		UDS_Drink(pDrink, L"Fanta");
		UDS_Price(pDrink, 240);
		break;
	case D_ICE_TEA:
		UDS_Drink(pDrink, L"Ice Tea");
		UDS_Price(pDrink, 270);
		break;
	case D_SPRITE:
		UDS_Drink(pDrink, L"Sprite");
		UDS_Price(pDrink, 260);
		break;
	case D_SPA:
		UDS_Drink(pDrink, L"Spa");
		UDS_Price(pDrink, 220);
		break;
	}
}