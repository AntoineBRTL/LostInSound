#include "precompile.hpp"

class Updater
{
    private:
        std::vector<Object *> objects;
    public:
        void update(float deltaTime);
        void putObjects(std::vector<Object *> objects);
};