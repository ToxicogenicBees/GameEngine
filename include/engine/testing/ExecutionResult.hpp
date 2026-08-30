/*
    ExecutionResult.hpp

    Declaration of a struct containing test execution data.
*/

#pragma once

#include <ostream>
#include <string>

namespace toxico::test {
    struct ExecutionResult {
        bool success = false;
        std::string info = "N/A";
        double microseconds = 0;
    };

    /**
     * @brief Write an execution result to an output stream
     * 
     * @param o The output stream being written to.
     * @param result The result being written.
     * 
     * @return A reference to the modified output stream.
     */
    std::ostream& operator<<(std::ostream& o, const ExecutionResult& result);
}
