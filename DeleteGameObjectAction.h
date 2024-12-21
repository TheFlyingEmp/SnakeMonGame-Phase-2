#pragma once
#include "Action.h"


class DeleteGameObjectAction : public Action
{
	CellPosition cellPos;

public:
	DeleteGameObjectAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~DeleteGameObjectAction();
};