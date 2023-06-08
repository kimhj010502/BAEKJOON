#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//요세푸스 순열 반환
vector<int> josephus(int n, int k, queue<int>& number) {
	vector<int> result;
	int cnt = 0; //몇 번째 사람인지 저장

	while (!number.empty()) {
		int num = number.front();
		number.pop();

		cnt++;
		//k번째 사람 제거하고 result에 추가한 다음 cnt 초기화
		if (cnt == k) {
			result.push_back(num);
			cnt = 0;
		}
		//k번째 사람이 아니라면 number에 다시 추가
		else {
			number.push(num);
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, k;
	cin >> n >> k;

	//1부터 n까지의 숫자 저장
	queue<int> number;
	for (int i = 1; i <= n; i++) {
		number.push(i);
	}

	//연산
	vector<int> result = josephus(n, k, number);

	//출력
	cout << "<";
	for (int i = 0; i < n - 1; i++) {
		cout << result[i] << ", ";
	}
	cout << result[n - 1] << ">";

	return 0;
}