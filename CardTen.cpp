#include "CardTen.h"

bool CardTen::IsBought = false;
bool CardTen::PlayerHasCard = false;

CardTen::CardTen(const CellPosition& pos) : Card(pos) {
	cardNumber = 10;
}

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
	int EF = 0, i = 0;

	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	Cell* CellPlayerisOn = pPlayer->GetCell();

	Card::Apply(pGrid, pPlayer);

	if (IsBought == false) {
		do {
			if (EF > 0)
				pGrid->PrintErrorMessage("Please input an appropriate value...");

			pGrid->PrintErrorMessage("Do you want to buy this card and all other cards of corresponding number? (y/n) Card Price: " + to_string(CardPrice) + " Fees that other players will pay: " + to_string(FeestoPay));
			string TempStringHolder = pIn->GetString(pOut);
			answer = TempStringHolder[0];
			answer = tolower(answer);
			EF++;
		} while (!(answer == 'y' || answer == 'n'));

		if (answer == 'y') {
			pPlayer->SetWallet(pPlayer->GetWallet() - CardPrice);
			IsBought = true;
			i = 0;
			do {
				if (pPlayer->GetCardsOwned(i) == NULL) {
					pPlayer->SetCardOwned(i, Card_10);
					break;
				}
				i++;
			} while (i < 4);
		}
		else return;
	}

	if (CellPlayerisOn->GetCellPosition() == position) {

		i = 0;
		do {
			if (pPlayer->GetCardsOwned(i) == Card_10) {
				PlayerHasCard = true;
				break;
			}
			i++;
		} while (i < 4);

		if (PlayerHasCard != true) {
      
			pGrid->PrintErrorMessage("The card is owned by player: " + to_string(pPlayer->GetPlayerNum()));
			pGrid->PrintErrorMessage(to_string(FeestoPay) + " will be deducted from your wallet");
			pPlayer->SetWallet(pPlayer->GetWallet() - FeestoPay);
		}
	}
}