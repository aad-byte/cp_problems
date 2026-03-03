#include <iostream>
#include <algorithm>
#include <vector> 
#include <map>
#include <set>
using namespace std;

// USACO 2016 December Contest, Bronze, Problem 2
int main(){
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    int N;
    cin >> N;

    char d;
    map<char, int> main; //overall letter bank 
    //vars to take in string inputs
    string r1, r2;
    
    //iterate through each word pair
    for(int i =0; i < N; i++){
        cin >> r1;
        cin >> r2;

        //cout << "\n value of r1: " << r1 << " and value of r2: " << r2 << "\n";

        map<char, int> personalr1;
        map<char, int> personalr2;

        for(char &f: r1){
            //char g = 97;
            //cout << "\n vlaue of char f: " << g << "\n";
            personalr1[f]++;
            //cout << "\n\n" << personalr1[f] << "\n\n";
        }

        for(char &f: r2){
            personalr2[f]++;
        }

        //for each letter in the alphabet, add the word with the instances of more of that letter from each word
        for(char start = 97; start < (97+26); start++){
            main[start] += max(personalr1[start], personalr2[start]);
        }

    }

    for(char i = 97; i < 97+26; i++){
        cout << main[i] << "\n";
    }

    
}