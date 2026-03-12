#include "PauseMenu.h"
#include "Game.h"
#include "MainMenu.h"

PauseMenu::PauseMenu(RenderWindow* window, vector<GameState*>* _states) : GameState(window, _states)
{
    overlay.setSize(Vector2f(win_width, win_heigt));
    overlay.setFillColor(Color(0, 0, 0, 150));

    buttonResume = new Button();
    buttonResume->setFillColor(Color(100, 100, 250, 255));
    buttonResume->setSize(Vector2f(300, 80));
    buttonResume->setPosition(Vector2f(810, 400));

    buttonQuit = new Button();
    buttonQuit->setFillColor(Color(250, 100, 100, 255));
    buttonQuit->setSize(Vector2f(300, 80));
    buttonQuit->setPosition(Vector2f(810, 550));
}

void PauseMenu::Instance(RenderWindow* window, vector<GameState*>*& states)
{
    GameState* pauseMenu = new PauseMenu(window, states);
    states->push_back(pauseMenu);
}

void PauseMenu::manageState()
{
    if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
    {
        GameState::nextState(states);
    }

    if (Mouse::isButtonPressed(Mouse::Button::Left))
    {
        Vector2i mousePos = Mouse::getPosition(*window);
        Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

        if (buttonResume && buttonResume->getGlobalBounds().contains(mousePosF))
        {
            GameState::nextState(states);
        }

        if (buttonQuit && buttonQuit->getGlobalBounds().contains(mousePosF))
        {
            while (!states->empty())
            {
                states->pop_back();
            }
            MainMenu::Instance(window, states);
        }
    }
}

void PauseMenu::update(float& dt)
{
    if (buttonResume)
    {
        buttonResume->update(dt);
    }

    if (buttonQuit)
    {
        buttonQuit->update(dt);
    }
}

void PauseMenu::render()
{
    window->draw(overlay);

    if (buttonResume)
    {
        buttonResume->render(window);
    }

    if (buttonQuit)
    {
        buttonQuit->render(window);
    }
}

PauseMenu::~PauseMenu()
{
    delete buttonResume;
    delete buttonQuit;
}