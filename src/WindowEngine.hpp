#include "precompile.hpp"

class WindowEngine
{
    private:
        sf::RenderWindow *renderWindow;
        Updater *updater;
        Renderer *renderer;
        Input *input;
        Level *level;
        Player *player;
        ChoiceCircle *choiceCircle;
        sf::Thread *thread;
        int oldLevel = 1;

    public:
        WindowEngine();
        inline static int currentLevel = 1;
        void initLevel();
};