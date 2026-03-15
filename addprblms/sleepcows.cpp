#include <iostream>
#include <vector>

using namespace std;

int main(){
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    int N, input;
    cin >> N;
    vector<int> cows;

    for(int i = 0; i < N; i ++){
        cin >> input;
        cows.push_back(input);
    }

    int prev = cows[N-1];
    for(int i = N-2; i >= 0; i--){
        if(cows[i] > prev){
            cout << (i+1);
            return 0;
        }
        prev = cows[i];
    }

    cout << 0; 


}