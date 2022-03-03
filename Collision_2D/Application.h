#pragma once

#include <SFML/Graphics.hpp>

/*
* wrapper class for application
*/

class Application
{
private:

	//vars
	//window
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;
	//objects
	sf::RectangleShape block;
	
	//private fun
	void initVariables();
	void initWindow();
	void initBlocks();

public:
	//con-/cestructor
	Application();
	virtual ~Application();

	//functions
	void update();
	void render();

	//acc functions
	const bool running();
	void pollEvents();
};

