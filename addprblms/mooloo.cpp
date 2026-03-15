#include<iostream>
#include<vector>
using namespace std;

int main(){
    long long N, K;

    cin >> N >> K;

    vector<long long> days;
    long long total = K;
    long long input;
    for(long long i = 0; i < N; i++){
        cin >> input;
        days.push_back(input);
        if(i == 0){
            total+=1;
        }else{
            if(days[i] - days[i-1] <= K){
                total += days[i]-days[i-1];
            }else{
                total += K+1;
            }
        }
    }

    cout << total;
}