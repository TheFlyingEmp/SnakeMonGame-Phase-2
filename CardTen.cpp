#include "CardTen.h"

void CardTen::ReadCardParameters(Grid* pGrid)
{
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pGrid->PrintErrorMessage("Please, input the Card's Price...");

	CardPrice = pIn->GetInteger(pOut);

	pGrid->PrintErrorMessage("Please, input the Fees to Pay when passing the Card...");

	FeestoPay = pIn->GetInteger(pOut);
}

