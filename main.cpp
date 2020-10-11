#include <windows.h>
#include <GL/glu.h>
#include <GL/glut.h>


GLint Width = 400, Height = 400;


void Output(const char *string)
{
	glViewport(0, 0, Width, Height);
	glRasterPos2f(1, -5.5);
	int len = strlen(string);
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, string[i]);
}


void Display(void)
{
	GLint w = Width, h = Height;
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);


	glViewport(w / 2, h / 2, w / 2, h / 2); //������ ��������

	for (int i = 0; i < 4; i++)
	{
		if (!i)
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glColor3f(1, 0, 0);
		}
		else
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glColor3f(1, 1, 1);
		}
		glBegin(GL_POLYGON);
		glVertex2f(-5, -3 + i * 2);
		glVertex2f(-5, -1 + i * 2);
		glVertex2f(-3, -1 + i * 2);
		glVertex2f(-3, -3 + i * 2);
		glEnd();
	} //������� �������������

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glColor3f(1, 0, 0);
	glVertex2f(1, -3);
	glVertex2f(2, -2);
	glColor3f(1, 1, 0);
	glVertex2f(2.5, -1);
	glVertex2f(3, 0);
	glColor3f(0, 0, 1);
	glVertex2f(2.5, 2);
	glVertex2f(2.2, 3);
	glColor3f(0, 0, 1);
	glVertex2f(1.5, 4);
	glEnd(); //���� �������������


	glViewport(0, Height / 2, Width / 2, Height / 2); //������ ��������

	glBegin(GL_LINES);
	glColor3f(1, 1, 0);
	glVertex2f(-5, -1);
	glVertex2f(4, 5);
	glEnd(); //������ �����

	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x1C47);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex2f(-4, 4);
	glVertex2f(5, -3);
	glEnd();
	glDisable(GL_LINE_STIPPLE); //������� �����-���������� �����

	glLineWidth(2.5);
	glBegin(GL_LINES);
	glColor3f(0, 1, 0);
	glVertex2f(-2, -2);
	glVertex2f(5, 3);
	glEnd(); //������� ������� �����


	glViewport(0, 0, Width / 2, Height / 2); //������ ��������

	glPointSize(5);
	glEnable(GL_POINT_SMOOTH);
	glBegin(GL_POINTS);
	glColor3f(1, 1, 0);
	glVertex2f(-3, 4);
	glEnd();
	glDisable(GL_POINT_SMOOTH); //������ ������� �����

	glEnable(GL_POINT_SMOOTH);
	glBegin(GL_POINTS);
	glColor3f(0, 1, 0);
	glVertex2f(3, -4);
	glEnd();
	glDisable(GL_POINT_SMOOTH); //������ �����

	glPointSize(15);
	glEnable(GL_POINT_SMOOTH);
	glBegin(GL_POINTS);
	glColor3f(0, 0, 1);
	glVertex2f(-5, -5);
	glEnd();
	glDisable(GL_POINT_SMOOTH); //����� ������� ������� �����

	glPointSize(15);
	glBegin(GL_POINTS);
	glColor3f(1, 0, 0);
	glVertex2f(3, 3);
	glEnd(); //������� ���������� ������� �����


	glViewport(Width / 2, 0, Width / 2, Height / 2); //��������� ��������

	glBegin(GL_LINE_STRIP);
	glColor3f(1, 1, 1);
	glVertex2f(-1, 1);
	glVertex2f(-1, 5);
	glVertex2f(-4, 2);
	glVertex2f(-3, 0.5);
	glVertex2f(-3, 5);
	glVertex2f(-5, 3.5);
	glEnd(); //������� �����

	glBegin(GL_TRIANGLES);
	glColor3f(0, 0, 1);
	glVertex2f(2, 3);
	glVertex2f(5, 2);
	glVertex2f(4.5, 5);
	glEnd(); //����� �����������

	glBegin(GL_POLYGON);
	glColor3f(1, 0.5, 0);
	glVertex2f(-4, -3);
	glVertex2f(1, -1);
	glVertex2f(4, -4);
	glVertex2f(0, -5);
	glEnd(); //��������� ������������


	float point[] = {
		0.0f, 0.0f, float(w), float(h),
		float(w) / 2.0f, float(h) / 2.0f, float(w) / 2.0f, float(h) / 2.0f,
		0.0f, float(h) / 2.0f, float(w) / 2.0f, float(h) / 2.0f,
		0.0f, 0.0f, float(w) / 2.0f, float(h) / 2.0f,
		float(w) / 2.0f, 0.0f, float(w) / 2.0f, float(h) / 2.0f
	}; //������ ����� ��� ��������

	glColor3f(1, 1, 1);
	for (int i = 0; i <= 16; i += 4)
	{
		glViewport(point[i], point[i + 1], point[i + 2], point[i + 3]);
		if (!i) glLineWidth(1.5);
		else glLineWidth(1);
		glBegin(GL_LINES);
		glVertex2f(-6, 0);
		glVertex2f(6, 0);
		glVertex2f(0, -6);
		glVertex2f(0, 6);
		glEnd();
	} //��������

	Output("K and S"); //������ ������


	glFinish();
}


void Reshape(GLint w, GLint h)
{
	Width = w;
	Height = h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(-6, 6, -6, 6);
}


int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(Width, Height);
	glutCreateWindow("lw2");
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutMainLoop();
}
