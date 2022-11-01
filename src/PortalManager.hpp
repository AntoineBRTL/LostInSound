#include "precompile.hpp"

class PortalManager
{
    private:
        int portalCount;
        int winnerKey;
        int winnerInstrument;
        ChoiceCircle* choiceCircle;

        void addToPortalList(Portal *portal);
        Vector2d getPortalPosition(int i);
        float getAlpha();

    public:
        std::vector<Portal*> portals;
        PortalManager(int portalsCount, int winnerPortal, int winnerKey, int winnerInstrument, std::vector<int>* keysAssagnedToPortals, std::vector<int>* instrumentsAssignedToPortal, ChoiceCircle* choiceCircle);
        void mousePortal(float x, float y);
        void fillObjects(std::vector<Object *>* object);
        ChoiceCircle* getChoiceCircle();
        void reloadPortalShaders();
};