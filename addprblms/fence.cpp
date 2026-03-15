#include <iostream>
using namespace std;

int main(){
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int input1, input2, a, b, c, d;

    cin >> input1 >> input2;
    a = min(input1, input2);
    b = max(input1, input2);

    cin >> input1 >> input2;
    c = min(input1, input2);
    d = max(input1, input2);

    if( (c > b && d > b) || (c < a && d < a)){
        cout << ((b-a) + (d-c));
    }else{
        int end1, end2;
    end1 = min(a, min(b, (min(c, d))));
    end2 = max(a, max(b, (max(c, d))));

    cout << (end2 - end1);
    }

    
}