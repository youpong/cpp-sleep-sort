#include "sleep_sort.h"
#include <chrono>
#include <mutex>
#include <thread>

void sleep_sort(std::vector<int> &v) {
    std::vector<std::thread> ths;
    std::mutex mtx;
    std::vector<int> r = v;

    v.clear();
    for (auto &e : r) {
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
