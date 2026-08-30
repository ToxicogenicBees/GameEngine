/*
    TestSet.hpp

    Declaration of a set of engine tests.
*/

#pragma once

#include "testing/Test.hpp"
#include "testing/TestResult.hpp"
#include <type_traits>
#include <iterator>
#include <vector>
#include <memory>

namespace toxico::test {
    class TestSet : public Test {
    private:
        using Tests = std::vector<std::unique_ptr<Test>>;
        Tests tests_;

    protected:
        /**
         * @brief Executes the test.
         * 
         * @return The test results.
         */
        TestResult test() final;

    public:
        using const_iterator = Tests::const_iterator;
        using iterator = Tests::iterator;

        /**
         * @brief Constructor.
         * 
         * @param name The name of this test.
         * @param begin The beginning of a set of tests.
         * @param end The end of a set of tests.
         */
        template<std::input_iterator InputIter>
        TestSet(const std::string& name, InputIter begin, InputIter end);

        /**
         * @brief Constructor.
         * 
         * @param name The name of this test.
         */
        TestSet(const std::string& name) noexcept;

        /**
         * @brief Constructor.
         * 
         * @param args The constructor arguments for the desired test.
         */
        template<std::derived_from<Test> T, typename... Args>
        Test* add(Args&& ...args);
    };
}

#include "testing/TestSet.tpp"
