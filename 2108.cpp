#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	int count;
	cin >> count;

	int sum = 0;
	
	vector<int> v;
	int arr[8001] = { 0 };

	for (int i = 0; i < count; i++) {
		int n;
		cin >> n;
		sum += n;
		v.push_back(n);
		arr[n+4000]++;

	}

	// 평균 - 소수점 이하 첫쨰자리 반올림
	double avg = ((double)sum) / count;
	avg = round(avg);
	if (avg == -0) {
		avg = 0;
	}
	cout << avg << "\n";

	// 중앙값
	sort(v.begin(), v.end());
	int med = v.at(v.size() / 2);
	cout << med << "\n";

	// 최빈값
	int stop = 0;
	int com;
	int common_value = 0;
	for (int i = 0; i < 8001; i++) {
		if (arr[i] > common_value) {
			common_value = arr[i];
		}
	}
	for (int i = 0; i <  8001; i++) {
		if (arr[i] == common_value) {
			com = i-4000;
			stop++;
		}
		if (stop == 2) {
			break;
		}
	}
	cout << com << "\n";

	// 범위
	int rng = v.back() - v.front();
	cout << rng;
	return 0;
}