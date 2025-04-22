// Authors: Luke B. ; Ahmad Y.

// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>




//Make the code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
	srand(time(NULL));
	// Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the game
	RenderWindow window(vm, "Chaos Game!!", Style::Default);
	
	vector<Vector2f> vertices;
	vector<Vector2f> points;
	

	//Fixed Font issue
	sf::Font font;
	if(!font.loadFromFile("Ubuntu-M.ttf"))
	{	cout << "Cant load file" << endl;
	}


	sf::Text text("Make a Triangle by clicking", font, 24);
	text.setFillColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);

		
	

	while (window.isOpen())
	{
		/*
		****************************************
		Handle the players input
		****************************************
		*/
		
		Event event;
		while (window.pollEvent(event))
		{
		    if (event.type == Event::Closed)
		    {
					// Quit the game when the window is closed
					window.close();
		    }
		    if (event.type == sf::Event::MouseButtonPressed)
		    {
			if (event.mouseButton.button == sf::Mouse::Left)
			{
			    std::cout << "the left button was pressed" << std::endl;
			    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
			    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
	
			    if(vertices.size() < 3)
			    {
				vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
				//std::cout << "size of vertices: " << vertices.size() << '\n';
			    }
			    else if(points.size() == 0)
			    {
				///fourth click
				///push back to points vector
				points.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
			    }
			}
		    }
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		/*
		****************************************
		Update
		****************************************
		*/
	
		if(points.size() > 0)
		{
		    ///generate more point(s)
		    ///select random vertex
		    ///calculate midpoint between random vertex and the last point in the vector
		    ///push back the newly generated coord.
			int randPoint = rand() % 3; 

			int dx = ((vertices[randPoint].x + points.back().x))/2;
			int dy = ((vertices[randPoint].y + points.back().y))/2;


			points.push_back(Vector2f(dx, dy));
		}
	
		/*
		****************************************
		Draw
		****************************************
		*/
		
		window.clear();
		window.draw(text);
		
		 
		for(int i = 0; i < vertices.size(); i++)
		{
		    RectangleShape rect(Vector2f(10,10));
		    rect.setPosition(Vector2f(vertices[i].x, vertices[i].y));
		    rect.setFillColor(Color::Red);
		    window.draw(rect);
			window.draw(text); 
		}
		
		for(int i = 0; i < points.size(); i++)
		{
		    RectangleShape rect(Vector2f(10,10));
		    rect.setPosition(Vector2f(points[i].x, points[i].y));
		    rect.setFillColor(Color::Red);
		    window.draw(rect);
		}
		
		window.display();
	}
}
