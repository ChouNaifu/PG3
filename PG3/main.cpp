#include<stdio.h>
#define _USE_MATH_DEFINES
#include<math.h>

// IShapeクラス（抽象クラス・インターフェース）
class IShape {
public:
    // 純粋仮想関数
    virtual void Size() = 0;
    virtual void Draw() = 0;
};

// Circleクラス（派生クラス）
class Circle : public IShape {
private:
    float r;
	float size = 0;// 面積を格納する変数
public:
    Circle(float radius) : r(radius) {}
    void Size() override {      
		size = static_cast<float>(M_PI) * r * r;// 円の面積を計算
    }
    void Draw() override {
		printf("面積：%f\n", size);// 面積を表示
    }
};

// Rectangleクラス（派生クラス）
class Rectangle : public IShape {
private:
    float w, h;
	float size = 0;// 面積を格納する変数
public:
    Rectangle(float width, float height) : w(width), h(height) {}
    void Size() override {
		size = w * h;// 長方形の面積を計算
    }
    void Draw() override {
		printf("長方形の面積: %f\n\n", size);// 面積を表示
    }
};

int main() {
    // ポリモーフィズムの例
    IShape* shapes[2];
    shapes[0] = new Circle(3.0);
    shapes[1] = new Rectangle(4.0, 5.0);

	// 各形状の面積を計算し、描画する
    for (int i = 0; i < 2; i++) {
        shapes[i]->Size();
        shapes[i]->Draw();
        delete shapes[i];
    }
    return 0;
}
