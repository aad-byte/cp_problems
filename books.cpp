#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    ll n, t;
    cin >> n >> t;

    vector<ll> books;
    ll input;
    for(ll i = 0; i < n; i++){
        cin >> input;
        books.push_back(input);
    }

    ll* left = books.data();
    ll* right = left;

    
    ll sum = books[0];
    ll counter = 0;
    if(sum <= t){
        counter++;
    }

    bool notend = true;
    while(notend){
        if(right+1 != books.data() + books.size()){
            right++;
            sum += *right; //move to next element
            while(sum > t){ //remove prev elements until new subarray is lower than or equal to target value
                sum -= *left;
                left++;
            }
            counter = max(counter, (ll)(right-left) + 1); // why is this not working?
        }else{
            notend = false;
        }
    }

    cout << counter;
    
}