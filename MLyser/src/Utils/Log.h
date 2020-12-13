#pragma once

#include "Core.h"
  
//spdlog
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/fmt/ostr.h> // osstream support

namespace MLyser { namespace utils {

    /// Logs different kinds of messages to Console and Log files.
    class Log
    {
    public:
        /// Initialize the logger system
        static void InitLogger();

        /// Returns the reference to the Application Console logger 
        inline static std::shared_ptr<spdlog::logger>& GetApplicationConsoleLogger() { return s_ApplicationConsoleLogger; }
        /// Returns the reference to the Application File logger 
        inline static std::shared_ptr<spdlog::logger>& GetApplicationFileLogger() { return s_ApplicationFileLogger; }
    private:
        static std::shared_ptr<spdlog::logger> s_ApplicationConsoleLogger;
        static std::shared_ptr<spdlog::logger> s_ApplicationFileLogger;
    };
} }

#ifndef MLZ_PRODUCTION
/// Application Logging to console
#define MLZ_CONSOLE_TRACE(...)         ::MLyser::utils::Log::GetApplicationConsoleLogger()->trace(__VA_ARGS__)                                    
#define MLZ_CONSOLE_INFO(...)          ::MLyser::utils::Log::GetApplicationConsoleLogger()->info(__VA_ARGS__)                                     
#define MLZ_CONSOLE_WARN(...)          ::MLyser::utils::Log::GetApplicationConsoleLogger()->warn(__VA_ARGS__)                                     
#define MLZ_CONSOLE_ERROR(...)         ::MLyser::utils::Log::GetApplicationConsoleLogger()->error(__VA_ARGS__)
#else
#define MLZ_CONSOLE_TRACE
#define MLZ_CONSOLE_INFO
#define MLZ_CONSOLE_WARN
#define MLZ_CONSOLE_ERROR
#endif

/// Application Logging to file
#define MLZ_FILE_TRACE(...)            ::MLyser::utils::Log::GetApplicationFileLogger()->trace(__VA_ARGS__)
#define MLZ_FILE_INFO(...)             ::MLyser::utils::Log::GetApplicationFileLogger()->info(__VA_ARGS__)
#define MLZ_FILE_WARN(...)             ::MLyser::utils::Log::GetApplicationFileLogger()->warn(__VA_ARGS__)
#define MLZ_FILE_ERROR(...)            ::MLyser::utils::Log::GetApplicationFileLogger()->error(__VA_ARGS__)

