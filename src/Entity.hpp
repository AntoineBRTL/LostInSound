#include "precompile.hpp"

class Entity : public Object
{

    private:
        float dragFactor = 2.0f;
        std::list<Vector2d> previousPosition;
        int maxQueue = 200;
        float reduceSize = 0.05f;

        sf::RenderWindow *renderWindow;
        
    protected:
        Vector2d acceleration;
        Vector2d velocity;

    public:
        Entity(Vector2d position, float radius);

        void move(float deltaTime);
        
        void pushInside(Object *object);

        void render(sf::RenderWindow *renderWindow, sf::Font font);
};