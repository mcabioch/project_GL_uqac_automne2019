/*!
*
*	\file		collides.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\modified	September, 17 2019
*
*/
#ifndef HEADER_CPP_COLLIDES
#define HEADER_CPP_COLLIDES

#include "C++/Matrix.hpp"

namespace mcd {
	/*!
	* \brief	Compute if there is a collision between two circles
	*		\param[in]		r1		Radius of the first circle
	*		\param[in]		x1		X position of the first circle's center
	*		\param[in]		y1		Y position of the first circle's center
	*		\param[in]		r2		Radius of the second circle
	*		\param[in]		x2		X position of the second circle's center
	*		\param[in]		y2		Y position of the second circle's center
	*
	*		\return			\b true or \b false
	*/
	bool collidesC(double64_t r1, double64_t x1, double64_t y1, double64_t r2, double64_t x2, double64_t y2);
	/*!
	* \brief	Compute if there is a collision between two rectangles
	*		\param[in]		x1		X position of the first rectangle's left corner
	*		\param[in]		y1		Y position of the first rectangle's left corner
	*		\param[in]		w1		Width of the first rectangle
	*		\param[in]		h1		Height of the first rectangle
	*		\param[in]		x2		X position of the second rectangle's left corner
	*		\param[in]		y2		Y position of the second rectangle's left corner
	*		\param[in]		w2		Width of the second rectangle
	*		\param[in]		h2		Height of the second rectangle
	*
	*		\return			\b true or \b false
	*/
	bool collidesR(double64_t x1, double64_t y1, double64_t w1, double64_t h1, double64_t x2, double64_t y2, double64_t w2, double64_t h2);

	/*!
	* \brief	Compute if there is a collision between a rectangle and a circle
	*		\param[in]		rx		X position of the rectangle's left
	*		\param[in]		ry		Y position of the rectangle's left
	*		\param[in]		w		Width of the rectangle
	*		\param[in]		h		Height of the rectangle
	*		\param[in]		cx		X position of the circle's center
	*		\param[in]		cy		Y position of the circle's center
	*		\param[in]		r		Radius of the circle
	*
	*		\return			\b true or \b false
	*/
	bool collidesRC(double64_t rx, double64_t ry, double64_t w, double64_t h, double64_t cx, double64_t cy, double64_t r);
	/*!
	* \brief	Compute if there is a collision between a point and a circle
	*		\param[in]		cx		X position of the circle's center
	*		\param[in]		cy		Y position of the circle's center
	*		\param[in]		r		Radius of the circle
	*		\param[in]		x		X position of the point
	*		\param[in]		y		Y position of the point
	*
	*		\return			\b true or \b false
	*/
	bool collidesPC(double64_t cx, double64_t cy, double64_t r, double64_t x, double64_t y);
	/*!
	* \brief	Compute if there is a collision between a point and a rectangle
	*		\param[in]		rx		X position of the rectangle's left corner
	*		\param[in]		ry		Y position of the rectangle's left corner
	*		\param[in]		w		Width of the rectangle
	*		\param[in]		h		Height of the rectangle
	*		\param[in]		x		X position of the point
	*		\param[in]		y		Y position of the point
	*
	*		\return			\b true or \b false
	*/
	bool collidesPR(double64_t rx, double64_t ry, double64_t w, double64_t h, double64_t x, double64_t y);

	/*!
	* \brief	Compute if there is a collision on a segment
	*		\param[in]		Cx		X position of the point
	*		\param[in]		Cy		Y position of the point
	*		\param[in]		Ax		X position of the segment's first side
	*		\param[in]		Ay		Y position of the segment's first side
	*		\param[in]		Bx		X position of the segment's second side
	*		\param[in]		By		Y position of the segment's second side
	*
	*		\return			\b true or \b false
	*/
	bool ProjectionSurSegment(double64_t Cx, double64_t Cy, double64_t Ax, double64_t Ay, double64_t Bx, double64_t By);
}

#endif //HEADER_CPP_COLLIDES
