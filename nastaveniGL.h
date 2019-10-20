#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
class nastaveniGL
{
public:
	nastaveniGL(int sirka, int vyska);
	void zmenaOkna(int sirka, int vyska);
	void obnov(int sirka, int vyska);
};

