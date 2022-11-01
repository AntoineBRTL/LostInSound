#include "precompile.hpp"

class Portal : public Object
{
    private:
        bool winner;
        int index;
        int instrument;
        bool isMouseOn = false;
        void stopSound();
        sf::Shader shader;
        ChoiceCircle *choiceCircle;

    public:
        Portal(Vector2d position, bool winner, int index, int instrument);
        void goThrough(Player *player);
        void render(sf::RenderWindow *renderWindow, sf::Font font);
        void playSound();
        void testMouse(Vector2d mousePosition);
        void reloadShader();
        void portalAddChoiceCircle(ChoiceCircle *choiceCircle);
};