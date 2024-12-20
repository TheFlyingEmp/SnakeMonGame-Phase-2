#pragma once

#include "Action.h"

class NewGameAction : public Action
{
	//takes no parameters

public:
	NewGameAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~NewGameAction();
};
