#include "precompile.hpp"

std::vector<Object *> objects;
std::vector<Entity *> entities;

static int currentLevel = 1;

// constructor
WindowEngine::WindowEngine()
{
    // clock which manage dt counter
    sf::Clock clock;
    sf::Time time;
    float deltaTime;

    // generate window & updater & renderer
    renderWindow = new sf::RenderWindow(sf::VideoMode(800, 800), "Lost In Sound");
    updater = new Updater();
    renderer = new Renderer(renderWindow);

    // init a level
    initLevel();

    sf::View view(sf::FloatRect(0.0f, 0.0f, 800.0f, 800.0f));
    view.setCenter(0.0f, 0.0f);
    renderWindow->setView(view);

    while (renderWindow->isOpen())
    {  
        if(oldLevel != WindowEngine::currentLevel){
            oldLevel = WindowEngine::currentLevel;
            initLevel();
        }

        // compute dt
        time = clock.restart();
        deltaTime = time.asSeconds();

        input->updateInput(renderWindow, deltaTime);
        // update 
        updater->update(deltaTime);
        renderer->render();
    }
}

void WindowEngine::initLevel()
{    
    // clear objects
    objects = std::vector<Object *>();
    entities = std::vector<Entity *>();

    player = new Player(Vector2d(0, 0));
    entities.push_back(player);

    choiceCircle = new ChoiceCircle(250.0f);
    objects.push_back(choiceCircle);

    level = new Level(currentLevel, choiceCircle, player);
    level->getPortalManager()->fillObjects(&objects);
    //put entities into object
    for (Entity *entity : entities){
        objects.push_back(entity);
    }

    input = new Input(player, level->getPortalManager());
    thread = new sf::Thread(&Input::ask, input);
    thread->launch();

    renderer->putObjects(objects);
    updater->putObjects(objects);
}