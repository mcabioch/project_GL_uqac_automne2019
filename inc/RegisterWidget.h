#ifndef HEADER_REGISTERWIDGET
#define HEADER_REGISTERWIDGET

#include "includes.h"

/*!
* \class	RegisterWidget
* \brief	The main window of the software
*/
class RegisterWidget : public QWidget {
	/* Usefull or required defines */
		Q_OBJECT
	/* Members of RegisterWidget */
	public:
		/* Internal enums of RegisterWidget */
			
		/* Constructors & Destructor of RegisterWidget */
			/*! \brief	The constructor of the class */
			RegisterWidget(bool passless = false, QWidget* parent = nullptr);
			virtual ~RegisterWidget();
		/* Getters of RegisterWidget */
			std::string getDaysOff()const;
		/* Setters of RegisterWidget */
			
		/* Statics of RegisterWidget */
			
		/* Operators of RegisterWidget */
			
		/* Friends of RegisterWidget */
			
		/* Others members of RegisterWidget */
			

	public slots:
		void generalAllCheckstate(int state);

	signals:
		

	protected:
		/* Getters of RegisterWidget */
			
		/* Setters of RegisterWidget */
			
		/* Statics of RegisterWidget */
			
		/* Friends of RegisterWidget */
			
		/* Others members of RegisterWidget */
			

	private:
		RegisterWidget(const RegisterWidget& other);
		RegisterWidget& operator=(const RegisterWidget& other);
		void init(const RegisterWidget* other = nullptr);

	/* Atttributes of RegisterWidget */
	public:
		/* Global */
			
		/* Local */
			QLineEdit* _username;
			QLineEdit* _password;
			QLineEdit* _passwordConf;
			QCheckBox* _checkAll;
			QLineEdit* _firstName;
			QLineEdit* _lastName;
			QDoubleSpinBox* _hoursPerWeek;
			std::map<std::string, QCheckBox*> _t_daysCheckboxes;

	protected:
		/* Global */
			
		/* Local */
			

	private:
		/* Global */
			
		/* Local */
			QVBoxLayout* centerLayout;
			bool _passless;
};

#endif //HEADER_REGISTERWIDGET
