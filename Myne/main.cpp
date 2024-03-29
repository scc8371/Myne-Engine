#include <iostream>
#include "src/App.h"
#include "src/Game.h"
#include "src/events/EventManager.h"
#include "src/texture/SpriteSheetInfo.h"
#include <math.h>

#include <random>

using namespace std;

void wrapper();
void onResize(void* data);

char* helloWorld();

#define SHEET_WIDTH 9.0f
#define SHEET_HEIGHT 1.0f
#define SHEET_SCALE_X (1.0f / SHEET_WIDTH)
#define SHEET_SCALE_Y (1.0f / SHEET_HEIGHT)
#define SHEET_SCALE 5.0f

#define EDGE_CENTER (2.0f/7.0f)
#define CENTER (1.0f - EDGE_CENTER * 2.0f)

#define SPRITE_AT(X, Y) \
    Rectangle(X * SHEET_SCALE_X, Y * SHEET_SCALE_Y, SHEET_SCALE_X, SHEET_SCALE_Y)

#define CENTER_AT(X, Y) \
    Rectangle((X + EDGE_CENTER) * SHEET_SCALE_X, (Y + EDGE_CENTER) * SHEET_SCALE_Y, CENTER * SHEET_SCALE_X, CENTER * SHEET_SCALE_Y)


class Game1 : public Game{
public:
    Texture tex;
    Texture buttonTex;
    Font* font;
    Font* buttonFont;
    Sound sound;
    Song song;

    SpriteSheetInfo info = SpriteSheetInfo(9, 1, 5, 2.0f/7.0f, 7.0f);

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
        font = new Font("resources/font/font.ttf", 55);   
        std::cout << "LOADED!" << std::endl;
        App::changeIcon("resources/myne.png");

        song = Song("resources/audio/track5.wav");
        sound = Sound("resources/audio/boom.wav");

        sound.volume = 0.1f;

        screenBounds = Rectangle(0, 0, App::window_x, App::window_y);

        static UISprite normal_sprite(buttonTex, info.spriteAt(1, 0), info.centerAt(1, 0), 
            Vector2(info.sheetWidth * info.pixelsPerSprite * info.sheetScale, info.sheetHeight * info.pixelsPerSprite * info.sheetScale));

        static UISprite hover_sprite(buttonTex, info.spriteAt(2, 0), info.centerAt(2, 0), 
            Vector2(info.sheetWidth * info.pixelsPerSprite * info.sheetScale, info.sheetHeight * info.pixelsPerSprite * info.sheetScale));

        static UISprite disabled_sprite(buttonTex, info.spriteAt(7, 0), info.centerAt(7, 0), 
            Vector2(info.sheetWidth * info.pixelsPerSprite * info.sheetScale, info.sheetHeight * info.pixelsPerSprite * info.sheetScale));
        
        texBounds = Rectangle(0, 0, 200, 200);
        velocity = Vector2(10, 10);
        color = Color(255, 255, 255);

        EventManager::getInstance()->attachEvent(WINDOW_RESIZE, onResize);
        static UIButton button(&normal_sprite, &hover_sprite, &hover_sprite, &disabled_sprite, *font,
        UIRectangle(50.0f, 50.0f, -50.0f, -50.0f, 0.25f, 0.25f, 0.5f, 0.5f), Color(0, 0, 0),
        Color(255, 255, 255), NULL, "start", NULL, NULL, NULL, false);
        static UIButton button2(&normal_sprite, &hover_sprite, &hover_sprite, &disabled_sprite, *font,
        UIRectangle(50.0f, 50.0f, -50.0f, -50.0f, 0.25f, 0.25f, 0.5f, 0.5f), Color(0, 0, 0),
        Color(255, 255, 255), NULL, "start", NULL, NULL, NULL, false);
        static UIButton button3(&normal_sprite, &hover_sprite, &hover_sprite, &disabled_sprite, *font,
        UIRectangle(50.0f, 50.0f, -50.0f, -50.0f, 0.25f, 0.25f, 0.5f, 0.5f), Color(0, 0, 0),
        Color(255, 255, 255), NULL, "start", NULL, NULL, NULL, false);
        static UIText text(*font, UIRectangle(10, 10, 10, 10, 0, 0, 1, 1), helloWorld);
        addUI(&button);
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
        _spriteBatch->colorWindow(255, 0, 0, 1.0f);
        _spriteBatch->draw(tex, Rectangle(0, 0, 1, 1), texBounds, color);
        font->draw("lol", Vector2(50, 50), Color(0, 0, 0));
    };     

    void kbPress(int* key) override{
        std::cout << *key << std::endl;
    }

    void onClose() override{
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

char* helloWorld(){
    return "Hello World\nsomething else\nthird line\nmore stuff\nlolrekt";
}



