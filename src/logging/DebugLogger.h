#ifndef __DEBUG_LOGGER_H__
#define __DEBUG_LOGGER_H__

#include "LoggerBackend.h"
#include "MemoryLoggerBackend.h"
#include <memory>
#include <string>
#include <sstream>
#include <mutex>
#include <ctime>
#include <iomanip>

enum class LogLevel {
    Info,
    Debug,
    Warning,
    Error
};

class DebugLogger {
private:
    std::mutex log_mutex;
    std::unique_ptr<LoggerBackend> backend;
    LogLevel level = LogLevel::Debug;
    static DebugLogger* instance;

    DebugLogger();
    std::string get_current_time();
    std::string level_to_string(LogLevel l);

public:
    static DebugLogger* get_instance();
    void set_backend(std::unique_ptr<LoggerBackend> b);
    void set_level(LogLevel lv);
    void log(const std::string& msg, const char* file, int line, const char* func, LogLevel msg_level);
    // MemoryLoggerBackend* get_memory_backend();
};

template <typename T>
std::string ToStringStream(const T& expr) {
    std::ostringstream oss;
    oss << expr;
    return oss.str();
}

#ifdef _DEBUG
#define INFO_LOG(expr) DebugLogger::get_instance()->log(ToStringStream(expr), __FILE__, __LINE__, __FUNCTION__, LogLevel::Info)
#define DEBUG_LOG(expr) DebugLogger::get_instance()->log(ToStringStream(expr), __FILE__, __LINE__, __FUNCTION__, LogLevel::Debug)
#define WARNING_LOG(expr) DebugLogger::get_instance()->log(ToStringStream(expr), __FILE__, __LINE__, __FUNCTION__, LogLevel::Warning)
#define ERROR_LOG(expr) DebugLogger::get_instance()->log(ToStringStream(expr), __FILE__, __LINE__, __FUNCTION__, LogLevel::Error)
#else
#define INFO_LOG(expr) ((void)0)
#define DEBUG_LOG(expr) ((void)0)
#define WARNING_LOG(expr) ((void)0)
#define ERROR_LOG(expr) ((void)0)
#endif // _DEBUG

#endif // __DEBUG_LOGGER_H__