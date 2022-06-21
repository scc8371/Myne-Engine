#include "WavReader.h"
using namespace std;

WavReader::WavReader(const char* path){
    ifstream reader(path);

    //reader not instantiated properly.
    if(!reader){
        std::cout << "Failed to open source .wav file!" << std::endl;
    }

    char chunkID[4];
    reader.read(chunkID, sizeof(chunkID));

    char chunkSize[4];
    reader.read(chunkSize, sizeof(chunkSize));

    char format[4];
    reader.read(format, sizeof(format));

    char subChunkID[4];
    reader.read(subChunkID, sizeof(subChunkID));

    char subChunkSize[4];
    reader.read(subChunkSize, sizeof(subChunkID));

    char audioFormat[2];
    reader.read(audioFormat, sizeof(audioFormat));

    char numChannels[2];
    reader.read(numChannels, sizeof(numChannels));

    char sampleRate[4];
    reader.read(sampleRate, sizeof(sampleRate));

    char byteRate[4];
    reader.read(byteRate, sizeof(byteRate));

    char blockAlign[2];
    reader.read(blockAlign, sizeof(blockAlign));

    char bitsPerSample[2];
    reader.read(bitsPerSample, sizeof(bitsPerSample));

    char subChunkID2[4];
    reader.read(subChunkID2, sizeof(subChunkID2));

    char subChunkSize2[4];
    reader.read(subChunkSize2, sizeof(subChunkSize2));

    //calculates size for data
    int size = stoi(&subChunkSize[0]);
    data = malloc(size);

    reader.read((char*)data, size);

    if(strcmp(subChunkID2, "LIST") == 0){

        reader.read(subChunkID2, sizeof(subChunkID2));
        reader.read(subChunkSize2, sizeof(subChunkSize2));

        delete data;
        data = nullptr;

        //calculates size for data
        int size = stoi(&subChunkSize[0]);
        data = malloc(size);

        reader.read((char*)data, size);

    }


    if(strcmp(chunkID, "RIFF") != 0){
        std::cout << "Invalid audio file: " << path << std::endl; 
        return;
    }
    
    if(strcmp(format, "WAVE") != 0){
        std::cout << "File is not .wav: " << path << std::endl;
        return;
    }

    if(strcmp(subChunkID, "fmt ") != 0){
        std::cout << "No format specified for audio file: " << path << std::endl;
        return;
    }

    if(stoi(&audioFormat[0]) != 1){
        std::cout << "Invalid audio format for audio file: " << path << std::endl;
        return;
    }

    if(strcmp(subChunkID2, "data") != 0){
        std::cout << "No data subchunk for audio file: " << path << std::endl;
        return;
    }

    this->channels = stoi(&numChannels[0]);
    this->size = size;
    this->freq = stoi(&sampleRate[0]);

    reader.close();
}

WavReader::~WavReader(){
    delete data;
}