set libs= main.cpp src/App.cpp src/rendering/Sprite.cpp src/ui/elements/UIButton.cpp src/ui/elements/UIText.cpp src/ui/UIManager.cpp src/ui/tools/UISprite.cpp src/ui/elements/UIElement.cpp src/ui/tools/UIRectangle.cpp src/sound/Song.cpp src/sound/Sound.cpp src/gl/SpriteBatch.cpp src/sound/WavReader.cpp src/sound/SoundManager.cpp src/utils/Color.cpp src/utils/Font.cpp src/Game.cpp src/utils/Rectangle.cpp src/events/InputManager.cpp src/events/EventManager.cpp src/ResourceManager.cpp src/utils/Vector2.cpp src/stb.cpp src/gl/Shader.cpp src/texture/Texture.cpp src/texture/TextureManager.cpp src/gl/VAO.cpp src/gl/VBO.cpp src/utils/Circle.cpp src/physics/Body.cpp src/physics/DynamicBody.cpp src/physics/World.cpp glad.c
set ilibs=-I../library -L../library -lglfw3 -lgdi32 -lopengl32 -lfreetype -lopenal32

rem g++.exe -s -shared -o cygMyne.dll -Wl,--out-implib=libMyne.dll.a -Wl,--export-all-symbols -Wl,--enable-auto-import -Wl,--whole-archive %libs% -Wl,--no-whole-archive %ilibs% -static -static-libgcc -static-libstdc++ 

g++.exe %libs% %ilibs% -o main.exe -g

main.exe