#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//메달이 많은 순으로 정렬
bool cmp(vector<int>& v1, vector<int>& v2) {
	//금메달 많은 순으로 정렬
	if (v1[1] != v2[1]) {
		return v1[1] > v2[1];
	}

	//은메달 많은 순으로 정렬
	if (v1[2] != v2[2]) {
		return v1[2] > v2[2];
	}

	//동메달 많은 순으로 정렬
	if (v1[3] != v2[3]) {
		return v1[3] > v2[3];
	}

	return v1[0] < v2[0];
}

int getRank(int n, int k, vector<vector<int>>& medal) {
	//메달이 많은 순으로 정렬
	sort(medal.begin(), medal.end(), cmp);

	//첫 번째 국가가 k 국가인 경우 1위 반환
	if (medal[0][0] == k) {
		return 1;
	}

	//먼저 순서대로 순위 채우기
	int rank = 1;
	for (int i = 0; i < n; i++) {
		medal[i][4] = rank++;
	}

	for (int i = 1; i < n; i++) {
		//이전 국가와 메달 개수가 같은 경우 이전 국가의 순위와 같게 함
		if (medal[i][1] == medal[i - 1][1] && medal[i][2] == medal[i - 1][2] && medal[i][3] == medal[i - 1][3]) {
			medal[i][4] = medal[i - 1][4];
		}

		//k 국가의 순위 반환
		if (medal[i][0] == k) {
			return medal[i][4];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, k;
	cin >> n >> k;

	vector<vector<int>> medal(n, vector<int>(5)); //medal[i]: {국가, 금, 은, 동, 순위}
	for (int i = 0; i < n; i++) {
		cin >> medal[i][0] >> medal[i][1] >> medal[i][2] >> medal[i][3];
	}

	//연산 & 출력
	cout << getRank(n, k, medal);

	return 0;
}