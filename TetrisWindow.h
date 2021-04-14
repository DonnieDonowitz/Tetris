#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLCDNumber>
#include <QGridLayout>
#include <QApplication>
#include "TetrisBoard.h"

class TetrisWindow : public QWidget
{
	Q_OBJECT

public:
	explicit TetrisWindow(QWidget *parent = nullptr);
	~TetrisWindow();

private:
	QLabel *createLabel(const QString& text);

	TetrisBoard *board;
	QLabel *nextPieceLabel;
	QLCDNumber *scoreLCD, *levelLCD, *linesLCD;
	QPushButton *startButton, *quitButton, *pauseButton;
};
