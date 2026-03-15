#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int total = 0;

string generate(string order, int cow, int num, set<int> remain, vector<vector<int>> conditions, int total){
    //run through all possible permutations of cows
    string new_order = order;

    new_order += (cow + 48); //ASCI value conversion
    remain.erase(cow);

    if(num == 7){
    //check if they staisfy condtions 

    //for each cow
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < conditions[i].size(); j++){
            //Append number chars to stirng (easier to compare than names)
            string search1 = "";
            string search2 = "";
            string temp1 = "";
            temp1 += (i + 48);
            string temp2 = "";
            temp2 += conditions[i][j];

            search1 += temp1;
            search1 += temp2;
            search2 += temp2;
            search2 += temp1; 

            //check to see if this sequence of chars (this specific substring is in the main built up string)
            bool Search1 = true; 
            bool Search2 = true;

            if(new_order.find(search1) == string::npos){
                Search1 = false;
            }

            if(new_order.find(search2) == string::npos){
                Search2 = false;
            }else{
                total ++;
            }

            cout << "\n the order: " << new_order;
            cout << "\n\t satisfys? : " << (Search1 || Search2);

            cout << "\n\n";

            string a = "zzzz";
            string b = "01234567";
            string smaller = min({a, b});
            cout << "the smaller string is" << smaller << "\n\n"; 

            if(!(Search1 || Search2)){
                new_order = "zzzz"; //set to high value char
                return  new_order;
            }

        }
    }
    
    return new_order;
    //if they dont satisfy the condtions just return -1
    }

    //create stirng
    //return the minimum string

    string minimum;
    for(int i : remain){
        //PASS in value of i as the cow for remain
        string blah = generate(new_order, i, num + 1, remain, conditions, total);
        if(i == 0){
            minimum = blah;
        }
        minimum = min(minimum, blah);

        cout << "\nminimum is currently" << minimum << "\n";
    }   

    return minimum;
    
}

int toNum(string name){
    if(name == "Beatrice"){
        return 0;
    }else if(name == "Bella"){
        return 1;
    }else if(name == "Belinda"){
        return 2;
    }
    else if(name == "Bessie"){
        return 3;
    }else if(name == "Betsy"){
        return 4;
    }else if(name == "Blue"){
        return 5;
    }else if(name == "Buttercup"){
        return 6;
    }
    else if(name == "Sue"){
        return 7;
    }else{
        return -1;
    }
}

int main(){
    int n;
    cin >> n;
    string names[8] = {"Beatrice", "Bella", "Belinda", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};

    vector<vector<int>> cows;
    cows.resize(8);

    string first, second, temp;
    for(int i =0; i < n; i++){
        cin >>  first;
        cin >> temp >> temp >> temp >> temp;
        cin >> second;

        cows[toNum(first)].push_back(toNum(second));
        cows[toNum(second)].push_back(toNum(first));
        
    }

    set<int> remain;
    string order = ""; //empty string for order

    //insert all cows in reamin
    for(int i = 0; i < 8; i++){
        remain.insert(i);
    }
    //for each cow, call generate, take minimum order
    string minimum;

    int total = 0;
    for(int i : remain){
        //PASS in value of i as the cow for remain
        string blah = generate(order, i, 0, remain, cows, total);
        if(i == 0){
            minimum = blah;
        }
        minimum = min(minimum, blah);
    }   

    cout << "\ntotal possible combos: " << total;
    cout << minimum;

}