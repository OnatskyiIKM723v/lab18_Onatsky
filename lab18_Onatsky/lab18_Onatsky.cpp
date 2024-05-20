#include <iostream>
using namespace std;

class Matrix 
{
private:
    int matrix[2][8];

public:

    Matrix(int data[][8]) 
    {
        for (int i = 0; i < 2; i++) 
        {
            for (int j = 0; j < 8; j++) 
            {
                matrix[i][j] = data[i][j];
            }
        }
    }

    // ���������
    Matrix operator+(const Matrix& other) 
    {
        int result[2][8];
        for (int i = 0; i < 2; i++) 
        {
            for (int j = 0; j < 8; j++) 
            {
                result[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        return Matrix(result);
    }

    // ��������
    Matrix operator*(const Matrix& other) 
    {
        int result[2][8];
        for (int i = 0; i < 2; i++) 
        {
            for (int j = 0; j < 8; j++) 
            {
                result[i][j] = 0;
                for (int k = 0; k < 8; k++) 
                {
                    result[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }
        return Matrix(result);
    }

    // ���������
    bool operator==(const Matrix& other) const 
    {
        for (int i = 0; i < 2; i++) 
        {
            for (int j = 0; j < 8; j++) 
            {
                if (matrix[i][j] != other.matrix[i][j]) 
                {
                    return false;
                }
            }
        }
        return true;
    }

    // ���������� �������
    void print() 
    {
        for (int i = 0; i < 2; i++) 
        {
            for (int j = 0; j < 8; j++) 
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() 
{
    setlocale(LC_CTYPE, "ukr"); // ��������� ������������ ��������� ����

    // ��� ��� ����� �������
    int data1[2][8] = { {1, 2, 3, 4, 5, 6, 7, 8}, {9, 10, 11, 12, 13, 14, 15, 16} };
    Matrix matrix1(data1);

    // ��� ��� ����� �������
    int data2[2][8] = { {8, 7, 6, 5, 4, 3, 2, 1}, {16, 15, 14, 13, 12, 11, 10, 9,} };
    Matrix matrix2(data2);

    //���������
    Matrix resultMatrix = matrix1 + matrix2;
    cout << "���� �������:" << endl;
    resultMatrix.print();

    // ��������
    resultMatrix = matrix1 * matrix2;
    cout << "\n������� �������:" << endl;
    resultMatrix.print();
    
    // ���������
    if (matrix1 == matrix2) 
    {
        cout << "\n������� ���" << endl;
    }
    else 
    {
        cout << "\n������� �� ���" << endl;
    }

    return 0;
}
