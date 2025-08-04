#include <stdio.h>
#include <string>
#include <chrono>

int main() {
    // 100万文字のstd::stringを生成
    std::string a(1000000, 'a');

    // コピーの計測
    auto start_copy = std::chrono::high_resolution_clock::now();
    std::string b = a; // コピー
    auto end_copy = std::chrono::high_resolution_clock::now();
    auto copy_us = std::chrono::duration_cast<std::chrono::microseconds>(end_copy - start_copy).count();
    printf("コピー: %lld us\n", copy_us);

    // ムーブ（右辺値参照）の計測
    auto start_move = std::chrono::high_resolution_clock::now();
    std::string c = std::move(a); // ムーブ
    auto end_move = std::chrono::high_resolution_clock::now();
    auto move_us = std::chrono::duration_cast<std::chrono::microseconds>(end_move - start_move).count();
    printf("ムーブ: %lld us\n", move_us);

    return 0;
}