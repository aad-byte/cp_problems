#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int N, x;
    cin >> N;
    cin >> x;
    vector<pair<int, int>> values(N);
    int input;
    
    for(int i =0; i < N; i++){
        cin >> input;
        values[i].first = input;
        values[i].second = i;
    }
    
    sort(values.begin(), values.end());
    int a1 = 0;
    int a2 = N-1;
    int sum;
    bool found = false;
    while(a2 > a1 && !found){
        if(values[a1].first + values[a2].first > x){
            a2--;
        }else if (values[a1].first + values[a2].first < x){
            a1++;
        }else{
            cout << values[a1].second + 1 << " " << values[a2].second + 1;
            found = true;
        }
    }

    if(!found){
        cout << "IMPOSSIBLE";
    }
    
}