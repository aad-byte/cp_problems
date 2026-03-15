#include <iostream>
using namespace std; 

int main(){
    int w1, w2, w3, w4;
    int b1, b2, b3, b4;
    int B1, B2, B3, B4;

    cin >> w1 >> w2 >> w3 >> w4;
    cin >> b1 >> b2 >> b3 >> b4;
    cin >> B1 >> B2 >> B3 >> B4;

    bool leftbtm, lefttop, rightbtm, righttop;

    //check if each corner of the white sheet lies in some part of the black sheet
    //btm left
    if(((w1 >= b1 && w1 <= b3) && (w2 >= b2 && w2 <= b4)) || ((w1 >= B1 && w1 <= B3) && (w2 >= B2 && w2 <= B4))){
        leftbtm = true;
    }else{
        cout << "YES";
        return 0;
    }

    //btm right
    if(((w3 >= b1 && w3 <= b3) && (w2 >= b2 && w2 <= b4)) || ((w3 >= B1 && w3 <= B3) && (w2 >= B2 && w2 <= B4))){
        rightbtm = true;
    }else{
        cout << "YES";
        return 0;
    }

    //top right
    if(((w3 >= b1 && w3 <= b3) && (w4 >= b2 && w4 <= b4)) || ((w3 >= B1 && w3 <= B3) && (w4 >= B2 && w4 <= B4))){
        righttop = true;
    }else{
        cout << "YES";
        return 0;
    }

    if(((w1 >= b1 && w1 <= b3) && (w4 >= b2 && w4 <= b4)) || ((w1 >= B1 && w1 <= B3) && (w4 >= B2 && w4 <= B4))){
        lefttop = true;
    }else{
        cout << "YES";
        return 0;
    }

    cout << "NO";

}