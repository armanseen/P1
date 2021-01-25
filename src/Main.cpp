#include "Platform/Platform.hpp"
using namespace sf;
int main()
{
	util::Platform platform;

#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif

	RenderWindow window;
	// in Windows at least, this must be called before creating the window
	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
	// Use the screenScalingFactor
	window.create(VideoMode(847.0f * screenScalingFactor, 649.0f * screenScalingFactor), "Frogger !!!"
		/*,Style::Fullscreen*/);
	platform.setIcon(window.getSystemHandle());

	//sf::ConvexShape shape(window.getSize().x / 3);
	//shape.setFillColor(sf::Color::White);

	//window.setPosition(sf::Vector2i(10, 50));
	//window.setTitle("SFML window");
	//window.setSize(sf::Vector2u(800, 600));

	Texture BackGround, Ambulance, Bus, Car33, Firetruck, Limousine, Minicar, Police, Taxi, Van;
	//BackGround.loadFromFile("content/background.png");
	BackGround.setSmooth(true);
	 /*
	Ambulance.setSmooth(true);
	Bus.setSmooth(true);
	Car33.setSmooth(true);
	Firetruck.setSmooth(true);
	Limousine.setSmooth(true);
	Minicar.setSmooth(true);
	Police.setSmooth(true);
	Taxi.setSmooth(true);
	Van.setSmooth(true);
	*/
	//Sprite sprite;
	//Vector2u size = window.getSize();
	//sprite.setTexture(BackGround);
	//sprite.setOrigin(0,0);

	//sprite.setScale(Vector2f(0.3f, 0.3f));
	//sprite.scale(Vector2f(size.x,size.y));
	//shape.setTexture(&BackGround);
	BackGround.loadFromFile("content/background.png");
	Ambulance.loadFromFile("content/ambulance.png");
	Bus.loadFromFile("content/bus.png");
	Car33.loadFromFile("content/car33.png");
	Firetruck.loadFromFile("content/firetruck.png");
	Limousine.loadFromFile("content/limousine.png");
	Minicar.loadFromFile("content/minicar.png");
	Police.loadFromFile("content/police.png");
	Taxi.loadFromFile("content/taxi.png");
	Van.loadFromFile("content/van.png");

	Sprite BG;
	BG.setTexture(BackGround);
	//sprite.setColor(sf::Color(255, 0, 0));
	//sprite.setColor(sf::Color(255, 255, 255, 18));
	BG.setPosition(Vector2f(0.f, 0.f));
	BG.setScale(Vector2f(0.5f, 0.5f));

	//Line1
	Sprite L1C1, L1C2, L1C3;
	float l1c1 = -150, l1c2 = -459.08, l1c3 = -768.17;
	L1C1.setTexture(Van);
	L1C1.setPosition(Vector2f(-150.f, 555.f));
	L1C1.setScale(Vector2f(0.063f, 0.063f));
	L1C2.setTexture(Van);
	L1C2.setPosition(Vector2f(-350.f, 555.f));
	L1C2.setScale(Vector2f(0.063f, 0.063f));
	L1C3.setTexture(Van);
	L1C3.setPosition(Vector2f(-550.f, 555.f));
	L1C3.setScale(Vector2f(0.063f, 0.063f));

	//Line3
	Sprite L2C1, L2C2, L2C3, L2C4;
	float l2c1 = -250, l2c2 = -500, l2c3 = -750, l2c4 = -1000;
	L2C1.setTexture(Taxi);
	L2C1.setPosition(Vector2f(-150.f, 454.f));
	L2C1.setScale(Vector2f(0.048f, 0.048f));
	L2C2.setTexture(Taxi);
	L2C2.setPosition(Vector2f(-350.f, 454.f));
	L2C2.setScale(Vector2f(0.048f, 0.048f));
	L2C3.setTexture(Taxi);
	L2C3.setPosition(Vector2f(-550.f, 454.f));
	L2C3.setScale(Vector2f(0.048f, 0.048f));
	L2C4.setTexture(Taxi);
	L2C4.setPosition(Vector2f(-750.f, 454.f));
	L2C4.setScale(Vector2f(0.048f, 0.048f));

	//L2C4.setColor(Color(255, 255, 255, 128));
	Event event;

	Clock clock;
	Time elapsed1 = clock.getElapsedTime();
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(BG);
		window.draw(L1C1);
		window.draw(L1C2);
		window.draw(L1C3);
		window.draw(L2C1);
		window.draw(L2C2);
		window.draw(L2C3);
		window.draw(L2C4);
		window.display();
		elapsed1 = clock.getElapsedTime();
		if ((int)elapsed1.asMilliseconds() > 3)
		{
			L1C1.setPosition(Vector2f(l1c1, 555.f));
			l1c1 += 1;
			L1C2.setPosition(Vector2f(l1c2, 555.f));
			l1c2 += 1;
			L1C3.setPosition(Vector2f(l1c3, 555.f));
			l1c3 += 1;

			L2C1.setPosition(Vector2f(l2c1, 454.f));
			l2c1 += 1;
			L2C2.setPosition(Vector2f(l2c2, 454.f));
			l2c2 += 1;
			L2C3.setPosition(Vector2f(l2c3, 454.f));
			l2c3 += 1;
			L2C4.setPosition(Vector2f(l2c4, 454.f));
			l2c4 += 1;
			clock.restart();
		}
		if (l1c1 > 848)
		{
			l1c1 = -80.26;
		}
		if (l1c2 > 848)
		{
			l1c2 = -80.26;
		}
		if (l1c3 > 848)
		{
			l1c3 = -80.26;
		}

		if (l2c1 == 848)
		{
			l2c1 = -150;
		}
		if (l2c2 == 848)
		{
			l2c2 = -150;
		}
		if (l2c3 == 848)
		{
			l2c3 = -150;
		}
		if (l2c4 == 848)
		{
			l2c4 = -150;
		}
	}
	return 0;
}
