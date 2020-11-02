#include <math.h>
#include <string>
#include <iostream>
#include <GL\glut.h>
using namespace std;

int alpha, beta;
float look_eye[3];
float theta[4], psi[4];
float light_post[3];

const float pi = 3.14;

float radii = 50;
int state = 0;
int stateTheta = 0;

GLUquadricObj *cylinder;

void multiply(float M[4][4], float N[4][4], float result[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			float SumElements = 0.0f;
			for (int k = 0; k < 4; k++) {
				SumElements += M[i][k] * N[k][j];
			}
			result[i][j] = SumElements;
		}
	}
}
void grid() {
	glPushAttrib(GL_POLYGON_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glPushAttrib(GL_CURRENT_BIT);
	glColor4f(1, 1, 1, 1);

	int i, j, min, max, inc;
	min = -50; max = -min;
	i = j = min;
	inc = 5;

	while (j < max) {
		i = min;
		glBegin(GL_QUAD_STRIP);
		while (i <= max) {
			glVertex3f(i, 0, j + inc);
			glVertex3f(i, 0, j);
			i = i + inc;
		}
		glEnd();
		j = j + inc;
	}
	glPopAttrib();
	glPopAttrib();
}

void object() {
	float m_diffuse[] = { 0.0f,  1.0f,  1.0f, 1.0f };
	float m_specular[] = { 1.0f,  1.0f,  1.0f, 1.0f };
	float shinines[] = { 100.0f };

	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, m_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shinines);


	//tiang sebelah Kiri
	glPushMatrix();
	//send
	//glRotatef(-psi[0], 1, 0, 0);
	glRotatef(theta[0], 0, 0, 1);

	//Lingkaran tengah kiri
	glPushMatrix();
	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glutSolidSphere(1.5, 30, 30);
	glPopMatrix();


	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, 0, 0);
	glPushMatrix();
	glRotatef(-260, 1, 0, 0.47);
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	gluCylinder(cylinder, 1.5, 1.8, 25, 30, 4);
	glPopMatrix();

	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, 0, 0);
	glPushMatrix();
	glRotatef(-260, 1, 0, -0.47);
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	gluCylinder(cylinder, 1.5, 1.8, 25, 30, 4);
	glPopMatrix();



	glPopMatrix();
	//tiang sebelah Kiri



	//tiang sebelah kanan
	glPushMatrix();
	glTranslatef(0, 0, 10);
	//send
	//glRotatef(-psi[0], 1, 0, 0);
	glRotatef(theta[0], 0, 0, 1);

	glPushMatrix();
	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glutSolidSphere(1.5, 30, 30);
	glPopMatrix();


	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, 0, 0);
	glPushMatrix();
	glRotatef(100, 1, 0, 0.5);
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	gluCylinder(cylinder, 1.5, 1.8, 25, 30, 4);
	glPopMatrix();

	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, 0, 0);
	glPushMatrix();
	glRotatef(100, 1, 0, -0.5);
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	gluCylinder(cylinder, 1.5, 1.8, 25, 30, 4);
	glPopMatrix();

	glPopMatrix();
	//tiang sebelah kanan

	//Tulang Tengah 
	glPushMatrix();
	//send
	//glRotatef(-psi[0], 1, 0, 0);
	glRotatef(theta[0], 0, 0, 1);

	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, 0, 0);
	glPushMatrix();
	glRotatef(1, 1, 0, 0.5);
	gluQuadricDrawStyle(cylinder, GLU_FILL);
	gluCylinder(cylinder, 1.5, 1.5, 10, 30, 4);
	glPopMatrix();
	glPopMatrix();
	//Tulang Tengah 

	//lingkaran Kanan Kincir
	glPushMatrix();
	//send
	//glRotatef(-psi[0], 1, 0, 0);
	glRotatef(theta[0], 0, 0, 1);

	m_diffuse[0] = 1;
	m_diffuse[1] = 0;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, 0, 2.75);
	glPushMatrix();
	glRotatef(1, 1, 0, 0.5);
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	gluDisk(cylinder, 15, 15, 100, 20);
	glPopMatrix();

	glPopMatrix();
	//lingkaran Kanan Kincir

	//lingkaran Kiri Kincir
	glPushMatrix();
	//send
	//glRotatef(-psi[0], 1, 0, 0);
	glRotatef(theta[0], 0, 0, 1);

	m_diffuse[0] = 1;
	m_diffuse[1] = 0;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, 0, 7.5);
	glPushMatrix();
	glRotatef(1, 1, 0, 0.5);
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	gluDisk(cylinder, 15, 15, 100, 20);
	glPopMatrix();

	glPopMatrix();
	//lingkaran Kiri Kincir


	//Kubus Garis Atas Bawah
	glPushMatrix();

	glRotatef(theta[0], 0, 0, 1);

	m_diffuse[0] = 0;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, 0, 5);
	glPushMatrix();
	glRotatef(1, 1, 0, 0);
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	glScalef(0, 7.5, 1);
	glutWireCube(4);
	glPopMatrix();

	glPopMatrix();
	//Batas


	//Kubus Garis Samping 1
	glPushMatrix();

	glRotatef(theta[0], 0, 0, 1);

	m_diffuse[0] = 0;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, 0, 5);
	glRotatef(-45, 1, 1, 45);
	glPushMatrix();
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	glScalef(0, 7.5, 1);
	glutWireCube(4);
	glPopMatrix();

	glPopMatrix();
	//Batas

	//Kubus Garis Samping 2
	glPushMatrix();

	glRotatef(theta[0], 0, 0, 1);

	m_diffuse[0] = 0;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, 0, 5);
	glRotatef(45, 1, 1, 45);
	glPushMatrix();
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	glScalef(0, 7.5, 1);
	glutWireCube(4);
	glPopMatrix();

	glPopMatrix();
	//Batas

	//Kubus Garis Kiri Kanan
	glPushMatrix();

	glRotatef(theta[0], 0, 0, 1);

	m_diffuse[0] = 0;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, 0, 5);
	glRotatef(90, 1, 1, 45);
	glPushMatrix();
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	glScalef(0, 7.5, 1);
	glutWireCube(4);
	glPopMatrix();

	glPopMatrix();
	//Batas



	//lingkaran dalam Kanan
	glPushMatrix();
	//send
	//glRotatef(-psi[0], 1, 0, 0);
	glRotatef(theta[0], 0, 0, 1);

	m_diffuse[0] = 1;
	m_diffuse[1] = 0;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, 0, 2.75);
	glPushMatrix();
	glRotatef(1, 1, 0, 0.5);
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	gluDisk(cylinder, 10, 10, 100, 20);
	glPopMatrix();

	glPopMatrix();
	//lingkaran dalam Kanan

	//lingkaran dalam kiri
	glPushMatrix();
	//send
	//glRotatef(-psi[0], 1, 0, 0);
	glRotatef(theta[0], 0, 0, 1);

	m_diffuse[0] = 1;
	m_diffuse[1] = 0;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, 0, 7.5);
	glPushMatrix();
	glRotatef(1, 1, 0, 0.5);
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	gluDisk(cylinder, 10, 10, 100, 20);
	glPopMatrix();

	glPopMatrix();
	//lingkaran dalam kiri




	//Bulet dan kotak 1 
	glPushMatrix();
	glRotatef(theta[2], 0, 0, 1);

	glPushMatrix();
	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0, 15, 3);
	glutSolidSphere(1, 30, 30);
	//Segitiga kiri
	glPushMatrix();
	//send
	//glRotatef(-psi[0], 1, 0, 0);
	glRotatef(theta[1], 0, 0, 1);

	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, -2, -1);
	glRotatef(30, 0, 0, -5);
	glPushMatrix();
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	glutWireTorus(1, 1, 1, 3);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();
	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0, 15, 8);
	glutSolidSphere(1, 30, 30);
	//Segitiga Kanan
	glPushMatrix();
	//send
	//glRotatef(-psi[0], 1, 0, 0);
	glRotatef(theta[1], 0, 0, 1);

	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, -2, 1);
	glRotatef(30, 0, 0, -5);
	glPushMatrix();
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	glutWireTorus(1, 1, 1, 3);

	//Sendi Kubus kecil kanan
	glPushMatrix();
	m_diffuse[0] = 0;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0.5, -1, 0);
	glutSolidSphere(0.5, 30, 30);


	//Sendi Kubus kecil kiri
	glPushMatrix();
	m_diffuse[0] = 0;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0.5, 0, -7);
	glutSolidSphere(0.5, 30, 30);

	//Kubus
	glPushMatrix();
	m_diffuse[0] = 1;
	m_diffuse[1] = 0.10;
	m_diffuse[2] = 0.5;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(1.5, -2.5, 3.5);
	glRotatef(-30, 0, 0, -5);


	glPushMatrix();
	gluQuadricDrawStyle(cylinder, GLU_FILL);
	glScalef(2.0, 1.5, 1.7);
	glutSolidCube(4);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPopMatrix();


	glPopMatrix();



	glPopMatrix();




	glPopMatrix();

	//Bulet dan kotak 2
	glPushMatrix();

	glTranslatef(10, -4, 0);
	glPushMatrix();
	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0, 15, 3);
	glutSolidSphere(1, 30, 30);
	//Segitiga kiri
	glPushMatrix();
	//send
	//glRotatef(-psi[0], 1, 0, 0);
	glRotatef(theta[1], 0, 0, 1);

	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, -2, -1);
	glRotatef(30, 0, 0, -5);
	glPushMatrix();
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	glutWireTorus(1, 1, 1, 3);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();
	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0, 15, 8);
	glutSolidSphere(1, 30, 30);
	//Segitiga Kanan
	glPushMatrix();
	//send
	//glRotatef(-psi[0], 1, 0, 0);
	glRotatef(theta[1], 0, 0, 1);

	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, -2, 1);
	glRotatef(30, 0, 0, -5);
	glPushMatrix();
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	glutWireTorus(1, 1, 1, 3);

	//Sendi Kubus kecil kanan
	glPushMatrix();
	m_diffuse[0] = 0;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0.5, -1, 0);
	glutSolidSphere(0.5, 30, 30);


	//Sendi Kubus kecil kiri
	glPushMatrix();
	m_diffuse[0] = 0;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0.5, 0, -7);
	glutSolidSphere(0.5, 30, 30);

	//Kubus
	glPushMatrix();
	m_diffuse[0] = 1;
	m_diffuse[1] = 0.10;
	m_diffuse[2] = 0.5;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(1.5, -2.5, 3.5);
	glRotatef(-30, 0, 0, -5);


	glPushMatrix();
	gluQuadricDrawStyle(cylinder, GLU_FILL);
	glScalef(2.0, 1.5, 1.7);
	glutSolidCube(4);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPopMatrix();

	glPopMatrix();

	glPopMatrix();


	glPopMatrix();

	glPushMatrix();

	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, 15, 3);
	glPushMatrix();
	glRotatef(1, 1, 0, 0.5);
	gluQuadricDrawStyle(cylinder, GLU_FILL);
	gluCylinder(cylinder, 1, 1, 5, 30, 4);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
	//batas

	//Bulet dan kotak 3
	glPushMatrix();

	glTranslatef(14, -14, 0);
	glPushMatrix();
	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0, 15, 3);
	glutSolidSphere(1, 30, 30);
	//Segitiga kiri
	glPushMatrix();
	//send
	//glRotatef(-psi[0], 1, 0, 0);
	glRotatef(theta[1], 0, 0, 1);

	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, -2, -1);
	glRotatef(30, 0, 0, -5);
	glPushMatrix();
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	glutWireTorus(1, 1, 1, 3);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();
	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0, 15, 8);
	glutSolidSphere(1, 30, 30);
	//Segitiga Kanan
	glPushMatrix();
	//send
	//glRotatef(-psi[0], 1, 0, 0);
	glRotatef(theta[1], 0, 0, 1);

	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, -2, 1);
	glRotatef(30, 0, 0, -5);
	glPushMatrix();
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	glutWireTorus(1, 1, 1, 3);

	//Sendi Kubus kecil kanan
	glPushMatrix();
	m_diffuse[0] = 0;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0.5, -1, 0);
	glutSolidSphere(0.5, 30, 30);


	//Sendi Kubus kecil kiri
	glPushMatrix();
	m_diffuse[0] = 0;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0.5, 0, -7);
	glutSolidSphere(0.5, 30, 30);

	//Kubus
	glPushMatrix();
	m_diffuse[0] = 1;
	m_diffuse[1] = 0.10;
	m_diffuse[2] = 0.5;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(1.5, -2.5, 3.5);
	glRotatef(-30, 0, 0, -5);


	glPushMatrix();
	gluQuadricDrawStyle(cylinder, GLU_FILL);
	glScalef(2.0, 1.5, 1.7);
	glutSolidCube(4);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPopMatrix();

	glPopMatrix();

	glPopMatrix();


	glPopMatrix();

	glPushMatrix();

	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, 15, 3);
	glPushMatrix();
	glRotatef(1, 1, 0, 0.5);
	gluQuadricDrawStyle(cylinder, GLU_FILL);
	gluCylinder(cylinder, 1, 1, 5, 30, 4);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
	//batas

	//Bulet dan kotak 4
	glPushMatrix();

	glTranslatef(12, -25, 0);
	glPushMatrix();
	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0, 15, 3);
	glutSolidSphere(1, 30, 30);
	//Segitiga kiri
	glPushMatrix();
	//send
	//glRotatef(-psi[0], 1, 0, 0);
	glRotatef(theta[1], 0, 0, 1);

	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, -2, -1);
	glRotatef(30, 0, 0, -5);
	glPushMatrix();
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	glutWireTorus(1, 1, 1, 3);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();
	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0, 15, 8);
	glutSolidSphere(1, 30, 30);
	//Segitiga Kanan
	glPushMatrix();
	//send
	//glRotatef(-psi[0], 1, 0, 0);
	glRotatef(theta[1], 0, 0, 1);

	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, -2, 1);
	glRotatef(30, 0, 0, -5);
	glPushMatrix();
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	glutWireTorus(1, 1, 1, 3);

	//Sendi Kubus kecil kanan
	glPushMatrix();
	m_diffuse[0] = 0;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0.5, -1, 0);
	glutSolidSphere(0.5, 30, 30);


	//Sendi Kubus kecil kiri
	glPushMatrix();
	m_diffuse[0] = 0;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0.5, 0, -7);
	glutSolidSphere(0.5, 30, 30);

	//Kubus
	glPushMatrix();
	m_diffuse[0] = 1;
	m_diffuse[1] = 0.10;
	m_diffuse[2] = 0.5;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(1.5, -2.5, 3.5);
	glRotatef(-30, 0, 0, -5);


	glPushMatrix();
	gluQuadricDrawStyle(cylinder, GLU_FILL);
	glScalef(2.0, 1.5, 1.7);
	glutSolidCube(4);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPopMatrix();

	glPopMatrix();

	glPopMatrix();


	glPopMatrix();

	glPushMatrix();

	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, 15, 3);
	glPushMatrix();
	glRotatef(1, 1, 0, 0.5);
	gluQuadricDrawStyle(cylinder, GLU_FILL);
	gluCylinder(cylinder, 1, 1, 5, 30, 4);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
	//batas

	//Bulet dan kotak 5
	glPushMatrix();

	glTranslatef(0, -30, 0);
	glPushMatrix();
	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0, 15, 3);
	glutSolidSphere(1, 30, 30);
	//Segitiga kiri
	glPushMatrix();
	//send
	//glRotatef(-psi[0], 1, 0, 0);
	glRotatef(theta[1], 0, 0, 1);

	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, -2, -1);
	glRotatef(30, 0, 0, -5);
	glPushMatrix();
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	glutWireTorus(1, 1, 1, 3);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();
	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0, 15, 8);
	glutSolidSphere(1, 30, 30);
	//Segitiga Kanan
	glPushMatrix();
	//send
	//glRotatef(-psi[0], 1, 0, 0);
	glRotatef(theta[1], 0, 0, 1);

	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, -2, 1);
	glRotatef(30, 0, 0, -5);
	glPushMatrix();
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	glutWireTorus(1, 1, 1, 3);

	//Sendi Kubus kecil kanan
	glPushMatrix();
	m_diffuse[0] = 0;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0.5, -1, 0);
	glutSolidSphere(0.5, 30, 30);


	//Sendi Kubus kecil kiri
	glPushMatrix();
	m_diffuse[0] = 0;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0.5, 0, -7);
	glutSolidSphere(0.5, 30, 30);

	//Kubus
	glPushMatrix();
	m_diffuse[0] = 1;
	m_diffuse[1] = 0.10;
	m_diffuse[2] = 0.5;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(1.5, -2.5, 3.5);
	glRotatef(-30, 0, 0, -5);


	glPushMatrix();
	gluQuadricDrawStyle(cylinder, GLU_FILL);
	glScalef(2.0, 1.5, 1.7);
	glutSolidCube(4);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPopMatrix();

	glPopMatrix();

	glPopMatrix();


	glPopMatrix();

	glPushMatrix();

	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, 15, 3);
	glPushMatrix();
	glRotatef(1, 1, 0, 0.5);
	gluQuadricDrawStyle(cylinder, GLU_FILL);
	gluCylinder(cylinder, 1, 1, 5, 30, 4);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
	//batas

	//Bulet dan kotak 6
	glPushMatrix();

	glTranslatef(-10, -26, 0);
	glPushMatrix();
	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0, 15, 3);
	glutSolidSphere(1, 30, 30);
	//Segitiga kiri
	glPushMatrix();
	//send
	//glRotatef(-psi[0], 1, 0, 0);
	glRotatef(theta[1], 0, 0, 1);

	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, -2, -1);
	glRotatef(30, 0, 0, -5);
	glPushMatrix();
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	glutWireTorus(1, 1, 1, 3);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();
	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0, 15, 8);
	glutSolidSphere(1, 30, 30);
	//Segitiga Kanan
	glPushMatrix();
	//send
	//glRotatef(-psi[0], 1, 0, 0);
	glRotatef(theta[1], 0, 0, 1);

	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, -2, 1);
	glRotatef(30, 0, 0, -5);
	glPushMatrix();
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	glutWireTorus(1, 1, 1, 3);

	//Sendi Kubus kecil kanan
	glPushMatrix();
	m_diffuse[0] = 0;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0.5, -1, 0);
	glutSolidSphere(0.5, 30, 30);


	//Sendi Kubus kecil kiri
	glPushMatrix();
	m_diffuse[0] = 0;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0.5, 0, -7);
	glutSolidSphere(0.5, 30, 30);

	//Kubus
	glPushMatrix();
	m_diffuse[0] = 1;
	m_diffuse[1] = 0.10;
	m_diffuse[2] = 0.5;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(1.5, -2.5, 3.5);
	glRotatef(-30, 0, 0, -5);


	glPushMatrix();
	gluQuadricDrawStyle(cylinder, GLU_FILL);
	glScalef(2.0, 1.5, 1.7);
	glutSolidCube(4);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPopMatrix();

	glPopMatrix();

	glPopMatrix();


	glPopMatrix();

	glPushMatrix();

	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, 15, 3);
	glPushMatrix();
	glRotatef(1, 1, 0, 0.5);
	gluQuadricDrawStyle(cylinder, GLU_FILL);
	gluCylinder(cylinder, 1, 1, 5, 30, 4);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
	//batas

	//Bulet dan kotak 7
	glPushMatrix();

	glTranslatef(-15, -15, 0);
	glPushMatrix();
	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0, 15, 3);
	glutSolidSphere(1, 30, 30);
	//Segitiga kiri
	glPushMatrix();
	//send
	//glRotatef(-psi[0], 1, 0, 0);
	glRotatef(theta[1], 0, 0, 1);

	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, -2, -1);
	glRotatef(30, 0, 0, -5);
	glPushMatrix();
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	glutWireTorus(1, 1, 1, 3);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();
	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0, 15, 8);
	glutSolidSphere(1, 30, 30);
	//Segitiga Kanan
	glPushMatrix();
	//send
	//glRotatef(-psi[0], 1, 0, 0);
	glRotatef(theta[1], 0, 0, 1);

	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, -2, 1);
	glRotatef(30, 0, 0, -5);
	glPushMatrix();
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	glutWireTorus(1, 1, 1, 3);

	//Sendi Kubus kecil kanan
	glPushMatrix();
	m_diffuse[0] = 0;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0.5, -1, 0);
	glutSolidSphere(0.5, 30, 30);


	//Sendi Kubus kecil kiri
	glPushMatrix();
	m_diffuse[0] = 0;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0.5, 0, -7);
	glutSolidSphere(0.5, 30, 30);

	//Kubus
	glPushMatrix();
	m_diffuse[0] = 1;
	m_diffuse[1] = 0.10;
	m_diffuse[2] = 0.5;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(1.5, -2.5, 3.5);
	glRotatef(-30, 0, 0, -5);


	glPushMatrix();
	gluQuadricDrawStyle(cylinder, GLU_FILL);
	glScalef(2.0, 1.5, 1.7);
	glutSolidCube(4);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPopMatrix();

	glPopMatrix();

	glPopMatrix();


	glPopMatrix();

	glPushMatrix();

	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, 15, 3);
	glPushMatrix();
	glRotatef(1, 1, 0, 0.5);
	gluQuadricDrawStyle(cylinder, GLU_FILL);
	gluCylinder(cylinder, 1, 1, 5, 30, 4);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
	//batas

	//Bulet dan kotak 8
	glPushMatrix();

	glTranslatef(-10, -4, 0);
	glPushMatrix();
	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0, 15, 3);
	glutSolidSphere(1, 30, 30);
	//Segitiga kiri
	glPushMatrix();
	//send
	//glRotatef(-psi[0], 1, 0, 0);
	glRotatef(theta[1], 0, 0, 1);

	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, -2, -1);
	glRotatef(30, 0, 0, -5);
	glPushMatrix();
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	glutWireTorus(1, 1, 1, 3);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();
	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0, 15, 8);
	glutSolidSphere(1, 30, 30);
	//Segitiga Kanan
	glPushMatrix();
	//send
	//glRotatef(-psi[0], 1, 0, 0);
	glRotatef(theta[1], 0, 0, 1);

	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, -2, 1);
	glRotatef(30, 0, 0, -5);
	glPushMatrix();
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	glutWireTorus(1, 1, 1, 3);

	//Sendi Kubus kecil kanan
	glPushMatrix();
	m_diffuse[0] = 0;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0.5, -1, 0);
	glutSolidSphere(0.5, 30, 30);


	//Sendi Kubus kecil kiri
	glPushMatrix();
	m_diffuse[0] = 0;
	m_diffuse[1] = 1;
	m_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glTranslatef(0.5, 0, -7);
	glutSolidSphere(0.5, 30, 30);

	//Kubus
	glPushMatrix();
	m_diffuse[0] = 1;
	m_diffuse[1] = 0.10;
	m_diffuse[2] = 0.5;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(1.5, -2.5, 3.5);
	glRotatef(-30, 0, 0, -5);


	glPushMatrix();
	gluQuadricDrawStyle(cylinder, GLU_FILL);
	glScalef(2.0, 1.5, 1.7);
	glutSolidCube(4);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPopMatrix();

	glPopMatrix();

	glPopMatrix();


	glPopMatrix();

	glPushMatrix();

	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, 15, 3);
	glPushMatrix();
	glRotatef(1, 1, 0, 0.5);
	gluQuadricDrawStyle(cylinder, GLU_FILL);
	gluCylinder(cylinder, 1, 1, 5, 30, 4);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
	//batas

	glPushMatrix();



	m_diffuse[0] = 1;
	m_diffuse[1] = 1;
	m_diffuse[2] = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);

	glTranslatef(0, 15, 3);
	glPushMatrix();
	glRotatef(1, 1, 0, 0.5);
	gluQuadricDrawStyle(cylinder, GLU_FILL);
	gluCylinder(cylinder, 1, 1, 5, 30, 4);
	glPopMatrix();

	glPopMatrix();



	glPopMatrix();
	//batas





}
void init() {
	glClearColor(0, 0.0, 0.0, 1);

	cylinder = gluNewQuadric();

	look_eye[0] = 0;
	look_eye[1] = 0;
	look_eye[2] = 0.5*radii;

	light_post[0] = light_post[1] = light_post[2] = 0;

	alpha = beta = 0;

	for (int t = 0; t < 2; t++) { theta[t] = psi[t] = 0; }

}
void display() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (state == 0) {
		glOrtho(-0.5*radii, 0.5*radii, -0.5*radii, 0.5*radii, 0, radii);

	}
	else {
		gluPerspective(90, 1, 10, 40);
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(look_eye[0], look_eye[1], look_eye[2], 0, 0, 0, 0, 1, 0);
	cout << "[" << look_eye[0] << "," << look_eye[1] << ", " << look_eye[2] << "]" << endl;
	grid();

	glPushMatrix();
	glTranslatef(light_post[0], light_post[1], light_post[2]);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	//float l_position[] = { 50.0f, 50.0f, 50.0f, 1.0f };
	float l_position[] = { light_post[0], light_post[1], light_post[2] , 1.0f };

	float l_ambient[] = { 1.0f,  1.0f,  1.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, l_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, l_ambient);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	object();
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);

	glDisable(GL_DEPTH_TEST);
	glutSwapBuffers();
}
void delay() { for (int i = 0; i < 3500; i++) for (int j = 0; j < 3500; j++); }

void animation() {

	if (animation) {
		theta[1] = theta[1] - 0.5;
		theta[2] = theta[2] + 0.5;

	}

	delay();
	glutPostRedisplay();
}
void pause() {

}
void keyboard(unsigned char key, int xmouse, int ymouse) {
	float aradian, bradian, gradian;

	switch (key)
	{
	case 'w': alpha = (alpha + 5) % 360; break;
	case 's': alpha = (alpha - 5) % 360; break;
	case 'd': beta = (beta + 5) % 360; break;
	case 'a': beta = (beta - 5) % 360; break;
		//Zoom
	case 'o': state = 0; break;
	case 'p': state = 1; break;




	case '+':  theta[1] --; theta[2] ++; break;
	case '-':  theta[1]++;  theta[2] --; break;
		//Light_post
	case 'y': light_post[0]++; break;
	case 'h': light_post[0]--; break;
	case 'u': light_post[1]++; break;
	case 'j': light_post[1]--; break;
	case 'i': light_post[2]++; break;
	case 'k': light_post[2]--; break;
		//Animation
	case '1':glutIdleFunc(animation); break;
	case '2':glutIdleFunc(pause); break;




	default:
		break;
	}

	aradian = -alpha * pi / 180.0;
	bradian = beta * pi / 180.0;


	float xaxis[4][4] = {
		{ 1, 0, 0, 0 },
		{ 0, cos(aradian),  -sin(aradian), 0 },
		{ 0, sin(aradian), cos(aradian), 0 },
		{ 0, 0, 0, 1 },
	};

	float yaxis[4][4] = {
		{ cos(bradian), 0, sin(bradian), 0 },
		{ 0, 1, 0, 0 },
		{ -sin(bradian), 0, cos(bradian), 0 },
		{ 0, 0, 0, 1 },
	};

	float point[4][4] = {
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0.5*radii, 0, 0, 0 },
		{ 0, 0, 0, 1 },
	};

	float result[4][4];


	multiply(xaxis, point, result);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			point[i][j] = result[i][j];
		}
	}

	multiply(yaxis, point, result);

	look_eye[0] = result[0][0];
	look_eye[1] = result[1][0];
	look_eye[2] = result[2][0];

	//glutPostRedisplay();

	//for (int i = 0; i < 5; i++) {
	//glutPostRedisplay();
	//}

	glutPostRedisplay();
}
void main() {
	glutInitWindowSize(500, 500);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("3D OBJECT");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}
