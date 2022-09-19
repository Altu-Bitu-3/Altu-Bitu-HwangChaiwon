#include <iostream>

using namespace std;


// ��Ŭ���� ȣ����
int gcdRecursion(int x, int y) {
    // a > b �� ��, a�� b�� �ִ������� ����
    if (y == 0) {
        return x;
    }
    return gcdRecursion(y, x % y);
}

int main() {
    // �Է�
    int x, y;
    cin >> x >> y;

    // x�� y�� �ִ����� ���ϱ�
    int gcd = gcdRecursion(x, y);

    cout << x + y - gcd;

    return 0;
}