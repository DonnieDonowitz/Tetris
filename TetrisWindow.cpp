#include "TetrisWindow.h"

TetrisWindow::TetrisWindow(QWidget *parent)
	: QWidget(parent), board(new TetrisBoard)
{
	nextPieceLabel = new QLabel;
	nextPieceLabel->setFrameStyle(QFrame::Box | QFrame::Raised);
	nextPieceLabel->setAlignment(Qt::AlignCenter);
	
	board->setNextPieceLabel(nextPieceLabel);

	scoreLCD = new QLCDNumber(5);
	scoreLCD->setSegmentStyle(QLCDNumber::Filled);

	levelLCD = new QLCDNumber(5);
	levelLCD->setSegmentStyle(QLCDNumber::Filled);
	
	linesLCD = new QLCDNumber(5);
	linesLCD->setSegmentStyle(QLCDNumber::Filled);

	startButton = new QPushButton(tr("&Start"));
	startButton->setFocusPolicy(Qt::NoFocus);

	quitButton = new QPushButton(tr("&Quit"));
	quitButton->setFocusPolicy(Qt::NoFocus);

	pauseButton = new QPushButton(tr("&Pause"));
	pauseButton->setFocusPolicy(Qt::NoFocus);

	connect(startButton, &QPushButton::clicked, board, &TetrisBoard::start);
	connect(quitButton, &QPushButton::clicked, qApp, &QApplication::quit);
	connect(pauseButton, &QPushButton::clicked, board, &TetrisBoard::pause);
	connect(board, &TetrisBoard::scoreChanged, scoreLCD, qOverload<int>(&QLCDNumber::display));
	connect(board, &TetrisBoard::levelChanged, levelLCD, qOverload<int>(&QLCDNumber::display));
	connect(board, &TetrisBoard::linesRemovedChanged, linesLCD, qOverload<int>(&QLCDNumber::display));
	
	QGridLayout *layout = new QGridLayout;
	layout->addWidget(createLabel(tr("NEXT")), 0, 0);
	layout->addWidget(nextPieceLabel, 1, 0);
	layout->addWidget(createLabel(tr("LEVEL")), 2, 0);
	layout->addWidget(levelLCD, 3, 0);
	layout->addWidget(startButton, 4, 0);
	layout->addWidget(board, 0, 1, 6, 1);
	layout->addWidget(createLabel(tr("SCORE")), 0, 2);
	layout->addWidget(scoreLCD, 1, 2);
	layout->addWidget(createLabel(tr("LINES REMOVED")), 2, 2);
	layout->addWidget(linesLCD, 3, 2);
	layout->addWidget(quitButton, 4, 2);
	layout->addWidget(pauseButton, 5, 2);
	setLayout(layout);

	setWindowTitle(tr("Tetris"));
	resize(550, 370);

}

TetrisWindow::~TetrisWindow()
{
	delete startButton;
	delete pauseButton;
	delete quitButton;
	delete scoreLCD;
	delete linesLCD;
	delete linesLCD;
	delete nextPieceLabel;
	delete board;
}

QLabel *TetrisWindow::createLabel(const QString &text)
{
	QLabel *label = new QLabel(text);
	label->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
	return label;
}
