#include <iostream>

using namespace std;


// 유클리드 호제법
int gcdRecursion(int x, int y) {
    // a > b 일 때, a와 b의 최대공약수를 리턴
    if (y == 0) {
        return x;
    }
    return gcdRecursion(y, x % y);
}

int main() {
    // 입력
    int x, y;
    cin >> x >> y;

    // x와 y의 최대공약수 구하기
    int gcd = gcdRecursion(x, y);

    cout << x + y - gcd;

    return 0;
}