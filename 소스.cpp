#include<glut.h>
#include <stdlib.h>
#include <math.h>

int angles[71];
static GLfloat fx, lx, fy, ly, valx = 0.0, valy = 0.0;
static int temx = 0, temy = 0;
static GLfloat pi = 4 * atan(1.0);
static GLfloat val = pi / 180.0;
static int delay = 1000;
GLfloat scale = 1.0;
GLUquadricObj *pQuad;
int Width = 1000, Height = 1000, temp = 0, c_y = 0, e_y = 0, c_x = 0, c_z = 0, e_z = 0, e_x = 0;
GLfloat left_x = -1, right_x = 1, size = 5;
static GLfloat eye[3] = { 25 + e_x, e_y + size - 25, e_z + 5 }, tmpeye[3] = { 0.0, 0.0, 0.0 }, at[3] = { c_x, c_y - 2, c_z }, thetax = 0.0, thetay = 0.0;

void drawRectangle_3(float a, float b, float c, int color, int flag)
{
	//¾Æ·§¸é
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.1f*b, 0.0f);
	glVertex3f(0.1f*a, 0.1f*b, 0.0f);
	glVertex3f(0.1f*a, 0.0f, 0.0f);
	glEnd();

	//¿À¸¥ÂÊ¸é
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0.6);
	glVertex3f(0.1f*a, 0.0f, 0.0f);
	glVertex3f(0.1f*a, 0.1f*b, 0.0f);
	glVertex3f(0.1f*a, 0.1f*b, 0.1f*c);
	glVertex3f(0.1f*a, 0.0f, 0.1f*c);
	glEnd();

	//À­¸é
	glBegin(GL_POLYGON);
	if (flag == 1)
		glColor3f(1, 0, 0);
	else
		glColor3f(1, 1, 0.4 + (color / 30.0));
	glNormal3f(-1.0, 0.0, 0.0);
	glVertex3f(0.1f*a, 0.0f, 0.1f*c);
	glVertex3f(0.1f*a, 0.1f*b, 0.1f*c);
	glVertex3f(0.0f, 0.1f*b, 0.1f*c);
	glVertex3f(0.0f, 0.0f, 0.1f*c);
	glEnd();

	glBegin(GL_POLYGON);
	if (flag == 1)
		glColor3f(1, 1, 0.4 + (color / 30.0));
	else
		glColor3f(1, 0, 0);
	glVertex3f(0.1f*a, 0.0f, 0.1f*c);
	glVertex3f(0.1f*a, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.1f*c);
	glEnd();

	//left
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3f(0.1f*a, 0.1f*b, 0.1f*c);
	glVertex3f(0.1f*a, 0.1f*b, 0.0f);
	glVertex3f(0.0f, 0.1f*b, 0.0f);
	glVertex3f(0.0f, 0.1f*b, 0.1f*c);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5, 0, 0);
	glVertex3f(0.0f, 0.1f*b, 0.1f*c);
	glVertex3f(0.0f, 0.0f, 0.1f*c);
	glVertex3f(0.0f, 0.0f, 0.0f*c);
	glVertex3f(0.0f, 0.1f*b, 0.0f*c);
	glEnd();
}
//¹Ù´Ú
void drawSquare(float a, float b, float c) {
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.1f*b, 0.0f);
	glVertex3f(0.1f*a, 0.1f*b, 0.0f);
	glVertex3f(0.1f*a, 0.0f, 0.0f);
	glEnd();
}
//µµ¹Ì³ë
void display() {
	float har, x, y, z;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glFrustum(left_x, right_x, -1.0, 1.0, 4.0, 100000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glColor3f(0, 0.0, 1);
	glTranslatef(-100, 100, 0);
	//glRotated(90.0, 1.0, 0.0, 0.0);
	drawSquare(2000.0, 10000.0, 10.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.2, 0.2, 0.2);
	glTranslatef(-1, 0, 0);
	gluLookAt(eye[0], eye[1], eye[2], at[0], at[1], at[2], 0, 1, 0);

	glRotated(90.0, 0.0, 1.0, 0.0);

	int c = 1;
	for (int i = 0; i < 70; i = i + 1) {

		for (float j = 0.6*i; j <= i * 0.61; j = j + 1) {
			glPushMatrix();
			glTranslatef(j, i / 1.5, 0);
			if (-0.1* angles[i + 1] < -70) {
				glRotatef(-80, 1, 0, 0);
				drawRectangle_3(8.0, 5.0, 10.0, i + j, 1);

			}
			else {
				if (angles[i + 1] >= 0 && angles[i] >= 50) {
					glRotatef(-0.1* angles[i + 1], 1, 0, 0);
				}
				drawRectangle_3(8.0, 5.0, 10.0, i + j, 1);
			}
			glPopMatrix();
		}


		for (float j = -0.6*i; j < 0.6* ((float)i - 0.5); j = j + 1.2) {
			glPushMatrix();
			glTranslatef(j, i / 1.5, 0);
			if (-0.1* angles[i + 1] < -70) {
				glRotatef(-60, 1, 0, 0);

				if ((i >= 20 && i < 30) && (j > -0.59*i))
					drawRectangle_3(8.0, 5.0, 10.0, i + j, 2);
				if ((i >= 30 && i<40) && (j > 15))
					drawRectangle_3(8.0, 5.0, 10.0, i + j, 2);
				if ((i >= 40 && i < 50) && (j > -0.59*i))
					drawRectangle_3(8.0, 5.0, 10.0, i + j, 2);
				if ((i >= 50 && i<60) && (j<-20 && j > -0.59*i))
					drawRectangle_3(8.0, 5.0, 10.0, i + j, 2);
				if ((i >= 60 && i<68) && (j > -0.59*i))
					drawRectangle_3(8.0, 5.0, 10.0, i + j, 2);
				else drawRectangle_3(8.0, 5.0, 10.0, i + j, 1);
			}
			else {
				if (angles[i + 1] >= 0 && angles[i] >= 50) {
					glRotatef(-0.1* angles[i + 1], 1, 0, 0);
				}
				if ((i >= 20 && i < 30) &&  (j > -0.59*i))
					drawRectangle_3(8.0, 5.0, 10.0, i + j, 2);
				if ((i >= 30 && i<40) && (j > 15))
					drawRectangle_3(8.0, 5.0, 10.0, i + j, 2);
				if ((i >= 40 && i < 50) && (j > -0.59*i))
					drawRectangle_3(8.0, 5.0, 10.0, i + j, 2);
				if ((i >= 50 && i<60) && (j<-20 && j > -0.59*i))
					drawRectangle_3(8.0, 5.0, 10.0, i + j, 2);
				if ((i >= 60 && i<68) && (j > -0.59*i))
					drawRectangle_3(8.0, 5.0, 10.0, i + j, 2);
				else drawRectangle_3(8.0, 5.0, 10.0, i + j, 1);


			}
			glPopMatrix();
		}
	}
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}

void init() {
	pQuad = gluNewQuadric();
	glEnable(GL_DEPTH_TEST);
	glClearColor(0, 0, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}
void timer() {
	for (int i = 1; i < 71; ++i) {
		angles[i] += 1;
	}
	if (angles[70] <= 60) {
		eye[2] -= sin((thetax)*(val)) / 20.0;
		eye[0] += cos((thetax)*(val)) / 20.0;
	}
	glutPostRedisplay();
}
void keyboard_handler(unsigned char key, int x, int y)
{
	GLfloat fraction = 0.3;

	if (key == 'a') {
		eye[0] += fraction * cos((thetax + 90)*(val));
		at[0] += fraction * cos((thetax + 90)*(val));
		eye[2] += fraction * sin((thetax + 90)*(val));
		at[2] += fraction * sin((thetax + 90)*(val));
	}
	if (key == 'd') {
		eye[0] -= fraction * cos((thetax + 90)*(val));
		at[0] -= fraction * cos((thetax + 90)*(val));
		eye[2] -= fraction * sin((thetax + 90)*(val));
		at[2] -= fraction * sin((thetax + 90)*(val));
	}
	if (key == 'w') {
		eye[1] += fraction * cos((thetax)*(val));
		at[1] += fraction * cos((thetax)*(val));
		eye[2] += fraction * sin((thetax)*(val));
		at[2] += fraction * sin((thetax)*(val));
	}
	if (key == 's') {
		eye[1] -= fraction * cos((thetax)*(val));
		at[1] -= fraction * cos((thetax)*(val));
		eye[2] -= fraction * sin((thetax)*(val));
		at[2] -= fraction * sin((thetax)*(val));
	}

	if (key == 'z') {
		glutIdleFunc(timer);
	}
	if (key == 'x') {
		glutDestroyWindow(glutCreateWindow("Domino"));
		exit(0);
	}

}
int main(int argc, char* argv[])
{
	angles[0] = 60;

	for (int i = 1; i <= 70; i++)
		angles[i] = -60 * (i - 1);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Simple OpenGL Example");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard_handler);
	
	init();

	glutMainLoop();
	return 0;
}
/*

#include<gl/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <WinUser.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#define Max 20


GLfloat angle1 = 0.0;

static GLfloat eye[3] = { 5.0, 2.0, 20.0 }, tmpeye[3] = { 0.0, 0.0, 0.0 }, at[3] = { 2.0, 0.0, 0.0 }, thetax = 0.0, thetay = 0.0;
static GLfloat fx, lx, fy, ly, valx = 0.0, valy = 0.0;
static int temx = 0, temy = 0;
static GLfloat pi = 4 * atan(1.0);
static GLfloat val = pi / 180.0;
static GLfloat angle = 0.0;
int Gx, Gy;
int direction_parts = 36, cur = 0;
double distance = 4.;
char Domino[Max][Max];
bool dominocheck[Max][Max] = { { false, }, };
bool start = 0;


//¹Ù´ÚÀ» ±×¸²
void drawFloor(GLfloat x1, GLfloat x2, GLfloat z1, GLfloat z2) {
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex3f(x1, 0, z2);
	glVertex3f(x2, 0, z2);
	glVertex3f(x2, 0, z1);
	glVertex3f(x1, 0, z1);
	glEnd();
}
void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT0); //ºû
	glEnable(GL_LIGHTING); //ÀÔÃ¼°¨
	glEnable(GL_COLOR_MATERIAL); //»ö±ò
	angle = 90 / Max;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	drawFloor(-12000, 12000, -120000, 120000);
}
//¹Ì·Î¸¦ ±×

void drawDomino(GLint j, GLint i) {
	GLfloat x1 = i, x2 = (i + 1), y1 = 0, y2 = 2, z1 = j, z2 = (j + 0.5);
	//glRotatef(angle, 0, 1, 0);
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex3f(x2, y1, z1);
	glVertex3f(x1, y1, z1);
	glVertex3f(x1, y2, z1);
	glVertex3f(x2, y2, z1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0.0, 0.0, 1.0);
	glVertex3f(x1, y1, z2);
	glVertex3f(x2, y1, z2);
	glVertex3f(x2, y2, z2);
	glVertex3f(x1, y2, z2);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-1.0, 0.0, 0.0);
	glVertex3f(x1, y1, z1);
	glVertex3f(x1, y1, z2);
	glVertex3f(x1, y2, z2);
	glVertex3f(x1, y2, z1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(1.0, 0.0, 0.0);
	glVertex3f(x2, y1, z2);
	glVertex3f(x2, y1, z1);
	glVertex3f(x2, y2, z1);
	glVertex3f(x2, y2, z2);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0.0, 1.0, 0.0);
	glVertex3f(x1, y2, z2);
	glVertex3f(x2, y2, z2);
	glVertex3f(x2, y2, z1);
	glVertex3f(x1, y2, z1);

	glBegin(GL_POLYGON);
//	glNormal3f();
	glEnd();

}
//
void spin_cube() {
	angle1 += 15.0;
	glutPostRedisplay();
}



void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawFloor(-120000, 120000, -120000, 120000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye[0], eye[1], eye[2], at[0], at[1], at[2], 0, 1, 0);

	for (int i = 0; i < Gx * 2; i = i + 2) {

		for (int j = 0; j < Gy * 2; j = j + 2) {
			if (Domino[i][j] == 'b') {
				glPushMatrix();
				drawDomino(i, j);
				glPopMatrix();
			}
		}
	}
	glPushMatrix();
	glColor3f(89 / 256.0, 218.0 / 256.0, 80.0 / 256.0);
	glTranslatef(1.4, 0, -0.1);
	if (start)
		glTranslatef(0.12f, 0.0f, 0.0f);

	glPopMatrix();
	glutSwapBuffers();

	if (angle1 < 80.0 && start == 1)
		angle1 += 2.0f;
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 60.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 25, 0, 0, 0, 0, 1, 0);
}

void keyboard_handler(unsigned char key, int x, int y) {

	GLfloat fraction = 0.1;

	if (key == 'a') {
		eye[0] -= fraction * sin((thetax + 90)*(val));
		at[0] -= fraction * sin((thetax + 90)*(val));
		eye[2] -= fraction * cos((thetax + 90)*(val));
		at[2] -= fraction * cos((thetax + 90)*(val));
	}
	if (key == 'd') {
		eye[0] += fraction * sin((thetax + 90)*(val));
		at[0] += fraction * sin((thetax + 90)*(val));
		eye[2] += fraction * cos((thetax + 90)*(val));
		at[2] += fraction * cos((thetax + 90)*(val));
	}
	if (key == 'w') {
		eye[0] -= fraction * sin((thetax)*(val));
		at[0] -= fraction * sin((thetax)*(val));
		eye[2] -= fraction * cos((thetax)*(val));
		at[2] -= fraction * cos((thetax)*(val));
	}
	if (key == 's') {
		eye[0] += fraction * sin((thetax)*(val));
		at[0] += fraction * sin((thetax)*(val));
		eye[2] += fraction * cos((thetax)*(val));
		at[2] += fraction * cos((thetax)*(val));
	}
	if (key == 'u') {
		eye[1] += cos((thetax)*(val));
		eye[2] -= sin((thetax)*(val));
	}
	if (key == 'U') {
		eye[1] -= cos((thetax)*(val));
		eye[2] += sin((thetax)*(val));
	}
	if (key == 'x') {
		glutDestroyWindow(glutCreateWindow("Domino"));
		exit(0);
	}
}

void RandomDomino(int Dx, int Dy) {
	int dir;

	dir = rand() % 4;
	Domino[Dx][Dy] = 'a';
	dominocheck[Dx][Dy] = true;
	if (dir = 0) {
		if (Dx + 1 > Gx || dominocheck[Dx + 1][Dy])
			return;
		RandomDomino(Dx + 1, Dy);
	}
	else if (dir == 1) {
		if (Dx - 1 < 0 || dominocheck[Dx - 1][Dy])
			return;
		RandomDomino(Dx - 1, Dy);
	}
	else if (dir == 2) {
		if (Dy + 1 > Gy || dominocheck[Dx][Dy + 1])
			return;
		RandomDomino(Dx, Dy + 1);
	}
	else if (dir == 3) {
		if (Dy - 1 < 0 || dominocheck[Dx][Dy - 1])
			return;
		RandomDomino(Dx, Dy - 1);
	}

}

void made() {

	int i, j;
	for (i = 0; i < Gx; i++) {
		for (j = 0; j < Gy; j++) {
			if ((i == 0) || (j == 0) || (i == Gx - 1) || (j == Gy - 1)) {
				Domino[i][j] = 'b';
			}
			else
				Domino[i][j] = 'e';
		}
	}
}
void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		start = 1;
}
void fallen() {

	glRotatef(angle1, 1, 0, 1);

}
int main(int argc, char** argv) {

	int select;
	srand((unsigned)time(NULL));

	printf("1. Custom mode : \n2. Random mode : \n");
	scanf("%d", &select);
	if (select == 1) {
		while (1) {
			printf("Type a X , Y (X,Y < 50) : ");
			scanf("%d %d", &Gx, &Gy);
			if (Gx * 2 > Max)
				printf("X is too big !!\n");
			if (Gy * 2 > Max)
				printf("Y is too big !!\n");
			if (Gx * 2 <= Max & Gy * 2 <= Max)
				break;
		}

		for (int i = 0; i < Gx * 2; i = i + 2) {
			for (int j = 0; j < Gy * 2; j = j + 2) {
				scanf(" %c", &Domino[i][j]);
			}
		}
	}
	else {
		Gx = rand() % 20;
		Gy = rand() % 20;
		made();
		RandomDomino(Gx / 2, Gy / 2);
	}

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1200, 1000);
	glutCreateWindow("Domino");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard_handler);
	glutMouseFunc(mouse);

	glutIdleFunc(spin_cube);
	glutMainLoop();
	return 0;
}*/