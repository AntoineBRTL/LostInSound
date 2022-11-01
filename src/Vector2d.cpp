#include "precompile.hpp"

// Generate a null vector
Vector2d::Vector2d():x(0.0f), y(0.0f) {}

// Generate a vector using x & y
Vector2d::Vector2d(float x, float y) :x(x), y(y) {}

float Vector2d::getX(){ return x; }
float Vector2d::getY(){ return y; }

float Vector2d::getTheta() 
{
    return atan2(y, x);
}

float Vector2d::getThetaWith(Vector2d vector)
{
    return std::atan2(x*vector.getY() - y*vector.getX(), dot(vector));
}

float Vector2d::dot(Vector2d vector)
{
    return x * vector.getX() + y * vector.getY();
}

float Vector2d::magnitude()
{
    return std::sqrt(dot(*this));
}

Vector2d Vector2d::operator+(Vector2d vector)
{
    return Vector2d(x + vector.x, y + vector.y);
}

Vector2d Vector2d::operator-(Vector2d vector)
{
    return Vector2d(x - vector.x, y - vector.y);
}

Vector2d Vector2d::operator*(float scale)
{
    return Vector2d(x * scale, y * scale);
}

Vector2d Vector2d::operator/(float scale)
{
    return Vector2d(x / scale, y / scale);
}

void Vector2d::operator+=(Vector2d vector)
{
    x += vector.x;
    y += vector.y;
}

void Vector2d::operator-=(Vector2d vector)
{
    x -= vector.x;
    y -= vector.y;
}

void Vector2d::operator*=(float scale)
{
    x *= scale;
    y *= scale;
}

void Vector2d::operator/=(float scale)
{
    x /= scale;
    y /= scale;
}

Vector2d Vector2d::normalized()
{
    if(magnitude() != 0.0f)
    {
        return this->operator/(magnitude());
    }
    return *this;
}

sf::Vector2f Vector2d::toVector2f()
{
    return sf::Vector2f(x, y);
}

std::string Vector2d::toString()
{
    return std::to_string(x) + "\t" + std::to_string(y);
}

Vector2d Vector2d::rotate(float angle)
{
    return Vector2d(cos(angle) * x - sin(angle) * y, sin(angle) * x + cos(angle) * y);
}