#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int factorial(int num){
    int ans = 1;
    for(int i = num; i >= 1; i--){
        ans *= i;
    }
    return ans;
}

void subset(int start, string word, string og, char passed){
   
    //append char to the word passed in 
        word+=passed;

        //cout << "updating word to " << word << "\n"; 

        // remove char from og
        int index = og.find(passed);
        og.erase(index, 1);

        //cout << "\nlength of og is now " << og.length() << " \n and og is now " << og << " \n\n";

        //create a set for uniqe chars with remaining chars in the word
        set<char> s;
        for(char c : og){
            s.insert(c);
        }

        //for each unique char (iterate in alphabetical order), sets automatically organize chars alphabetically 
        for(char c : s){
            //cout << "now appending the char " << c << "\n";
            subset(start+1, word, og, c);
        }

        if(og.length() == 0){ //no chars left to append
            //cout << "IS THIS EVER HAPPENING???";
            cout << word << "\n"; // print the word once it is complete
        }
}

int main(){
    string input;
    cin >> input;
    int strlegnth = input.length();
    vector<int> repeats; 

    //create set to store the unqie chars based on input (also aplhatebally organizes them)
    set<char> s;
    for(char c : input){
        s.insert(c);
    }

    int total = factorial(strlegnth);
    for(char c: s){ //count number of times each char occurs in a string
        int occ = count(input.begin(), input.end(), c);
        total /= factorial(occ);
    }

    //output total number of strings
    cout << total << "\n";
    //call recursive pritning method for each char
    for(char c : s){
        subset(0, "", input, c);
    }

    //iterate through the subsets and output all possible arrangements of the chars
}