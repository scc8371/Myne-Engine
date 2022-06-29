# MYNE ENGINE<br>
# PROJECT FOR SUMMER 2022.<br>
Uses OpenGL to render, OpenAL for sound, and freetype for typography.<br>

<em>Please note, this is the first engine I've ever written, and there are bound to be flaws. This project is mainly used to demonstrate what I've learned regarding the development of game engines.</em><br>


# Important Documentation <br>
<hr>
Please include these to allow the engine to work, after properly placing the Myne dlls into your project.<br>
#include "Myne/src/App.h"<br>
#include "Myne/src/Game.h"<br><br>

<b>Please note, these includes are likely to be changed at a later date.</b><br>

<b>App.h</b>: Contains most of the engine's initialization. Sets up OpenGL, OpenAL, freetype, physics, and various managers.<br>
<b>Game.h</b>: A template class that holds overridable functions that make up a basic initialization and game loop.<br><br>

# Component Basics <br>
<hr>

<h2><b>Textures</b></h2>

Textures can be made by calling the <b>Texture</b> constructor <br>
As an example: Texture tex("path as string");<br><br>

textures can be drawn in an overriden draw(SpriteBatch spriteBatch) function.<br>
As an example, you would call spriteBatch(tex, sourceRectangle, destinationRectangle, color);<br>

<em>Rectangles</em><br>
Rectangles are part of the built-in math library of Myne. It allows you to define an area with a top-left x and y position, as well as it's width and height (width increases to the right, while height increases downwards).<br>







