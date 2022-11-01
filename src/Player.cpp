#include "precompile.hpp"

Player::Player(Vector2d position):Entity(position, 10.0f)
{
    this->reloadShader();
}

void Player::reloadShader()
{
    time = clock.restart();
    shader.loadFromFile("./src/Player.frag", sf::Shader::Fragment);

    if(!shader.isAvailable()) 
    {
		std::cout << "The shader is not available\n";
	}

    shader.setUniform("radius", radius);
    shader.setUniform("glow", glow);
}

void Player::accelerate(Vector2d direction)
{
    acceleration = direction.normalized() * accelerationFactor;
}

void Player::mouse(float x, float y){

    Vector2d mousePosition(-x, -y);

    if((mousePosition - position).magnitude() < radius)
    {
        if(!isMouseOn)
        {
            playSound();
        }
        isMouseOn = true;
        radius = 15.0f;
    }else
    {
        isMouseOn = false;
        radius = 10.0f;
    }
}

void Player::playSound()
{
    if(keyPlayed == -1)
    {
        // playing no key
        return;
    }

    stopSound();

    std::string wpath("./wav/instr" + std::to_string(instrumentPlayed) + "/" + std::to_string(keyPlayed) + ".wav");
    const char* path = wpath.c_str();

    PlaySound(TEXT(path), NULL, SND_ASYNC);
}

void Player::stopSound()
{
    PlaySound(NULL, NULL, SND_FILENAME);
}

void Player::setNoteFromLevel(int keyPlayed, int instrumentPlayed){
    this->keyPlayed = keyPlayed;
    this->instrumentPlayed = instrumentPlayed;
}

void Player::render(sf::RenderWindow *renderWindow, sf::Font font){

    time = clock.getElapsedTime();
    shader.setUniform("position", sf::Glsl::Vec2(position.getX(), position.getY()));
    shader.setUniform("time", time.asSeconds());

    this->Entity::render(renderWindow, font);

    sf::CircleShape shape(radius + glow);
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(1);
    shape.setFillColor(sf::Color::Transparent);
    Vector2d size(radius + glow, radius + glow);
    shape.setOrigin((position + size).toVector2f());
    renderWindow->draw(shape, &shader);

}