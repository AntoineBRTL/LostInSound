#define PI 3.14159265358979323846

#include "precompile.hpp"

PortalManager::PortalManager(int portalsCount, int winnerPortal, int winnerKey, int winnerInstrument, std::vector<int>* keysAssignedToPortals, std::vector<int>* instrumentsAssignedToPortal, ChoiceCircle* choiceCircle)
{
    this->portalCount = portalsCount;
    this->winnerKey = winnerKey;
    this->winnerInstrument = winnerInstrument;
    this->choiceCircle = choiceCircle;

    for(int i = 0; i < portalCount; i++)
    {
        Portal *portalToAdd;

        // check for the winner
        if(i == winnerPortal)
        {
            // create the winner portal
            portalToAdd = new Portal(getPortalPosition(i), true, keysAssignedToPortals->operator[](i), instrumentsAssignedToPortal->operator[](i));
        }else
        {
            portalToAdd = new Portal(getPortalPosition(i), false, keysAssignedToPortals->operator[](i), instrumentsAssignedToPortal->operator[](i));
        }

        portalToAdd->portalAddChoiceCircle(choiceCircle);
        addToPortalList(portalToAdd);
    }
}

void PortalManager::reloadPortalShaders()
{
    for(Portal* portal : portals)
    {
        portal->reloadShader();
    }
}

void PortalManager::addToPortalList(Portal *portal)
{
    portals.push_back(portal);
}

float PortalManager::getAlpha()
{
    return (2.0f * PI) / portalCount;
}

Vector2d PortalManager::getPortalPosition(int i)
{
    float alpha = getAlpha();
    Vector2d position = Vector2d(choiceCircle->getRadius() * cos(alpha * i), choiceCircle->getRadius() * sin(alpha * i));
    return position;
}

void PortalManager::mousePortal(float x, float y){

    Vector2d mousePosition(-x, -y);

    for(Portal *portal : portals){
        portal->testMouse(mousePosition);
    }
}

void PortalManager::fillObjects(std::vector<Object *>* objects)
{
    for(Portal *portal : portals)
        objects->push_back(portal);   
}

ChoiceCircle* PortalManager::getChoiceCircle()
{
    return choiceCircle;
}