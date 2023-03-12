/** @file */
#include "sleep_sort.h"
#include <chrono>
#include <mutex>
#include <stdexcept>
#include <thread>

/**
 * Make an effort to sort a vector of int in ascending order. 
 *
 * The success rate is exacerbated by the following conditions:
 * 1. The greater the distance between the postions of the two elements
 * 2. The smaller the difference between two elements
 * 3. The higher the system load.
 *
 * Time to process:
 * Max value(in seconds)
 *
 * @param v the vector of int to sort.
 * @throws std::range_error a vector contains a negative number.
 */
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
