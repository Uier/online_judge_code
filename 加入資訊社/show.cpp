#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>
using namespace std;
int main()
{
	system("mode con:cols=31 lines=20");
	while(true)
	{
		for(int i=0;i<5;i++)
		{
			ifstream ifs("word.txt");
			string s;
			while(getline(ifs,s))
			{
				cout<<"      "; 
				if(s.size()>i*18+18) 
					s=s.substr(i*18,18);
				cout<<s<<endl;
				Sleep(5);
			}
			Sleep(1000);
			ifs.close();
		}
	}
}
