/*
    Test.hpp

    Declaration of an abstract engine debug test.
*/

#pragma once

#include "Foundation/Result.hpp"
#include <ostream>
#include <string>

namespace toxico::test {
    class Test {
    private:
        std::string NAME_;

    public:
        /**
         * @brief Constructor.
         * 
         * @param name The name of this test.
         */
        Test(const std::string& name);

        /**
         * @brief Executes the test.
         */
        virtual Result<std::string, bool> execute() = 0;

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
