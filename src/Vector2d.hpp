#include "precompile.hpp"

class Vector2d
{
    private:
        float x;
        float y;

    public:
        Vector2d();
        Vector2d(float x, float y);

        float getX();
        float getY();

        float dot(Vector2d vector);
        float magnitude();
        Vector2d operator+(Vector2d vector);
        Vector2d operator-(Vector2d vector);
        Vector2d operator*(float scale);
        Vector2d operator/(float scale);
        void operator+=(Vector2d vector);
        void operator-=(Vector2d vector);
        void operator*=(float scale);
        void operator/=(float scale);
        Vector2d normalized();

        sf::Vector2f toVector2f();
        std::string toString();

        float getTheta();

        float getThetaWith(Vector2d vector);

        Vector2d rotate(float angle);
};