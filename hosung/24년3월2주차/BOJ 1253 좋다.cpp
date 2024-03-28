#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* ���� Ž���� ���� �� ���� ���� �־��� ���� �����ϴ� �� ã�Ƴ���
* �̶� �� ���� ���� �����ϴ� ���� �ε����� �迭�� ũ��� �ʱ�ȭ�Ͽ�
* �����ϸ� �μ��� �յ� �� �� �� �ε����� ����Ű�� �ϰ�
* �μ��� �պ��� �۰ų� �������� ���� ��� continue�� �Ͽ� ����ġ�� �Ѵ�
* visited�迭�� ���� ���� ������ �ٸ� ������ ������ ���� ���� ǥ���ϰ�
* �ð��ʰ��� ���� ���� ���� ������ �ٸ� ������ ���� �� ���� ���� �ε�����
* ����Ű���� �Ϸ��� ���� ������ �ٸ� �����Ǵ� ù �ε����� ���� ��Ÿ�� ������
* �������� �����Ͽ���
* �������ͷ� �ϱ⿡ �������� �����ؼ� �̿� ���� �ذ���
*/

vector<long long>good;
int visited[2000];

bool chk(int mid, long long sum) {
    return sum <= good[mid];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        long long num;
        cin >> num;
        good.push_back(num);
    }

    sort(good.begin(), good.end());

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) {
                int tmp = good[i] + good[j];
                //����Ž��
                int start = 0;
                int eNd = N - 1;
                int mid = 0;
                int idx = N;
                while (start <= eNd) {
                    mid = (start + eNd) / 2;
                    if (chk(mid, tmp)) {
                        eNd = mid - 1;
                        idx = min(mid, idx);
                    }
                    else {
                        start = mid + 1;
                    }
                }

                if (idx == N) continue; //����X ��������
                if (good[idx] != tmp) continue; //ã�Ҵµ� ���� ���̸� ��������

                int correction = 0;
                if (visited[idx] >= 1) {
                    correction = visited[idx];
                    visited[idx]++;
                }

                for (int k = idx + correction; k < N; k++) {
                    if (good[idx] != good[k]) {
                        break;
                    }
                    else {
                        if (i == k || j == k) continue;
                        if (visited[k] == 0) {
                            visited[k] = 1;
                            break;
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i] >= 1) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}


