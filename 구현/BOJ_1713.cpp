#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct student {
	int num; //학생 번호
	int vote = 0; //추천수
	int time = 1000; //추천받은 시간
	bool photo = false; //사진틀에 게시되어있는지의 여부
};

//제거될 학생 순으로 정렬
bool cmp1(student s1, student s2) {
	//추천수로 오름차순 정렬
	if (s1.vote != s2.vote) {
		return s1.vote < s2.vote;
	}

	//추천수가 같다면 추천시간으로 오름차순 정렬
	return s1.time < s2.time;
}

//학생 번호 순으로 오름차순 정렬
bool cmp2(student s1, student s2) {
	return s1.num < s2.num;
}

vector<student> getStudent(int n, int m, vector<int>& candidate) {
	vector<student> result; //최종 후보
	vector<student> v(101); //v[i]: i 학생의 {추천수, 추천시간, 사진틀 게시여부}

	for (int i = 0; i < m; i++) {
		int s = candidate[i]; //추천받은 학생

		//사진틀에 게시되어있는 후보인 경우
		if (v[s].photo) {
			for (int j = 0; j < result.size(); j++) {
				if (result[j].num == s) {
					result[j].vote++; //추천수 증가
					v[s] = result[j];
					break;
				}
			}
		}

		//사진틀에 게시되어있지 않은 후보인 경우
		else {
			//최종 후보 자리가 꽉 찬 경우 한 명 삭제
			if (result.size() == n) {
				sort(result.begin(), result.end(), cmp1); //제거될 학생 순으로 정렬됨

				int d = result[0].num; //제거될 학생의 번호
				result.erase(result.begin() + 0); //0번째 인덱스 학생 d 제거
				v[d].vote = 0;
				v[d].time = -1;
				v[d].photo = false;
			}

			//새로운 학생 s 등록
			v[s].num = s;
			v[s].vote++;
			v[s].time = i;
			v[s].photo = true;
			result.push_back(v[s]);
		}
	}

	sort(result.begin(), result.end(), cmp2); //학생 번호 순으로 오름차순 정렬
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m;
	cin >> n >> m;
	
	vector<int> candidate(m);
	for (int i = 0; i < m; i++) {
		cin >> candidate[i];
	}

	//연산
	vector<student> result = getStudent(n, m, candidate);

	//출력
	for (int i = 0; i < result.size(); i++) {
		cout << result[i].num << " ";
	}

	return 0;
}