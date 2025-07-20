#include "DebugLogger.h"

using namespace std;

string DebugLogger::get_current_time() {
    time_t t = time(nullptr);
    char buf[32];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&t));
    return buf;
}

string DebugLogger::level_to_string(LogLevel lv) {
    switch (lv) {
        case LogLevel::Info:
            return "INFO";
        case LogLevel::Debug:
            return "DEBUG";
        case LogLevel::Error:
            return "ERROR";
        case LogLevel::Warning:
            return "WARNING";
        default:
            return "INFO";
    }
}

DebugLogger* DebugLogger::get_instance() {
    if (!instance) instance = new DebugLogger();
    return instance;
}

void DebugLogger::set_backend(std::unique_ptr<LoggerBackend> b) {
    lock_guard<mutex> lock(log_mutex);
    backend = move(b);
}

void DebugLogger::set_level(LogLevel lv) {
    level = lv;
}

void DebugLogger::log(const std::string& msg, const char* file, int line, const char* func, LogLevel msg_level) {
    if (!backend || msg_level < level) return;

    std::ostringstream oss;
    oss << "[" << get_current_time() << "][" << level_to_string(msg_level) << "]"
        << " (" << file << ":" << line << " - " << func << ") " << msg;

    std::lock_guard<std::mutex> lock(log_mutex);
    backend->write(oss.str());
}

// MemoryLoggerBackend* DebugLogger::get_memory_backend() {
//     return dynamic_cast<MemoryLoggerBackend*>(backend.get());
// }
