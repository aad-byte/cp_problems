#include<iostream>
#include<cmath>

using namespace std;

int main(){
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    
    int x, y;
    cin >> x >> y;

    bool found = false;
    int steps = 0;

    if(x == y){
        cout << 0;
        return 0;
    }

    for(int i =0; !found; i++){
        if(x > y){
            if(x + pow(-2, i) <= y){
                found = true;
            }
        }else if(x < y){
            if(x + pow(-2, i) >= y){
                found = true;
            }
        }

        if(found){
            steps = i;
        }

    }

    int ans = 2*(pow(2, (steps)) -1) + abs(x-y);
    cout << ans;
}