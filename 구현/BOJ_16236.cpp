#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

const int MAX = 1e5;

struct fish {
	ii position;
	int distance;
};

int n;
vector<vector<int>> space;
vector<vector<bool>> visited;
vector<int> cnt(MAX, 0); //cnt[i]: 아기 상어의 크기가 i일때, 먹은 물고기의 개수
ii shark_position;
int shark_size = 2; //처음 아기 상어의 크기

int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

//다음에 먹을 물고기의 위치와 물고기까지의 거리 반환
void getMinFish(int x, int y, int dist, int& min_x, int& min_y, int& min_dist) {
	//현재 찾은 물고기까지의 거리가 더 짧은 경우 갱신
	if (min_dist > dist) {
		min_x = x;
		min_y = y;
		min_dist = dist;
	}

	//최단 거리와 같은 경우 가장 위쪽, 왼쪽에 있는 물고기의 위치로 갱신
	else if (min_dist == dist) {
		if (min_x == x) {
			if (min_y > y) {
				min_x = x;
				min_y = y;
			}
		}
		else if (min_x > x) {
			min_x = x;
			min_y = y;
		}
	}
}

//현재 아기 상어의 위치(x,y)에서 (i,j)까지 이동하는데 지나야하는 칸의 개수의 최솟값 계산
int getDistance() {
	queue<fish> q;
	q.push({ shark_position, 0 }); //초기화
	visited.assign(n, vector<bool>(n, false));
	visited[shark_position.first][shark_position.second] = true;

	int min_x = n, min_y = n;
	int min_dist = MAX;

	while (!q.empty()) {
		int x = q.front().position.first;
		int y = q.front().position.second;
		int dist = q.front().distance;
		q.pop();

		//아기 상어가 먹을 수 있는 크기의 물고기인 경우
		if (space[x][y] && space[x][y] < shark_size) {
			//가장 가까이에 있는 물고기에 대한 정보로 갱신
			getMinFish(x, y, dist, min_x, min_y, min_dist);
		}

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			//공간을 벗어났거나 이미 왔던 길이면 넘어감
			if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) {
				continue;
			}

			//자신의 크기보다 더 큰 물고기가 있는 칸은 지나갈 수 없음
			if (space[nx][ny] > shark_size) {
				continue;
			}

			q.push({ {nx,ny}, dist + 1 });
			visited[nx][ny] = true;
		}
	}

	//min_dist가 갱신되지 않은 경우 먹을 수 있는 물고기가 없으므로 -1 반환
	if (min_dist == MAX) {
		return -1;
	}

	shark_position = { min_x,min_y }; //상어의 위치를 먹은 물고기의 위치로 바꾸기

	space[min_x][min_y] = 0;//칸 비우기
	cnt[shark_size]++; //먹은 물고기의 개수 증가

	//자신의 크기와 같은 수의 물고기를 먹을 때마다 크기 1 증가
	if (cnt[shark_size] == shark_size) {
		shark_size++;
	}

	return min_dist;
}

//도움을 요청하지 않고 물고기를 잡아먹을 수 있는 시간 반환
int getTime() {
	int time = 0;

	while (true) {
		int dist = getDistance();

		//물고기를 먹을 수 있는 만큼 먹은 경우 종료
		if (dist == -1) {
			return time;
		}
		else {
			time += dist;
		}
	}
	return time;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	cin >> n;

	space.assign(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> space[i][j];

			if (space[i][j] == 9) {
				shark_position = { i,j };
				space[i][j] = 0;
			}
		}
	}

	//연산 & 출력
	cout << getTime();

	return 0;
}