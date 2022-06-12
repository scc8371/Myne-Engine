#!/bin/bash

libs="main.cpp src/App.cpp src/gl/SpriteBatch.cpp src/Game.cpp src/utils/Rectangle.cpp src/events/InputManager.cpp src/events/EventManager.cpp src/ResourceManager.cpp src/utils/Vector2.cpp src/stb.cpp src/gl/Shader.cpp src/texture/Texture.cpp src/texture/TextureManager.cpp src/gl/VAO.cpp src/gl/VBO.cpp src/utils/Circle.cpp glad.c"
ilibs="-I../library -L../library -lglfw3 -lgdi32 -lopengl32"

x86_64-w64-mingw32-g++ -s -shared -o cygMyne.dll \
  -Wl,--out-implib=libMyne.dll.a \
  -Wl,--export-all-symbols \
  -Wl,--enable-auto-import \
  -Wl,--whole-archive ${libs} \
  -Wl,--no-whole-archive ${ilibs} \
  -static -static-libgcc -static-libstdc++ 


x86_64-w64-mingw32-g++ main.cpp src/App.cpp src/gl/SpriteBatch.cpp src/Game.cpp src/utils/Rectangle.cpp src/events/InputManager.cpp src/events/EventManager.cpp src/ResourceManager.cpp src/utils/Vector2.cpp src/stb.cpp src/gl/Shader.cpp src/texture/Texture.cpp src/texture/TextureManager.cpp src/gl/VAO.cpp src/gl/VBO.cpp src/utils/Circle.cpp glad.c -o main.exe -I../library -L../library -lglfw3 -lgdi32 -lopengl32 -static -static-libgcc -static-libstdc++ && ./main.exe