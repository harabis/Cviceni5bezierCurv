#include "kresliObjekt.h"

void kresliObjekt::zmenCtrlPoint(int poradi, int x, int y)
{
	ctrlPoints[poradi][0] = x;
	ctrlPoints[poradi][1] = y;
}

void kresliObjekt::bezierovaKubika()
{
	glColor3f(0, 1.0, 0.0);

	glEnable(GL_POINT_SMOOTH);
	glPointSize(10.0f);

	glBegin(GL_POINTS);
	for (int d = 0; d < 4; d++) {
		glVertex2f(ctrlPoints[d][0], ctrlPoints[d][1]);
	}
	glEnd();

	glLineStipple(2, 0x00ff);
	glEnable(GL_LINE_STIPPLE);

	glBegin(GL_LINE_STRIP);
	for (int d = 0; d < 4; d++)
		glVertex2f(ctrlPoints[d][0], ctrlPoints[d][1]);
	glEnd();
	glDisable(GL_LINE_STIPPLE);

	float p0x = ctrlPoints[0][0];
	float p0y = ctrlPoints[0][1];
	float p1x = ctrlPoints[1][0];
	float p1y = ctrlPoints[1][1];
	float p2x = ctrlPoints[2][0];
	float p2y = ctrlPoints[2][1];
	float p3x = ctrlPoints[3][0];
	float p3y = ctrlPoints[3][1];

	float ax, ay, bx, by, cx, cy, dx, dy;
	float x, y, t;

	ax = p0x;
	ay = p0y;
	bx = 3.0f * (p1x - p0x);
	by = 3.0f * (p1y - p0y);
	cx = 3.0f * (p0x + p2x - 2.0f * p1x);
	cy = 3.0f * (p0y + p2y - 2.0f * p1y);
	dx = p3x - 3.0f * p2x + 3.0f * p1x - p0x;
	dy = p3y - 3.0f * p2y + 3.0f * p1y - p0y;

	glBegin(GL_LINE_STRIP);
	for (t = 0.0f; t < 1.0f; t += 0.01) {
		x = ax + bx * t + cx * t * t + dx * t * t * t;
		y = ay + by * t + cy * t * t + dy * t * t * t;
		glVertex2f(x, y);
	}
	glEnd();
}

void kresliObjekt::bezierovaKubikaEval()
{
	glColor3f(0, 0, 1.0);

	glEnable(GL_POINT_SMOOTH);
	glPointSize(10.0f);

	glBegin(GL_POINTS);
	for (int d = 4; d < 8; d++) {
		glVertex2f(ctrlPoints[d][0], ctrlPoints[d][1]);
	}
	glEnd();

	glLineStipple(2, 0x0df4);
	glEnable(GL_LINE_STIPPLE);

	glBegin(GL_LINE_STRIP);
	for (int d = 4; d < 8; d++)
		glVertex2f(ctrlPoints[d][0], ctrlPoints[d][1]);
	glEnd();
	glDisable(GL_LINE_STIPPLE);



	glEnable(GL_MAP1_VERTEX_3);
	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlPoints[4][0]);

	glBegin(GL_LINE_STRIP);
	for (float t = 0.0f; t < 1.0f; t += 0.01) {
		glEvalCoord1f(t);
	}
	glEnd();
}

void kresliObjekt::klikLeveho(int x, int y)
{
	if (bodNalezen == false)
	{
		for (int i = 0; i < 8; i++) {
			if ((abs(ctrlPoints[i][0] - x) < 10) && (abs(ctrlPoints[i][1] - y) < 10)) {
				bodNalezen = true;
				kteryBod = i;
				break;
			}
		}
	}

	if (bodNalezen)
	{
		ctrlPoints[kteryBod][0] = x;
		ctrlPoints[kteryBod][1] = y;
	}

}

void kresliObjekt::nastavBodNalezen(bool bodNalezen)
{
	this->bodNalezen = bodNalezen;
}
