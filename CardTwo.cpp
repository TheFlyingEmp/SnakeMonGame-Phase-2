#include"CardTwo.h"

CardTwo::CardTwo(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number (2 here)
}

CardTwo::~CardTwo(void)
{
}
void CardTwo::ReadCardParameters(Grid* pGrid)
{

	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("New CardTwo: Enter its wallet amount ...");

	walletAmount = pIn->GetInteger(pOut);

	while (!(walletAmount > 0))
	{
		pGrid->PrintErrorMessage("Inavlid Wallet Amount.please try again.....");
		walletAmount = pIn->GetInteger(pOut);
	}



	
	pOut->ClearStatusBar();
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pPlayer->SetWallet(pPlayer->GetWallet() - walletAmount);
}

void CardTwo::Save(ofstream& OutFile)
{
	OutFile << cardNumber << " " << position.GetCellNum() << endl;
}

void CardTwo::Load(ifstream& InFile)
{
}