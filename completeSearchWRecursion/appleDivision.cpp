#include <iostream>
#include <vector>
using namespace std;
vector<int> apples;

long long apple_set(int index, int max, long long sum1, long long sum2){
    if(index == max){
        return abs(sum1 - sum2); //once all apple have been organized in a group
    }

    return min((apple_set(index+1, max, sum1 + apples[index], sum2)), apple_set(index+1, max, sum1, sum2+ apples[index]));
}
///Hahaha

int main(){
    int n;
    cin >> n;

    long long input;
    for(int i = 0; i < n; i++){
        cin >> input;
        apples.push_back(input);
    }

    cout<< apple_set(0, n, 0, 0);
}