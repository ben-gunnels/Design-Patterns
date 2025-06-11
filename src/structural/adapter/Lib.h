/**
 * @file Lib.h
 * 
 * @author Benjamin Gunnels (bengunnels8@gmail.com)
 * @brief Implements a adapter design pattern for translating signals of differing frequencies.
 * 
 * @date 2025-10-04
 * 
 * @copyright Copyright (Benjamin Gunnels) 2025
 *
 * 
 * 
 */

#include <iostream>

struct Signal {
    Signal(int sig) : sig(sig) {};
    int sig;
    virtual int getFreq() const = 0;
    int getRawSignal() { return sig; };
};

struct HighFrequencySignal : Signal {
    HighFrequencySignal(int sig) : Signal(sig) {};
    int getFreq() const override { return 2; } // This value is known
};

struct LowFrequencySignal : Signal {
    LowFrequencySignal(int sig) : Signal(sig) {};
    int getFreq() const override { return 4; } // This value is known
};


// Adapter class
class HighToLowFrequencyAdapter {
public:
    HighToLowFrequencyAdapter(HighFrequencySignal signal) : signal(signal) {};

    char getSignal(); 
private:
    HighFrequencySignal signal;
};


class SignalReader {
public:
    SignalReader(){};
    char getSignal(Signal& signal);
};

