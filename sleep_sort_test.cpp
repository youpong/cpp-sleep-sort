#include "sleep_sort.h"
#include <mutex>
#include <thread>

struct Unit {
    std::string msg;
    std::vector<int> want;
    std::vector<int> sample;
};
static void test_sort(Unit &u);
std::mutex print_mtx;

void test_normal() {
    std::vector<Unit> tests = {
        Unit{"zero element"s, {}, {}}, Unit{"one element"s, {1}, {1}},
        Unit{"five elements"s, {1, 2, 3, 4, 5}, {5, 4, 2, 3, 1}},
        Unit{"duplicated values"s, {1, 1, 2, 2}, {2, 1, 1, 2}}};

    std::vector<std::thread> ths;
    for (auto &u : tests) {
        ths.push_back(std::thread{[&] { test_sort(u); }});
    }

    for (auto &t : ths) {
        if (t.joinable())
            t.join();
    }
}

static void test_sort(Unit &u) {
    auto pp = [](std::vector<int> v) {
        std::cout << "["s;
        auto delim = ""s;
        for (auto i : v) {
            std::cout << delim << i;
            delim = ", ";
        }
        std::cout << "]"s;
    };

    sleep_sort(u.sample);

    if (u.want != u.sample) {
        std::lock_guard<std::mutex> lock(print_mtx);
        std::cout << u.msg << ": want"s;
        pp(u.want);
        std::cout << ", got"s;
        pp(u.sample);
        std::cout << std::endl;
        exit(1);
    }
}
