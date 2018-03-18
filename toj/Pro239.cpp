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
#include <iostream>
#include <algorithm>
using namespace std;
int pre[1000001];
int Answer(int N,int P,int *H,int *L,int *R,int *V) {
    for ( int i=0; i<P; ++i ) {
    	pre[L[i]] += V[i];
    	pre[R[i]+1] -= V[i];
	}
	for ( int i=1; i<=N; ++i )
		pre[i] += pre[i-1];
	for ( int i=0; i<N; ++i )
		H[i] += pre[i+1];
	return *max_element(H,H+N)-*min_element(H,H+N);
}

