#include <iostream>
#include <vector>

using namespace std;

typedef pair<bool, bool> bb;

string getOrder(vector<int>& number) {
	bb order = { false, false }; //{ascending 여부, descending 여부}

	for (int i = 1; i < 8; i++) {
		if (number[i] > number[i - 1]) {
			order.first = true;
			continue;
		}
		order.second = true;
	}

	if (order.first && order.second) {
		return "mixed";
	}
	if (order.first) {
		return "ascending";
	}
	return "descending";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	vector<int> number(8);
	for (int i = 0; i < 8; i++) {
		cin >> number[i];
	}

	//연산 & 출력
	cout << getOrder(number);

	return 0;
}