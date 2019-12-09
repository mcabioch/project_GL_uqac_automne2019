/*!
*
*	\file		IconedFormContainer.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\created	Thursday December, 05 2019 23:35:42
*	\modified	Thursday December, 05 2019
*
*/
#ifndef HEADER_ICONED_FORM_CONTAINER
#define HEADER_ICONED_FORM_CONTAINER

#include "Widgets/Qt.hpp"

/*!
* \class	IconedFormContainer
* \brief	A QWidget to contain some form fields
*/
class IconedFormContainer : public QWidget {
	/* Usefull or required defines */
		Q_OBJECT
	/* Members of IconedFormContainer */
	public:
		/* Constructors & Destructor of IconedFormContainer */
			/*! \brief	The constructor of the class */
			IconedFormContainer(QIcon* icon, int size, QWidget* field, const QString& str = "", QWidget* parent = nullptr );
			virtual ~IconedFormContainer();

			/*!
			* \brief	The copy constructor of the class
			*	\param[in]		other		The class' instance for copying
			*/
			IconedFormContainer(const IconedFormContainer& other);
		/* Getters of IconedFormContainer */
			
		/* Setters of IconedFormContainer */
			
		/* Statics of IconedFormContainer */
			
		/* Operators of IconedFormContainer */
			/*!
			* \brief	The copy operator of the class
			*	\param[in]		other		The class' instance for copying
			*/
			IconedFormContainer& operator=(const IconedFormContainer& other) noexcept;
		/* Friends of IconedFormContainer */
			
		/* Others members of IconedFormContainer */
			

	protected:
		/* Getters of IconedFormContainer */
			
		/* Setters of IconedFormContainer */
			
		/* Statics of IconedFormContainer */
			
		/* Friends of IconedFormContainer */
			
		/* Others members of IconedFormContainer */
			void paintEvent(QPaintEvent *event);

	private:
		void init();

	/* Atttributes of IconedFormContainer */
	public:
		/* Local */
			QIcon* _icon;
			QWidget* _field;
			QString _str;
			int _size;
};

#endif //HEADER_ICONED_FORM_CONTAINER
