#include "Song.h"

Song::Song(const char* path, float loopPoint){

    if(loopPoint < 0 || loopPoint > 1){
        std::cout << "Invalid loop point. Please specify a value between 0 and 1.";
        return;
    }

    auto song = WavReader(path);
    
    if(loopPoint != 0){
        hasIntro = true;
        alGenBuffers(1, &introBuffer);
        alBufferData(introBuffer, AL_FORMAT_STEREO16, song.data, song.size, song.freq);
        
        //determines where the loop of the song starts (ex. intro plays, will not play again due to loop)
        auto start = (int)(((float)song.size / 4) * loopPoint) * 4;
        
        alGenBuffers(1, &loopBuffer);
        alBufferData(loopBuffer, AL_FORMAT_STEREO16, (void*)((int)song.data + start), ((ALsizei)(song.size - start)), song.freq);
    }
    else{
        alGenBuffers(1, &loopBuffer);
        alBufferData(loopBuffer, AL_FORMAT_STEREO16, song.data, song.size, song.freq);
    }
}