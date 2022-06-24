#include "Game.h"

Game::Game(){}
void Game::initialize(){}
void Game::draw(SpriteBatch* _spriteBatch){}
void Game::update(float dt){}

void Game::kbPress(int* key){}
void Game::kbRelease(int* key){}
void Game::mousePress(int* button){}
void Game::mouseRelease(int* button){}

Vector2 Game::getMousePos(){
    return InputManager::GetInstance()->getMousePosition();
}

void Game::playAudio(Sound sound){
    SoundManager::getInstance()->play(sound);
}

void Game::playAudio(Song song){
    SoundManager::getInstance()->play(song);
}