#include<iostream>
#include"interactive.h"
using namespace std;
int main()
{
	Init();
	int boy=get_num_of_boy();
	int girl=get_num_of_girl();
	Answer(boy*girl);
	return 0;
}

