#define VIEW_WIDTH 1024
#define VIEW_HEIGHT 768

#include "Clock.h"

Clock myClock;

// Initialise window
void Init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	int centerX = glutGet(GLUT_WINDOW_WIDTH) / 2;
	int centerY = glutGet(GLUT_WINDOW_HEIGHT) / 2;

	gluPerspective(45.0f, (GLfloat)glutGet(GLUT_WINDOW_WIDTH) / (GLfloat)glutGet(GLUT_WINDOW_HEIGHT), 0.1f, 1000.0f);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	//glutWarpPointer(centerX, centerY);
}

void lighting()
{
	glEnable(GL_LIGHT0);
	GLfloat white[] = { 1.f, 1.f, 1.f, 1.f };
	float shine = 100.f;

	GLfloat light0pos[] = { 0.f, 0.f, 10.f, 1.f };
	GLfloat lightambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat lightdiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat lightspecular[] = { 0.5f, 0.5f, 0.5f, 1.0f };

	glLightfv(GL_LIGHT0, GL_AMBIENT, lightambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightdiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightspecular);
	glLightfv(GL_LIGHT0, GL_POSITION, light0pos);
}


// Display function
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	lighting();

	// Draw clock
	myClock.display();

	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_LIGHTING);

	glutSwapBuffers();
}

// Resize function
void reshape(GLsizei width, GLsizei height)
{

}

// Key press function
void keyPress(unsigned char key, int x, int y)
{

}

// Key release function
void keyRelease(unsigned char key, int x, int y)
{

}

// Mouse movement function
void mouseMovement(int x, int y)
{

}

// Timer function - redraw the screen.
void timer(int millisec)
{
	glutTimerFunc(millisec, timer, millisec);
	glutPostRedisplay();
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// Set viewport width and height
	glutInitWindowSize(VIEW_WIDTH, VIEW_HEIGHT);

	// Position the window in the centre of the screen
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - VIEW_WIDTH) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - VIEW_HEIGHT) / 2);

	// Create the window
	glutCreateWindow("OpenGL Clock");

	glewInit();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyPress);
	glutKeyboardUpFunc(keyRelease);

	glutPassiveMotionFunc(mouseMovement);

	Init();

	glutTimerFunc(16, timer, 16);

	glutMainLoop();

	return 0;
}