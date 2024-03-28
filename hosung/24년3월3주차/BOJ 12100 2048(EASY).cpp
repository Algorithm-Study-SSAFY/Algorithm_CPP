#include <iostream>
#include <algorithm>
#include <queue>

/*
* �����ϰ� �����ϰ� ��Ž ������ �� �ٽ�
*
* �ִ� 5�������̹Ƿ� �ϴ� 5���ϸ� return�Ѵ�.
* �̶� ���� ���� ���� �� ���� ���� �̹� �Ǽ��� �Űܾ�������
* ���� 5���ϴ� ����� 3�����迭�� �����Ǽ��� ��Ȳ�� �����Ѵ�.
* ��� ó�� ������
* ���� �ø��� ���� ���� ���
* ���� ����� �ø��� �Ǹ� ���ʺ��� ���� ���� �������ų� ���� ���� ����ؼ�
* ������ ���� �Ʒ��� ��ϵ��� Ž���Ͽ� ť�� ��´�.
* �� �� 0�� ���� ���� �ʴ´� ����ռ��� ������ ���� �ʱ� ������
* �� ����� �ٽ� ���������� Ž���ϸ� ť�� �� ���� Ȯ���Ѵ�
* 1.������ ť�� �����ϴ� �� Ȯ���Ѵ�.
* 1-1.ť�� ����ٸ� 0���� ä���,
* 1-2.������� �ʴٸ�, �տ� �ִ� ���� now�� �����ϰ� pop�� �Ѵ�.
* 2-1 �� ��Ȳ���� ť�� ������� �ʴٸ�
* ť�� �Ӹ��� now�� ���Ͽ� ������ ���� �������Ƿ� ����ġ�� 2�踦 ������ �� ���� ť�Ӹ��� pop�Ѵ�
* �ٸ��ٸ� �׳� now�� �����Ѵ�.
* 2-2 ť�� ����ִٸ� now�� �����Ѵ�
*
* �ٸ� �͵� ���� ������� �����Ͽ���.
*
* �������ǿ� �����ϸ� ��Ž���� ū�� ������ �װ��� �����ϸ�ȴ�.
*/

using namespace std;

int map[6][20][20];
int mirr[4][20][20];
int N;
int maxblock;


void top(int lv) { //���� �ø��Ŵϱ� ��ĥ ���� ������ ���� ��ġ�� �� Ȯ��
    queue<int>lnstk[20];
    //���������� 0�� �ƴ� �͵��� ť�� ��´�.
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[lv - 1][j][i] != 0) {
                lnstk[i].push(map[lv - 1][j][i]);
            }
        }
    }
    //�ӽ� �ʿ��ٰ� ������
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {


            if (!lnstk[i].empty()) {
                int now = lnstk[i].front();
                lnstk[i].pop();
                if (!lnstk[i].empty()) {
                    if (now == lnstk[i].front()) {
                        mirr[0][j][i] = now * 2;
                        lnstk[i].pop();
                    }
                    else mirr[0][j][i] = now;
                }
                else mirr[0][j][i] = now;
            }
            else {
                mirr[0][j][i] = 0;
            }
        }
    }

}

void left(int lv) { //�������� �ҰŴϱ� ��ĥ ���� ���ʺ��� ��ġ�� �� Ȯ��
    queue<int>lnstk[20];

    //���ʺ��� 0�� �ƴ� �͵��� ť�� ��´�.
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[lv - 1][i][j] != 0) {
                lnstk[i].push(map[lv - 1][i][j]);
            }
        }
    }
    //�ӽ� �ʿ��ٰ� ������
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {


            if (!lnstk[i].empty()) {
                int now = lnstk[i].front();
                lnstk[i].pop();
                if (!lnstk[i].empty()) {
                    if (now == lnstk[i].front()) {
                        mirr[1][i][j] = now * 2;
                        lnstk[i].pop();
                    }
                    else mirr[1][i][j] = now;
                }
                else mirr[1][i][j] = now;
            }
            else {
                mirr[1][i][j] = 0;
            }
        }
    }
}

void bottom(int lv) { //�Ʒ��� �����Ŵϱ� ��ĥ ���� �Ʒ����� ���� ��ġ�� �� Ȯ��
    queue<int>lnstk[20];
    int maxtmp = 0;
    //�Ʒ��������� 0�� �ƴ� �͵��� ť�� ��´�.
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= 0; j--) {
            if (map[lv - 1][j][i] != 0) {
                lnstk[i].push(map[lv - 1][j][i]);
            }
        }
    }
    //�ӽ� �ʿ��ٰ� ������
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= 0; j--) {


            if (!lnstk[i].empty()) {
                int now = lnstk[i].front();
                lnstk[i].pop();
                if (!lnstk[i].empty()) {
                    if (now == lnstk[i].front()) {
                        mirr[2][j][i] = now * 2;
                        lnstk[i].pop();
                    }
                    else mirr[2][j][i] = now;
                }
                else mirr[2][j][i] = now;
            }
            else {
                mirr[2][j][i] = 0;
            }
        }
    }


}

void right(int lv) { //���������� �ҰŴϱ� ��ĥ ���� �����ʺ��� ��ġ�� �� Ȯ��
    queue<int>lnstk[20];
    int maxtmp = 0;
    //�����ʺ��� 0�� �ƴ� �͵��� ť�� ��´�.
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= 0; j--) {
            if (map[lv - 1][i][j] != 0) {
                lnstk[i].push(map[lv - 1][i][j]);
            }
        }
    }
    //�ӽ� �ʿ��ٰ� ������
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= 0; j--) {


            if (!lnstk[i].empty()) {
                int now = lnstk[i].front();
                lnstk[i].pop();
                if (!lnstk[i].empty()) {
                    if (now == lnstk[i].front()) {
                        mirr[3][i][j] = now * 2;
                        lnstk[i].pop();
                    }
                    else mirr[3][i][j] = now;
                }
                else mirr[3][i][j] = now;
            }
            else {
                mirr[3][i][j] = 0;
            }
        }
    }

}


void board(int lv) {
    if (lv == 6) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (maxblock < map[lv - 1][i][j]) {
                    maxblock = map[lv - 1][i][j];
                }
            }
        }
        return;
    }

    //���� �ø���
    top(lv);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[lv][i][j] = mirr[0][i][j];
        }
    }
    board(lv + 1);




    //�������� �ֱ�
    left(lv);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[lv][i][j] = mirr[1][i][j];
        }
    }
    board(lv + 1);



    //�Ʒ������� ����
    bottom(lv);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[lv][i][j] = mirr[2][i][j];
        }
    }
    board(lv + 1);

    //���������� ����
    right(lv);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[lv][i][j] = mirr[3][i][j];
        }
    }
    board(lv + 1);

}

int main() {

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[0][i][j];
        }
    }

    board(1);

    cout << maxblock;

    return 0;
}
