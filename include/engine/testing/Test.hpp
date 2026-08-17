/*
    Test.hpp

    Declaration of an abstract engine debug test.
*/

#pragma once

#include "testing/ExecutionResult.hpp"
#include "testing/TestResult.hpp"
#include <string>
#include <ostream>

namespace toxico::test {
    class Test {
    private:
        std::string NAME_;

    protected:
        /**
         * @brief Executes the test.
         * 
         * @return The test results.
         */
        virtual TestResult test() = 0;

    public:
        /**
         * @brief Constructor.
         * 
         * @param name The name of this test.
         */
        Test(const std::string& name);

        /**
         * @brief Runs and collects data on the test.
         * 
         * @return The collected test data.
         */
        ExecutionResult execute();

        /**
         * @brief Gets the name of this test.
         * 
         * @return The name of this test.
         */
        const std::string& name() const;
    };

    /**
     * @brief Write a test to an output stream
     * 
     * @param o The output stream being written to.
     * @param test The test being written.
     * 
     * @return A reference to the modified output stream.
     */
    std::ostream& operator<<(std::ostream& o, Test& test);
}
