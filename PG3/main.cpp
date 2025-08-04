#include <stdio.h>
#include <thread>


void print_thread(const char* msg) {
    printf("%s\n", msg);
}

int main() {
    std::thread t1(print_thread, "thread 1");
    t1.join();
    std::thread t2(print_thread, "thread 2");
    t2.join();
    std::thread t3(print_thread, "thread 3");
    t3.join();

    return 0;
}