#include "Application.h"

//priv functions

void Application::initVariables()
{
	this->window = nullptr;
}

void Application::initWindow()
{
	this->videoMode.height = 800;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(this->videoMode,"2D_Collision", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Application::initBlocks()
{
	this->block.setPosition(200.f, 200.f);
	this->block.setSize(sf::Vector2f(100.f, 100.f));
	this->block.setFillColor(sf::Color::Blue);
	this->block.setOutlineColor(sf::Color::Green);
	this->block.setOutlineThickness(2.f);
}

//con-/destructor

Application::Application()
{
	this->initVariables();
	this->initWindow();
	this->initBlocks();
}

Application::~Application()
{
	delete this->window;
}

//functions

void Application::update()
{
	this->pollEvents();
}

void Application::render()
{
	this->window->clear();
	this->window->draw(this->block);
	//draw frame
	this->window->display();
}

//check if window is still open/app is running
const bool Application::running()
{
	return this->window->isOpen();
}

//check for events and handle them
void Application::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}