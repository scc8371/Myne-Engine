#include "WavReader.h"
using namespace std;

WavReader::WavReader(const char* path){
    ifstream reader(path);

    //reader not instantiated properly.
    if(!reader){
        std::cout << "Failed to open source .wav file!" << std::endl;
    }

    char* chunkID = (char*)malloc(4);
    reader.read(chunkID, 4);

    char* chunkSize = (char*)malloc(4);
    reader.read(chunkSize, 4);

    char* format = (char*)malloc(4);
    reader.read(format, 4);

    char* subChunkID = (char*)malloc(4);
    reader.read(subChunkID, 4);

    uint32_t subChunkSize;
    reader.read((char*)&subChunkSize, sizeof(subChunkSize));

    uint16_t audioFormat;
    reader.read((char*)&audioFormat, sizeof(audioFormat));

    uint16_t numChannels;
    reader.read((char*)&numChannels, sizeof(numChannels));

    uint32_t sampleRate;
    reader.read((char*)&sampleRate, sizeof(sampleRate));

    char* byteRate = (char*)malloc(4);
    reader.read(byteRate, 4);

    char* blockAlign = (char*)malloc(2);
    reader.read(blockAlign, 2);

    char* bitsPerSample = (char*)malloc(2);
    reader.read(bitsPerSample, 2);

    char* subChunkID2 = (char*)malloc(4);
    reader.read(subChunkID2, 4);

    uint32_t subChunkSize2;
    reader.read((char*)&subChunkSize2, sizeof(subChunkSize2));
    
    //calculates size for data
    uint32_t size = subChunkSize2;

    data = malloc(size);

    reader.read((char*)data, size);

    while(subChunkID2 == "LIST"){
        delete[] subChunkID2; 
        subChunkID2 = nullptr;
        reader.read(subChunkID2, 4);
        std::cout << subChunkID2 << std::endl;      
    }

    reader.read((char*)&subChunkSize2, 32);

    size = subChunkSize2;

    data = realloc(data, size);

    reader.read((char*)data, size);
        

        std::cout << subChunkID2 << std::endl;
    if(memcmp(chunkID, "RIFF", 4) != 0){
        std::cout << "Invalid audio file: " << path << std::endl; 
        return;
    }
    
    if(memcmp(format, "WAVE", 4) != 0){
        std::cout << "File is not .wav: " << path << std::endl;
        return;
    }

    if(memcmp(subChunkID, "fmt ", 4) != 0){
        std::cout << "No format specified for audio file: " << path << std::endl;
        return;
    }

    if(audioFormat != 1){
        std::cout << "Invalid audio format for audio file: " << path << std::endl;
        return;
    }

    if(memcmp(subChunkID2, "data", 4) != 0){
        std::cout << "No data subchunk for audio file: " << path << std::endl;
        return;
    }

    this->channels = numChannels;
    this->size = size;
    this->freq = sampleRate;

    reader.close();

    delete[] chunkID;
    delete[] chunkSize;
    delete[] format;
    delete[] subChunkID;
    delete[] byteRate;
    delete[] blockAlign;
    delete[] bitsPerSample;
    delete[] subChunkID2;
} 

WavReader::~WavReader(){
    free(data);
}