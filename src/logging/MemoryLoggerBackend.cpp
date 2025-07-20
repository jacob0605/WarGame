#include "MemoryLoggerBackend.h"

using namespace std;

int MemoryLoggerBackend::write(const string& msg) {
    lock_guard<mutex> lock(mtx);
    logs.push_back(msg);
    return static_cast<int>(msg.size());
}

const std::vector<std::string>& MemoryLoggerBackend::getLogs() const {
    return logs;
}
