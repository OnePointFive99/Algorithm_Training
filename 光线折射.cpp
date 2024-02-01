
#include<iostream>
using namespace std;

int main() {
    long long m, n;
    cin >> m >> n;
    if (m > n)
    {
        if (m < 2 * n)
        {
            cout << 2 * m - 2 * n << ' ' << 0 << endl;
        }
        else if (m == 2 * n)
        {
            cout << n << ' ' << n << endl;
        }
        else if (m > 2 * n && m < 3 * n)
        {
            cout << m << ' ' << m-2*n << endl;
        }
        else if (m >= 3 * n)
        {
            cout << 3 * n << ' ' << n << endl;
        }
    }
    else if(m < n)
    {
        if (n == 2 * m)
        {
            cout << m << ' ' << m << endl;
        }
        else if (n < 2 * m)
        {
            cout << 0 << ' ' << 2 * n - 2 * m << endl;
        }
        else if(n > 2 * m && n < 3 * m)
        {
            cout << n-2*m << ' ' << n << endl;
        }
        else if (n >= 3 * m)
        {
            cout << m << ' ' << 3 * m << endl;
        }
    }
    else {
        cout << m << ' ' << n << endl;
    }

    return 0;
}
