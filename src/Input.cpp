#include "precompile.hpp"

Input::Input(Player *player, PortalManager *portalManager):player(player), portalManager(portalManager)
{
}

void Input::updateInput(sf::RenderWindow *renderWindow, float deltaTime){

    while (renderWindow->pollEvent(event))
    {  
        switch (event.type)
        {
            case sf::Event::Closed:
                renderWindow->close();
                break;
                
            default:
                break;
        }

        sf::Vector2i pixelPos = sf::Mouse::getPosition(*renderWindow);
        sf::Vector2f worldPos = renderWindow->mapPixelToCoords(pixelPos);
        int virtualX = worldPos.x;
        int virtualY = worldPos.y;

        portalManager->mousePortal(virtualX, virtualY);
        player->mouse(virtualX, virtualY);

        int up = (sf::Keyboard::isKeyPressed(sf::Keyboard::Z));
        int down = -(sf::Keyboard::isKeyPressed(sf::Keyboard::S));
        int right = -(sf::Keyboard::isKeyPressed(sf::Keyboard::D));
        int left = (sf::Keyboard::isKeyPressed(sf::Keyboard::Q));
            
        player->accelerate(Vector2d(right + left, up + down));

    }
}

void Input::ask()
{
    int reload = 0;
    std::cin >> reload;
    if(reload == 1)
    {   
        player->reloadShader();
        portalManager->getChoiceCircle()->reloadShader();
        portalManager->reloadPortalShaders();

        ask();
    }
    
}