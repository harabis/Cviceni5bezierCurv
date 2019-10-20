#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>


class kresliObjekt
{
public:
	void bezierovaKubika();
	void bezierovaKubikaEval();
	void klikLeveho(int x, int y);
	void nastavBodNalezen(bool nalezen);

private:
	bool bodNalezen;
	int kteryBod;
	float ctrlPoints[8][3] = {
		{ 100,100,0 },
		{ 400,100,0 },
		{ 400,400,0 },
		{ 100,400,0 },
		{ 500,500,0 },
		{ 550,500,0 },
		{ 550,550,0 },
		{ 500,550,0 }
	};

	void zmenCtrlPoint(int poradi, int x, int y);


};

