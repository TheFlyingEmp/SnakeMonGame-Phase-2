#include "CardEight.h"

using namespace std;

CardEight::CardEight(const CellPosition& pos) : Card(pos)
{
}

void CardEight::ReadCardParameters(Grid* pGrid)
{

}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
<<<<<<< HEAD
  Card::Apply(pGrid, pPlayer);
  
=======
	Card::Apply(pGrid, pPlayer);
>>>>>>> 4897b028f2cd117db7bf6b02f7f799ccb08e6643
	pPlayer->SetExtraDiceRolls(-1);
}

void CardEight::Save(ofstream& OutFile)
{
	OutFile << cardNumber << " " << position.GetCellNum() << endl;
}

void CardEight::Load(ifstream& InFile)
{
}
