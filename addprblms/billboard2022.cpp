#include<iostream>
#include<vector>
using namespace std;

//assumes overlap (doesnt account for not overlaping rectangles)
vector<int> overlap(int a1, int a2, int a3, int a4, int b1, int b2, int b3, int b4){
    int w1, w2, h1, h2;

    if(b1 >= a1){
        w1 = b1;
    }else{
        w1 = a1;
    }

    if(b3 <= a3){
        w2 = b3;
    }else{
        w2 = a3;
    }

    if(b2 >= a2){
        h1 = b2;
    }else{
        h1 = a2;
    }

    if(b4 <= a4){
        h2 = b4;
    }else{
        h2 = a4;
    }

    vector<int> blah;
    blah.push_back(w1);
    blah.push_back(h1);
    blah.push_back(w2);
    blah.push_back(h2);
    return blah;
}
int main(){
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    int l1, l2, l3, l4;
    int f1, f2, f3, f4;

    cin >> l1 >> l2 >> l3 >> l4 >> f1 >> f2 >> f3 >> f4;

    int tarp = (l4-l2) * (l3 - l1);
    //if overlap
    if(!(((l3 <= f1) || (f3 <= l1)) || ((l4 <= f2)) || (f4 <= l2))){
        vector<int> coordinates = overlap(l1, l2, l3, l4, f1, f2, f3, f4);

        if(((coordinates[0] == l1 && coordinates[2] == l3) && (((coordinates[1] == l2 || coordinates[1] == l4)) || ((coordinates[3] == l2 || coordinates[3] == l4))) )|| ((coordinates[1] == l2 && coordinates[3] == l4) && (((coordinates[0] == l1 || coordinates[0] == l3)) || ((coordinates[2] == l1 || coordinates[2] == l3))))){ 
            tarp -= (coordinates[2] - coordinates[0]) * (coordinates[3] - coordinates[1]);
        }
    }
  

    cout << tarp;

}