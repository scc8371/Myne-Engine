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

    uint32_t subChunkSize;
    reader.read((char*)&subChunkSize, sizeof(subChunkSize));

    uint16_t audioFormat;
    reader.read((char*)&audioFormat, sizeof(audioFormat));

    uint16_t numChannels;
    reader.read((char*)&numChannels, sizeof(numChannels));

    uint32_t sampleRate;
    reader.read((char*)&sampleRate, sizeof(sampleRate));

    char byteRate[4];
    reader.read(byteRate, sizeof(byteRate));

    char blockAlign[2];
    reader.read(blockAlign, sizeof(blockAlign));

    char bitsPerSample[2];
    reader.read(bitsPerSample, sizeof(bitsPerSample));

    char subChunkID2[4];
    reader.read(subChunkID2, sizeof(subChunkID2));

    uint32_t subChunkSize2;
    reader.read((char*)&subChunkSize2, sizeof(subChunkSize2));
    
    //calculates size for data
    uint32_t size = subChunkSize2;

    data = malloc(size);

    reader.read((char*)data, size);

    if(memcmp(subChunkID2, "LIST", 4) == 0){
        
        reader.read(subChunkID2, 4);
        reader.read((char*)&subChunkSize2, 32);

        size = subChunkSize2;

        data = realloc(data, size);

        reader.read((char*)data, size);

        std::cout << subChunkID2 << std::endl;
    }

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
}

WavReader::~WavReader(){
    free(data);
}