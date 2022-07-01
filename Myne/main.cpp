#include <iostream>
#include "src/App.h"
#include "src/Game.h"
#include "src/events/EventManager.h"
#include <math.h>

#include <random>

using namespace std;

void wrapper();
void onResize(void* data);

class Game1 : public Game{
public:
    Texture tex;
    Font font;
    Sound sound;
    Song song;

    Rectangle screenBounds;
    Rectangle texBounds;
    Vector2 velocity;
    Color color;

    Game1() : Game()
    {
        srand(time(NULL));
        rand();
        std::cout << "loading" << std::endl;
    }
    void initialize() override{
        
        tex = Texture("resources/content/bearger.png");
        font = Font("resources/font/font.ttf", 55);   
        std::cout << "LOADED!" << std::endl;


        song = Song("resources/audio/track5.wav");
        sound = Sound("resources/audio/boom.wav");

        sound.volume = 0.1f;

        screenBounds = Rectangle(0, 0, App::window_x, App::window_y);

        texBounds = Rectangle(0, 0, 200, 200);
        velocity = Vector2(10, 10);
        color = Color(255, 255, 255);

        EventManager::getInstance()->attachEvent(EventType::Window_Resize, onResize);

        playAudio(song);   
    }
    void update(float dt) override
    {
        texBounds.x += velocity.x * dt * 60;
        texBounds.y += velocity.y * dt * 60;

        if(texBounds.x < 0 || texBounds.x + texBounds.width > screenBounds.width){

            color = Color(((float)rand() / RAND_MAX) * 255, ((float)rand() / RAND_MAX) * 255, ((float)rand() / RAND_MAX) * 255);
            texBounds.x -= velocity.x * dt * 60;        
            texBounds.y -= velocity.y * dt * 60;
            playAudio(sound);
            velocity.x *= -1;
        }        
        if(texBounds.y < 0 || texBounds.y + texBounds.height > screenBounds.height){
            color = Color(((float)rand() / RAND_MAX) * 255, ((float)rand() / RAND_MAX) * 255, ((float)rand() / RAND_MAX) * 255);
            texBounds.x -= velocity.x * dt * 60;        
            texBounds.y -= velocity.y * dt * 60 * abs(sinf(texBounds.y));
            playAudio(sound);

            velocity.y *= -1;
        }
    };
    void draw(SpriteBatch* _spriteBatch) override 
    {
        _spriteBatch->colorWindow(0, 0, 0, 1.0f);
        _spriteBatch->draw(tex, Rectangle(0, 0, 1, 1), texBounds, color);
    };     

    void kbPress(int* key) override{
        
    }
};

Game1 game;

void onResize(void* data){
    game.screenBounds = Rectangle(0, 0, App::window_x, App::window_y);
}

int main()
{
    wrapper();
}

/// <summary>
/// wrapper function for main execution of Myne
/// </summary>
void wrapper() { 
    App app = App(&game);
}



