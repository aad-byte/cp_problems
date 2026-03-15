#include<iostream>
using namespace std;

int main(){
    int a1, a2, a3, a4;
    int b1, b2, b3, b4;

    cin >> a1 >> a2 >> a3 >> a4;
    cin >> b1 >> b2 >> b3 >> b4;

    int total = (a3-a1)*(a4-a2);

    if(a3 <= b1 || b3 <= a1){

    }else if(a4 <= b2 || b4 <= a2){

    }else{
        int w1, w2, l1, l2;

        if(b1 < a1){
            w1 = a1;
        }else{
            w1 = b1;
        }

        if(b3 > a3){
            w2 = a3;
        }else{
            w2 = b3;
        }

        if(b2 < a2){
            l1 = a2;
        }else{
            l1 = b2;
        }

        if(b4 > a4){
            l2 = a4;
        }else{
            l2 = b4;
        }

        total -= ((w2-w1)*(l2-l1));

    }
        
    cout << total;
}