#include "Snake.h"

Snake::Snake(const CellPosition& StartCellPos, const CellPosition& endCellPos) : GameObject(endCellPos)
{
	this->StartCellPos = StartCellPos;

	///TODO: Do the needed validation
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, StartCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{
	pGrid->PrintErrorMessage("You have reached a Snake. Click to continue ...");
	pGrid->UpdatePlayerCell(pPlayer, StartCellPos);
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a Snake. Click to continue ..." and wait mouse click

	// 2- Apply the Snake's effect by moving the player to the StartCellPos
	//    Review the "pGrid" functions and decide which function can be used for that

}

CellPosition Snake::GetStartPosition() const
{
	return StartCellPos;
}

void Snake::Save(ofstream& OutFile)
{
	OutFile << StartCellPos.GetCellNum() << " " << position.GetCellNum() << endl; // prints the start and end positions in the file
}

void Snake::Load(ifstream& InFile)
{
	return;
}

Snake::~Snake()
{
}
