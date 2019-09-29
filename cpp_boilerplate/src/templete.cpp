#include <cstdio>
#include <cmath>

using namespace std;

int a,b,c;

int main(){
    scanf("%d%d%d",&a,&b,&c);
    long double v=(long double)sqrt((long double)c/(long double)a);

    long double f=(long double)a*v*v+(long double)b*v+(long double)c;

    printf("%.10lf\n",(double)v);
    printf("%.10lf\n",(double)(v/f));
    return 0;
}