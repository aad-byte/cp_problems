#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    int even = 0;
    int odd = 0;

    int input;
    for(int i = 0; i < N; i++){
        cin >> input;
        if(input % 2 == 1){
            odd++;
        }else{
            even++;
        }
    }

    int suck = min(odd, even);
    odd -= suck;
    even -= suck;

    suck *=2;
    if(odd == 0){
        if(even!=0){
            suck++;
        }
    }else{
        suck+= (odd/3)*2;
        if(odd % 3 == 0){
        }else if(odd %3 == 2){
            suck++;
        }else if(odd %3 == 1){
            suck--;
        }
    }

    cout << suck;
}