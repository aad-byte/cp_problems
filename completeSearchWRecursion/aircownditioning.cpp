#include <iostream>
#include <vector>
using namespace std;

int generate(vector<int> used, int which, bool included, vector<vector<int>> cow, vector<vector<int>> cond, int m){
    //APPEND which to the the used depeing on if included var is true or false
    vector<int> new_used = used;
    if(included && which != m){
        new_used.push_back(which);
    }

    //ADD at the end of generating each subset
    if(which == m){
         //calculate cost of conditoners used
    int total_cost = 0;
    for(int c : used){
        total_cost += cond[c][3];
    }

    //set temps in barn
    vector<int> barn(100, 0); //initalize all temps to 0
    for(int i : used){
        for(int j = cond[i][0]; j <= cond[i][1]; j++){ //set the stalls temp
           barn[j] += cond[i][2]; //append whatever the conditoner cools (if there is overlap, the condtioner will cool the stall more)
            /*int cooling =  cond[i][2];
            if(cooling > barn[j]){
                barn[j] = cooling;
            }*/
        }
    }

    bool satisfy = true;
    //check if the conditoners satisfy the cows
    //for each cow's stalls, check if their exists a cindtioner (in used) that meets that requirement
    //MD vector "cow" holds all the info on the cow's requirements, and cond on the conditoner's performance
    for(int i = 0; i < cow.size(); i++){
        if(satisfy){
            for(int j = cow[i][0]; j <= cow[i][1]; j++){
                int comf = cow[i][2];
                
                if(barn[j] < comf){
                    satisfy = false;
                    break;
                }
    
            }
        }else{
            break;
        }

    }

    if(!satisfy){
        total_cost = 1001 * 10; //set cost higher than any possible combination of air conditioners
    }

    return total_cost;
    }


    //call recruisvley and take the minimum of the costs, generating different subsets one with the element included and one without    
    int min_cost = min(generate(new_used, which + 1, true, cow , cond, m), generate(new_used, which + 1, false, cow , cond, m)); 
    return min_cost;

}

int main(){
    int n, m; // n represents the # of cows, m the # of air conditioners

    cin >> n >> m;

    vector<vector<int>> cow;
    cow.resize(n);
    for(int i = 0; i < n; i ++){ //for each ith cow at index i in cow, its si is stored at 0, ti at 1, c1 at 2
        cow[i].resize(3);
        for(int j = 0; j < 3; j++){
            cin >> cow[i][j];
        }
    }



    vector<vector<int>> cond;
    cond.resize(m);
    for(int i = 0; i < m; i ++){ //for each ith conditioner at index i in cond, similar to prev 
        cond[i].resize(4);
        for(int j = 0; j < 4; j++){
            cin >> cond[i][j];
        }
    }


    vector<int> used; //start off by giving an empty vector 
    int cost = min(generate(used, 0, true, cow, cond, m), generate(used, 0, false, cow, cond, m));

   cout << cost;
    //since M is 10, 2^10 is less than 10^8, try out every possibility of air conditonaers

}