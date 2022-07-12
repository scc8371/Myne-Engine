#!/bin/bash

libs="src/App.cpp src/rendering/Sprite.cpp src/ui/elements/UIButton.cpp src/ui/elements/UIText.cpp src/ui/UIManager.cpp src/ui/tools/UISprite.cpp src/ui/elements/UIElement.cpp src/ui/tools/UIRectangle.cpp src/sound/Song.cpp src/sound/Sound.cpp src/gl/SpriteBatch.cpp src/sound/WavReader.cpp src/sound/SoundManager.cpp src/utils/Color.cpp src/utils/Font.cpp src/Game.cpp src/utils/Rectangle.cpp src/events/InputManager.cpp src/events/EventManager.cpp src/ResourceManager.cpp src/utils/Vector2.cpp src/stb.cpp src/gl/Shader.cpp src/texture/Texture.cpp src/texture/TextureManager.cpp src/gl/VAO.cpp src/gl/VBO.cpp src/utils/Circle.cpp glad.c"
ilibs="-I../library -L/usr/lib -lfreetype -lglfw -lOpenGL -I/usr/include/AL -lopenal"

#x86_64-w64-mingw32-g++ -s -shared -o cygMyne.dll \
#  -Wl,--out-implib=libMyne.dll.a \
#  -Wl,--export-all-symbols \
#  -Wl,--enable-auto-import \
#  -Wl,--whole-archive ${libs} \
#  -Wl,--no-whole-archive ${ilibs} \
#  -static -static-libgcc -static-libstdc++ 


clang++ main.cpp $libs $ilibs -o main
