#include <iostream>
#include "windows.h"
using namespace std;


bool fib(unsigned int value) {
    if (value < 2) {
        return true;
    }
    else {
        int f1 = 0;
        int f2 = 1;
        while (f2 < value) {
            f2 += f1;
            f1 = f2 - f1;
            if (f2 == value) return true;
        }
        return false;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int rows = 5;
    const int cols = 6;
    int a[rows][cols];

    //���������� �������� �������� ������
    srand(time(NULL));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            a[i][j] = rand() % 10;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    //���� ��������, �� ������ �� ������ ������
    int sum1 = 0;
    for (int i = 0; i < rows; i++)
        if ((i + 1) % 2 == 0)
            for (int j = 0; j < cols; j++)
                sum1 += a[i][j];
    cout << "���� ��������, �� ������ �� ������ ������: " << sum1 << endl;

    //���� ��������, �� ������ ����� �� ������ ������
    int sum2 = 0;
    cout << "��������, �� ������ ����� �� ������ ������: ";
    for (int i = 0; i < rows; i++) {
        if ((i + 1) % 2 == 0) {
            for (int j = 0; j < cols; j++) {
                bool isUnique = true;
                for (int k = 0; k < rows; k++) {
                    if ((k + 1) % 2 == 1) {
                        for (int n = 0; n < cols; n++) {
                            isUnique = isUnique && (a[i][j] != a[k][n]);
                            if (!isUnique) break;
                        }
                        if (!isUnique) break;
                    }
                }
                if (isUnique) {
                    sum2 += a[i][j];
                    cout << a[i][j] << " ";
                }
            }
        }
    }
    cout << endl << "���� ��������, �� ������ ����� �� ������ ������: " << sum2 << endl;

    if (fib(sum1)) {
        cout << sum1 << " � ������ Գ������" << endl;
    }
    else {
        cout << sum1 << " �� � ������ Գ������" << endl;
    }

    if (fib(sum2)) {
        cout << sum2 << " � ������ Գ������" << endl;
    }
    else {
        cout << sum2 << " �� � ������ Գ������" << endl;
    }

    //�������� ����������� �����, �� ���������� � ������������ ������� �������� ������� �������.
    int arrayOfMax[cols];

    for (int j = 0; j < cols; j++) {
        int max = a[0][j];
        for (int i = 1; i < rows; i++) {
            if (a[i][j] > max) max = a[i][j];
        }
        arrayOfMax[j] = max;
    }

    cout << "�����, �� ���������� � ������������ ������� �������� ������� �������: ";
    for (int j = 0; j < cols; j++) cout << arrayOfMax[j] << " ";
    cout << endl;
}
