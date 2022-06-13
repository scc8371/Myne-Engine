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
        std::cout << "LOADED!" << std::endl;
        tex = Texture("resources/content/bearger.png");
        font = Font("resources/font/barcode.ttf", 100);
    }
    void update(float dt) override
    {
    };
    void draw(SpriteBatch* _spriteBatch) override 
    {
        _spriteBatch->colorWindow(1.00f, 0.0f, 0.0f, 1.0f);
        _spriteBatch->draw(tex, Rectangle(0, 0, 1, 1), Rectangle(0, 0, 100.0f, 100.0f));
        font.draw("test for longer strings", Vector2(100, 100));
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



