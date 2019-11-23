#include <QApplication>

#include "ConnectWindow.h"

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	mcd::logger.init("res/log.conf");

	MainWindow w;
	w.hide();

	/*ConnectWindow cw(w);
	cw.show();

	SigninWindow sw(&cw);
	sw.hide();*/
	ConnectWindow* cw;

	SigninWindow sw(cw);
	sw.hide();

	cw = new ConnectWindow(w);
	cw->show();

	auto out = app.exec();

	deletePtr(cw);

	return out;
}
