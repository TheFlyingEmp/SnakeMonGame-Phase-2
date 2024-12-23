#include "CardFour.h"
#include "Snake.h"

CardFour::CardFour(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4; // set the inherited cardNumber data member with the card number (1 here)
}

CardFour::~CardFour(void)
{
}
void CardFour::ReadCardParameters(Grid* pGrid)
{
}
void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);

	Snake* pSnake = pGrid->GetNextSnake(position); // note: "position" here is the position of CARD and we are making a pointer that points to
													//the starting position of SNAKE
	if (pSnake == nullptr)
		return;
	else
	{
		pPlayer->Move(pGrid, CellPosition::GetCellNumFromPosition(pSnake->GetPosition()) - pPlayer->GetjustRolledDiceNum() - 1);
		pPlayer->SetTurncount(pPlayer->GetTurnCount() - 1);
	}
}

void CardFour::Save(ofstream& OutFile)
{
	OutFile << cardNumber << " " << position.GetCellNum() << endl;
}

void CardFour::Load(ifstream& InFile)
{
}