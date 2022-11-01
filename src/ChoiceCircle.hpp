#include "precompile.hpp"

class ChoiceCircle : public Object
{
    private :
        int keyPlayed = 0;
        sf::Shader shader;
        WavToImage* wavToImage;
        sf::Text ruleText;
        sf::Text levelNumberText;

        sf::Clock clock;
        sf::Time time;

        float frequency = 0;

    public : 
        ChoiceCircle(float radius);
        void render(sf::RenderWindow *renderWindow, sf::Font font);
        void setNoteFromLevel(int keyPlayed);
        void reloadShader();
        void setRule(std::string rule);
        void setLevelNumber(int level);
        void sound(int index, int instrument);
};