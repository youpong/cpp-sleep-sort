#include "sleep_sort.h"
#include <algorithm>
#include <chrono>
#include <mutex>
#include <thread>

void sleep_sort(std::vector<int> &v) {
    std::vector<int> r;
    std::vector<std::thread> ths;
    std::mutex mtx;
    for (auto i : v) {
        ths.push_back(std::thread(
            [&](int s) {
                std::this_thread::sleep_for(std::chrono::seconds(s));
                mtx.lock();
                r.push_back(s);
                mtx.unlock();
            },
            i));
    }

    for (auto &t : ths) {
        t.join();
    }

    v = r;
}
