#include "sleep_sort.h"
#include "util.h"
#include <algorithm>
#include <chrono>
#include <thread>

void test_normal();

int main() { test_normal(); }

void sleep_sort(std::vector<int> &v) {
    std::vector<int> r;
    std::vector<std::thread> thread_group;
    for (auto i : v) {
        thread_group.push_back(std::thread(
            [&](int s) {
                std::this_thread::sleep_for(std::chrono::seconds(s));
                r.push_back(s);
            },
            i));
    }

    // for(auto t : thread_group) {
    for (size_t i = 0; i < thread_group.size(); i++) {
        thread_group.at(i).join();
    }

    v = r;
}
