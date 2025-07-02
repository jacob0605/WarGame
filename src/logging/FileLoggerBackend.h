#ifndef __FILE_LOGGER_BACKEND_H__
#define __FILE_LOGGER_BACKEND_H__

#include "LoggerBackend.h"
#include <fstream>

class FileLoggerBackend : LoggerBackend {
private:
    std::ofstream file;

public:
    FileLoggerBackend(const std::string& fileName);
    int write(const std::string& msg) override;
};

#endif // __FILE_LOGGER_BACKEND_H__