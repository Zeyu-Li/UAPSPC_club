#include <iostream>
#include <cmath>
using namespace std;
int main(){
    float e = 10e-6;
    float a,b,c;
    cin >> a >> b >> c;
    float res1 = c*log(b);
    float res2 = log(b) + log(c);
    if (abs(res1-res2) > e){
        cout << "Oh look, a squirrel!" << endl;
    }else{
        cout << "What an excellent example!" << endl;
    }
}