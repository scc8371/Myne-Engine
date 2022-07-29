#include "Game.h"

Game::Game(){}
//function to put any aspects that need to be initialized before the first update of the game
//inputs: none
//outputs: none
void Game::initialize(){}

//draws textures to the screen using SpriteBatch
//inputs: SpriteBatch* batch: the SpriteBatch to draw to
//outputs: none
void Game::draw(SpriteBatch* _spriteBatch){}

//updates aspects of the game every frame
void Game::update(float dt){}

//Event Methods

void Game::kbPress(int* key){}
void Game::kbRelease(int* key){}
void Game::mousePress(int* button){}
void Game::mouseRelease(int* button){}
void Game::onClose(){}

//returns the current mouse position to the user
Vector2 Game::getMousePos(){
    return InputManager::GetInstance()->getMousePosition();
}

//plays a sound
//inputs: Sound sound: the sound to play
//outputs: none
void Game::playAudio(Sound sound){
    SoundManager::getInstance()->play(sound);
}

//plays a sound
//inputs: Song song: the song to play
//outputs: none
void Game::playAudio(Song song){
    SoundManager::getInstance()->play(song);
}

//adds a UI element to the UIManager
//inputs: UIElement* element: the UIElement to add
//outputs: none
void Game::addUI(UIElement* element){
    UIManager::getInstance()->addUIElement(element);
}

//adds multiple UI elements to the UIManager
//inputs: std::vector<UIElement*> elements: the UIElements to add
void Game::addUIElements(std::vector<UIElement*> elements){
    UIManager::getInstance()->addUIElements(elements);
}