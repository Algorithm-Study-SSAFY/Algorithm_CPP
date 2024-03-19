#include <iostream>

using namespace std;

/*
* 1���� �������� ���ӵ� ������ ������ �˾ƾ��ϹǷ�
* ���Ͽ� ���ε带 ���� �ɰ� ���ٰ� ������
* ���ڵ����� �� ������ �ٵ� ������ �����Ͽ��� �׷��� �����ѵ�
* ���� ������ ���¸� �Է� �ް� �ʱ� ���¿� ���ӵ� ������ ������ ���Ѵ�
* ����� DAT�� ���� �θ� ������ �� �θ� �迭�� ī�����Ѵ� 
* ���� 0�� ���� ������ ���� ������ ����ϰ�
* 1�̸� ������ Ȯ���ϵ� cnt�� �̿��� union�� Ƚ���� ����
* union Ƚ���� 0�̸� ������ ������ �ϳ� ������Ű��
* union Ƚ���� 1�̸� ���� �ִ� ������ union�� ���̹Ƿ� �״���̸�
* union Ƚ���� 2�̸� ���� �ִ� �� ������ �ϳ��� union�� ���̹Ƿ� ������ ������ �ϳ� ���� ��Ų��
*/

int N, M;
int dirty;
int dx[] = { -1,1 };

bool aisle[1000000];
int parent[1000000];
int dirtyidx[1000000];


void init() {
	for (int i = 0; i < 1000000; i++) parent[i] = i;
}

int find(int tar) {
	if (tar == parent[tar]) return tar;
	return parent[tar] = find(parent[tar]);
}

void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);

	if (t1 == t2) return;
	parent[t2] = t1;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	init();

	cin >> N >> M;

	//���� ����
	for (int i = 0; i < N; i++) {
		cin >> aisle[i];
	}

	//������ ���� ���ӱ��� ���Ͽ�
	for (int i = 0; i < N; i++) {
		if (aisle[i]) {
			for (int j = 0; j < 2; j++) {
				int nidx = i + dx[j];

				if (nidx < 0 || nidx >= N) continue;
				if (!aisle[nidx]) continue;
				if (find(i) == find(nidx)) continue;
				setUnion(i, nidx);
			}
		}
	}

	//������ ���� ����
	for (int i = 0; i < N; i++) {
		if (aisle[i]) {
			dirtyidx[find(i)]++;
		}
	}

	for (int i = 0; i < N; i++) {
		if (dirtyidx[i] > 0) dirty++;
	}


	//�÷ý���
	for (int i = 0; i < M; i++) {
		bool test;
		cin >> test;
		if (!test) {
			cout << dirty << "\n";
		}
		else { //������������
			int idx;
			cin >> idx;
			idx -= 1; //i��°�� 1���� �����̶� i-1�� ������Ѵ�
			if (!aisle[idx]) {
				aisle[idx] = !aisle[idx];
				int cnt = 0;
				for (int j = 0; j < 2; j++) {
					int nidx = idx + dx[j];

					if (nidx < 0 || nidx >= N) continue;
					if (!aisle[nidx]) continue;
					if (find(idx) == find(nidx)) continue;
					setUnion(idx, nidx);
					cnt++;
				}
				if (cnt == 0) dirty++;
				else if (cnt == 2) dirty--;
			}
		}
	}

	return 0;
}