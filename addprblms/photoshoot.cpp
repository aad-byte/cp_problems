#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, input;
    string cows;
    vector<int> data;

    cin >> N >> cows;
    int benifit = 0;
    for(int i = 0 ; i < N; i++){
        if(i % 2 == 0){//odd position
            if(cows[i] == 'G'){
                benifit--;
                data.push_back(0);
            }
        }else{
            if(cows[i] == 'G'){
                benifit++;
                data.push_back(benifit);
            }
        }
    }
}