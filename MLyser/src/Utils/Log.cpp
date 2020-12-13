#include "mlzpch.h"

#include "Log.h"

namespace MLyser { namespace utils {

    std::shared_ptr<spdlog::logger> Log::s_ApplicationConsoleLogger;
    std::shared_ptr<spdlog::logger> Log::s_ApplicationFileLogger;

    void Log::InitLogger()
    {
        /// Logging Pattern
        //  %^       /* Starts Color range */
        //  %c       /* Date and time representation (Ex : "Thu Aug 23 15:35:46 2014") */
        //  %n       /* Logger name */
        //  %v       /* Text to log */
        //  %$       /* End color range */

        // TODO: Remove the global format pattern and set one for each logger
        // TODO: Add src file and line details to the pattern
        spdlog::set_pattern("%^ [%c] %n >>> %v %$");

        /// Application Console logger for debug and release modes
        s_ApplicationConsoleLogger = spdlog::stdout_color_mt("Application Console");
        s_ApplicationConsoleLogger->set_level(spdlog::level::info);

        // TODO: Fix the place where the log files get created in a OS and IDE independent manner
        /// Create a file rotating logger with 5mb size max and 3 rotated files
        auto max_size = 1048576 * 5;
        auto max_files = 3;
        s_ApplicationFileLogger = spdlog::rotating_logger_mt("Application File Logger", "logs/Log.txt", max_size, max_files);
        s_ApplicationFileLogger->flush_on(spdlog::level::info);
    }
} }
