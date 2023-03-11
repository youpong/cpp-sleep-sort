#include "sleep_sort.h"
#include "util.h"
#include <mutex>
#include <string>
#include <thread>

struct TestSet {
    std::string msg;
    std::vector<int> want;
    std::vector<int> sample;
};

static void test_normal();
static void test_negative();
static void test_sort(TestSet &);

std::mutex print_mtx;

void test_sleep_sort() {
    test_normal();
    test_negative();
}

static void test_normal() {
    std::vector<TestSet> tests = {
        {"zero element"s,      {},              {}             },
        {"one element"s,       {1},             {1}            },
        {"five elements"s,     {1, 2, 3, 4, 5}, {5, 4, 2, 3, 1}},
        {"duplicated values"s, {1, 1, 2, 2},    {2, 1, 1, 2}   },
        {"zero"s,              {0, 1, 2, 3, 4}, {4, 3, 1, 2, 0}},
    };

    std::vector<std::thread> ths;
    for (auto &t : tests) {
        ths.push_back(std::thread{[&] { test_sort(t); }});
    }

    for (auto &t : ths) {
        if (t.joinable()) {
            t.join();
        }
    }
}

static void test_negative() {
    auto t = TestSet{"negative"s, {}, {-1}};

    int checkPoint = 0;
    try {
        test_sort(t);
        checkPoint |= 0b1;
    } catch (std::range_error &e) {
        checkPoint |= 0b01;
    }
    expect(0b01, checkPoint, "");
}

static void test_sort(TestSet &t) {
    auto pp = [](std::vector<int> v) {
        auto result = "["s;
        auto delim = ""s;
        for (auto i : v) {
            result += delim + std::to_string(i);
            delim = ", "s;
        }
        return result + "]"s;
    };

    sleep_sort(t.sample);

    if (t.want != t.sample) {
        std::lock_guard<std::mutex> lock(print_mtx);
        std::cout << t.msg << ": want"s << pp(t.want) << ", but got"s << pp(t.sample)
                  << std::endl;
        std::exit(1);
    }
}
