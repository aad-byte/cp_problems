#include<iostream>
#include<vector>
#include <string>

using namespace std; 

int main(){
    int N;
    cin >>N;

    int right = 0;
    int wrong = 0;
    int maxi = 0; int diff;
    string input;
    
    cin >> input;

    for(int i = 0;i < N; i ++){
        if(i % 2 == 1){//even positions
            if(input[i] == 'G'){
                right++;
            }
        }else{//odd position
            if(input[i] == 'G'){
                wrong++;
            }
        }

        diff = wrong- right;
        maxi = max(maxi, diff);

        cout << "\n" << input[i];
        cout << "\nmax: " <<  
        cout << "\nright: " << right;
        cout << "\nwrong: " << wrong << "\n";
    } 
    
    if(maxi > 0){
        cout << 1;
    }else{
        cout << 0; 
    }

}