#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int N;
    cin >> N;

    string order;
    cin >> order;
    int reversals = 0;
    
    for(int i = N-2; i >= 0; i-= 2){
        if(order.substr(i, 2) == "GH"){
            if(reversals %2 == 0){
                reversals++;
            }
        }else if(order.substr(i, 2) == "HG"){
            if(reversals %2 == 1){
                reversals++;
            }
        }
    }
    cout << reversals;
}