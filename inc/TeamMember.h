#ifndef HEADER_TEAMMEMBER
#define HEADER_TEAMMEMBER

#include <string>
#include <vector>
#include "Widgets/Qt.hpp"

class TeamMember {
    public:
        TeamMember(int _id, double _nbHours, QString _firstName, QString _lastName, const std::vector<QString> &_daysOff);
        ~TeamMember();

        friend std::ostream & operator<<(std::ostream &os, const TeamMember &tm);
        friend std::ifstream & operator>>(std::ifstream &is, TeamMember &tm);
        friend std::ofstream & operator<<(std::ofstream &os, const TeamMember &tm);

        int getId()const { return id; }
        double getNbHours()const { return nbHours; }
        QString getFirstName()const { return firstName; }
        QString getLastName()const { return lastName; }
        std::vector<QString> getDaysOff()const { return daysOff; }

        void setId(int _id) { id = _id; }
        void setNbHours(double _nbHours) { nbHours = _nbHours; }
        void setFirstName(QString _firstName) { firstName = _firstName; }
        void setLastName(QString _lastName) { lastName = _lastName; }
        void setDaysOff(std::vector<QString> &_daysOff) { daysOff = _daysOff; }
        void setDaysOffFromQString(QString _daysOff);
        QString daysOffToQString();


    private:
        int id;
        double nbHours;
        QString firstName, lastName;
        std::vector<QString> daysOff;
};

#endif //TEAMMEMBER
