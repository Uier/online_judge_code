#include<iostream>
using namespace std;
int main()
{
	string s;
	while(getline(cin, s))
	{
		for(int i = 0;i < s.length();i++)
		{
			if(s[i] >= 'A' && s[i] <= 'Z')
			{
				s[i] = s[i] - 'A';
				s[i] = 26 - s[i];
				s[i] = s[i] + 'A' - 1; 
			}
			if(s[i] >= 'a' && s[i] <= 'z')
			{
				s[i] = s[i] - 'a' ;
				s[i] = 26 - s[i];
				s[i] = s[i] + 'a' - 1; 
			}
			cout << s[i];
		}
	}
	
	return 0;
}

