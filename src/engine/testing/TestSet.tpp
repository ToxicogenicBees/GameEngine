/*
    TestSet.tpp

    Template implementation of a set of engine tests.
*/

#include <utility>

namespace toxico::test {
    template<std::input_iterator InputIter>
    TestSet::TestSet(const std::string& name, InputIter begin, InputIter end)
        : Test(name),
          tests_(begin, end)
    {}

    template<std::derived_from<Test> T, typename... Args>
    Test* TestSet::add(Args&& ...args) {
        tests_.push_back(std::make_unique<Test>(std::forward<Args>(args)...));
        return tests_.back().get();
    }
}
