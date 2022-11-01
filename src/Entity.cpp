#include "precompile.hpp"

Entity::Entity(Vector2d position, float radius):Object(position, radius){}

void Entity::move(float deltaTime)
{
    
    velocity += acceleration * deltaTime;
    position += velocity * deltaTime;

    previousPosition.push_back(position);
    if(previousPosition.size() > maxQueue){  
        previousPosition.pop_front();
    }

    velocity -= velocity * dragFactor * deltaTime;
    
    //stop the velocity when too small
    if(velocity.magnitude() < 0.01f){
        velocity = Vector2d(0, 0);
    }
    
}

void Entity::pushInside(Object *object)
{
    float angle = (velocity * (-1)).getThetaWith(object->getPosition() - position);
    velocity = (velocity * (-1)).rotate(2*angle);

    //can't block the entity
    if(position.magnitude() > radius - 0.01){
        position += (object->getPosition() - position).normalized();
    }
    //exit(-1);
}

void Entity::render(sf::RenderWindow *renderWindow, sf::Font font)
{
    int i = 0;

    for(std::list<Vector2d>::reverse_iterator it = previousPosition.rbegin(); it != previousPosition.rend(); it++){

        float radius = this->radius - i*reduceSize;

        sf::CircleShape queueShape(radius);
        queueShape.setFillColor(sf::Color::White);
        Vector2d size(radius, radius);
        queueShape.setOrigin((*it + size).toVector2f());
        renderWindow->draw(queueShape);
        
        i++;
    }
}