#include "precompile.hpp"

class Input
{
    private:
        sf::Event event;
        Player *player;
        PortalManager *portalManager;

    public:
        Input(Player *player, PortalManager *portalManager);
        void updateInput(sf::RenderWindow *renderWindow, float deltaTime);
        
        void ask();
};