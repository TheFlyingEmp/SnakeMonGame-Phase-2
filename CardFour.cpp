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
<<<<<<< HEAD
	/*Snake* pSnake = pGrid->GetNextSnake(position); // note: "position" here is the position of CARD and we are making a pointer that points to
=======
	Snake* pSnake = pGrid->GetNextSnake(position); // note: "position" here is the position of CARD and we are making a pointer that points to
>>>>>>> 4897b028f2cd117db7bf6b02f7f799ccb08e6643
	//the starting position of SNAKE
	if (pSnake == nullptr)
		return;
	else
	pGrid->UpdatePlayerCell(pPlayer, pSnake->GetStartPosition());
<<<<<<< HEAD
	*/
}

void CardFour::Save(ofstream& OutFile)
{
	OutFile << cardNumber << " " << position.GetCellNum() << endl;
}

void CardFour::Load(ifstream& InFile)
{
=======

>>>>>>> 4897b028f2cd117db7bf6b02f7f799ccb08e6643
}