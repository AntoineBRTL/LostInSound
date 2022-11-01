#include "precompile.hpp"

class WavToImage
{
    private:
        AudioFile<double> audioFile;
        int channel = 0;
        int numSamples = 0;
        int bitDepth = 0;
        int samples = 0;
        double maxTime = 0;

    public:
        WavToImage(int index, int instr);
        float audioToValue(float t);
};