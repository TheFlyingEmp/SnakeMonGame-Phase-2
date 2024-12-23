#pragma once
#include "Action.h"
#include "Grid.h"
#include <fstream>

class LoadGridAction : public Action
{
public:
	LoadGridAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~LoadGridAction();
};
