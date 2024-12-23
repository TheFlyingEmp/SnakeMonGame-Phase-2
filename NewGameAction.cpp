#include "NewGameAction.h"
#include "Player.h"
#include "Grid.h"

NewGameAction::NewGameAction(ApplicationManager* pApp) : Action(pApp)
{

}
NewGameAction::~NewGameAction()
{
}


void NewGameAction::ReadActionParameters()
{
	// no parameters to read from user
}

void NewGameAction::Execute()
{
	
	int vcell = 8;
	int hcell = 0;
	CellPosition StartingPosition;     //this is the starting position of all players
	StartingPosition.SetVCell(vcell);  //initializes the vcell of starting position
	StartingPosition.SetHCell(hcell);  //initializes the hcell of starting position
	Player* pPlayer[MaxPlayerCount];  //an array of players
	SetofOwnedCards CardOwned = Does_Not_Own; //Set CardOwned enum to Does_Not_Own
	
		
	Grid* pGrid = pManager->GetGrid();
	for (int i = 0; i < MaxPlayerCount; i++) //looping on every player
	{
	  pPlayer[i] = pGrid->GetCurrentPlayer();
	  pGrid->UpdatePlayerCell(pPlayer[i], StartingPosition); //move each player to starting position
	  pPlayer[i]->SetWallet(100); //resets player wallet to 100
	  pPlayer[i]->SetTurncount(0);  //resets turncount to 0
	  pGrid->AdvanceCurrentPlayer(); 
	  for (int j = 0; j < 4; j++)
	  {
		  pPlayer[i]->SetCardOwned(j, CardOwned);  //make the cards owned of each player to not owning anything
	  }
	}
	pGrid->SetCurrentPlayer(0);  //resets the turn of players to player 0


	pGrid->UpdateInterface();
	
		
		
}