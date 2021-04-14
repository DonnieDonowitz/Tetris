#include <QApplication>
#include "TetrisWindow.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	TetrisWindow w;
	w.show();
	return app.exec();
}