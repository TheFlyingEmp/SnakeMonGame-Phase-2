#include "ToPlayMode.h"

#include "Grid.h"


ToPlayMode::ToPlayMode(ApplicationManager* pApp) : Action(pApp)
{

}
void ToPlayMode::ReadActionParameters()
{
	// no parameters to read from user
}
ToPlayMode::~ToPlayMode()
{

}
void ToPlayMode::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pGrid->SetEndGame(false);
	pOut->CreatePlayModeToolBar();
	pGrid->UpdateInterface();


}