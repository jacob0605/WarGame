#include "FileLoggerBackend.h"

using namespace std;

FileLoggerBackend::FileLoggerBackend(const string& fileName) {
    file.open(fileName);
}

int FileLoggerBackend::write(const std::string& msg) {
    if (file.is_open()) {
        file << msg << endl;
        return static_cast<int>(msg.size());
    }
    return -1;
}
