#include <iostream>
using namespace std;

int main(){
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    
    int l1, l2, l3, l4;
    int f1, f2, f3, f4;

    cin >> l1 >> l2 >> l3 >> l4 >> f1 >> f2 >> f3 >> f4;

    int total = (l4-l2) * (l3-l1);
    //cout << "value of total: \n" << total;
    if((l3 <= f1 || f3 <= l1) || (l4 <= f2 || f4 <= l2)){//no overlap between boards
        //cout << "\ngla1";
    }else{
        //determine dimensions of tarp
        //cout << "\ngla2";
        int overlap = 0;
        int m1 , m2;

        //determine height (x coordinates)

        if(f1 <= l1 && f3 >= l3){
            //heigth can be the difference of the given y coordinates
            //cout << "\ngla3";
            if(f4 <= l4){
                m2 = f4;
               // cout << "\ngla4";
            }else{
                m2 = l4;
                //cout << "\ngla5";
            }

            if(f2 >= l2){
                m1 = f2;
                //cout << "\ngla6";
            }else{
                m1 = l2;
                //cout << "\ngla7";
            }
            
            //calculate overlap
            overlap += (l3-l1) * (m2-m1); // remainign 

            total -= overlap;
        }else if(f2 <= l2 && f4 >= l4){
            //width is the given x coordinates minus this
            //cout << "\ngla8";
              
            if(f3 <= l3){
                m2 = f3;
                //cout << "\ngla9";
            }else{
                m2 = l3;
                //cout << "\ngla10";
            }

            if(f1 >= l1){
                m1 = f1;
                //cout << "\ngla11";
            }else{
                m1 = l1;
            }
            
            //calculate overlap
            overlap += (l4-l2) * (m2-m1); // remainign 

            total -= overlap;
        }else{
        }
    }

    cout << total; 
}