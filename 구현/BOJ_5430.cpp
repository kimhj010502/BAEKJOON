#include <iostream>
#include <vector>
#include <deque>
#include <string>

using namespace std;

//R: 배열에 있는 수의 순서를 뒤집는 함수
//r이 0인 경우 1 반환, 1인 경우 0 반환
int funcR(int r) {
	return 1 - r;
}

//D: 배열의 첫 번째 수를 버리는 함수
void funcD(int r, deque<int>& number) {
	//안뒤집어진 경우 front 삭제
	if (r == 0) {
		number.pop_front();
	}
	//뒤집어진 경우 back 삭제
	else {
		number.pop_back();
	}
}

//[a,b,c] 형태로 입력된 x에서 숫자만 따로 저장하여 deque으로 반환하는 함수
deque<int> getArray(string x) {
	deque<int> dq;

	//x가 빈 배열인 경우 비어있는 덱 반환
	if (x == "[]") {
		return dq;
	}

	string s = "";

	//대괄호 제외하고 탐색
	for (int i = 1; i < x.size() - 1; i++) {
		//콤마인 경우 숫자가 끝났으므로 s 저장
		if (x[i] == ',') {
			dq.push_back(stoi(s));
			s = "";
		}
		//콤마가 아닌 경우 숫자가 이어지고 있는 것이므로 s에 추가
		else {
			s += x[i];
		}
	}
	dq.push_back(stoi(s));

	return dq;
}

//함수 수행한 결과 반환
//에러가 발생한 경우 {-1} 반환
vector<int> solution(string p, int r, deque<int>& number) {
	for (int i = 0; i < p.size(); i++) {
		switch (p[i]) {
			case 'R':
				r = funcR(r);
				break;
			case 'D':
				//배열이 비어있는 경우 에러 발생
				if (number.empty()) {
					return { -1 };
				}
				funcD(r, number);
				break;
		}
	}

	vector<int> result;
	//안뒤집어진 경우 앞부터 반환
	if (r == 0) {
		while (!number.empty()) {
			result.push_back(number.front());
			number.pop_front();
		}
	}
	//뒤집어진 경우 뒤부터 반환
	else {
		while (!number.empty()) {
			result.push_back(number.back());
			number.pop_back();
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n;
	string p, x;
	cin >> t;

	while (t--) {
		//입력
		cin >> p >> n >> x;

		//연산
		int r = 0; //(0: 안뒤집어짐, 1: 뒤집어짐)
		deque<int> number = getArray(x);
		vector<int> result = solution(p, r, number);

		//출력
		//에러가 발생한 경우
		if (result.size() && result[0] == -1) {
			cout << "error\n";
			continue;
		}

		//배열이 비어있는 경우
		if (!result.size()) {
			cout << "[]\n";
			continue;
		}
		
		cout << "[";
		for (int i = 0; i < result.size() - 1; i++) {
			cout << result[i] << ",";
		}
		cout << result[result.size() - 1] << "]\n";
	}

	return 0;
}