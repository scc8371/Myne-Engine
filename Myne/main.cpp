#include <iostream>
#include "src/App.h"
#include "src/Game.h"

using namespace std;

void wrapper();

class Game1 : public Game{
public:
    Texture tex;
    Font font;
    Sound sound;

    Game1() : Game()
    {
       
        std::cout << "loading" << std::endl;
    }
    void initialize() override{
        
        tex = Texture("resources/content/bearger.png");
        font = Font("resources/font/font.ttf", 55);   
        std::cout << "LOADED!" << std::endl;

        sound = Sound("resources/audio/track5.wav");
       
        playSound(sound);
    }
    void update(float dt) override
    {
    };
    void draw(SpriteBatch* _spriteBatch) override 
    {
        _spriteBatch->colorWindow(0, 0, 0, 1.0f);
        _spriteBatch->draw(tex, Rectangle(0, 0, 1, 1), Rectangle(225, 25, 100, 100), Color(2, 102, 34, 200));
        font.draw("loser ->", Vector2(15, 100), Color(0, 255, 0, 255));
    };     

    void kbPress(int* key) override{
        std::cout << *key << std::endl;
        playSound(sound);
    }
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



