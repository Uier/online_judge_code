#include<iostream>
using namespace std;
long long ptr = 1,Prime[500] = {0}, Prime_time[500] = {0}; //168+1
void Prime_factor(long long n)
{
    for(unsigned long long i = 2;i <= n;i++)
    {
        while(n % i == 0)
        {
            Prime[ptr] = i;
            ptr++;
            if(Prime[ptr - 1] == Prime[ptr - 2])
                ptr--;
            Prime_time[ptr - 1]++;
            n = n / i;
        }
    }
}

int main()
{
    long long in;      //å„²å­˜è¼¸å…¥
    cin >> in;
    if(in == 1)
        cout << "0" << endl;
    else
    {
        Prime_factor(in);
        for(int i = 1;i < ptr;i++)
        {
            cout << Prime[i] << "ªº" << Prime_time[i] << "¦¸¤è" << endl;
        }
    }
    return 0;
}
