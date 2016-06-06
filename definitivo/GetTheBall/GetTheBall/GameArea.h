#pragma once

#include "Coordinates3D.h"

class GameArea {
private:
	double left;
	double right;
	double top;
	double bottom;
	int numberOfRows;
	int numberOfColumns;
	int numberOfSubRowsPerCell;
	int numberOfSubColumnsPerCell;
	double tableCellHeight;
	double tableCellWidth;
	Coordinates3D roomPosition;

	int getAreaMagnitudeIndex(double min, double max, int numberOfMagnitudeSubDivisions, double p);

public:
	GameArea( double left, double right,double bottom, double top, int numberOfRows, int numberOfColumns, int numberOfSubRowsPerCell, int numberOfSubColumnsPerCell, double tableCellHeight, double tableCellWidth, Coordinates3D roomPosition);
	GameArea(const GameArea& gameArea);
	GameArea& operator=(const GameArea& gameArea);
	~GameArea();

	double getBottom();
	void setBottom(double bottom);

	double getLeft();
	void setLeft(double left);

	double getRight();
	void setRight(double right);

	double getTop();
	void setTop(double top);

	int getNumberOfRows();
	void setNumberOfRows(int numberOfRows);

	int getNumberOfColumns();
	void setNumberOfColumns(int numberOfColumns);

	int getNumberOfSubRowsPerCell();
	void setNumberOfSubRowsPerCell(int numberOfSubRowsPerCell);

	int getNumberOfSubColumnsPerCell();
	void setNumberOfSubColumnsPerCell(int numberOfSubColumnsPerCell);

	double getTableCellHeight();
	void setTableCellHeight(double tableCellHeight);

	double getTableCellWidth();
	void setTableCellWidth(double tableCellWidth);

	Coordinates3D getRoomPosition();
	void setRoomPosition(Coordinates3D roomPosition);

	int getNumberOfSubRows();
	int getNumberOfSubColumns();
	
	int getRowIndexFromRealWorld(double p);
	int getColumnIndexFromRealWorld(double p);

	int getSubRowIndexFromRealWorld(double p);
	int getSubColumnIndexFromRealWorld(double p);

	int getRowIndexFromVirtualWorld(double p);
	int getColumnIndexFromVirtualWorld(double p);

	int getSubRowIndexFromVirtualWorld(double p);
	int getSubColumnIndexFromVirtualWorld(double p);

	double getTableSubCellHeight();
	double getTableSubCellWidth();

	int getRowIndexFromSubRowIndex(int subRowIndex);
	int getColumnIndexFromSubColumnIndex(int subColumnIndex);
};
