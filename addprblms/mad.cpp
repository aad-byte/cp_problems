#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    string blah1, blah2;
    int N;
    cin >> N >> blah1 >> blah2;

    int total = 0;
    bool match = true;
    for(int i = 0; i < N; i++){
        if(blah1[i] != blah2[i]){
            match = false;
        }else{
            if(match == false){
                match = true;
                total++;
            }
        }
    }

    cout << total;
}