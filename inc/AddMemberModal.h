#ifndef HEADER_ADDMEMBERMODAL
#define HEADER_ADDMEMBERMODAL

#include "RegisterWidget.h"

class AddMemberModal : public QDialog {
	Q_OBJECT

	public :
		AddMemberModal(QWidget *parent, std::vector<TeamMember> &teamMembers, QTableWidget &teamTable, Api& api);
		virtual ~AddMemberModal();

		enum Columns {
			ID, FIRSTNAME, LASTNAME, NBHOURS, DAYSOFF
		};

	private:
		AddMemberModal(const AddMemberModal& other);
		AddMemberModal& operator=(const AddMemberModal& other);
		void init(const AddMemberModal* other = nullptr);

	private :
		RegisterWidget* _register;
		QPushButton *_confirmButton;

		std::vector<QString> _daysOff;
		std::vector<TeamMember> &_teamMembers;
		QTableWidget &_teamTable;
		Api& _api;

		void initWindow();

	public slots:
		void addNewMember();
		void addingNewMember(const std::string& id);

	signals:
};

#endif
