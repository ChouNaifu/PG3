#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// call back type define
typedef void (*Callback)(int, int);

// wating function
void setTimeout(void (*callback)(int, int), int diceRoll, int userGuess, int seconds) {
    Sleep(seconds); // 秒数決める
	callback(diceRoll, userGuess); // コールバック関数を実行
}

// サイコロゲーム関数
void playDiceGame() {
    // 乱数シード
    unsigned int currentTime = time(nullptr);
    srand(currentTime);

    // サイコロを振る
    int diceRoll = rand() % 6 + 1;

    // プレイヤーの入力
    printf("サイコロを振って出目が奇数か偶数かを当ててください。\n");
    printf("奇数なら1、偶数なら2を入力してください: ");
    int userGuess;
    scanf_s("%d", &userGuess);

    auto checkResultLambda = [](int dice, int guess) {
        if ((dice % 2 == 0 && guess == 2) || (dice % 2 != 0 && guess == 1)) {
            printf("正解！\n");
        } else {
            printf("不正解。\n");
        }
        printf("サイコロの出目は: %d でした。\n", dice);
        };

    // 関数ポインタにキャストして渡す
    void (*callback)(int, int) = checkResultLambda;

	// 3秒後に結果を表示するためにコールバック関数を呼び出す
    setTimeout(callback, diceRoll, userGuess, 3000);
}

// メイン関数
int main() {
    //  ゲーム開始
    playDiceGame();

    return 0;
}