#include<iostream>
using namespace std;
int ptr = 1,Prime[500] = {0}, Prime_time[500] = {0}; //168+1
void Prime_factor(int n)
{
    for(unsigned int i = 2;i <= n;i++)
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
    int in;      //儲存輸入
    cin >> in;
    if(in == 1)
        cout << "0" << endl;
    else
    {
        Prime_factor(in);
        for(int i = 1;i < ptr;i++)
        {
            cout << Prime[i] << " " << Prime_time[i] << endl;
        }
    }
    return 0;
}
