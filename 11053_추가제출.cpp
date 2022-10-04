#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �ð� ���⵵ O(n^2)
int solution(int n, vector<int>& arr) {
    // dp ���ʹ� i��° ���ұ����� ���� �� ������ ���̸� �����Ѵ�
    vector<int> dp(n, 1); // n ũ���� ���͸� 1�� �ʱ�ȭ
    int ans = 1;

    for (int i = 1; i < n; i++) { // ���� ���� ��� ���ҵ鿡 ���� (0��° ���Ҵ� ���� ���Ұ� �������� �����Ƿ� ����)
        for (int j = 0; j < i; j++) { // ���������� ���ҵ�� ��Ұ��踦 ������
            if (arr[i] > arr[j]) { //�����ϴ� ������
                dp[i] = max(dp[i], dp[j] + 1); // dp[i] �� ũ�ٸ� �״��, dp[j]�� ũ�ٸ� i��° ������ �����Ͽ� ������Ʈ
            }
        }
        ans = max(ans, dp[i]); //���� ���� ����
    }
    return ans;
}

int main() {
    int n;

    //�Է�
    cin >> n;
    vector<int> arr(n, 0); // ������ ���� nũ���� ���͸� 0���� �ʱ�ȭ
    
    // ���Ϳ� ���� �Է¹ޱ�
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //���� & ���
    cout << solution(n, arr);

}