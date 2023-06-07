#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

int n, m;
vector<vector<int>> city;
vector<ii> house; //집 위치 저장
vector<ii> chicken; //치킨집 위치 저장
vector<ii> selected; //고른 치킨집 m개의 위치 저장
int min_distance = 100 * 13; //도시의 치킨거리의 최솟값

//h의 치킨거리 반환 (h: 집, c: 치킨집)
int houseChickenDistance(ii& h, ii& c) {
	return abs(h.first - c.first) + abs(h.second - c.second);
}

//도시의 치킨거리 반환
int cityChickenDistance() {
	int city_distance = 0;

	//모든 집에 대해서 치킨거리 계산
	for (int i = 0; i < house.size(); i++) {
		int chicken_distance = 100;

		//m개의 치킨집에 대해 탐색
		for (int j = 0; j < m; j++) {
			chicken_distance = min(chicken_distance, houseChickenDistance(house[i], selected[j]));
		}

		city_distance += chicken_distance;
	}
	return city_distance;
}

//도시의 치킨거리의 최솟값 계산
void backtrack(int cnt, int index) {
	//m개의 치킨집을 고른 경우 최소거리 갱신 후 종료
	if (cnt == m) {
		int distance = cityChickenDistance();
		min_distance = min(min_distance, distance);
		return;
	}

	//치킨집 하나씩 탐색
	for (int i = index; i < chicken.size(); i++) {
		//사용
		selected[cnt] = chicken[i];

		//다음 치킨집 탐색
		backtrack(cnt + 1, i + 1);

		//반납
		selected[cnt] = { 0,0 };
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	cin >> n >> m;

	selected.assign(m, { 0,0 });
	city.assign(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> city[i][j];

			if (city[i][j] == 1) {
				house.push_back({ i,j });
			}
			else if (city[i][j] == 2) {
				chicken.push_back({ i,j });
			}
		}
	}

	//연산
	backtrack(0, 0);

	//출력
	cout << min_distance;

	return 0; 
}