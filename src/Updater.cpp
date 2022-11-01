#include "precompile.hpp"

void Updater::update(float deltaTime)
{
    // compute acceleration
    for(Object *object : objects)
    {
        if(Entity* entity = dynamic_cast<Entity*>(object)){
            entity->move(deltaTime);
        }
        
    }

    //enitities collision
    for(Object *object : objects)
    {
        if(Entity* entity = dynamic_cast<Entity *>(object)){

            for(Object *object : objects)
            {
                if(ChoiceCircle* choiceCircle = dynamic_cast<ChoiceCircle*>(object)){
                    if(!choiceCircle->isColliding(entity)){
                        entity->pushInside(choiceCircle);
                    }
                }
            }
        }

        if(Player* player = dynamic_cast<Player *>(object)){
            for(Object *object : objects)
            {
                if(Portal* portal = dynamic_cast<Portal*>(object)){
                    portal->goThrough(player);
                }
            }
        }
    }
    
}

void Updater::putObjects(std::vector<Object*> objects){
    this->objects = objects;
}