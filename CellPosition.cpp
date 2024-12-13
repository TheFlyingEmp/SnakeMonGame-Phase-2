#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 
}

CellPosition::CellPosition (int v, int h)
{ 
	// (-1) indicating an invalid cell (uninitialized by the user)

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v)
{
	///TODO:(done) Implement this function as described in the .h file (don't forget the validation)

	if (v >= 0 && v <= 8)
	{
		vCell = v;
		return true;
	}
	else {
		vCell = -1;
		return false;
	}
}

bool CellPosition::SetHCell(int h) 
{
	///TODO:(done) Implement this function as described in the .h file (don't forget the validation)

	if (h >= 0 && h <= 10)
	{
		hCell = h;
		return true;
	}
	else {
		hCell = -1;
		return false;
	}
	 // this line sould be changed with your implementation
}

int CellPosition::VCell() const 
{
	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell() const
{
	if ((HCell() >= 0 && HCell() <= 10) && (VCell() >= 0 && VCell() <= 8)) return true;
	else return false;

	///TODO:(done) Implement this function as described in the .h file
	 // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO:(done) Implement this function as described in the .h file

	if (cellPosition.IsValidCell())
		return 89 + cellPosition.HCell() - cellPosition.VCell() * NumHorizontalCells;
	else return -1;

	// this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;
	if (cellNum >= 1 && cellNum <= 99) {
		position.SetHCell((cellNum - 1) % NumHorizontalCells);
		position.SetVCell((position.HCell() - cellNum + 89) / NumHorizontalCells);
	}
	else {
		position.SetHCell(-1);
		position.SetVCell(-1);
	}
	

	/// TODO:(done) Implement this function as described in the .h file



	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it


	return position;
}

void CellPosition::AddCellNum (int addedNum)
{
	
	/// TODO:(done) Implement this function as described in the .h file

	GetCellPositionFromNum(GetCellNum() + addedNum);

	// Note: this function updates the data members (vCell and hCell) of the calling object

}