#include <SFML/Graphics.hpp>
#include "cmrc/cmrc.hpp"

CMRC_DECLARE(HelloSFML);

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello SFML", sf::Style::Default, settings);

    sf::CircleShape greenCircleShape(80.f);
    greenCircleShape.setPosition(100.f, 100.f);
    greenCircleShape.setFillColor(sf::Color::Green);

    sf::CircleShape redCircleShape(60.f);
    redCircleShape.setPosition(120.f, 240.f);
    redCircleShape.setFillColor(sf::Color::Red);

    sf::CircleShape blueCircleShape(40.f);
    blueCircleShape.setPosition(140.f, 340.f);
    blueCircleShape.setFillColor(sf::Color::Blue);

    sf::RectangleShape cyanRectangleShape(sf::Vector2f(200.f, 100.f));
    cyanRectangleShape.setPosition(400.f, 100.f);
    cyanRectangleShape.setFillColor(sf::Color::Cyan);

    sf::CircleShape redTriangleShape(60.f, 3);
    redTriangleShape.setRotation(90.f);
    redTriangleShape.setPosition(400.f, 300.f);
    redTriangleShape.setFillColor(sf::Color::Red);

    sf::CircleShape yellowTriangleShape(60.f, 3);
    yellowTriangleShape.setPosition(400.f, 300.f);
    yellowTriangleShape.setFillColor(sf::Color::Yellow);

    sf::CircleShape whiteTriangleShape(60.f, 3);
    whiteTriangleShape.setRotation(270.f);
    whiteTriangleShape.setPosition(530.f, 420.f);
    whiteTriangleShape.setFillColor(sf::Color::White);

    auto fs = cmrc::HelloSFML::get_filesystem();

    if (!fs.exists("/resources/fonts/JetBrainsMono-Regular.ttf"))
        return EXIT_FAILURE;

    sf::Font font;
    auto fontFile = fs.open("/resources/fonts/JetBrainsMono-Regular.ttf");
    font.loadFromMemory(fontFile.begin(), fontFile.size());

    sf::Text text("Hello SFML", font, 30);
    text.setFillColor(sf::Color::Yellow);
    text.setPosition(410.f, 125.f);

    while (window.isOpen())
    {
        sf::Event event{};

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(greenCircleShape);
        window.draw(redCircleShape);
        window.draw(blueCircleShape);
        window.draw(cyanRectangleShape);
        window.draw(redTriangleShape);
        window.draw(yellowTriangleShape);
        window.draw(whiteTriangleShape);
        window.draw(text);
        window.display();
    }
}