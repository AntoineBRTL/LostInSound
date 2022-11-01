#include "precompile.hpp"

class Renderer
{
    private:
        sf::Font font;
        sf::RenderWindow *renderWindow;
        std::vector<Object *> objects;
    public:
        Renderer(sf::RenderWindow *renderWindow);
        void render();
        void putObjects(std::vector<Object *> objects);
};