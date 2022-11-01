#include "precompile.hpp"

ChoiceCircle::ChoiceCircle(float radius):Object(Vector2d(0, 0), radius) 
{
    wavToImage = new WavToImage(-1, -1);
    reloadShader();
}

void ChoiceCircle::reloadShader()
{
    shader.loadFromFile("./src/ChoiceCircle.vert", "./src/ChoiceCircle.frag");

    if(!shader.isAvailable()) 
    {
		std::cout << "The shader is not available\n";
	}
}

void ChoiceCircle::render(sf::RenderWindow *renderWindow, sf::Font font){

    /*sf::CircleShape shape(radius);
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(5);
    shape.setFillColor(sf::Color::Transparent);
    Vector2d size(radius, radius);
    shape.setOrigin((position + size).toVector2f());
    renderWindow->draw(shape);*/

    time = clock.getElapsedTime();
    float elapsedTime = time.asSeconds();
    shader.setUniform("time", elapsedTime);
    shader.setUniform("amplitude", wavToImage->audioToValue(elapsedTime));
    shader.setUniform("frequency", frequency);
    
    sf::RectangleShape shape(sf::Vector2f(-400.0f, -400.0f));
    shape.setOrigin(sf::Vector2f(400.0f, 400.0f));
    shape.setSize(sf::Vector2f(800.0f, 800.0f));
    shape.setTextureRect(sf::IntRect(0, 0, 1, 1));
    renderWindow->draw(shape, &shader);

    /*sf::Texture texture = wavToImage->audioToTex(1.0f, 0);
    sf::Sprite sprite(texture);
    sprite.setOrigin(400.0f, 400.0f);
    renderWindow->draw(sprite, &shader);*/

    if(keyPlayed != -1)
    {
        sf::Text text;
        text.setFont(font);
        text.setString(note[keyPlayed]);
        text.setCharacterSize(50);
        text.setPosition(-text.getLocalBounds().width/2, -text.getLocalBounds().height);
        renderWindow->draw(text);
    }

    // render the rule text
    ruleText.setFont(font);
    ruleText.setCharacterSize(25);
    ruleText.setPosition(-ruleText.getLocalBounds().width/2, -ruleText.getLocalBounds().height + 100.0f);
    renderWindow->draw(ruleText);

    levelNumberText.setFont(font);
    levelNumberText.setCharacterSize(25);
    levelNumberText.setPosition(-ruleText.getLocalBounds().width/2 + 25, -ruleText.getLocalBounds().height - 100.0f);
    renderWindow->draw(levelNumberText);
}

void ChoiceCircle::setNoteFromLevel(int keyPlayed)
{
    this->keyPlayed = keyPlayed;
}

// set the rule 
void ChoiceCircle::setRule(std::string rule)
{
    ruleText.setString(rule);
}

void ChoiceCircle::setLevelNumber(int level)
{
    levelNumberText.setString("Level : " + std::to_string(level));
}

void ChoiceCircle::sound(int index, int instrument)
{
    time = clock.restart();
    frequency = noteFrequency[index];
    wavToImage = new WavToImage(index, instrument);
}