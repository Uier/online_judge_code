//
//  main.cpp
//  Yu_1041029-2
//
//  Created by Student on 2015/10/29.
//  Copyright (c) 2015年 Student. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[])
{
    int tos[30],dl=0;
    for (int i=0;i<30;i++)
    {
        cin >> tos[i];
    }
    for (int j=0;j<28;j++)
    {
        if ( (j < 18) && (tos[j] == tos[j+6]) && (tos[j+6] == tos[j+12]) )
        {
            dl = 1;
        }
        else if ( (tos[j] == tos[j+1]) && (tos[j] == tos[j+2]) && (j != 4) && (j != 5) && (((j-4)%6) != 0) && (((j-5)%6) != 0) )
        {
            dl = 1;
        }
    }
    if ( dl == 1 )
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
