#ifndef HEADER_TEAMMEMBER
#define HEADER_TEAMMEMBER

#include "includes.h"

class TeamMember {
    public:
        TeamMember(int id, double nbHours, QString firstName, QString lastName, const std::vector<QString> &daysOff);
        ~TeamMember();

        friend std::ostream & operator<<(std::ostream &os, const TeamMember &tm);
        friend std::ifstream & operator>>(std::ifstream &is, TeamMember &tm);
        friend std::ofstream & operator<<(std::ofstream &os, const TeamMember &tm);

        inline int getId()const { return _id; }
        inline double getNbHours()const { return _nbHours; }
        inline QString getFirstName()const { return _firstName; }
        inline QString getLastName()const { return _lastName; }
        inline std::vector<QString> getDaysOff()const { return _daysOff; }

        inline void setId(int id) { _id = id; }
        inline void setNbHours(double nbHours) { _nbHours = nbHours; }
        inline void setFirstName(QString firstName) { _firstName = firstName; }
        inline void setLastName(QString lastName) { _lastName = lastName; }
        inline void setDaysOff(std::vector<QString> &daysOff) { _daysOff = daysOff; }
        void setDaysOffFromQString(QString daysOff);
        QString daysOffToQString();


    private:
        int _id;
        double _nbHours;
        QString _firstName, _lastName;
        std::vector<QString> _daysOff;
};

#endif //TEAMMEMBER
