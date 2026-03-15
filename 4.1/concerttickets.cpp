#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> price(n);

    for(auto &i: price){
        cin >> i;
    }

    sort(price.begin(), price.end());

    auto f = [&](int value){
        int lo = 0;
        int hi = price.size()-1;
        bool found = false;

        while(lo < hi && !found){
            int mid = (lo + hi)/2;
            if(price[mid] > value){
                hi = mid-1;
            }else if(price[mid] < value){
                lo = mid +1;
            }else{
                lo = mid;
                found = true;
            }
        }

        return lo;

    };
    
    int input;
    for(int i = 0; i < m; i++){
        cin >> input;

        auto it = f(input);

        if(it == price.end()){

        }else{
            int index = it - price.begin();
            cout << price[index];
            price[index] == 
        }

    }
}