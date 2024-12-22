#include "CardEight.h"

using namespace std;

CardEight::CardEight(const CellPosition& pos) : Card(pos)
{
	cardNumber = 8;
}

void CardEight::ReadCardParameters(Grid* pGrid)
{

}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pPlayer->SetExtraDiceRolls(-1);
}