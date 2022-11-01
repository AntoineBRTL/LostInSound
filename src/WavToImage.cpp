#include "precompile.hpp"

WavToImage::WavToImage(int index, int instr)
{
    if(index != -1){
        audioFile.load("./wav/instr" + std::to_string(instr) + "/" + std::to_string(index) + ".wav");
        channel = 0;
        numSamples = audioFile.getNumSamplesPerChannel();
        bitDepth = audioFile.getBitDepth();
        samples = audioFile.getSampleRate();
        maxTime = audioFile.getLengthInSeconds();
        audioFile.printSummary();
    }

}

float WavToImage::audioToValue(float t){

    double value = 0;

    if(samples*t < numSamples)
        value = (audioFile.samples[0][(int)(samples*t)]*bitDepth);


    return std::abs((float)(value));
}