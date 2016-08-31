#include<iostream> 
#include<cmath> 
using namespace std; 
double f(double a,double b,double c,double d) 
{ 
    double x=(b*c/(6*a*a))-(b*b*b/(27*a*a*a))-(d/(2*a)); 
    double y=(c/(3*a))-(b*b/(9*a*a)); 
    return -(b/(3*a))+cbrt(x+sqrt(x*x+y*y*y))+cbrt(x-sqrt(x*x+y*y*y)); 
}   
int main() 
{ 
    int n; 
    double a,b,c,d; 
    scanf("%d", &n); 
    while ( n-- ) { 
        scanf("%lf %lf %lf %lf", &a ,&b ,&c ,&d); 
        printf("%.3lf\n", f(a,b,c,d)); 
    } 
    return 0; 
}
