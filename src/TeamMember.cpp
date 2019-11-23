#include "TeamMember.h"

TeamMember::TeamMember(int id, double nbHours, QString firstName, QString lastName, const std::vector<QString> &daysOff) :
	_id(id),
	_nbHours(nbHours),
	_firstName(firstName),
	_lastName(lastName),
	_daysOff(daysOff)
{}

TeamMember::~TeamMember() {}

std::ostream & operator<<(std::ostream &os, const TeamMember &tm) {
    os << "Id : " << tm._id << "\nNb hours : " << tm._nbHours << "\n" << tm._firstName.toStdString() << " " << tm._lastName.toStdString() << "\nDays off ;";

    for(auto &e : tm._daysOff) {
        os << "\n\t- " << e.toStdString();
    }

    return os;
}

std::ofstream & operator<<(std::ofstream &os, const TeamMember &tm) {
    os << tm._id << " " << tm._nbHours << " " << tm._firstName.toStdString() << " " << tm._lastName.toStdString() << " " << tm._daysOff.size();

    for(auto &e : tm._daysOff) {
        os << " " << e.toStdString();
    }

    return os;
}

std::ifstream & operator>>(std::ifstream &is, TeamMember &tm) {
    size_t size;
    std::string first, last;
    is >> tm._id >> tm._nbHours >> first >> last >> size;
    tm._firstName = first.c_str();
    tm._lastName = last.c_str();

    for(size_t i = 0; i < size; ++i) {
        std::string str;
        is >> str;
        tm._daysOff.push_back(QString(str.c_str()));
    }

    return is;
}


void TeamMember::setDaysOffFromQString(QString daysOff) {
    QStringList qsl = daysOff.split(' ');
    _daysOff.clear();

    for(int i = 0; i < qsl.size(); ++i) {
        _daysOff.push_back(qsl.at(i).toLocal8Bit().constData());
    }
}

QString TeamMember::daysOffToQString() {
    QString qs = "";
    
    for(auto &a : _daysOff) {
        qs.append(a + " ");
    }

    return qs;
}
