#include "WavReader.h"
using namespace std;

WavReader::WavReader(const char* path){
    FILE* file = fopen(path, "rb");

    //reader not instantiated properly.
    if(!file){
        std::cout << "Failed to open source .wav file!" << std::endl;
        return;
    }

    char chunkID[4];
    fread(chunkID, sizeof(char), 4, file);

    char chunkSize[4];
    fread(chunkSize, sizeof(char), 4, file);

    char format[4];
    fread(format, sizeof(char), 4, file);

    char subChunkID[4];
    fread(subChunkID, sizeof(char), 4, file);

    uint32_t subChunkSize;
    fread(&subChunkSize, sizeof(uint32_t), 1, file);

    uint16_t audioFormat;
    fread(&audioFormat, sizeof(uint16_t), 1, file);

    uint16_t numChannels;
    fread(&numChannels, sizeof(uint16_t), 1, file);

    uint32_t sampleRate;
    fread(&sampleRate, sizeof(uint32_t), 1, file);

    char byteRate[4];
    fread(byteRate, sizeof(char), 4, file);

    char blockAlign[2];
    fread(blockAlign, sizeof(char), 2, file);

    char bitsPerSample[2];
    fread(bitsPerSample, sizeof(char), 2, file);

    char subChunkID2[4];
    fread(subChunkID2, sizeof(char), 4, file);

    uint32_t subChunkSize2;
    fread(&subChunkSize2, sizeof(uint32_t), 1, file);

    fread(data, sizeof(char), subChunkSize2, file);

    if(strcmp(subChunkID2, "LIST")){

        fread(subChunkID2, sizeof(char), 4, file);
          
        fread(&subChunkSize2, sizeof(uint32_t), 1, file);

        fread(data, sizeof(char), subChunkSize2, file);
    }

   
    std::cout << subChunkID2 << std::endl;

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
    this->size = size;
    this->freq = sampleRate;
} 

WavReader::~WavReader(){

}