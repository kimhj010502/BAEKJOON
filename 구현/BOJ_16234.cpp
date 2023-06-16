#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

typedef pair<int, int> ii;

int n, l, r;
vector<vector<int>> country;
vector<vector<bool>> visited;
vector<vector<int>> unite;
vector<ii> unite_cnt; //unite_cnt[i]: i 유닛에 속한 나라의 개수와 인구수 합

//경계를 공유하는 나라를 한 유닛으로 묶고 유닛의 종류의 개수 반환
int countryUnite() {
	unite.assign(n, vector<int>(n, 0));
	visited.assign(n, vector<bool>(n, false));
	unite_cnt.assign(pow(n, 2) + 1, { 0,0 });

	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };

	queue<ii> q; //탐색할 나라 저장
	int u = 0; //유닛 번호

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//탐색한 칸은 넘어감
			if (visited[i][j]) {
				continue;
			}

			visited[i][j] = true;
			q.push({ i,j });
			u++;

			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				unite[x][y] = u;
				unite_cnt[u].first++;
				unite_cnt[u].second += country[x][y];

				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];

					//범위를 벗어났거나 이미 탐색한 칸인 경우 다음 칸으로 이동
					if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) {
						continue;
					}

					//국경선을 공유하는 두 나라의 인구 차이가 l명 이상, r명 이하라면 국경선 열기
					if (abs(country[x][y] - country[nx][ny]) >= l && abs(country[x][y] - country[nx][ny]) <= r) {
						visited[nx][ny] = true;
						unite[nx][ny] = u;
						q.push({ nx,ny });
					}
				}
			}
		}
	}
	return u;
}

//인구 이동하고 한 유닛에 속한 나라의 개수 반환
void movePeople(int k) {
	//한 유닛에 나라가 한 개만 속한 경우 바꾸지 않아도 됨
	if (unite_cnt[k].first == 1) {
		return;
	}

	int cnt = unite_cnt[k].first; //연합에 속한 나라의 개수
	int total = unite_cnt[k].second; //연합의 인구수

	int people = total / cnt; //각 칸의 인구수
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (unite[i][j] == k) {
				country[i][j] = people;
			}
		}
	}
	return;
}

//인구 이동이 발생하는 일수 반환
int getday() {
	int day = 0;

	while (true) {
		int u = countryUnite(); //경계를 공유하는 나라를 한 유닛으로 묶음

		//모든 나라가 다른 유닛에 속할 경우 인구 이동이 불가능하므로 무한 반복문 종료
		if (u == pow(n, 2)) {
			break;
		}

		//모든 유닛에 대해서 인구 이동
		for (int i = 1; i <= u; i++) {
			movePeople(i);
		}

		day++;
	}
	return day;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	cin >> n >> l >> r;

	country.assign(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> country[i][j];
		}
	}

	//연산 & 출력
	cout << getday();

	return 0;
}