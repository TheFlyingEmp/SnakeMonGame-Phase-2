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

	pOut->PrintMessage("Please, input the Card's Price...");

	CardPrice = pIn->GetInteger(pOut);

	pOut->PrintMessage("Please, input the Fees to Pay when passing the Card...");

	FeestoPay = pIn->GetInteger(pOut);
}

void CardTen::Apply(Grid* pGrid, Player* pPlayer)
{
	char answer;
	int EF = 0, i = 0;
	bool isbought = false;
	bool PlayerHasCard = false;

	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
<<<<<<< HEAD
	Cell* CellPlayerisOn = pPlayer->GetCell();
=======
>>>>>>> 4897b028f2cd117db7bf6b02f7f799ccb08e6643

	Card::Apply(pGrid, pPlayer);

	if (IsBought == false) {
		do {
			if (EF > 0)
<<<<<<< HEAD
				pGrid->PrintErrorMessage("Please input an appropriate value...");
=======
				pGrid->PrintErrorMessage("Please, input an appropriate value...");
>>>>>>> aa565882f47340f3e6d0f75c2107432b43395c95

			pOut->PrintMessage("Do you want to buy this card and all other cards of corresponding number? (y/n) Card Price: " + to_string(CardPrice) + " Fees that other players will pay: " + to_string(FeestoPay));
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

<<<<<<< HEAD
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
=======
	i = 0;
	do {
		if (pPlayer->GetCardsOwned(i) == Card_10) {
			PlayerHasCard = true;
			break;
>>>>>>> 4897b028f2cd117db7bf6b02f7f799ccb08e6643
		}
		i++;
	} while (i < 4);

	if (PlayerHasCard != true) {
      
		pGrid->PrintErrorMessage("The card is owned by player: " + to_string(pPlayer->GetPlayerNum()));
		pGrid->PrintErrorMessage(to_string(FeestoPay) + " will be deducted from your wallet");
		pPlayer->SetWallet(pPlayer->GetWallet() - FeestoPay);
      
	}
}

void CardTen::Save(ofstream& OutFile)
{
	OutFile << cardNumber << " " << position.GetCellNum() << " " << CardPrice << " " << FeestoPay << endl;
}

void CardTen::Load(ifstream& InFile)
{
	InFile >> CardPrice >> FeestoPay;
}

