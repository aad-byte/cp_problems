#include <iostream>
#include <vector>
using namespace std;

int main(){
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    int a1, a2, a3, a4;
    int b1, b2, b3, b4;
    int t1, t2, t3, t4;
    int w1, w2, l1, l2;

    cin >> a1 >> a2 >> a3 >> a4;
    cin >> b1 >> b2 >> b3 >> b4;
    cin >> t1 >> t2 >> t3 >> t4;

    int total = ((a3 - a1) * (a4 - a2)) + ((b3 - b1) * (b4 - b2));
    //for billboard a
    //check if truck y range is within a's y range
    if( (t4 <= a2 || a4 <= t2)){ //truck not within range of bill board
    }else if((t3 <= a1) || (a3 <= t1)){// if y is in range but x is out of range
    }else{// if both x an dy in rnage, then the truck is corveing some part of the bill board
        //calculate width of covering based on x coordinates of the billboard and truck 

        if(t1 < a1){
            w1 = a1;
        }else{
            w1 = t1;
        }
        if(t3 > a3){
            w2 = a3;
        }else{
            w2 = t3;
        }

        if(t2 < a2){
            l1 = a2;
        }else{
            l1 = t2;
        }
        if(t4 > a4){
            l2 = a4;
        }else{
            l2 = t4;
        }

        total -= (w2-w1)*(l2-l1);
    }
     // DO THE SAME FOR B

     if( (t4 <= b2 || b4 <= t2)){ //truck not within rbnge of bill bobrd
    }else if((t3 <= b1) || (b3 <= t1)){// if y is in rbnge but x is out of rbnge
    }else{// if both x bn dy in rnbge, then the truck is corveing some pbrt of the bill bobrd

        //cblculbte width of covering bbsed on x coordinbtes of the billbobrd bnd truck 

        if(t1 < b1){
            w1 = b1;
        }else{
            w1 = t1;
        }
        if(t3 > b3){
            w2 = b3;
        }else{
            w2 = t3;
        }

        if(t2 < b2){
            l1 = b2;
        }else{
            l1 = t2;
        }
        if(t4 > b4){
            l2 = b4;
        }else{
            l2 = t4;
        }

        total -= (w2-w1)*(l2-l1);
    }

    cout  << total;
}