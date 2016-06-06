#include "GameArea.h"

#include <math.h>

GameArea::GameArea(double left, double right,double bottom, double top,  int numberOfRows, int numberOfColumns, int numberOfSubRowsPerCell, int numberOfSubColumnsPerCell, double tableCellHeight, double tableCellWidth, Coordinates3D roomPosition)
	: left(left),
	right(right),
	top(top),
	bottom(bottom),
	numberOfRows(numberOfRows),
	numberOfColumns(numberOfColumns),
	numberOfSubRowsPerCell(numberOfSubRowsPerCell),
	numberOfSubColumnsPerCell(numberOfSubColumnsPerCell),
	tableCellHeight(tableCellHeight),
	tableCellWidth(tableCellWidth),
	roomPosition(roomPosition) {
}

GameArea::GameArea(const GameArea& gameArea)
	: left(gameArea.left),
	right(gameArea.right),
	top(gameArea.top),
	bottom(gameArea.bottom),
	numberOfRows(gameArea.numberOfRows),
	numberOfColumns(gameArea.numberOfColumns),
	numberOfSubRowsPerCell(gameArea.numberOfSubRowsPerCell),
	numberOfSubColumnsPerCell(gameArea.numberOfSubColumnsPerCell),
	tableCellHeight(gameArea.tableCellHeight),
	tableCellWidth(gameArea.tableCellWidth),
	roomPosition(gameArea.roomPosition) {
}

GameArea& GameArea::operator=(const GameArea& gameArea) {
	if  (this != &gameArea) {
		this->left = gameArea.left;
		this->right = gameArea.right;
		this->top = gameArea.top;
		this->bottom = gameArea.bottom;
		this->numberOfRows = gameArea.numberOfRows;
		this->numberOfColumns = gameArea.numberOfColumns;
		this->numberOfSubRowsPerCell = gameArea.numberOfSubRowsPerCell;
		this->numberOfSubColumnsPerCell = gameArea.numberOfSubColumnsPerCell;
		this->tableCellHeight = gameArea.tableCellHeight;
		this->tableCellWidth = gameArea.tableCellWidth;
		this->roomPosition = gameArea.roomPosition;
	}

	return *this;
}

GameArea::~GameArea() {
}

double GameArea::getBottom() {
	return bottom;
}

double GameArea::getLeft() {
	return left;
}

double GameArea::getRight() {
	return right;
}

double GameArea::getTop() {
	return top;
}

void GameArea::setBottom(double bottom) {
	this->bottom = bottom;
}

void GameArea::setLeft(double left) {
	this->left = left;
}

void GameArea::setRight(double right) {
	this->right = right;
}

void GameArea::setTop(double top) {
	this->top = top;
}

int GameArea::getNumberOfRows() {
	return numberOfRows;
}

void GameArea::setNumberOfRows(int numberOfRows) {
	this->numberOfRows = numberOfRows;
}

int GameArea::getNumberOfColumns() {
	return numberOfColumns;
}

void GameArea::setNumberOfColumns(int numberOfColumns) {
	this->numberOfColumns = numberOfColumns;
}

int GameArea::getNumberOfSubRowsPerCell() {
	return numberOfSubRowsPerCell;
}

void GameArea::setNumberOfSubRowsPerCell(int numberOfSubRowsPerCell) {
	this->numberOfSubRowsPerCell  = numberOfSubRowsPerCell;
}

int GameArea::getNumberOfSubColumnsPerCell() {
	return numberOfSubColumnsPerCell;
}

void GameArea::setNumberOfSubColumnsPerCell(int numberOfSubColumnsPerCell) {
	this->numberOfSubColumnsPerCell = numberOfSubColumnsPerCell;
}

double GameArea::getTableCellHeight() {
	return tableCellHeight;
}

void GameArea::setTableCellHeight(double tableCellHeight) {
	this->tableCellHeight = tableCellHeight;
}

double GameArea::getTableCellWidth() {
	return tableCellWidth;
}

void GameArea::setTableCellWidth(double tableCellWidth) {
	this->tableCellWidth = tableCellWidth;
}

Coordinates3D GameArea::getRoomPosition() {
	return roomPosition;
}

void GameArea::setRoomPosition(Coordinates3D roomPosition) {
	this->roomPosition = roomPosition;
}

int GameArea::getNumberOfSubRows() {
	return numberOfRows * numberOfSubRowsPerCell;
}

int GameArea::getNumberOfSubColumns() {
	return numberOfColumns * numberOfSubColumnsPerCell;
}

int GameArea::getRowIndexFromRealWorld(double p) {
	return getAreaMagnitudeIndex(bottom, top, numberOfRows, p);
}

int GameArea::getColumnIndexFromRealWorld(double p) {
	return getAreaMagnitudeIndex(left, right, numberOfColumns, p);
}

int GameArea::getSubRowIndexFromRealWorld(double p) {
	return getAreaMagnitudeIndex(bottom, top, getNumberOfSubRows(), p);
}

int GameArea::getSubColumnIndexFromRealWorld(double p) {
	return getAreaMagnitudeIndex(left, right, getNumberOfSubColumns(), p);
}
///////////////
int GameArea::getRowIndexFromVirtualWorld(double p) {
	double bottomV = roomPosition.getZ();
	double topV = bottomV - numberOfRows * tableCellHeight;
	return getAreaMagnitudeIndex(bottomV, topV, numberOfRows, p);
}

int GameArea::getColumnIndexFromVirtualWorld(double p) {
	double leftV = roomPosition.getX();
	double rightV = bottom + numberOfColumns * tableCellWidth;
	return getAreaMagnitudeIndex(leftV, rightV, numberOfColumns, p);
}

int GameArea::getSubRowIndexFromVirtualWorld(double p) {
	double bottomV = roomPosition.getZ();
	double topV = bottomV - numberOfRows * tableCellHeight;
	return getAreaMagnitudeIndex(bottomV, topV, getNumberOfSubRows(), p);
}

int GameArea::getSubColumnIndexFromVirtualWorld(double p) {
	double leftV = roomPosition.getX();
	double rightV = bottom + numberOfColumns * tableCellWidth;
	return getAreaMagnitudeIndex(left, right, getNumberOfSubColumns(), p);
}

int GameArea::getAreaMagnitudeIndex(double min, double max, int numberOfMagnitudeSubDivisions, double p) {
	double subDivisionLength = (max - min) / (double)numberOfMagnitudeSubDivisions;
	return (int)floor((p - min) / subDivisionLength);
}

double GameArea::getTableSubCellHeight() {
	return tableCellHeight/ numberOfSubRowsPerCell;
}

double GameArea::getTableSubCellWidth() {
	return tableCellWidth / numberOfSubColumnsPerCell;
}

int GameArea::getRowIndexFromSubRowIndex(int subRowIndex) {
	return subRowIndex / getNumberOfSubRows();
}

int GameArea::getColumnIndexFromSubColumnIndex(int subColumnIndex) {
	return subColumnIndex / getNumberOfSubColumns();
}
