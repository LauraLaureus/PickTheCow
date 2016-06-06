#include "TableXY.h"

TableXY::TableXY(Coordinates3D position, int numberOfRows, int numberOfColumns, double squareHeight, double squareWidth, bool home)
	: Object3D(position),
	numberOfRows(numberOfRows),
	numberOfColumns(numberOfColumns),
	squareHeight(squareHeight),
	squareWidth(squareWidth),
	home(home) {
}

TableXY::~TableXY() {
}

int TableXY::getNumberOfRows() {
	return numberOfRows;
}

void TableXY::setNumberOfRows(int numberOfRows) {
	this->numberOfRows = numberOfRows;
}

int TableXY::getNumberOfColumns() {
	return numberOfColumns;
}

void TableXY::setNumberOfColumns(int numberOfColumns) {
	this->numberOfColumns = numberOfColumns;
}

double TableXY::getSquareHeight() {
	return squareHeight;
}

void TableXY::setSquareHeight(int squareHeight) {
	this->squareHeight = squareHeight;
}

double TableXY::getSquareWidth() {
	return squareWidth;
}

void TableXY::setSquareWidth(double squareWidth) {
	this->squareWidth = squareWidth;
}

bool TableXY::hasHome() {
	return home;
}

void TableXY::setHome(bool home) {
	this->home = home;
}

double TableXY::getHeight() {
	return squareHeight * numberOfRows;
}

double TableXY::getWidth() {
	return squareWidth * numberOfColumns;
}
