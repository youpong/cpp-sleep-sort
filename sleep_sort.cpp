#include "sleep_sort.h"
#include "util.h"
#include <algorithm>
#include <chrono>
#include <thread>

void test_normal();

int main() {
    test_normal();
    return 0;
}

void sleep_sort(std::vector<int> &v) {
    std::vector<int> r;
    std::vector<std::thread> ths;
    for (auto i : v) {
        ths.push_back(std::thread(
            [&](int s) {
                std::this_thread::sleep_for(std::chrono::seconds(s));
                r.push_back(s);
            },
            i));
    }

    for(auto &t : ths) {
        t.join();
    }

    v = r;
}
