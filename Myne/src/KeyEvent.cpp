#include "KeyEvent.h"

//constructs a new key event. This should be inaccessable to anything other than
//a specific key event... such as release or press.
KeyEvent::KeyEvent(int keycode){
    this->keycode = keycode;
}   