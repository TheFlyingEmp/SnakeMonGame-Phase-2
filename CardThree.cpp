#include "CardThree.h"
#include "Ladder.h"

CardThree::CardThree(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3; // set the inherited cardNumber data member with the card number (1 here)
}

CardThree::~CardThree()
{
}
void CardThree::ReadCardParameters(Grid* pGrid)
{
}
void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	Ladder* pLadder = pGrid->GetNextLadder(position); // note: "position" here is the position of CARD and we are making a pointer that points to
	//the position of LADDER
	if (pLadder == nullptr)
		return;
	else
		pGrid->UpdatePlayerCell(pPlayer, pLadder->GetPosition());
}

void CardThree::Save(ofstream& OutFile)
{
	OutFile << cardNumber << " " << position.GetCellNum() << endl;
}

void CardThree::Load(ifstream& InFile)
{
}