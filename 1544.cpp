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

	// ť�� �ܾ� ����
	for (int i = 0; i < word.size(); i++) {
		q.push(word[i]);
	}
	
	if (v.size() == 0) {
		return false;
	}
	else {
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < word.size(); j++) {

				// ���� �ȿ� �ܾ ����
				if (v[i] == wordArrange(q)) {
					return true;
				}
				// ������ ť �ٲ㼭 �˻�
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

	// �Է�
	cin >> num;
	
	while (num--) {
		cin >> word;

		// �Է¹��� �ܾ ���Ϳ� �����ϴ��� �˻��ϴ� �Լ�
		flag = checkWord(word, v);

		//���Ϳ� �������� ���� ��쿡�� ���Ϳ� ����
		if (flag == false) {
			v.push_back(word);
		}
	}
	// ���� ���� �ܾ� ���� ����ϱ�
	cout << v.size();

	return 0;
}