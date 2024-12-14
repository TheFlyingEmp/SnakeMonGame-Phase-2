#include "CardSeven.h"

CardSeven::CardSeven(const CellPosition& pos) : Card(pos) {
	cardNumber = 7;
}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);

	pGrid->PrintErrorMessage("Player " + to_string(pPlayer->GetPlayerNum()) + " will roll the dice again");

	ApplicationManager CardAppManage = ApplicationManager();
	CardAppManage.ExecuteAction(ROLL_DICE);
}