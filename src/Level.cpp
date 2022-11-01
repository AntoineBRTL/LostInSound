#include "precompile.hpp"

int rand(int min, int max)
{
    int range = max - min + 1;
    return rand() % range + min;
}

// the player must search for the same key
void rule1(int portalCount, int winnerInstrument, int winnerKey, int winnerIndexAssignement, std::vector<int>* keysAssignedToPortals, std::vector<int>* instrumentsAssignedToPortals)
{ 
    for(int i = 0; i < portalCount; i++)
    {
        // winner index
        if(i == winnerIndexAssignement)
        {
            // Keys
            keysAssignedToPortals->push_back(winnerKey);

            // Instruments
            instrumentsAssignedToPortals->push_back(winnerInstrument);   // 0 since we only have instr 0
            continue;
        }

        // Keys
        int nextKey = rand(0, portalCount - 1);
        while(std::find(keysAssignedToPortals->begin(), keysAssignedToPortals->end(), nextKey) != keysAssignedToPortals->end() || nextKey == winnerKey)
            nextKey = rand(0, portalCount - 1);
        keysAssignedToPortals->push_back(nextKey);

        // Instruments
        instrumentsAssignedToPortals->push_back(winnerInstrument);   // 0 since we only have instr 0
    }
}

// The player must search for the lowest key
void rule2(int portalCount, int winnerInstrument, int winnerKey, int winnerIndexAssignement, std::vector<int>* keysAssignedToPortals, std::vector<int>* instrumentsAssignedToPortals)
{
    for(int i = 0; i < portalCount; i++)
    {
        // winner index
        if(i == winnerIndexAssignement)
        {
            // Keys
            keysAssignedToPortals->push_back(winnerKey);

            // Instruments
            instrumentsAssignedToPortals->push_back(winnerInstrument);   // 0 since we only have instr 0
            continue;
        }

        // Keys
        int nextKey = rand(winnerKey + 1, portalCount - 1);

        keysAssignedToPortals->push_back(nextKey);

        // Instruments
        instrumentsAssignedToPortals->push_back(winnerInstrument);   // 0 since we only have instr 0
    }
}

// The player must search for the highest key
void rule3(int portalCount, int winnerInstrument, int winnerKey, int winnerIndexAssignement, std::vector<int>* keysAssignedToPortals, std::vector<int>* instrumentsAssignedToPortals)
{
    for(int i = 0; i < portalCount; i++)
    {
        // winner index
        if(i == winnerIndexAssignement)
        {
            // Keys
            keysAssignedToPortals->push_back(winnerKey);

            // Instruments
            instrumentsAssignedToPortals->push_back(winnerInstrument);   // 0 since we only have instr 0
            continue;
        }

        // Keys
        int nextKey = rand(0, winnerKey - 1);
        keysAssignedToPortals->push_back(nextKey);

        // Instruments
        instrumentsAssignedToPortals->push_back(winnerInstrument);   // 0 since we only have instr 0
    }
}

Level::Level(int number, ChoiceCircle *choiceCircle, Player *player):number(number){
    std::ifstream in("./lvl/" + std::to_string(number) + ".lvl");

    int portalCount = 0;
    int winnerInstrument = 0;
    int winnerKey = 0;
    int instrumentPlayed = 0;
    int keyPlayed = 0;
    int rule = 0;
    
    in >> portalCount;
    in >> winnerInstrument;
    in >> winnerKey;
    in >> instrumentPlayed;
    in >> keyPlayed;
    in >> rule;

    int winnerIndexAssignement = rand(0, portalCount - 1);
    std::vector<int>* instrumentsAssignedToPortals = new std::vector<int>();
    std::vector<int>* keysAssignedToPortals = new std::vector<int>();

    std::string ruleText;

    switch(rule)
    {
        case 1:
            rule1(portalCount, winnerInstrument, winnerKey, winnerIndexAssignement, keysAssignedToPortals, instrumentsAssignedToPortals);
            ruleText = "Find the same key";
            break;

        case 2:
            rule2(portalCount, winnerInstrument, winnerKey, winnerIndexAssignement, keysAssignedToPortals, instrumentsAssignedToPortals);
            ruleText = "Find the lowest key";
            break;

        case 3:
            rule3(portalCount, winnerInstrument, winnerKey, winnerIndexAssignement, keysAssignedToPortals, instrumentsAssignedToPortals);
            ruleText = "Find the highest";
            break;
    }

    portalManager = new PortalManager(portalCount, winnerIndexAssignement, winnerKey, winnerInstrument, keysAssignedToPortals, instrumentsAssignedToPortals, choiceCircle);
    // set the rule text
    portalManager->getChoiceCircle()->setRule(ruleText);
    portalManager->getChoiceCircle()->setLevelNumber(number);

    choiceCircle->setNoteFromLevel(keyPlayed);
    player->setNoteFromLevel(keyPlayed, instrumentPlayed);
}

PortalManager* Level::getPortalManager()
{
    return portalManager;
}