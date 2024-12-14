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

void CardTen::Apply(Grid* pGrid, Player* pPlayer)
{
	char answer;
	int EF = 0;

	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	do {
		if (EF > 0)
			pGrid->PrintErrorMessage("Please an appropriate value...");

		pGrid->PrintErrorMessage("Do you want to buy this card and all other cards of corresponding number? (y/n) Card Price: " + to_string(CardPrice) + " Fees that other players will pay: " + to_string(FeestoPay));
		answer = pIn->GetString(pOut);
		answer = tolower(answer);
		EF++
	} while (!(answer == 'y' || answer == 'n'));

	if (answer == 'y') {
		pPlayer->SetWallet(pPlayer->GetWallet() - CardPrice);

	}
	else return;
}