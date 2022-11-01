#include "precompile.hpp"

Portal::Portal(Vector2d position, bool winner, int index, int instrument):Object(position, 25.0f)
{
    this->winner = winner;
    this->index = index;
    this->instrument = instrument;
    reloadShader();
}

void Portal::reloadShader()
{
    shader.loadFromFile("./src/Portal.frag", sf::Shader::Fragment);

    if(!shader.isAvailable()) 
    {
		std::cout << "The shader is not available\n";
	}
}

void Portal::goThrough(Player *player){

    bool isColliding = this->isColliding(player);

    if(isColliding)
    {
        if(winner)
            WindowEngine::currentLevel ++; 
        else
            WindowEngine::currentLevel = 1;   
    }
}

void Portal::render(sf::RenderWindow *renderWindow, sf::Font font)
{
    shader.setUniform("position", sf::Glsl::Vec2(position.getX(), position.getY()));

    sf::CircleShape shape(radius);
    Vector2d size(radius, radius);
    shape.setOrigin((position + size).toVector2f());
    shape.setFillColor(sf::Color(70,130,180));
    renderWindow->draw(shape, &shader);
    return;
}

void Portal::playSound()
{
    stopSound();

    std::string wpath("./wav/instr" + std::to_string(instrument) + "/" + std::to_string(index) + ".wav");
    const char* path = wpath.c_str();

    choiceCircle->sound(index, instrument);

    PlaySound(TEXT(path), NULL, SND_ASYNC);
}

void Portal::stopSound()
{
    PlaySound(NULL, NULL, SND_FILENAME);
}

void Portal::testMouse(Vector2d mousePosition)
{
    if((mousePosition - position).magnitude() < radius)
    {
        if(!isMouseOn)
        {
            playSound();
        }
        isMouseOn = true;
        radius = 30.0f;
    }else
    {
        isMouseOn = false;
        radius = 25.0f;
    }
}

void Portal::portalAddChoiceCircle(ChoiceCircle *choiceCircle){
    this->choiceCircle = choiceCircle;
}