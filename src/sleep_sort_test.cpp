/** @file */
#include "sleep_sort.h"
#include "util.h"
#include <mutex>
#include <thread>

struct TestCase {
    std::string name;
    std::vector<int> expected;    
    /** a vector to sort */
    std::vector<int> v;
};

static void test_normal();
static void test_negative();
static void test_sort(TestCase &);

/** for exclusive control of output */
std::mutex print_mtx;

void test_sleep_sort() {
    test_normal();
    test_negative();
}

static void test_normal() {
    std::vector<TestCase> cases = {
        {"zero element"s,      {},              {}             },
        {"one element"s,       {1},             {1}            },
        {"five elements"s,     {1, 2, 3, 4, 5}, {5, 4, 2, 3, 1}},
        {"duplicated values"s, {1, 1, 2, 2},    {2, 1, 1, 2}   },
        {"zero"s,              {0, 1, 2, 3, 4}, {4, 3, 1, 2, 0}},
    };

    std::vector<std::thread> ths;
    for (auto &c : cases) {
        ths.push_back(std::thread{[&] { test_sort(c); }});
    }

    for (auto &t : ths) {
        if (t.joinable()) {
            t.join();
        }
    }
}

static void test_negative() {
    auto c = TestCase{"negative"s, {}, {-1}};

    int checkPoint = 0;
    try {
        test_sort(c);
        checkPoint |= 0b1;
    } catch (std::range_error &e) {
        checkPoint |= 0b01;
    }
    expect(0b01, checkPoint, "");
}

static void test_sort(TestCase &c) {
    auto pp = [](std::vector<int> v) {
        auto result = "["s;
        auto delim = ""s;
        for (auto i : v) {
            result += delim + std::to_string(i);
            delim = ", "s;
        }
        return result + "]"s;
    };

    sleep_sort(c.v);

    if (c.expected != c.v) {
        std::lock_guard<std::mutex> lock(print_mtx);
        std::cout << c.name << ": want"s << pp(c.expected) << ", but got"s << pp(c.v)
                  << std::endl;
        std::exit(1);
    }
}
