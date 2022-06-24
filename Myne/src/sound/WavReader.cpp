#include "WavReader.h"

WavReader::WavReader(const char* path){
    AudioFile<double> audio;
    if(audio.load(path)){
        audio.printSummary();

        
        int channelSize = (audio.getNumSamplesPerChannel() * audio.getBitDepth() / 8);
        size = channelSize * audio.getNumChannels();

        data = malloc(size);

        void* dest;

        for(int i = 1, size = audio.samples.size(); i < size - 1; i++){
            dest = (void*)((size_t)data + (channelSize) * i - 1);
            memcpy_s(dest, channelSize, &audio.samples[i][0], channelSize);
        }

        channels = audio.getNumChannels();
        freq = audio.getSampleRate();
    }
    else{
        std::cout << "couldn't open audio file: " << path << std::endl;
        return;
    }   
}

