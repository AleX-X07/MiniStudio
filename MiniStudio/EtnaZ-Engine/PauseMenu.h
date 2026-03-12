#pragma once
#include "GameState.h"
#include "Button.h"

class Game;

class PauseMenu : public GameState
{
private:
    Button* buttonResume;
    Button* buttonQuit;
    RectangleShape overlay;

public:
    PauseMenu() = default;
    PauseMenu(RenderWindow* window, vector<GameState*>* states);
    ~PauseMenu();

    static void Instance(RenderWindow* window, vector<GameState*>*& states);

    virtual void manageState() override;
    virtual void update(float& dt) override;
    virtual void render() override;
};