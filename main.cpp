#include <SFML/Graphics.hpp>

using namespace sf;
int main()
{
    RenderWindow window(VideoMode(600, 600), "SFML works!");
    CircleShape shape(100.f);
    shape.setFillColor(Color::Green);
    Texture texture;
    if(!texture.loadFromFile("walking2.png"));
    Sprite sprite;

    int X = texture.getSize().x;
    int Y = texture.getSize().y;
    int perSprite  = X/14;

    IntRect rectplay(0,0,perSprite, Y);

    sprite.setTexture(texture);
    sprite.setTextureRect(rectplay);
    sprite.setScale(0.2,0.2);
    Clock clock;
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        if(clock.getElapsedTime().asSeconds() > 0.09){
            if(rectplay.left >= X-X/14){
                rectplay.left = 0;
            }
            else{
                rectplay.left+=perSprite;
            }
            sprite.setTextureRect(rectplay);
            clock.restart();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
