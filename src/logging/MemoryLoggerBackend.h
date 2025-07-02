#ifndef __MEMORY_LOGGER_BACKEND_H__
#define __MEMORY_LOGGER_BACKEND_H__

#include "LoggerBackend.h"
#include <vector>
#include <string>
#include <mutex>

class MemoryLoggerBackend : public LoggerBackend {
private:
    std::vector<std::string> logs;
    std::mutex mtx;

public:
    int write(const std::string& msg);
    const std::vector<std::string>& getLogs() const;
};

#endif //__MEMORY_LOGGER_BACKEND_H__