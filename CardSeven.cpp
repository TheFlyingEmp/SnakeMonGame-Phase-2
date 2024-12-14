#include "CardSeven.h"

CardSeven::CardSeven(const CellPosition& pos) : Card(pos) {
	cardNumber = 7;
}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	ApplicationManager CardAppManage = ApplicationManager();
	CardAppManage.ExecuteAction(ROLL_DICE);
}