#ifndef CLOCK_H
#define CLOCK_H

#include <Windows.h>
#include "SFML/Window.hpp"
#include "gl/glew.h"
#include "gl/glut.h"

class Clock
{
public:
	Clock();
	~Clock();

	void drawBox();
	void drawCylinder();
	void drawHands();
	void drawNumbers();
	void tick();
	void display();

private:
	GLfloat secHandAngle, minHandAngle, hourHandAngle; // Angles of clock hands
	const GLfloat hourAngle = 30.f;
	const GLfloat minAngle = 6.f;

	// Clock time variables
	SYSTEMTIME sysTime;


};

#endif
