#include <iostream>
#include "src/App.h"
#include "src/Game.h"
#include "src/events/EventManager.h"
#include <math.h>

#include <random>



using namespace std;

void wrapper();
void onResize(void* data);

#define SHEET_WIDTH 10.0f
#define SHEET_HEIGHT 1.0f
#define SHEET_SCALE_X 1.0f / SHEET_WIDTH
#define SHEET_SCALE_Y 1.0f / SHEET_HEIGHT
#define SHEET_SCALE 5.0f

#define EDGE_CENTER 1.0f/7.0f
#define CENTER 1.0f - EDGE_CENTER * 2.0f

#define SPRITE_AT(X, Y) \
    Rectangle(X * SHEET_SCALE_X, Y * SHEET_SCALE_Y, SHEET_SCALE_X, SHEET_SCALE_Y)

#define CENTER_AT(X, Y) \
    Rectangle((X + EDGE_CENTER) * SHEET_SCALE_X, (Y + EDGE_CENTER) * SHEET_SCALE_Y, CENTER * SHEET_SCALE_X, CENTER * SHEET_SCALE_Y)


class Game1 : public Game{
public:
    Texture tex;
    Texture buttonTex;
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
        buttonTex = Texture("resources/content/ui.png");
        font = Font("resources/font/font.ttf", 55);   
        std::cout << "LOADED!" << std::endl;


        song = Song("resources/audio/track5.wav");
        sound = Sound("resources/audio/boom.wav");

        sound.volume = 0.1f;

        screenBounds = Rectangle(0, 0, App::window_x, App::window_y);

        static UISprite normal_sprite(buttonTex, SPRITE_AT(1, 0), CENTER_AT(1, 0), Vector2(7.0f, SHEET_SCALE * 7));
        static UISprite hover_sprite(buttonTex, SPRITE_AT(3, 0), CENTER_AT(3, 0), Vector2(7.0f, SHEET_SCALE * 7));
        static UISprite pressed_sprite(buttonTex, SPRITE_AT(3, 0), CENTER_AT(3, 0), Vector2(7.0f, SHEET_SCALE * 7));
        static UISprite disabled_sprite(buttonTex, SPRITE_AT(7, 0), CENTER_AT(7, 0), Vector2(7.0f, SHEET_SCALE * 7));

        static UIButton button(&normal_sprite, &hover_sprite, &pressed_sprite, &disabled_sprite, &font,
        UIRectangle(-50, -50, 50, 50, 0.5f, 0.5f, 0.5f, 0.5f), Color(255, 255, 255),
        Color(255, 0, 0), NULL, "lol noob", NULL, NULL, NULL, false);

        addUI(&button);

        texBounds = Rectangle(0, 0, 200, 200);
        velocity = Vector2(10, 10);
        color = Color(255, 255, 255);

        EventManager::getInstance()->attachEvent(WINDOW_RESIZE, onResize);
    }

    void update(float dt) override
    {
        texBounds.x += velocity.x * dt * 60;
        texBounds.y += velocity.y * dt * 60;

        if(texBounds.x < 0 || texBounds.x + texBounds.width > screenBounds.width){
            texBounds.x -= velocity.x * dt * 60;        
            texBounds.y -= velocity.y * dt * 60;
            playAudio(sound);
            velocity.x *= -1;
        }        
        if(texBounds.y < 0 || texBounds.y + texBounds.height > screenBounds.height){
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
        font.draw("xcvvsfgvsdfqsdfsdafasdfasdfasdfasdfasd", Vector2(50, 50));
    };     

    void kbPress(int* key) override{
        std::cout << *key << std::endl;
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



