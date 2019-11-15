#include "TeamMember.h"

TeamMember::TeamMember(int _id, double _nbHours, QString _firstName, QString _lastName, const std::vector<QString> &_daysOff) {
    id = _id;
    nbHours = _nbHours;
    firstName = _firstName;
    lastName = _lastName;
    daysOff = _daysOff;
}

TeamMember::~TeamMember() {

}

std::ostream & operator<<(std::ostream &os, const TeamMember &tm) {
    os << "Id : " << tm.id << "\nNb hours : " << tm.nbHours << "\n" << tm.firstName.toStdString() << " " << tm.lastName.toStdString() << "\nDays off ;";

    for(auto &e : tm.daysOff) {
        os << "\n\t- " << e.toStdString();
    }

    return os;
}

std::ofstream & operator<<(std::ofstream &os, const TeamMember &tm) {
    os << tm.id << " " << tm.nbHours << " " << tm.firstName.toStdString() << " " << tm.lastName.toStdString() << " " << tm.daysOff.size();

    for(auto &e : tm.daysOff) {
        os << " " << e.toStdString();
    }

    return os;
}

std::ifstream & operator>>(std::ifstream &is, TeamMember &tm) {
    size_t size;
    std::string first, last;
    is >> tm.id >> tm.nbHours >> first >> last >> size;
    tm.firstName = first.c_str();
    tm.lastName = last.c_str();

    for(size_t i = 0; i < size; ++i) {
        std::string str;
        is >> str;
        tm.daysOff.push_back(QString(str.c_str()));
    }

    return is;
}


void TeamMember::setDaysOffFromQString(QString _daysOff) {
    QStringList qsl = _daysOff.split(' ');
    daysOff.clear();

    for(int i = 0; i < qsl.size(); ++i) {
        daysOff.push_back(qsl.at(i).toLocal8Bit().constData());
    }
}

QString TeamMember::daysOffToQString() {
    QString qs = "";
    
    for(auto &a : daysOff) {
        qs.append(a + " ");
    }

    return qs;
}