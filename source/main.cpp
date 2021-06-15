#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

void addSegment(std::vector<sf::Vertex>* tree, sf::Vector2f start, int i, 
			    double lenght, double angle, double incrementAngle)
{
	static constexpr double degToRad{ 0.01745329 };
	
	if(i > 0)
	{
		sf::Vector2f end{ sf::Vector2f(start.x - sin(angle * degToRad) * lenght, start.y - cos(angle * degToRad) * lenght) };
		
		tree->push_back(sf::Vertex(start, sf::Color::White));
		tree->push_back(sf::Vertex(end, sf::Color::White));
		
		addSegment(tree, end, i - 1, lenght * 0.75, angle - incrementAngle, incrementAngle);
		addSegment(tree, end, i - 1, lenght * 0.75, angle + incrementAngle, incrementAngle);
	}
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Fractal tree");
	window.setFramerateLimit(60);
	
	double segmentLenght{ 100.0 };
	double segmentAngle{ 30.0 };

	auto tree{ std::vector<sf::Vertex>() };

	addSegment(&tree, sf::Vector2f(400.0f, 500.0f), 15, segmentLenght, 0.0, segmentAngle);

	sf::Event event;

    while (window.isOpen())
    {
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }
		
		window.clear();

		window.draw(&tree.at(0), tree.size(), sf::Lines);
		
		window.display();
    }

    return 0;
}