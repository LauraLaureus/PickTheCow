#include "LaserTableSpace.h"

#include <math.h>

LaserTableSpace::LaserTableSpace(double bottom, double left, double right, double top, int numberOfTableRows, int numberOfTableColumns, int numberOfSubRowsPerTableCell, int numberOfSubColumnsPerTableCell)
	: bottom(bottom),
	left(left),
	right(right),
	top(top),
	numberOfTableRows(numberOfTableRows),
	numberOfTableColumns(numberOfTableColumns),
	numberOfSubRowsPerTableCell(numberOfSubRowsPerTableCell),
	numberOfSubColumnsPerTableCell(numberOfSubColumnsPerTableCell) {
}

LaserTableSpace::~LaserTableSpace() {
}

double LaserTableSpace::getBottom() {
	return bottom;
}

double LaserTableSpace::getLeft() {
	return left;
}

double LaserTableSpace::getRight() {
	return right;
}

double LaserTableSpace::getTop() {
	return top;
}

void LaserTableSpace::setBottom(double bottom) {
	this->bottom = bottom;
}

void LaserTableSpace::setLeft(double left) {
	this->left = left;
}

void LaserTableSpace::setRight(double right) {
	this->right = right;
}

void LaserTableSpace::setTop(double top) {
	this->top = top;
}

int LaserTableSpace::getNumberOfTableRows() {
	return numberOfTableRows;
}

void LaserTableSpace::setNumberOfTableRows(int numberOfTableRows) {
	this->numberOfTableRows = numberOfTableRows;
}

int LaserTableSpace::getNumberOfTableColumns() {
	return numberOfTableColumns;
}

void LaserTableSpace::setNumberOfTableColumns(int numberOfTableColumns) {
	this->numberOfTableColumns = numberOfTableColumns;
}

int LaserTableSpace::getNumberOfSubRowsPerTableCell() {
	return numberOfSubRowsPerTableCell;
}

void LaserTableSpace::setNumberOfSubRowsPerTableCell(int numberOfSubRowsPerTableCell) {
	this->numberOfSubRowsPerTableCell = numberOfSubRowsPerTableCell;
}

int LaserTableSpace::getNumberOfSubColumnsPerTableCell() {
	return numberOfSubColumnsPerTableCell;
}

void LaserTableSpace::setNumberOfSubColumnsPerTableCell(int numberOfSubColumnsPerTableCell) {
	this->numberOfSubColumnsPerTableCell = numberOfSubColumnsPerTableCell;
}

int LaserTableSpace::getNumberOfLaserSubRows() {
	return numberOfTableRows * numberOfSubRowsPerTableCell;
}

int LaserTableSpace::getNumberOfLaserSubColumns() {
	return numberOfTableColumns * numberOfSubColumnsPerTableCell;
}

double LaserTableSpace::getLaserSubRowIndex(double p) {
	return getLaserSubDivision(bottom, top, getNumberOfLaserSubRows(), p);
}

double LaserTableSpace::getLaserSubColumnIndex(double p) {
	return getLaserSubDivision(left, right, getNumberOfLaserSubColumns(), p);
}

double LaserTableSpace::getTableRowIndex(double p) {
	return getLaserSubDivision(bottom, top, numberOfTableRows, p);
}

double LaserTableSpace::getTableSubColumnIndex(double p) {
	return getLaserSubDivision(bottom, top, numberOfTableColumns, p);
}

double LaserTableSpace::getLaserSubDivision(double min, double max, int numberOfLaserSubDivisions, double p) {
	double subDivisionLength = (max - min) / (double)numberOfLaserSubDivisions;
	return floor((p - min) / subDivisionLength);
}
