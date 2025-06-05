#include "main.h"

int main() {
    int lowFreqRawSig  =  0b10011001100010000000100100011001; // Every 4th digit is read
    int highFreqRawSig =  0b10011001100010010000100100011001; // Every 4th digit is read
    // int highFreqRawSig = 0b01010011101101010000100100110011; // Every 4th digit is read

    LowFrequencySignal  low{lowFreqRawSig};
    HighFrequencySignal high{highFreqRawSig};
    SignalReader reader = SignalReader();

    std::cout << "Low Frequency Signal: " << reader.getSignal(low) << std::endl;
    std::cout << "High Frequency Signal: " << reader.getSignal(high) << std::endl;

}