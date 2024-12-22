#include "Grid.h"

#include "Cell.h"
#include "GameObject.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
<<<<<<< HEAD
#include "Snake.h"
=======
#include "ToPlayMode.h"
>>>>>>> 4897b028f2cd117db7bf6b02f7f799ccb08e6643
#include "Player.h"
#include <fstream>


Grid::Grid(Input * pIn, Output * pOut) : pIn(pIn), pOut(pOut) // Initializing pIn, pOut
{
	// Allocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			CellList[i][j] = new Cell(i, j);
		}
	}

	// Allocate thePlayer Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		PlayerList[i] = new Player(CellList[NumVerticalCells-1][0], i); // first cell
		PlayerList[i]->Draw(pOut); // initially draw players in the first cell
	}

	// Initialize currPlayerNumber with 0 (first player)
	currPlayerNumber = 0; // start with the first player

	// Initialize Clipboard with NULL
	Clipboard = NULL;

	// Initialize endGame with false
	endGame = false;
}


// ========= Adding or Removing GameObjects to Cells =========


bool Grid::AddObjectToCell(GameObject * pNewObject)  // think if any validation is needed
{
	// Get the cell position of pNewObject
	CellPosition pos = pNewObject->GetPosition();
	if (pos.IsValidCell()) // Check if valid position
	{
		// Get the previous GameObject of the Cell
		GameObject * pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if( pPrevObject)  // the cell already contains a game object
			return false; // do NOT add and return false

		// Set the game object of the Cell with the new game object
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(pNewObject);
		return true; // indicating that addition is done
	}
	return false; // if not a valid position
}

bool Grid::HasGameObject(const CellPosition &cellpositon)
{
	if (cellpositon.IsValidCell())
	{
		GameObject* pPrevObject = CellList[cellpositon.VCell()][cellpositon.HCell()]->GetGameObject();
		if (pPrevObject)
			return true;
		else
			return false;
		
	}
	return false;
}

GameObject* Grid::GetGameObjectfromCell(const CellPosition& cellpositon)
{
	return CellList[cellpositon.VCell()][cellpositon.HCell()]->GetGameObject();
}

bool Grid::HasCardObject(const CellPosition& pos)
{
	if (pos.IsValidCell())
	{
		GameObject* pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if (pPrevObject)
			if (CellList[pos.VCell()][pos.HCell()]->HasCard())
				return true;
			else
				return false;
		else
			return false;

	}
	return false;
}

GameObject* Grid::GetGameObjectFromCellList(const CellPosition& pos) const
{
	return CellList[pos.VCell()][pos.HCell()]->GetGameObject();
}

void Grid::RemoveObjectFromCell(const CellPosition & pos)
{
	if (pos.IsValidCell()) // Check if valid position
	{
		GameObject* pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		pPrevObject = NULL;
		if (CellList[pos.VCell()][pos.HCell()]->SetGameObject(pPrevObject));
	}

		// Note: you can deallocate the object here before setting the pointer to null if it is needed

		
}

void Grid::UpdatePlayerCell(Player * player, const CellPosition & newPosition)
{
	// Clear the player's circle from the old cell position
	player->ClearDrawing(pOut);

	// Set the player's CELL with the new position
	Cell * newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);	

	// Draw the player's circle on the new cell position
	player->Draw(pOut);
}


// ========= Setters and Getters Functions =========


Input * Grid::GetInput() const
{
	return pIn;
}

Output * Grid::GetOutput() const
{
	return pOut;
}

void Grid::SetClipboard(Card * pCard) // to be used in copy/cut
{
	// you may update slightly in implementation if you want (but without breaking responsibilities)
	Clipboard = pCard;
}

Card * Grid::GetClipboard() const // to be used in paste
{
	return Clipboard;
}

void Grid::SetEndGame(bool endGame)
{
	this->endGame = endGame;
}

bool Grid::GetEndGame() const
{
	return endGame;
}

void Grid::AdvanceCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber + 1) % MaxPlayerCount; // this generates value from 0 to MaxPlayerCount - 1
}

Cell * Grid::GetCellFromPosition(const CellPosition& pos)
{
	for (int i = 0; i < NumVerticalCells; i++)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (CellList[i][j]->GetCellPosition() == pos)
			{
				return CellList[i][j];
			}
		}
	}
	return nullptr;
}

void Grid::SetCurrentPlayer(int current_player)
{
	this->currPlayerNumber = current_player;
}

// ========= Other Getters =========


Player * Grid::GetCurrentPlayer() const
{
	return PlayerList[currPlayerNumber];
}

Ladder * Grid::GetNextLadder(const CellPosition & position)
{
	
	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{
			if (CellList[i][j]->HasLadder())
				return CellList[i][j]->HasLadder();
		

			///TODO: Check if CellList[i][j] has a ladder, if yes return it
			

		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}
Snake* Grid::GetNextSnake(const CellPosition& position)
{

	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{

			if (CellList[i][j]->HasSnake())
				return CellList[i][j]->HasSnake();
			///TODO: Check if CellList[i][j] has a Snake, if yes return it


		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}



/*Snake* Grid::GetNextSnake(const CellPosition& position)
{
	return nullptr;
}*/


// ========= User Interface Functions =========


void Grid::UpdateInterface() const
{
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// 1- Draw cells with or without cards 
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCellOrCard(pOut);
			}
		}

		// 2- Draw other cell objects (ladders, snakes)
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawLadderOrSnake(pOut);
			}
		}

		// 3- Draw players
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
	else // In PLAY Mode
	{
		// 1- Print Player's Info
		string playersInfo = "";
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->AppendPlayerInfo(playersInfo); // passed by reference
			if (i < MaxPlayerCount-1) // except the last player
				playersInfo += ", ";
		}
		playersInfo += " | Curr = " + to_string(currPlayerNumber);

		pOut->PrintPlayersInfo(playersInfo);
		

		// Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
		//       so we do NOT need draw all players again in UpdateInterface() of the Play mode
		// In addition, cards/snakes/ladders do NOT change positions in Play Mode, so need to draw them here too
			// 1- Draw cells with or without cards 
		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCellOrCard(pOut);
			}
		}

		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawLadderOrSnake(pOut);
			}
		}
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
}

void Grid::PrintErrorMessage(string msg)
{
	pOut->PrintMessage(msg);
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}


void Grid::SaveGrid(ofstream& OutFile, string fileName)
{
	OutFile.open(fileName, ios::app);
	int ladderNum, snakeNum, cardNum;
	ladderNum = snakeNum = cardNum = 0;
	for (int i = 0; i < NumVerticalCells; i++)
	{
		for (int j = 0; j < NumVerticalCells; i++)
		{
			if (!CellList[i][j]->HasLadder())
			{
				ladderNum++;
			}

			if (!CellList[i][j]->HasSnake())
			{
				snakeNum++;
			}

			if (!CellList[i][j]->HasCard())
			{
				cardNum++;
			}
		}
	}

	OutFile << ladderNum << endl;

	for (int i = 0; i < NumHorizontalCells; i++)
	{
		for (int j = 0; j < NumVerticalCells; j++)
		{
			if (CellList[i][j]->HasLadder())
			{
				CellList[i][j]->HasLadder()->Save(OutFile);
			}
		}
	}

	/*OutFile << snakeNum << endl;

	for (int i = 0; i < NumHorizontalCells; i++)
	{
		for (int j = 0; j < NumVerticalCells; j++)
		{
			if (CellList[i][j]->HasSnake())
			{
				CellList[i][j]->HasSnake()->Save(OutFile);
			}
		}
	}*/ //wating for the snake class

	/*OutFile << cardNum << endl;

	for (int i = 0; i < NumHorizontalCells; i++)
	{
		for (int j = 0; j < NumVerticalCells; j++)
		{
			if (CellList[i][j]->HasCard())
			{
				CellList[i][j]->HasCard()->Save(OutFile);//, CellList[i][j]->GetCellPosition());
			}
		}
	}*/

	OutFile.close();
}

void Grid::LoadGrid(ifstream& InFile, string filename)
{
	InFile.open(filename, ios::in);

	int ladderNum, snakeNum, cardNum;

	int startCell, endCell;

	InFile >> ladderNum;

	for (int i = 0; i < ladderNum; i++)
	{
		InFile >> startCell >> endCell;

		CellPosition startPos = CellPosition::GetCellPositionFromNum(startCell);
		CellPosition endPos = CellPosition::GetCellPositionFromNum(endCell);

		Ladder* ladderPtr = new Ladder(startPos, endPos);

		GetCellFromPosition(startPos)->SetGameObject(ladderPtr);
	}

	InFile >> snakeNum;

	/*for (int i = 0; i < snakeNum; i++)
	{
		InFile >> startCell >> endCell;

		CellPosition startPos = CellPosition::GetCellPositionFromNum(startCell);
		CellPosition endPos = CellPosition::GetCellPositionFromNum(endCell);

		Snake* snakePtr = new Snake(startPos, endPos);

		GetCellFromPosition(startPos)->SetGameObject(snakePtr);
	}*?

	int CardType, CardPos;
	Card* cardPtr;

	/*InFile >> cardNum;

	for (int i = 0; i < cardNum; i++)
	{
		InFile >> CardType >> CardPos;
		switch (CardType)
		{
		case 1:
			cardPtr = new CardOne(CardPos);
			GetCellFromPosition(CardPos)->SetGameObject(cardPtr);
			break;

		case 2:
			cardPtr = new CardTwo(CardPos);
			GetCellFromPosition(CardPos)->SetGameObject(cardPtr);
			break;

		case 3:
			cardPtr = new CardThree(CardPos);
			GetCellFromPosition(CardPos)->SetGameObject(cardPtr);
			break;
		
		case 4:
			cardPtr = new CardFour(CardPos);
			GetCellFromPosition(CardPos)->SetGameObject(cardPtr);
			break;
		
		case 5:
			cardPtr = new CardFive(CardPos);
			GetCellFromPosition(CardPos)->SetGameObject(cardPtr);
			break;
		
		case 6:
			cardPtr = new CardSix(CardPos);
			GetCellFromPosition(CardPos)->SetGameObject(cardPtr);
			break;
		
		case 7:
			cardPtr = new CardSeven(CardPos);
			GetCellFromPosition(CardPos)->SetGameObject(cardPtr);
			break;
		
		case 8:
			cardPtr = new CardEight(CardPos);
			GetCellFromPosition(CardPos)->SetGameObject(cardPtr);
			break;
		
		case 9:
			cardPtr = new CardNine(CardPos);
			GetCellFromPosition(CardPos)->SetGameObject(cardPtr);
			break;
		
		case 10:
			cardPtr = new CardTen(CardPos);
			GetCellFromPosition(CardPos)->SetGameObject(cardPtr);
			cardPtr->Load()
			break;
		
		case 11:
			cardPtr = new CardEleven(CardPos);
			GetCellFromPosition(CardPos)->SetGameObject(cardPtr);
			break;

		case 12:
			cardPtr = new CardTwelve(CardPos);
			GetCellFromPosition(CardPos)->SetGameObject(cardPtr);
			break;

		case 13:
			cardPtr = new CardThirteen(CardPos);
			GetCellFromPosition(CardPos)->SetGameObject(cardPtr);
			break;

		}
	}*/
}

Grid::~Grid()
{
	delete pIn;
	delete pOut;

	// Deallocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) 
	{
		for (int j = 0; j < NumHorizontalCells; j++) 
		{
			delete CellList[i][j];
		}
	}

	// Deallocate the Player Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		delete PlayerList[i];
	}
}