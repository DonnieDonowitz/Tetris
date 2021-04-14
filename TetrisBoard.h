#pragma once

#include <QFrame>
#include <QBasicTimer>
#include <QPointer>
#include <QLabel>
#include <QPainter>
#include <QKeyEvent>
#include "TetrisPiece.h"

class TetrisBoard : public QFrame
{
	Q_OBJECT

public:
	TetrisBoard(QWidget *parent = nullptr);
	 
	void setNextPieceLabel(QLabel *label);
	QSize sizeHint() const override;
	QSize minimumSizeHint() const override;

public slots:
	void start();
	void pause();

signals:
	void scoreChanged(int score);
	void levelChanged(int level);
	void linesRemovedChanged(int numLines);

protected:
	void paintEvent(QPaintEvent *event) override;
	void keyPressEvent(QKeyEvent *event) override;
	void timerEvent(QTimerEvent *event) override;

private:
	enum { BoardWidth = 10, BoardHeight = 22 };

	TetrisShape &shapeAt(int x, int y) { return board[(y * BoardWidth) + x]; }
	int timeoutTime() { return 1000 / (1 + level); }
	int squareWidth() { return contentsRect().width() / BoardWidth - 1; }
	int squareHeight() { return contentsRect().height() / BoardHeight - 1; }
	void clearBoard();
	void dropDown();
	void oneLineDown();
	void pieceDropped(int dropHeight);
	void removeFullLines();
	void newPiece();
	void showNextPiece();
	bool tryMove(const TetrisPiece &newPiece, int newX, int newY);
	void drawSquare(QPainter &painter, int x, int y, TetrisShape shape);

	QBasicTimer timer;
	QPointer<QLabel> nextPieceLabel;
	bool isStarted, isPaused, isWaitingAfterLine;
	TetrisPiece curPiece, nextPiece;
	int curX, curY, numLinesRemoved, numPiecesDropped, score, level;
	TetrisShape board[BoardWidth * BoardHeight];
};
