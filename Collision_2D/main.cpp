#include <SFML/Graphics.hpp>
#include "Application.h"
int main()
{
	//init Application
	Application app;

	//loop
	while (app.running())
	{
		//render frame
		app.update();

		//draw frame
		app.render();
	}

	//end application
	return 0;
}