#ifndef EVAL
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int Answer(int N,int P,int *H,int *L,int *R,int *V);

int main()
{
	const int maxN = 1000000;
	const int maxP = 1000000;
	int *H = new int[maxN];
	int *L = new int[maxP];
	int *R = new int[maxP];
	int *V = new int[maxP];
	int N,P;
	while( cin>>N>>P )
	{
		for(int i=0;i<N;++i)
			scanf("%d", &H[i]);
		for(int i=0;i<P;++i)
			scanf("%d %d %d", &L[i], &R[i], &V[i]);
		printf("%d\n",Answer(N,P,H,L,R,V));
	}
}
#endif
/*================================================================*/
/*================================================================*/
/*================================================================*/
/*================================================================*/
/*Write Your Program Here*/
/*Notice: You should include header for youself*/
#include<iostream>
using namespace std;
int Answer(int N,int P,int *H,int *L,int *R,int *V)
{
	for ( int i=0; i<P; i++ )
	{
		for ( int j=L[i]-1; j<R[i]; j++ )
			H[j] += V[i];
	}
	int mn=H[0], mx=H[0];
	for ( int i=1; i<N; i++ )
	{
		if ( H[i] > mx )
			mx = H[i];
		if ( H[i] < mn )
			mn = H[i];
	}
	return mx-mn;
}
