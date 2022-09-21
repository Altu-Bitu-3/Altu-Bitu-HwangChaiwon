#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

string wordArrange(queue<char> q) {
	string new_word = "";

	for (int i = 0; i < q.size(); i++) {
		new_word += q.front();
		q.push(q.front());
		q.pop();
	}

	return new_word;
}

bool checkWord(string word, vector<string> v) {
	queue<char> q;

	// 큐에 단어 저장
	for (int i = 0; i < word.size(); i++) {
		q.push(word[i]);
	}
	
	if (v.size() == 0) {
		return false;
	}
	else {
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < word.size(); j++) {

				// 벡터 안에 단어가 존재
				if (v[i] == wordArrange(q)) {
					return true;
				}
				// 없으면 큐 바꿔서 검사
				else {
					q.push(q.front());
					q.pop();
				}
			}
		}
	}

	return false;
}

int main() {
	int num;
	string word;
	bool flag = false;

	vector<string> v;

	// 입력
	cin >> num;
	
	while (num--) {
		cin >> word;

		// 입력받은 단어가 벡터에 존재하는지 검사하는 함수
		flag = checkWord(word, v);

		//벡터에 존재하지 않을 경우에만 벡터에 삽입
		if (flag == false) {
			v.push_back(word);
		}
	}
	// 벡터 안의 단어 개수 출력하기
	cout << v.size();

	return 0;
}