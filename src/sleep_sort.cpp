/** @file */
#include "sleep_sort.h"
#include <chrono>
#include <mutex>
#include <stdexcept>
#include <string>
#include <thread>

void sleep_sort(std::vector<int> &v) {
    std::vector<std::thread> ths;
    std::mutex mtx;
    std::vector<int> r = v;

    v.clear();
    for (auto &e : r) {
        if (e < 0) {
            throw std::range_error("Must be non-negative: "s + std::to_string(e));
        }
        ths.push_back(std::thread([&] {
            std::this_thread::sleep_for(std::chrono::seconds(e));
            std::lock_guard<std::mutex> lock(mtx);
            v.push_back(e);
        }));
    }

    for (auto &t : ths) {
        if (t.joinable()) {
            t.join();
        }
    }
}
