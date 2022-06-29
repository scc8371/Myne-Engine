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

Textures can be drawn in an overriden draw(SpriteBatch spriteBatch) function.<br>
As an example, you would call spriteBatch(tex, sourceRectangle, destinationRectangle, color);<br>

<h2><b>Rectangles</b></h2><br>
Rectangles are part of the built-in math library of Myne. It allows you to define an area with a top-left x and y position, as well as it's width and height (width increases to the right, while height increases downwards).<br><br>

Here are some important Rectangles that are used in spriteBatch: <br><br>

<h3>Source Rectangles</h3><br>
Source Rectangles define where on a texture sheet a sprite is located. If a texture sheet is not being used, this can be defined as Rectangle(0, 0, 1, 1)<br>

<h3>Destination Rectangles</h3><br>
Destination Rectangles define where a certain texture is rendered at.<br>For example, if I defined a Rectangle(400, 400, 10, 10), the sprite would appear 400px right and 400px down from the top-left of the screen. Also, the texture would be 10px wide and 10px tall.<br><br>
  
<h2>Vector2</h2><br>
  
A Vector2 can be created using the Vector2 constructor, which accepts two float or int datatypes.<br>
  
<em>Vector2 functions</em><br>
  
- magnitude() -> calculates the magnitude of the vector<br>
- normalize() -> normalizes the vector (magnitude will be equal to 1)<br>
- setAngle(float degrees) -> sets the angle of a vector, adjusting the x and y values accordingly<br>

<h2>Sound and Song</h2><br>

<h3>Sound</h3><br>
Sounds can be created using the Sound constructor (Sound sound("path to sound");)<br>
Sounds <b>do not</b> loop.<br>

<h3>Song</h3><br>
Songs are created using the Song constructor (Song song("path to song", (float)introDuration);)<br>
Songs can be looped, and the intro duration determines where this loop starts. <br>

<br><br><hr>

More will be added as this engine develops!

  
                                                                                                     
                                                                                                






