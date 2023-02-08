#include "sleep_sort.h"

static void test_sort(const std::string msg, std::vector<int> want,
                      std::vector<int> sample) {
    auto pp = [](std::vector<int> v) {
        std::cout << "["s;
        auto delim = ""s;
        for (auto i : v) {
            std::cout << delim << i;
            delim = ", ";
        }
        std::cout << "]"s;
    };

    sleep_sort(sample);

    if (want != sample) {
        std::cout << msg << ": want"s;
        pp(want);
        std::cout << ", got"s;
        pp(sample);
        std::cout << std::endl;
        exit(1);
    }
}

void test_normal() {
    test_sort("one element"s, {1}, {1});
    test_sort("two elements"s, {1, 2}, {2, 1});
    test_sort("five elements"s, {1, 2, 3, 4, 5}, {5, 4, 2, 3, 1});
    test_sort("duplicated values"s, {1, 1, 2, 2}, {2, 1, 1, 2});
}
