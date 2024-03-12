#include <iostream>

using namespace std;

/*
* 10X10���� �����̹Ƿ� ��Ž�Ͽ��� ���
* ũ�⸦ 5X5���� 1X1���� �ϳ��� �ٿ����� ��Ʈ��ŷ�� �����ϸ�
* ��� �ٿ����� ��� ���� ������ ����� ���� ���� ���� �����Ѵ�
*/

int map[10][10];
int visited[10][10];
int papertype[6] = { 0,5,5,5,5,5 };
int ans = 21e8;

bool chk() { // ��� ���̰� ���ٿ����� �� Ȯ��
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (map[i][j] == 1) { //���� �����ִٸ� return
                return 0;
            }
        }
    }
    return 1;
}

bool patchpaper(int x, int y, int scale) {
    for (int i = x; i < x + scale; i++) {
        for (int j = y; j < y + scale; j++) {
            if (map[i][j] == 0) //�����̷��� �� ���̰� �ƴ� �κ��� �ִٸ� ��������
                return 0;
        }
    }
    return 1;
}

void recur(int level) {
    if (chk()) {
        ans = min(ans, level);
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (map[i][j] == 1) { //������ �� �ִ� ��쿡�� ���̸� ������
                for (int s = 5; s >= 1; s--) { //������ ũ�⸦ ��� ��Ž
                    if (papertype[s] == 0) continue; //�� ������ �ѱ�
                    if (i + s - 1 >= 10 || j + s - 1 >= 10) continue; //������ ������ �ѱ�                    
                    if (patchpaper(i, j, s)) { //ũ�⿡ �°� ������ �� �ִ� �� Ȯ��
                        for (int k = i; k < i + s; k++) { //�����ϸ� �� ��ŭ �����
                            for (int p = j; p < j + s; p++) {
                                map[k][p] = 0;
                            }
                        }
                        papertype[s]--; //����� ������ ���̱�
                        recur(level + 1);
                        papertype[s]++;
                        for (int k = i; k < i + s; k++) {
                            for (int p = j; p < j + s; p++) {
                                map[k][p] = 1;
                            }
                        }
                    }
                }
                return;
            }
        }
    }
    
}

int main() {

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> map[i][j];
        }
    }

    recur(0);
    
    if (ans == 21e8) cout << -1;
    else cout << ans;

    return 0;
}


