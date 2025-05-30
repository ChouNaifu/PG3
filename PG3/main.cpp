#include<stdio.h>

template<typename T1, typename T2>
class MinClass {

private:
    T1 x;
    T2 y;

public:
    MinClass(T1 a, T2 b) : x(a), y(b) {}
	// Function to find the minimum of x and y
    auto Min() const {
        return (x < y) ? x : y;
    }

    void Print() const {
		// Print the types and values of x and y
        if (sizeof(x) == sizeof(int) && sizeof(y) == sizeof(int))
            printf("Min(%d, %d) = %d\n", (int)x, (int)y, (int)Min());
        else if (sizeof(x) == sizeof(float) || sizeof(y) == sizeof(float))
            printf("Min(%f, %f) = %f\n", (double)x, (double)y, (double)Min());
        else
            printf("Min(%lf, %lf) = %lf\n", (double)x, (double)y, (double)Min());
    }

};

//main function
int main() {
	//int, float, double 三種類型のMinClassを作成し、各型のインスタンスを生成して最小値を表示する
    MinClass<int, int> a(3, 7);           a.Print();
    MinClass<int, float> b(3, 7.5f);      b.Print();
    MinClass<int, double> c(3, 7.5);      c.Print();
    MinClass<float, float> d(3.5f, 7.5f); d.Print();
    MinClass<float, double> e(3.5f, 7.5); e.Print();
    MinClass<double, double> f(3.5, 7.5); f.Print();

return 0;//終了
}