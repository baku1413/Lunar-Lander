#include "cpp11_utils.h"

#include <chrono>
#include <ratio>
#include <thread>

namespace Cpp11 {

static const std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
void SleepS(double seconds) {
    std::this_thread::sleep_for(std::chrono::duration<double>(seconds));
}

void SleepMs(double miliseconds) {
    std::this_thread::sleep_for(std::chrono::duration<double, std::milli>(miliseconds));
}

double TimeS() {
    const std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time = std::chrono::duration_cast<std::chrono::duration<double>>(now - start);
    return time.count();
}

double TimeMs() {
    return TimeS() * 1000;
}

}
