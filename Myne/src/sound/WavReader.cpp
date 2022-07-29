#include "WavReader.h"
using namespace std;

//opens a new wav reader which reads the data from the given .wav file
WavReader::WavReader(const char* path){
    FILE* file = fopen(path, "rb");

    //reader not instantiated properly.
    if(!file){
        std::cout << "Failed to open source .wav file!" << std::endl;
        return;
    }

    //reads the header of the file
    char chunkID[4];
    fread(chunkID, sizeof(char), 4, file);

    char chunkSize[4];
    fread(chunkSize, sizeof(char), 4, file);

    //reads the format of the file
    char format[4];
    fread(format, sizeof(char), 4, file);

    char subChunkID[4];
    fread(subChunkID, sizeof(char), 4, file);

    //reads the size of the subchunk
    uint32_t subChunkSize;
    fread(&subChunkSize, sizeof(uint32_t), 1, file);

    //checks if the file is a .wav
    uint16_t audioFormat;
    fread(&audioFormat, sizeof(uint16_t), 1, file);

    //reads in the number of channels present in the audio
    uint16_t numChannels;
    fread(&numChannels, sizeof(uint16_t), 1, file);

    //reads in the sample rate of the audio
    uint32_t sampleRate;
    fread(&sampleRate, sizeof(uint32_t), 1, file);

    //reads in the byte rate of the audio
    uint32_t byteRate;
    fread(&byteRate, sizeof(uint32_t), 1, file);

    //used to align to the next piece of data
    char blockAlign[2];
    fread(blockAlign, sizeof(char), 2, file);

    //reads in the bit depth of the audio
    uint16_t bitsPerSample;
    fread(&bitsPerSample, sizeof(uint16_t), 1, file);
    
    //reads in the data chunk
    char subChunkID2[4];
    fread(subChunkID2, sizeof(char), 4, file);

    //reads in the size of the data chunk
    uint32_t subChunkSize2;
    fread(&subChunkSize2, sizeof(uint32_t), 1, file);

    //raw audio data read in and allocated
    data = malloc(subChunkSize2);
    fread(data, sizeof(char), subChunkSize2, file);

    //checks if the format of the data has LIST, skips over it if so.
    if(strcmp(subChunkID2, "LIST")){

        fread(subChunkID2, sizeof(char), 4, file);
          
        fread(&subChunkSize2, sizeof(uint32_t), 1, file);

        data = realloc(data, subChunkSize2);
        fread(data, sizeof(char), subChunkSize2, file);
    }

    //checks for invalid audio data, prints errors to the console.

    if(!strcmp(chunkID, "RIFF")){
        std::cout << "Invalid audio file: " << path << std::endl; 
        return;
    }

    if(!strcmp(format, "WAVE")){
        std::cout << "File is not .wav: " << path << std::endl;
        return;
    }

    if(!strcmp(subChunkID, "fmt")){
        std::cout << "No format specified for audio file: " << path << std::endl;
        return;
    }

    if(audioFormat != 1){
        std::cout << "Invalid audio format for audio file: " << path << std::endl;
        return;
    }

    if(!strcmp(subChunkID2, "data")){
        std::cout << "No data subchunk for audio file: " << path << std::endl;
        return;
    }

    this->channels = numChannels;
    this->size = subChunkSize2;
    this->freq = sampleRate;

    fflush(file);
} 

WavReader::~WavReader(){
    free(data);
}