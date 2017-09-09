#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include <stdio.h>

void init()
{
	glClearColor(.0, .0, .0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

float getColor()
{
	float value = rand() / 100.0;
	if (value > 1.0)
		value = value - floor(value);
	printf("color value:%f\n", value);
	return value;
}

int getX()
{
	int value = rand() % 400;
	return value;
}

int getY()
{
	int value = rand() % 300;
	return value;
}

static size_t count = 0;

void lineSegment()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
		for(size_t i = 0; i < 1000; ++i)
		{
			glColor3f(getColor(), getColor(), getColor());
			glVertex2i(getX(), getY());
		}
	glEnd();

	glFlush();

	printf("count:%ld\n", ++count);
}

int main(int argc, char** argv)
{
	srand(time(NULL));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(400, 300);
	glutCreateWindow("An Example OpenGL Program");

	init();
	glutDisplayFunc(lineSegment);
	glutMainLoop();
}
