#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

const int MAX = 1e10;

struct fish {
	ii position;
	int distance;
};

struct compare {
	bool operator()(fish a, fish b) {
		//거리가 가장 짧은 물고기가 top에 오도록 정렬
		if (a.distance != b.distance) {
			return a.distance > b.distance;
		}

		//가장 위에 있는 물고기가 top에 오도록 정렬
		if (a.position.first != b.position.first) {
			return a.position.first > b.position.first;
		}

		//가장 왼쪽에 있는 물고기가 top에 오도록 정렬
		return a.position.second > b.position.second;
	}
};

int n, min_dist;
vector<vector<int>> space;
vector<vector<bool>> visited;
vector<int> fish_cnt(10, 0); //fish_cnt[i]: 크기가 i인 물고기의 개수
ii shark_position;
int shark_size = 2; //처음 아기 상어의 크기

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

//현재 아기 상어의 위치(x,y)에서 (i,j)까지 이동하는데 지나야하는 칸의 개수의 최솟값 계산
void getDistance(int x, int y, int i, int j, int dist) {
	//min_dist가 1인 경우, 더이상 갱신될 수가 없기 때문에 바로 종료
	if (min_dist == 1) {
		return;
	}

	//칸에 도달한 경우 종료
	if (x == i && y == j) {
		min_dist = min(min_dist, dist);
		return;
	}

	//주변 4 방향 탐색
	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];

		//공간을 벗어난 경우 넘어감
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
			continue;
		}

		//이미 왔던 길이면 넘어감
		if (visited[nx][ny]) {
			continue;
		}

		//자신의 크기보다 더 큰 물고기가 있는 칸은 지나갈 수 없음
		if (space[nx][ny] > shark_size) {
			continue;
		}

		//사용
		visited[nx][ny] = true;

		//다음 경로 탐색
		getDistance(nx, ny, i, j, dist + 1);

		//반납
		visited[nx][ny] = false;
	}
}

//pq에 자기보다 작은 물고기들의 위치와 물고기까지의 거리 저장
void getFish(int fish_size, priority_queue<fish, vector<fish>, compare>& pq) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//fish_size이상 6 이하 크기의 물고기가 있는 곳만 탐색할 것이므로 아니면 넘어감
			//현재 상어의 크기보다 큰 물고기가 있는 칸도 넘어감
			if (space[i][j] < fish_size || space[i][j] > shark_size) {
				continue;
			}

			min_dist = MAX; //최소 거리 초기화
			int x = shark_position.first;
			int y = shark_position.second;

			visited.assign(n, vector<bool>(n, false));
			visited[x][y] = true;
			getDistance(x, y, i, j, 0);

			pq.push({ {i,j}, min_dist }); //먹을 수 있는 상어의 위치와 거리 저장
		}
	}
}

//도움을 요청하지 않고 물고기를 잡아먹을 수 있는 시간 반환
int getTime(int n, vector<vector<int>>& space) {
	int time = 0;
	vector<int> cnt(MAX, 0); //cnt[i]: 아기 상어의 크기가 i일때, 먹은 물고기의 개수

	while (true) {
		priority_queue<fish, vector<fish>, compare> pq; //먹을 수 있는 물고기의 좌표

		//아기 상어의 크기보다 작은 물고기의 좌표 탐색
		for (int i = 1; i < shark_size; i++) {
			//i 크기의 물고기가 없는 경우 다음 크기로 넘어감
			if (!fish_cnt[i]) {
				continue;
			}

			cout << i << " 사이즈의 물고기: " << fish_cnt[i] << "개 남음\n";

			getFish(i, pq); //pq에 자기보다 작은 물고기들의 위치와 물고기까지의 거리 저장

			cout << "찾았으니까 종료함!\n";
			break;
		}
		
		//더 이상 먹을 수 있는 물고기가 없는 경우 시간 반환
		if (pq.empty()) {
			return time;
		}

		fish next = pq.top(); //다음으로 먹을 수 있는 물고기
		pq.pop();

		cout << "현재 위치: (" << shark_position.first << ", " << shark_position.second << ") -> (" << next.position.first << ", " << next.position.second << "), 거리: " << next.distance <<", 물고기 크기: "<< space[next.position.first][next.position.second] <<"\n";
		
		time += next.distance; //상어의 이동 시간 갱신
		shark_position = next.position; //상어의 위치를 물고기의 위치로 바꾸기

		fish_cnt[space[next.position.first][next.position.second]]--;
		space[next.position.first][next.position.second] = 0; //칸 비우기
		cnt[shark_size]++; //먹은 물고기의 개수 증가

		//자신의 크기와 같은 수의 물고기를 먹을 때마다 크기 1 증가
		if (cnt[shark_size] == shark_size) {
			shark_size++;
		}

		cout << "시간: " << time << "\n";
	}
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

			fish_cnt[space[i][j]]++;

			if (space[i][j] == 9) {
				shark_position = { i,j };
				space[i][j] = 0;
			}
		}
	}

	//연산 & 출력
	cout << getTime(n, space);

	return 0;
}