#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    int N, input;
    
    cin >> N;
    vector<int> log1;

    for(int i = 0; i < N; i++){
        cin >> input;
        log1.push_back(input);
    }

    
    //DUPLICATE vector into two more vectors
    vector<int> log, log2;
    for(int i = 0; i < N; i ++){
        log.push_back(log1[i]);
        log2.push_back(log1[i]);
    }

    //check if this log is valid or not
    
    for(int i = 0; i < N; i++){
        if(log2[i] > i){
            //print -1 and stop code
            cout << -1;
            return 0;
        }

        
    //fill log2 with all the numbers that need to placed predescely for wach log entry
        if(log2[i] != -1){
            int loop = log2[i];
            for(int j = 1; j <= loop; j++){
                log2[i-j] = loop -j;
            }
        }
    }
    
    //if there is overlap between numbers, (e.g. data is not consistent), then its not possible to fill it up 
    for(int i = 0; i < N; i++){
        if(log1[i] != -1){
            if(log1[i] != log2[i]){
                cout << -1;
            return 0;
            }
        }
    }
    bool all = true;
    for(int i = 0; i< N; i++){
        if(log[i] != -1){
            log[i - log[i]] = 0;
        }
    }
    //manually set the first day to have a breakout
    log[0] = 0;

    int minimum = count(log.begin(), log.end(), 0);

    int counter2 = 0;
    int total = 0;
    for(int i = 0; i  < N; i++){
        if(log[i] == -1){
            counter2++;
        }else{
            if(log[i] > 0){
                counter2 = 0;
            }else{
                total += counter2;
                counter2 = 0;
            }
        }

        if(i == (N-1)){//-1 is the last num, we can still count it to be a breakout 
            total += counter2;
        }
    }

    for(int i =0 ; i < N; i++){
        if(log1[i] != 0){

        }
    }

    int maximum  = minimum + total;

    cout << minimum << " " << maximum;
}