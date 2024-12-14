#include "CardSeven.h"

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	ApplicationManager CardAppManage = ApplicationManager();
	CardAppManage.ExecuteAction(ROLL_DICE);
}