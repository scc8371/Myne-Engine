#include "KeyEvent.h"
#include <iostream>
//constructs a new key event. This should be inaccessable to anything other than
//a specific key event... such as release or press.
KeyEvent::KeyEvent(int keycode){
    this->keycode = keycode;
}   

std::string KeyPressedEvent::toString() const{
    std::string msg = "KeyPressedEvent " + std::to_string(keycode) + ". Repeated " + std::to_string(repeatCount) + " times.";
    std::cout << 
    msg << 
    std::endl; 

    return msg;
}

KeyPressedEvent::KeyPressedEvent(int keycode, int repeatCount) : KeyEvent(keycode){
    this->repeatCount = repeatCount;
}

KeyReleasedEvent::KeyReleasedEvent(int keycode) : KeyEvent(keycode){}

std::string KeyReleasedEvent::toString() const{
    std::string msg = "KeyReleasedEvent " + std::to_string(keycode);
    std::cout << 
    msg << 
    std::endl; 

    return msg;
}