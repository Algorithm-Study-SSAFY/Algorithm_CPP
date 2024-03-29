/*
    방법
    1. 모든 가능한 사각형 을 저장한다
    2. 탐색 하며 1인 경우 가능한 색종이를 모두 dfs로 탐색한다.
    2.1 탐색한 색종이는 0으로 처리한다 (cover함수)
    2.2 만약 모든 1을 0으로 만들었다면 (numblock = 0) 리턴한다.
    2.3 리턴하면서 탐색한 색종이를 다시 1로 만든다(discover)


    테스트케이스만 맞고 22% 틀렸다고 나옴
*/

#include <iostream>
#include <vector>

using namespace std;

int paper[10][10];
//prefix_sum
int ps[11][11];
int sizep[10][10];
int use_paper[6];
int numblock = 0;
int numPaper = 0;
int result = 101;

void cover(int i, int j, int k) {
    for (int y = i; y <= i + k; y++) {
        for (int x = j; x <= j + k; x++) {
            paper[y][x] = 0;
        }
    }
}

void discover(int i, int j, int k) {
    for (int y = i; y <= i + k; y++) {
        for (int x = j; x <= j + k; x++) {
            paper[y][x] = 1;
        }
    }
}

int valid(int y, int x)
{
    for(int k = 0; k < 5; k++) {
        for(int i = 0; i <= k; i++) {
            if(!paper[y + i][x + k]) return k;
        }
        for(int j = 0; j < k; j++) {
            if(!paper[y + k][x + j]) return k;
        }
    }
    return 5;
}

void dfs(int y, int x) {

    while(paper[y][x] == 0) {
        if(x == 9) {
            y++;
            x = 0;
        }
        else x++;
        if(y >= 10) return;
    }

    numPaper++;
    if (numPaper >= result) {
        numPaper--;
        return;
    }

    //사용할 수 있는 색종이 사용
    //어떤 색종이를 사용할 것인지 
    int sizep = valid(y, x);
    // cout << sizep << " ";
    for (int k = sizep - 1; k >= 0; k--) {

        //커버된는 부분을 0으로 바꿈
        if(use_paper[k] == 5) continue;
        use_paper[k]++;
        cover(y, x, k);
        numblock -= ((k + 1) * (k + 1));
        if(numblock == 0) {
            result = min(result, numPaper);
        }
        else {
            //다음 색종이 사용 부분 찾기 
            dfs(y, x + k);
        }

        //커버된는 부분을 1으로 바꿈
        use_paper[k]--;
        numblock += ((k + 1) * (k + 1));
        discover(y, x, k);
    }

    numPaper--;
}



int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> paper[i][j];
            if (paper[i][j]) numblock++;
        }
    }
    if (numblock == 0) {
        cout << "0\n";
        return 0;
    }

    dfs(0, 0);

    if (result == 101) result = -1;
    cout << result;
}

