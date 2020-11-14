#include <bits/stdc++.h>
#define PI M_PI
using namespace std;

int main(){
    double D, V;
    while(cin >> D >> V){
        if(!D && !V)
            break;
        double left = 0, right = D, d;
        while(right - left> 1.0e-5){
            d = (left+right) / 2;
            if(PI*D*D*D - PI*d*d*d > 6.0*V){
                left = d;
            }else{
                right = d;
            }
        }
        printf("%.3f\n", d);
    }
}