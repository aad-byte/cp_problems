#include <iostream>
#include <map>
using namespace std;

int main(){
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);

    int N, input1, input2;
    cin >> N;

    map<int, int> cows;
    
    for(int i = 0; i < N;i ++){
        cows[i] = 0;
    }

    for(int i = 0; i < (N-1); i++){
        cin >> input1 >> input2;
        if(cows[input1 -1] != 0){
            cout << -1;
            return 0;
        }else{
            cows[input1 -1]++;
        }
    }

    for(int i = 0; i < N; i++){
        if(cows[i] == 0){
            cout << (i+1);
        }
    }
}