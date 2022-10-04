#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 시간 복잡도 O(n^2)
int solution(int n, vector<int>& arr) {
    // dp 벡터는 i번째 원소까지의 가장 긴 수열의 길이를 저장한다
    vector<int> dp(n, 1); // n 크기의 벡터를 1로 초기화
    int ans = 1;

    for (int i = 1; i < n; i++) { // 수열 안의 모든 원소들에 대해 (0번째 원소는 이전 원소가 존재하지 않으므로 제외)
        for (int j = 0; j < i; j++) { // 직전까지의 원소들과 대소관계를 따진다
            if (arr[i] > arr[j]) { //증가하는 관계라면
                dp[i] = max(dp[i], dp[j] + 1); // dp[i] 가 크다면 그대로, dp[j]가 크다면 i번째 수까지 포함하여 업데이트
            }
        }
        ans = max(ans, dp[i]); //최장 길이 갱신
    }
    return ans;
}

int main() {
    int n;

    //입력
    cin >> n;
    vector<int> arr(n, 0); // 수열을 넣을 n크기의 벡터를 0으로 초기화
    
    // 벡터에 수열 입력받기
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //연산 & 출력
    cout << solution(n, arr);

}