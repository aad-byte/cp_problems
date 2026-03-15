#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> cows;
    int input;
    for(int i = 0; i < N; i++){
        cin >> input;
        cows.push_back(input);
    }

    sort(cows.begin(), cows.end());
    int balls = 0;
    bool direc = true;
    bool prev =  true;
    int right = 0;
    int left = 0;
    for(int i =0 ; i < N; i++){
        if( i == 0){
            prev = true;
            right++;
        }else if (i == (N-1)){
        
        }else{
            if(cows[i] - cows[i-1] <= cows[i+1] - cows[i]){
                direc = false;
            }else{
                direc = true;
            }

            if(direc == prev{
                
            }
        }


    }
}