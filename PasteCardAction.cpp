#include "PasteCardAction.h"

PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{
	pManager = pApp;
}

void PasteCardAction::Execute() 
{
	Grid* pGrid = pManager->GetGrid();

	CardtoBePasted = pGrid->GetClipboard();

	pGrid->AddObjectToCell(CardtoBePasted);

	pGrid->UpdateInterface();
}

PasteCardAction::~PasteCardAction()
{
}