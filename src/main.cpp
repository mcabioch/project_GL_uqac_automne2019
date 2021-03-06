#include <QApplication>

#include "ConnectWindow.h"

int main(int argc, char** argv) {
	mcd::arguments.addProg(argc, argv);

	QApplication app(argc, argv);
	mcd::logger.init("res/log.conf");

	QFontDatabase::addApplicationFont("res/Raleway/Raleway-Light.ttf");
	QFontDatabase::addApplicationFont("res/Raleway/Raleway-SemiBold.ttf");

	Api api;
	if(!api.connection("http://34.95.48.165")){
	//if(!api.connection("http://192.168.0.169")){
		mcd::logs(mcd::Logger::Fatal, "Impossible to connect to the apis, check your network connection.");
	}

	mcd::arguments.add("weekdays", "Monday");
	mcd::arguments.add("weekdays", "Tuesday");
	mcd::arguments.add("weekdays", "Wednesday");
	mcd::arguments.add("weekdays", "Thursday");
	mcd::arguments.add("weekdays", "Friday");
	mcd::arguments.add("weekdays", "Saturday");
	mcd::arguments.add("weekdays", "Sunday");

	MainWindow w(api);
	w.hide();

	ConnectWindow cw(w, api);
	cw.show();

	SigninWindow sw(&cw, api);
	sw.hide();

	cw.link(&sw);

	//cw.testConnect("chef", "welcome1");
	//cw.testRegister();

	return app.exec();
}
