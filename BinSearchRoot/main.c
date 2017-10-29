#include <stdio.h>
double eps = 1e-9;
double x;

double func( double p)
{
    return p * p * p - x;
}

double root()
{
    double l = - 1000000.0;
    double r = 1000000.0;
    double m;
    while ( (r - l) > eps ){
        m = (l + r) / 2;
        if ( func(m) > 0){
            r = m;
        } else {
            l = m;
        }
    }
    return m;
}

int main() {
    scanf("%lf",&x);
    double res = root();
    printf("%.8lf\n",res);
    return 0;
}