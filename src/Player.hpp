#include "precompile.hpp"

class Player: public Entity
{

    private :
        float accelerationFactor = 300.0f;
        bool isMouseOn = false;
        void playSound();
        void stopSound();
        int keyPlayed = 0;
        int instrumentPlayed = 0;
        
        sf::Shader shader;
        float glow = 10;

        sf::Clock clock;
        sf::Time time;

    public:
        Player(Vector2d position);
        void accelerate(Vector2d direction);
        void mouse(float x, float y);
        void setNoteFromLevel(int key, int instrument);
        void render(sf::RenderWindow *renderWindow, sf::Font font);
        void reloadShader();
};