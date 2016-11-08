#include <iostream>
using namespace std;
char mp[10][10];
int get_step(int row,int x,int y){
	int add=row==0?-1:1,res=0;
	while(x!=row){
		x+=add;
		res++;
		if(mp[x][y]!='.') return 0x3f3f3f3f;
	}
	return res;
}
int main() {
	for(int i=0;i<8;i++)
		scanf("%s",mp[i]);
	int min_a=0x3f3f3f3f,min_b=0x3f3f3f3f;
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++){
			if(mp[i][j]=='W')
				min_a=min(min_a,get_step(0,i,j));
			else if(mp[i][j]=='B')
				min_b=min(min_b,get_step(7,i,j));
		}
	if(min_a<=min_b) puts("A");
	else puts("B");
	return 0;
}
