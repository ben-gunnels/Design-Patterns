#include "Lib.h"

char HighToLowFrequencyAdapter::getSignal() {
    int freq = 4; // Low frequency 
    int sig  = signal.getRawSignal();

    // Return a character composed of the sig every freq digits
    char output = 0;

    int bitCount = sizeof(sig) * 8;

    for (int i = bitCount - 1; i >= 0; i -= freq) {
        int bit = (sig >> i) & 1;
        output = (output << 1) | bit;
    }

    return output;
}

char SignalReader::getSignal(Signal& signal) {
    char output = 0;
    if (signal.getFreq() == 4) {
        HighToLowFrequencyAdapter adapter = HighToLowFrequencyAdapter(static_cast<HighFrequencySignal&>(signal));

        output = adapter.getSignal();
        return output;
    }

    else {
        int freq = 4;
        int sig = signal.getRawSignal();

        int bitCount = sizeof(sig) * 8;

        for (int i = bitCount - 1; i >= 0; i -= freq) {
            int bit = (sig >> i) & 1;
            output = (output << 1) | bit;
        }

        return output;
    }
}