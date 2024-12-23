#include "ToDesignMode.h"
#include "Grid.h"
#include "NewGameAction.h"

ToDesignMode::ToDesignMode(ApplicationManager* pApp) : Action(pApp)
{

}
void ToDesignMode::ReadActionParameters()
{
	// no parameters to read from user
}
ToDesignMode::~ToDesignMode()
{

}
void ToDesignMode::Execute()
{
	
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->CreateDesignModeToolBar();
	pManager->ExecuteAction(NEW_GAME); //since the session has ended everything should be reset
	pGrid->UpdateInterface();


}