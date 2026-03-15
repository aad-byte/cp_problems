#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    
    int n, input;
    cin >> n;
    vector<int> cows, sorted;

    for(int i = 0; i < n; i++){
        cin >> input;
        cows.push_back(input);
        sorted.push_back(input);
    }

    sort(sorted.begin(), sorted.end());

    int total = 0;
    for(int i = 0; i < n; i++){
        if(cows[i] != sorted[i]){
            total++;
        }
    }

    if(total != 0){
        total--;
    }

    cout << total;
}