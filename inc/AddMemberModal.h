#ifndef HEADER_ADDMEMBERMODAL
#define HEADER_ADDMEMBERMODAL

#include "includes.h"

#include "TeamMember.h"

class AddMemberModal : public QDialog {
    Q_OBJECT

    public :
        AddMemberModal(QWidget *parent, const std::vector<QString> &weekdays, std::vector<TeamMember> &teamMembers, QTableWidget &teamTable);
        virtual ~AddMemberModal();

        enum Columns {
			ID, FIRSTNAME, LASTNAME, NBHOURS, DAYSOFF
		};

	private:
		AddMemberModal(const AddMemberModal& other);
		AddMemberModal& operator=(const AddMemberModal& other);
		void init(const AddMemberModal* other = nullptr);

    private :
        QCheckBox* _checkAll;
        QLineEdit *_firstName;
        QLineEdit *_lastName;

		QDoubleSpinBox *_hoursPerWeek;
        QPushButton *_confirmButton;

        std::vector<QString> _daysOff, _weekdays;
        std::vector<TeamMember> &_teamMembers;
        QTableWidget &_teamTable;
		std::map<QString, QCheckBox*> _t_daysCheckboxes;
        int _workTime;

        void initWindow();

    public slots:
	    void generalAllCheckstate(int state);
        void addNewMember();

    signals:
};

#endif
