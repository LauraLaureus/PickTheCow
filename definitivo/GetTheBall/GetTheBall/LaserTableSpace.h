#pragma once

class LaserTableSpace {
protected:
	double left;
	double right;
	double top;
	double bottom;
	int numberOfTableRows;
	int numberOfTableColumns;
	int numberOfSubRowsPerTableCell;
	int numberOfSubColumnsPerTableCell;

	double getLaserSubDivision(double min, double max, int numberOfLaserSubDivisions, double p);

public:
	LaserTableSpace(double bottom, double left, double right, double top, int numberOfTableRows, int numberOfTableColumns, int numberOfSubRowsPerTableCell, int numberOfSubColumnsPerTableCell);
	~LaserTableSpace();

	double getBottom();
	void setBottom(double bottom);

	double getLeft();
	void setLeft(double left);

	double getRight();
	void setRight(double right);

	double getTop();
	void setTop(double top);

	int getNumberOfTableRows();
	void setNumberOfTableRows(int numberOfTableRows);

	int getNumberOfTableColumns();
	void setNumberOfTableColumns(int numberOfTableColumns);

	int getNumberOfSubRowsPerTableCell();
	void setNumberOfSubRowsPerTableCell(int numberOfSubRowsPerTableCell);

	int getNumberOfSubColumnsPerTableCell();
	void setNumberOfSubColumnsPerTableCell(int numberOfSubColumnsPerTableCell);

	int getNumberOfLaserSubRows();	
	int getNumberOfLaserSubColumns();
	
	double getLaserSubRowIndex(double p);
	double getLaserSubColumnIndex(double p);

	double getTableRowIndex(double p);
	double getTableSubColumnIndex(double p);
};
