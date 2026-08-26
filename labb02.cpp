#include <bits/stdc++.h>
using namespace std;
class Matrix
{
    static int cnt;
    int r, c;
    int **M;
public:
    Matrix()
    {
        int a,b;
        cin>>a>>b;
        r=a;
        c=b;
        M = new int *[r];
        for (int i = 0; i < r; i++)
        {
            M[i] = new int[c];
            for (int j = 0; j < c; j++)
            {
            cin>>M[i][j];
            }
        }
        cnt++;
        cout << "matrix created" << cnt << endl;
    }
    Matrix(const Matrix &m)
    {
        r = m.r;
        c = m.c;
        M = new int *[r];
        for (int i = 0; i < r; i++)
        {
            M[i] = new int[c];
            for (int j = 0; j < c; j++)
            {
                M[i][j]=m.M[i][j];
            }
            cout<<endl;
        }
        cnt++;
        cout << "matrix created" << cnt << endl;
    }
    ~Matrix()
    {
        for (int i = 0; i < r; i++)
            delete[] M[i];
        delete[] M;

        cnt--;
        cout << "Matrix destroyed. Active matrices: " << cnt << endl;
    }
    void setValue(int i, int j, int val)
    {
        if (i >= 0 && i < r && j >= 0 && j < c)
            M[i][j] = val;
    }
    void display()
    {
        cout << "Matrix (" << r << "x" << c << "):\n";
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                cout << M[i][j] << " ";
            cout << endl;
        }
    }
};
int Matrix::cnt = 0;
int main()
{
    Matrix m1;
    m1.display();
    Matrix m2 = m1; // calls copy constructor
    m2.display();
    return 0;
}