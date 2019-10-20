#include "nastaveniGL.h"

nastaveniGL::nastaveniGL(int sirka, int vyska)
{
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);	
	glLoadIdentity();
	glOrtho(0, sirka, 0, vyska, -1, 1);
	glScalef(1, -1, 1);
	glTranslatef(0, -vyska, 0);
}

void nastaveniGL::zmenaOkna(int sirka, int vyska)
{
	glViewport(0, 0, sirka, vyska);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);
	glOrtho(0, sirka, 0, vyska, -1, 1);
	glScalef(1, -1, 1);
	glTranslatef(0, -vyska, 0);
}

void nastaveniGL::obnov(int sirka, int vyska)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, sirka, 0, vyska, -1, 1);
	glScalef(1, -1, 1);
	glTranslatef(0, -vyska, 0);
}
