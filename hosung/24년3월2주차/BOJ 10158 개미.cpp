#include <iostream>


using namespace std;

/*
* �ð� ������ 0.15���̹Ƿ� ������ �������� �ھƾ��Ѵٰ� �����ߴ�
* ������ ������ ���,����,�»�,���� 4�����̴�.
* ������ ��ġ�κ��� ���ο� ���� �� �� ���� �����ϴ� ���� ã��
* �� ���̸�ŭ �ð��� ������ �ε����� ���� ���̰� ��ġ�ϵ��� �Ͽ���
* �� �� ���̸�ŭ �ð��� ������ �� 
* ������ ���ѽð��� ������ ���� �ð���ŭ ���⿡ �°� �̵��ϵ����Ͽ���
*/

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int w, h, antx, anty, t;
    int dim = 0; //���:0, �»�:1, ����:2, ����:3
    cin >> w >> h >> antx >> anty >> t;

    int tmp = 0;

    while (1) {
        if (dim == 0) { //���
            int distx = w - antx;
            int disty = h - anty;

            if (distx <= disty) {
                //�ð� �߰��� Ȯ��
                if (tmp+distx > t) {
                    //��ǥ �̵�
                    antx += (t - tmp);
                    anty += (t - tmp);
                    tmp= t;
                }
                else {
                    //��ǥ �̵�
                    antx += distx;
                    anty += distx;
                    tmp += distx;
                }
                
                if (distx == disty) dim = 2; //����
                else dim = 1; //�»�
            }
            else{
                //�ð����� Ȯ��
                if (tmp + disty > t) {
                    antx += (t - tmp);
                    anty += (t - tmp);
                    tmp = t;
                }
                else {
                    //��ǥ�̵�
                    antx += disty;
                    anty += disty;

                    tmp += disty;
                }

                dim = 3;
            }
        }
        else if (dim == 1) { //�»�
            int distx = antx;
            int disty = h - anty;

            if (distx <= disty) {
                if (tmp + distx > t) {
                    antx -= (t - tmp);
                    anty += (t - tmp);

                    tmp = t;
                }
                else {
                    //�ð�����
                    tmp += distx;
                    //��ǥ�̵�
                    antx -= distx;
                    anty += distx;
                }
               
                if (distx == disty) dim = 3;//����
                else dim = 0;
            }
            else {
                if (tmp + disty > t) {
                    antx -= (t - tmp);
                    anty += (t - tmp);
                    
                    tmp = t;
                }
                else {
                    //��ǥ�̵�
                    antx -= disty;
                    anty += disty;

                    //�ð� ����
                    tmp += disty;
                }
                dim = 2;
            }
        }
        else if (dim == 2) { //����
            int distx = antx;
            int disty = anty;

            if (distx <= disty) {
                if (tmp + distx > t) {
                    antx -= (t - tmp);
                    anty -= (t - tmp);

                    tmp = t;
                }
                else {
                    //�ð�����
                    tmp += distx;
                    //��ǥ�̵�
                    antx -= distx;
                    anty -= distx;
                }
                
                if (distx == disty) dim = 0;
                else dim = 3;
            }
            else{
                if (tmp + disty > t) {
                    antx -= (t - tmp);
                    anty -= (t - tmp);
                    tmp = t;
                }
                else {
                    //�ð� ����
                    tmp += disty;
                    //��ǥ�̵�
                    antx -= disty;
                    anty -= disty;
                }

                dim = 1;
            }
        }
        else if (dim == 3) {//����
            int distx = w - antx;
            int disty = anty;

            if (distx <= disty) {
                if (tmp + distx > t) {
                    antx += (t - tmp);
                    anty -= (t - tmp);

                    tmp = t;
                }
                else {
                    //��ǥ�̵�
                    antx += distx;
                    anty -= distx;
                    //�ð�����
                    tmp += distx;
                }
                
                if (distx == disty) dim = 1;
                else dim = 2;
            }
            else if (distx > disty) {
                if (tmp + disty > t) {
                    antx += (t - tmp);
                    anty -= (t - tmp);
                    tmp = t;
                }
                else {
                    //��ǥ�̵�
                    antx += disty;
                    anty -= disty;

                    //�ð�����
                    tmp += disty;
                }
                
                dim = 0;
            }
        }
        
        if (tmp == t) break;
    }

    cout << antx << " " << anty;

    return 0;
}



