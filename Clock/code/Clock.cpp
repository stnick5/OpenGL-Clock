#include "Clock.h"

Clock::Clock()
{
	
}

Clock::~Clock()
{

}

void Clock::drawBox()
{
	// Uses Right Handed Axis

	glBegin(GL_QUADS);
	// Back face
	// Takes three float values as xyz
	//glColor3f(1.f, 0.f, 0.f); // Red
	glVertex3f(-10.f, 10.f, -10.f);
	glVertex3f(-10.f, -10.f, -10.f);
	glVertex3f(10.f, -10.f, -10.f);
	glVertex3f(10.f, 10.f, -10.f);

	// Front face
	//glColor3f(0.f, 1.f, 0.f); // Green
	glVertex3f(-10.f, 10.f, 10.f);
	glVertex3f(-10.f, -10.f, 10.f);
	glVertex3f(10.f, -10.f, 10.f);
	glVertex3f(10.f, 10.f, 10.f);

	// Left Side
	//glColor3f(0.f, 0.f, 1.f); // Blue
	glVertex3f(-10.f, 10.f, -10.f);
	glVertex3f(-10.f, -10.f, -10.f);
	glVertex3f(-10.f, -10.f, 10.f);
	glVertex3f(-10.f, 10.f, 10.f);

	// Right Side
	//glColor3f(0.5f, 0.5f, 0.f);
	glVertex3f(10.f, 10.f, 10.f);
	glVertex3f(10.f, -10.f, 10.f);
	glVertex3f(10.f, -10.f, -10.f);
	glVertex3f(10.f, 10.f, -10.f);

	// Top Side
	//glColor3f(0.5f, 0.f, 0.5f);
	glVertex3f(-10.f, 10.f, -10.f);
	glVertex3f(-10.f, 10.f, 10.f);
	glVertex3f(10.f, 10.f, 10.f);
	glVertex3f(10.f, 10.f, -10.f);

	// Bottom Side
	//glColor3f(0.f, 0.5f, 0.5f);
	glVertex3f(-10.f, -10.f, 10.f);
	glVertex3f(-10.f, -10.f, -10.f);
	glVertex3f(10.f, -10.f, -10.f);
	glVertex3f(10.f, -10.f, 10.f);

	glEnd();
}

void Clock::drawCylinder()
{
	float radius = 155;
	float height = 5;
	int numberOfSides = 60;
	const float PI = 3.14159;
	float angle = 360 / numberOfSides;

	int posY, negY, x, z;
	posY = height / 2;
	negY = -height / 2;

	// Top cylinder
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0, posY, 0);
	glVertex3f(radius, posY, 0);

	for (int i = 1; i < numberOfSides + 1; i++)
	{
		x = radius * cos((angle*PI / 180)*i);
		z = radius * sin((angle*PI / 180)*i);
		glVertex3f(x, posY, z);
	}
	glEnd();

	// Body
	glBegin(GL_QUAD_STRIP);

	glVertex3f(radius, posY, 0);
	glVertex3f(radius, negY, 0);

	for (int i = 1; i < numberOfSides + 1; i++)
	{
		x = radius * cos((angle*PI / 180)*i);
		z = radius * sin((angle*PI / 180)*i);
		glVertex3f(x, posY, z);
		glVertex3f(x, negY, z);
	}
	glEnd();

	// Bottom cylinder
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0, negY, 0);
	glVertex3f(radius, negY, 0);

	for (int i = 1; i < numberOfSides + 1; i++)
	{
		x = radius * cos((angle*PI / 180)*i);
		z = radius * sin((angle*PI / 180)*i);
		glVertex3f(x, negY, z);
	}
	glEnd();
}

void Clock::drawHands()
{
	// Draw second hand.
	glPushMatrix();
	glRotatef(-secHandAngle, 0.f, 0.f, 1.f);
	glScalef(0.1f, 8.f, 1.0f);
	glTranslatef(0.f, 8.5f, -500.f);
	drawBox();
	glPopMatrix();

	// Draw minute hand.
	glPushMatrix();
	glRotatef(-minHandAngle, 0.f, 0.f, 1.f);
	glScalef(0.2f, 7.5f, 1.f);
	glTranslatef(0.f, 8.5f, -500.f);
	drawBox();
	glPopMatrix();

	// Draw hour hand.
	glPushMatrix();
	glRotatef(-hourHandAngle, 0.f, 0.f, 1.f);
	glScalef(0.3f, 6.f, 1.f);
	glTranslatef(0.f, 8.5f, -500.f);
	drawBox();
	glPopMatrix();
}

void Clock::drawNumbers()
{
	// Rotate, scale, translate

	// Draw 12, 3, 6 and 9
	for (int i = 0; i < 12; i++)
	{
		glPushMatrix();
		if (i == 0)
		{
			glScalef(0.1f, 1.6f, 1.0f);
			glTranslatef(0.f, 84.f, -500.f);
		}
		else if (i == 3 || i == 6 || i == 9)
		{
			glRotatef(hourAngle*i, 0.f, 0.f, 1.f);
			glScalef(0.1f, 1.5f, 1.0f);
			glTranslatef(0.f, 90.f, -500.f);
		}
		else
		{
			glRotatef(hourAngle*i, 0.f, 0.f, 1.f);
			glScalef(0.1f, 1.2f, 1.0f);
			glTranslatef(0.f, 110.f, -500.f);
		}
		drawBox();
		glPopMatrix();
	}

	for (int j = 0; j < 60; j++)
	{
		glPushMatrix();
		if (j != 0 && j != 5 && j != 10 && j != 15 && j != 20 && j != 25 && j != 30 && j != 35 && j != 40 && j != 45 && j != 50 && j != 55)
		{
			glRotatef(j*minAngle, 0.f, 0.f, 1.0f);
			glScalef(0.05f, 0.5f, 1.0f);
			glTranslatef(0.f, 270.f, -500.f);
			drawBox();
		}
		glPopMatrix();
	}
}

void Clock::tick()
{
	// Get time
	GetLocalTime(&sysTime);
	
	// Angle of second hand.
	secHandAngle = sysTime.wSecond * minAngle;

	// Angle of minute hand.
	minHandAngle = sysTime.wMinute * minAngle;
	minHandAngle += (sysTime.wSecond*0.1f);

	// Angle of hour hand.
	hourHandAngle = sysTime.wHour * hourAngle;
	hourHandAngle += (sysTime.wMinute*0.5f);
}

void Clock::display()
{
	tick();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Draw face
	glPushMatrix();
	glTranslatef(0.f, 0.f, -500.f);
	glRotatef(90.f, 1.f, 0.f, 0.f);
	drawCylinder();
	glPopMatrix();

	// draw numbers
	drawNumbers();

	// Draw hands
	drawHands();
}