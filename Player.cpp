#include "Player.h"

#include "GameObject.h"

Player::Player(Cell* pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	this->ExtraDiceRolls = 0;
	this->onFire = 0;
	this->poisoned = 0;
	this->specialAttaksLeft = 2;

	for (int i = 0; i < 4; i++) {
		CardsOwned[i] = Does_Not_Own;
	}

	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell* cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

int Player::GetPlayerNum() const
{
	return playerNum;
}

void Player::SetWallet(int wallet)
{
	if (wallet < 0)
		wallet = 0;
	else
	this->wallet = wallet;
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

void Player::SetTurncount(int turncount)
{
	turnCount = turncount;
}
int Player::GetTurnCount() const
{
	return turnCount;
}

SetofOwnedCards Player::GetCardsOwned(int i) const
{
	if (i >= 0 && i <= 3)
		return CardsOwned[i];
}

void Player::SetCardOwned(int i, SetofOwnedCards Card)
{
	if (i >= 0 && i <= 3)
		CardsOwned[i] = Card;
}

int Player::GetjustRolledDiceNum() const
{
	return justRolledDiceNum;
}

void Player::SetjustRolledDiceNum(int d)
{
	justRolledDiceNum = d;
}

int Player::GetExtraDiceRolls() const
{
	return ExtraDiceRolls;
}

void Player::SetExtraDiceRolls(int e)
{
	ExtraDiceRolls = e;
}

int Player::GetPoisoned() const
{
	return poisoned;
}

void Player::SetPosisond(int p)
{
	poisoned = p;
}

int Player::GetOnFire() const
{
	return onFire;
}

void Player::SetOnFire(int f)
{
	onFire = f;
}

int Player::GetSpecialAttaksLeft() const
{
	return specialAttaksLeft;
}

void Player::SetSpecialAttacksLeft(int s)
{
	specialAttaksLeft = s;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];

	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);

	///TODO: use the appropriate output function to draw the player with "playerColor"

}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);
	
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)

}

// ====== Game Functions ======

void Player::Move(Grid* pGrid, int diceNumber)
{



	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==



	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	
	turnCount = (turnCount + 1) % 3;

	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)

	if (ExtraDiceRolls < 0)
		{
			ExtraDiceRolls++;
			diceNumber = 0;
		}
	if (!turnCount)
	{
		SetWallet(GetWallet() + 10 * diceNumber);

		return;
	}

	if (wallet == 0)
	{
		return;
	}

	
	// 3- Set the justRolledDiceNum with the passed diceNumber

	SetjustRolledDiceNum(diceNumber);

	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"

	CellPosition pos = pCell->GetCellPosition(); // Gets the cell position by using the cell class 
										//to get a cellposition then addind diceNum to it 

	pos.AddCellNum(diceNumber);

	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position

	pGrid->UpdatePlayerCell(this, pos);

	// 6- Apply() the game object of the reached cell (if any)

	GameObject* cellObject = pCell->GetGameObject();

	if (cellObject != NULL)
	{
		cellObject->Apply(pGrid, this);
	}

	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)

	if (pos.GetCellNum() >= 99)
	{
		pos = pCell->GetCellPosition().GetCellPositionFromNum(99);
		pGrid->SetEndGame(true);
	}

	
}

void Player::AppendPlayerInfo(string& playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(";
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}