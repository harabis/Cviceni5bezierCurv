// Cviceni5bezierCurv.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <math.h>
#include <vector>

#include "nastaveniGL.h"
#include "kresliObjekt.h"

using namespace std;

int main()
{

	sf::Window Aplikace(sf::VideoMode(800, 600), "Cviceni 5 - Bezier curves");
	kresliObjekt kresli;

	nastaveniGL nastavGL(800, 600);
	int poradiBodu;

	bool jeFull = false;

	bool bodNalezen = false;


	while (Aplikace.isOpen())
	{
		sf::Event Udalosti;

		while (Aplikace.pollEvent(Udalosti))
		{
			switch (Udalosti.type)
			{

			case sf::Event::Closed:
				Aplikace.close();
				break;

			case sf::Event::Resized:
				nastavGL.zmenaOkna(Udalosti.size.width, Udalosti.size.height);
				break;

			case sf::Event::KeyPressed:
				switch (Udalosti.key.code)
				{
				case sf::Keyboard::Escape:
					Aplikace.close();
					break;
				case sf::Keyboard::W:
					
					if (jeFull) // když je fullscreen, tak zmenši do okna 
					{
						Aplikace.create(sf::VideoMode(800, 600), "Cviceni 4 - udalosti", sf::Style::Default);
						nastavGL.obnov(800,600);
						jeFull = false;
					}
					else // když není fullscreen, tak zvětši na celou obrazovku 
					{
						sf::VideoMode videoMod(sf::VideoMode::getFullscreenModes()[0]);
						Aplikace.create(sf::VideoMode(videoMod), "Cviceni 4 - udalosti", sf::Style::Fullscreen);
						nastavGL.obnov(videoMod.width, videoMod.height);
						jeFull = true;
						
					}
					break;
				}

			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				kresli.klikLeveho(sf::Mouse::getPosition(Aplikace).x, sf::Mouse::getPosition(Aplikace).y);		
											
			}
			else
			{
				kresli.nastavBodNalezen(false);				
			}


		}

		// kresli bezierovou křivku
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		kresli.bezierovaKubika();
		kresli.bezierovaKubikaEval();
				
		
		glFlush();
			
		Aplikace.display();
			   		 	  	  	   
	}

 

	return 0;
}


