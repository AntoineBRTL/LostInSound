#include "precompile.hpp"

class Level{

    private: 
        int number;
        PortalManager *portalManager;

    public:
        Level(int number, ChoiceCircle *choiceCircle, Player *player);
        PortalManager* getPortalManager();
};
