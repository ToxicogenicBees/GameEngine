/*
    Logger.cpp

    Implementation of a logger class that allows for easy system debugging.
*/

#include "Logging/Logger.hpp"
#include <filesystem>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <format>

namespace {
    constexpr size_t MAX_BUFFER_SIZE = 5000;
    constexpr size_t MAX_LOGS = 20;

    const std::string FILE_EXTENTION = ".log";
    const std::string LOG_DIRECTORY = "logs";
}

void Logger::log(LogLevel level, LogCategory category, const std::string& message, const std::source_location& location ) {
    // Create message
    LogMessage msg(level, category, message, location);

    // Buffer for later purposes
    buffer_.emplace_back(msg);
    if (buffer_.size() > MAX_BUFFER_SIZE)
        buffer_.pop_front();

    // Write messages to log files
    for (auto& log : logs_)
        log << msg.message() << "\n";
    std::clog << msg.message() << "\n";

    // Exit if requires
    if (level == LogLevel::FATAL) {
        shutdown();
        std::exit(EXIT_FAILURE);
    }
}

void Logger::init() {
    // Filter all log files
    if (std::filesystem::exists(LOG_DIRECTORY)) {
        std::deque<std::filesystem::directory_entry> logs;
        for (const auto& entry : std::filesystem::directory_iterator(LOG_DIRECTORY)) {
            if (!entry.is_regular_file())
                continue;
            if (entry.path().filename() == "latest" + FILE_EXTENTION)
                continue;

            logs.emplace_back(entry);
        }
        
        // Sort logs by write time
        std::sort(logs.begin(), logs.end(), [](const auto& a, const auto& b) {
            return a.last_write_time() < b.last_write_time();
        });

        // Delete old logs
        while (logs.size() >= MAX_LOGS && logs.size() > 0) {
            auto entry = logs.begin();
            std::filesystem::remove(std::move(*entry));
            logs.pop_front();
        }
    }
    else {
        std::filesystem::create_directory(LOG_DIRECTORY);
    }
    
    // Fetch system time
    auto now = std::time(0);
    auto local_time = std::localtime(&now);

    // Format the day
    std::string day;
    {
        std::stringstream ss;
        ss << local_time->tm_year + 1900 << "-"
            << std::setw(2) << std::setfill('0') << local_time->tm_mon << "-"
            << std::setw(2) << std::setfill('0') << local_time->tm_mday;
        day = ss.str();
    }

    // Format the time
    auto time = [local_time](char delim) {
        std::stringstream ss;
        ss << std::setw(2) << std::setfill('0') << local_time->tm_hour << delim
            << std::setw(2) << std::setfill('0') << local_time->tm_min << delim
            << std::setw(2) << std::setfill('0') << local_time->tm_sec;
        return ss.str();
    };

    // Construct file names
    log_names_ = {
        LOG_DIRECTORY + "/" + day + "_" + time('-') + FILE_EXTENTION,
        LOG_DIRECTORY + "/latest" + FILE_EXTENTION
    };

    // Open and validate log folders
    for (size_t i = 0; i < logs_.size(); ++i) {
        // Open log
        logs_[i].open(log_names_[i]);

        // Validate that the log is open
        if (!logs_[i]) {
            std::cerr << "Failed to open log " + log_names_[i] << "\n";
            std::exit(EXIT_FAILURE);
        }
    }

    // Insert header
    for (auto& log : logs_) {
        log << "=============================\n"
            << "Engine Startup\n"
            << "Time: " + day << " " << time(':') << "\n"
            << "=============================\n\n";
    }
}

void Logger::shutdown() {
    // Search for a fatal log
    auto iter = std::find_if(buffer_.rbegin(), buffer_.rend(), [](const LogMessage& message) {
        return message.level() == LogLevel::FATAL;
    });

    // Create a remark based on the logs found
    auto remark = (iter != buffer_.rend() ? "Fatal error\nEngine terminated" : "Engine shutdown successfully");

    // Finalize log with success/fatal remark
    for (auto& log : logs_) {
        // Insert remark
        log << "\n" << remark << "\n";

        // Flush and close log
        log.flush();
        log.close();
    }
}
