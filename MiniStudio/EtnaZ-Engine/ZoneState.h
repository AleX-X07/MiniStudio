#pragma once
#include "Parallax.h"

struct ZoneData {
    sf::FloatRect zRect;
    Parallax::zone parallaxZone;
    std::string roomFile;
};

class ZoneState {
private:
    Parallax* parallax;
    Parallax::zone myZone = Parallax::zone::zone0;

    std::vector<ZoneData> zones;
    std::string myRoomFile;

public:
    ZoneState(Parallax* _parallax);
    ~ZoneState();

    void addZone(sf::FloatRect zRect, Parallax::zone pZone, const std::string& roomFile);

    bool updateZone(float playerX, float playerY);

    Parallax::zone getMyZone() const { return myZone; }
    std::string getMyRoomFile() const { return myRoomFile; }
};