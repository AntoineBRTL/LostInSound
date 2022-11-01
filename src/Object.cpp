#include "precompile.hpp"

Object::Object(Vector2d position, float radius):position(position), radius(radius){}

bool Object::isColliding(Object *object)
{
    return (object->getPosition() - this->getPosition()).magnitude() < radius;
}

Vector2d Object::getPosition()
{
    return position;
}

float Object::getRadius()
{
    return radius;
}