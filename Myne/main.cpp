#include <iostream>
#include "src/App.h"
#include "src/Game.h"

using namespace std;

void wrapper();

class Game1 : public Game{
public:
    Texture tex;
    Font font;

    Game1() : Game()
    {
       
        std::cout << "loading" << std::endl;
    }
    void initialize() override{
        
        tex = Texture("resources/content/bearger.png");
        font = Font("resources/font/font.ttf", 55);
     
        std::cout << "LOADED!" << std::endl;
    }
    void update(float dt) override
    {
    };
    void draw(SpriteBatch* _spriteBatch) override 
    {
        _spriteBatch->colorWindow(1, 1, 1, 1.0f);
        _spriteBatch->draw(tex, Rectangle(0, 0, 1, 1), Rectangle(225, 25, 100, 100), Color(255, 0, 0));
        font.draw("loser ->", Vector2(15, 100));
    };     
};

int main()
{
    wrapper();
}

/// <summary>
/// wrapper function for main execution of Myne
/// </summary>
void wrapper() { 
    Game1 game;
    App app = App(&game);
}



