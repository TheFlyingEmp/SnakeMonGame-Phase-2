#include "Snake.h"

Snake::Snake(const CellPosition& StartCellPos, const CellPosition& EndCellPos) : GameObject(StartCellPos)
{
	this->EndCellPos = EndCellPos;

	///TODO: Do the needed validation
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, EndCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{
	pGrid->PrintErrorMessage("You have reached a Snake. Click to continue ...");
	pGrid->UpdatePlayerCell(pPlayer, EndCellPos);
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a Snake. Click to continue ..." and wait mouse click

	// 2- Apply the Snake's effect by moving the player to the StartCellPos
	//    Review the "pGrid" functions and decide which function can be used for that

}


void Snake::Save(ofstream& OutFile)
{
	OutFile << EndCellPos.GetCellNum() << " " << position.GetCellNum() << endl; // prints the start and end positions in the file
}

void Snake::Load(ifstream& InFile)
{
	return;
}

CellPosition Snake::GetEndPosition() const
{
	return EndCellPos;
}

Snake::~Snake()
{
}
