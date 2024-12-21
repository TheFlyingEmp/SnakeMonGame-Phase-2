#include "AddCardAction.h"
#include "EditCardAction.h"

EditCardAction::EditCardAction(ApplicationManager* pApp) : Action(pApp)
{

	// Initializes the pManager pointer of Action with the passed pointer
}

EditCardAction::~EditCardAction()
{

}

void EditCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("click on the source to edit");
	cardPosition = pIn->GetCellClicked();
	//Card* pCard = pGrid->GetClipboard();
	
	pOut->ClearStatusBar();
}

void EditCardAction::Execute()
{
	ReadActionParameters();
     
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	bool hascardObject = pGrid->HasGameObject(cardPosition);
	if (!hascardObject)
	{
		pGrid->PrintErrorMessage("Invalid Card Cell position.Click anywhere to continue...");
		return;
	}
	else
	{
		Card* pCard = dynamic_cast<Card*>(pGrid->GetGameObjectfromCell(cardPosition));
		if (pCard)
		{
			switch (pCard->GetCardNumber())
			{
			case 1:
				pGrid->RemoveObjectFromCell(pCard->GetPosition());
				pManager->ExecuteAction(ADD_CARD);
				break;
			case 2:
				pManager->ExecuteAction(ADD_CARD);
				break;
			case 3:
				pGrid->PrintErrorMessage("Invalid Card type.Click anywhere to continue...");
				break;
			case 4:
				pGrid->PrintErrorMessage("Invalid Card type.Click anywhere to continue...");
				break;
			case 5:
				pGrid->PrintErrorMessage("Invalid Card type.Click anywhere to continue...");
				break;
			case 6:
				pGrid->PrintErrorMessage("Invalid Card type.Click anywhere to continue...");
				break;
			case 7:
				pGrid->PrintErrorMessage("Invalid Card type.Click anywhere to continue...");
				break;
			case 8:
				pGrid->PrintErrorMessage("Invalid Card type.Click anywhere to continue...");
				break;
			case 9:
				pManager->ExecuteAction(ADD_CARD);
				break;
			case 10:
				pManager->ExecuteAction(ADD_CARD);
				break;
			case 11:
				pManager->ExecuteAction(ADD_CARD);
				break;
			case 12:
				pManager->ExecuteAction(ADD_CARD);
				break;
			case 13:
				pManager->ExecuteAction(ADD_CARD);
				break;
			}
		}

		else
		{
			pGrid->PrintErrorMessage("Invalid Object Type.Click anywhere to continue...");
			return;
		}
	}
}
