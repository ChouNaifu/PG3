#include<stdio.h>

// Air Supportクラス（基底クラス）
class AirSupport {
public:
	// 仮想関数：Close Air Support
    virtual void CAS() {
        printf("Air Support Inbound. ETA 3 mikes out.\n");
    }
};

// Apacheクラス（派生クラス）
class Apache : public AirSupport {
public:
    void CAS() override {
        printf("All Bravo, Kilo 1-1 is inbound hot, danger close.\n");
    }
};

// AC130クラス（派生クラス）
class AC130 : public AirSupport {
public:
    void CAS() override {
        printf("Bravo 6- This is Viper 1-1 on approach, ready for tasking.\n");
    }
};

// UAVクラス（派生クラス）
class UAV : public AirSupport {
public:
    void CAS() override {
        printf("All station be advised. Shadow-1 is on station for close-air, guns hot.\n");
    }
};

int main() {
    // ポリモーフィズムの例
    AirSupport* fire[3];
    fire[0] = new Apache();
    fire[1] = new AC130();
    fire[2] = new UAV();

    // それぞれのCASを出す
    for (int i = 0; i < 3; i++) {
        fire[i]->CAS();
        delete fire[i];
    }

    return 0; // 終了
}