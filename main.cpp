#include <iostream>
#include <cmath>

#include "AudioFile.h"

const int kChunkSize = 1024;

double computeRMS(int startIdx, AudioFile<double>& audioFile) {
    double rms = 0;
    int endIdx = std::min(startIdx + kChunkSize, static_cast<int>(audioFile.samples[0].size()));  

    for (int i = startIdx; i < endIdx; ++i) {
        rms += audioFile.samples[0][i] * audioFile.samples[0][i];
    }

    return sqrt(rms / (endIdx - startIdx));  
}
int main() {
    AudioFile<double> audioFile;

    audioFile.load("test.wav");

    for (int curChunkStart = 0; curChunkStart < audioFile.samples[0].size(); curChunkStart += kChunkSize) {
        double amplitude = computeRMS(curChunkStart, audioFile);
    }

    return 0;
}

