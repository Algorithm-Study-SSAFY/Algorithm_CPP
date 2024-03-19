#include <iostream>
#include <vector>

using namespace std;

/*
* N X M�� 500,000�̹Ƿ� int�迭�� 2���� ����
* row���� col���� ���ؼ� ���߿� �������� ���ϸ� �ȴٰ� ������
*/

vector<int>row;
vector<int>col;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M, Q;
	cin >> N >> M >> Q;

	row = vector<int>(N, 0);
	col = vector<int>(M, 0);

	for (int i = 0; i < Q; i++) {
		int sel; //1�̸� r��° �� v�� ����, 2�̸� r��° �� v�� ����
		int r, v;
		cin >> sel >> r >> v;
		if (sel == 1) {
			row[r - 1] += v;
		}
		else {
			col[r - 1] += v;
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << row[i] + col[j] << " ";
		}
		cout << "\n";
	}

	return 0;
}