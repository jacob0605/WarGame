#ifndef __LOGGER_BACKEND_H__
#define __LOGGER_BACKEND_H__

#include <string>

class LoggerBackend {
public:
    virtual int write(const std::string& msg) = 0;
    virtual ~LoggerBackend() = default;
};

#endif // __LOGGER_BACKEND_H__