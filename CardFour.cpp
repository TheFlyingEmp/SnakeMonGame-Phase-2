#include "CardFour.h"
#include "Snake.h"

CardFour::CardFour(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4; // set the inherited cardNumber data member with the card number (1 here)
}

CardFour::~CardFour()
{
}
void CardFour::ReadCardParameters(Grid* pGrid)
{
}
void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	Snake* pSnake = pGrid->GetNextSnake(position); // note: "position" here is the position of CARD and we are making a pointer that points to
	//the starting position of SNAKE
	if (pSnake == nullptr)
		return;
	else
	pGrid->UpdatePlayerCell(pPlayer, pSnake->GetStartPosition());
}

void CardFour::Save(ofstream& OutFile)
{
	OutFile << cardNumber << " " << position.GetCellNum() << endl;
}

void CardFour::Load(ifstream& InFile)
{
}