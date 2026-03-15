#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(){
    freopen("outofplace.in", "r", stdin);
   freopen("outofplace.out", "w", stdout);
    int input, N;
    cin >> N;
    int ans = 0;
    vector<int> cows;
    vector<int> sorted;
    for(int i = 0; i < N; i++){
        cin >> input;
        if(i == 0){
            cows.push_back(input);
            sorted.push_back(input);
        }else{
            if(input != cows[i-1]){
                cows.push_back(input);
                sorted.push_back(input);
            }
        }

        sort(sorted.begin(), sorted.end());
        
        for(int i = 0; i < cows.size(); i++){
            if(cows[i] != sorted[i]){
                ans++;
            }
        }


    }

    if(ans != 0){
        ans--;
    }
    cout << ans;
}