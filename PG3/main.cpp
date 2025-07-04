#include<stdio.h>
#include<list>

// 駅名をchar配列で定義（英語表記のみ）
const char* yamanote_1970[][2] = {
    {"Tabata", "Tabata"},
    {"Nishi-Nippori", "Nishi-Nippori"}, // 1971年開業
    {"Nippori", "Nippori"},
    {"Uguisudani", "Uguisudani"},
    {"Ueno", "Ueno"},
    {"Okachimachi", "Okachimachi"},
    {"Akihabara", "Akihabara"},
    {"Kanda", "Kanda"},
    {"Tokyo", "Tokyo"},
    {"Yurakucho", "Yurakucho"},
    {"Shimbashi", "Shimbashi"},
    {"Hamamatsucho", "Hamamatsucho"},
    {"Tamachi", "Tamachi"},
    {"Shinagawa", "Shinagawa"},
    {"Osaki", "Osaki"},
    {"Gotanda", "Gotanda"},
    {"Meguro", "Meguro"},
    {"Ebisu", "Ebisu"},
    {"Shibuya", "Shibuya"},
    {"Harajuku", "Harajuku"},
    {"Yoyogi", "Yoyogi"},
    {"Shinjuku", "Shinjuku"},
    {"Shin-Okubo", "Shin-Okubo"},
    {"Takadanobaba", "Takadanobaba"},
    {"Mejiro", "Mejiro"},
    {"Ikebukuro", "Ikebukuro"},
    {"Otsuka", "Otsuka"},
    {"Sugamo", "Sugamo"},
    {"Komagome", "Komagome"},
    {"Tabata", "Tabata"}
};

// 2019年: 高輪ゲートウェイ駅(2020年開業)を追加
const char* takanawa = "Takanawa Gateway";
const char* nishinippori = "Nishi-Nippori";

void print_list(std::list<const char*>& lst) {
    for (std::list<const char*>::iterator it = lst.begin(); it != lst.end(); ++it) {
        printf("%s\n", *it);
    }
    printf("\n");
}

int main() {
    // 1970年
    printf("【1970年】\n");
    std::list<const char*> list1970;
    for (int i = 0; i < 30; ++i) {
        // 1971年開業の西日暮里駅は1970年には含めない
        if (i == 1) continue;
        list1970.push_back(yamanote_1970[i][0]);
    }
    print_list(list1970);

    // 2019年
    printf("【2019年】\n");
    std::list<const char*> list2019;
    for (int i = 0; i < 30; ++i) {
        list2019.push_back(yamanote_1970[i][0]);
    }
    print_list(list2019);

    // 2022年
    printf("【2022年】\n");
    std::list<const char*> list2022;
    for (int i = 0; i < 30; ++i) {
        // 高輪ゲートウェイ駅を品川と田町の間に挿入
        list2022.push_back(yamanote_1970[i][0]);
        if (strcmp(yamanote_1970[i][0], "Tamachi") == 0) {
            list2022.push_back(takanawa);
        }
    }
    print_list(list2022);

    return 0;
}