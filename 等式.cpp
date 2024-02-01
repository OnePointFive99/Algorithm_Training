
#include<iostream>

using namespace std;



bool isprime(int n)
{
    if (n == 1)return false;
    for (int i = 2; i * i <= n; i++)
    {
        if ((float(n) / i)==(n / i))return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; i <= (n+1)/2; i++)
    {
        if (isprime(i) && !(isprime(n - i)))
        {
            for (int j = 1; j * j <= n-i; j++)
            {
                if ((n - i) / j == j)count++;
                else if ((float(n-i) / j)==(n - i) / j)count = count + 2;
            }
        }
    }
    cout << count << endl;
    return 0;
}