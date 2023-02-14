#include <iostream>
#include <vector>

const int PULSE_CYCLE_LENGTH = 50;

struct WaveformParameters {
int a, b, c, d;
};

class Signal {
public:
Signal(int mode, int switch1, int switch2, WaveformParameters params)
: mode_(mode), switch1_(switch1), switch2_(switch2), params_(params) {}

std::vector<int> GenerateSignalA() {
std::vector<int> signal;
if (switch1_ == 0) {
int num_pulses = params_.c;
if (switch2_ == 1) {
switch (mode_) {
case 1:
num_pulses -= 3;
break;
case 2:
// Invert signal
break;
case 3:
num_pulses += 3;
break;
case 4:
// Half d and b time
break;
}
}
for (int i = 0; i < num_pulses; ++i) {
signal.push_back(params_.a + i * PULSE_CYCLE_LENGTH);
signal.push_back(params_.b);
}
signal.push_back(params_.d);
}
return signal;
}

std::vector<int> GenerateSignalB() {
std::vector<int> signal;
if (switch1_ == 0) {
int num_pulses = params_.c;
if (switch2_ == 1) {
switch (mode_) {
case 1:
num_pulses -= 3;
break;
case 2:
// Invert signal
break;
case 3:
num_pulses += 3;
break;
case 4:
// Half d and b time
break;
}
}
for (int i = 0; i < num_pulses; ++i) {
signal.push_back(PULSE_CYCLE_LENGTH);
signal.push_back(params_.b);
}
signal.push_back(params_.d);
}
return signal;
}

private:
int mode_, switch1_, switch2_;
WaveformParameters params_;
};

int main() {
int mode, switch1, switch2;
WaveformParameters params;
std::cin >> mode >> switch1 >> switch2 >> params.a >> params.b >> params.c >>
params.d;
Signal signal(mode, switch1, switch2, params);
std::vector<int> signalA = signal.GenerateSignalA();
std::vector<int> signalB = signal.GenerateSignalB();
// Print signalA and signalB
return 0;
}
