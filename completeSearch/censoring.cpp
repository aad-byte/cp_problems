#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    string input;
    cin >> input;

    string check;
    cin >> check;
    int countercheck = 0;
    vector<int> prev;

    for(int i = 0; i < input.size(); i++){
        if(input[i] == check[countercheck]){
            countercheck++;
        }else if(input[i] == check[0]){
            if(countercheck != 0){
                prev.push_back(countercheck);
            }
            countercheck = 1;
        }else{
            countercheck = 0;
        }

        if(countercheck == )
    }
}