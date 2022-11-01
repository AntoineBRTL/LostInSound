#include "precompile.hpp"

class Object
{
    protected:
        Vector2d position;
        float radius;
    public: 
        bool isColliding(Object *object);
        Object(Vector2d position, float radius);
        virtual void render(sf::RenderWindow *renderWindow, sf::Font font) = 0;

        Vector2d getPosition();
        float getRadius();
};