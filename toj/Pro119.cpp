#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
 
int main () {
       
        int n;
        cin >> n;
        int x[n],t,sum=0;
       
        for (int i=0 ; i<n ; i++){
                cin >> x[i];
        }
       
        cin >> t;
        int a[t],b[t];
       
        for (int i=0 ; i< t ; i++){
                cin >> a[i] >> b[i];
        }
       
        for (int i=0 ; i< t ; i++){
                if ( abs(a[i]-b[i])-1 < 7 ){
                        swap(x[a[i]-1],x[b[i]-1]);
                }
                else if ( abs(a[i]-b[i])-1 >= 7 ){
                        sum=1;
                        break;
                }
        }
       
        if (sum==0){
                cout<<"SORTED!\n";
        }
        else {
                cout<<"I QUIT!\n";
        }
        for (int i=0 ; i<n ; i++){
                cout << x[i];
                if (i<n-1){
                        cout << " ";
                }
        }
        cout << "\n";
	return 0;
}
