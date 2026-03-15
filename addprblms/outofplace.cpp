#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    int N, input;
    cin >> N;
    vector<int> cows;
    int index1 = -1; 
    int index2, bessie;
    bool smaller;
    //store all cows, no repeats in a vector
    for(int i = 0; i < N; i++){
        cin >> input;
        if(i == 0){
            cows.push_back(input);
        }else{
            if(input != cows[i-1]){
                cows.push_back(input);
            }
        }
    }

    //iterate through cowlist
    for(int i = 0; i < cows.size(); i++){
        //for all non-first cows
        if(i != 0){
            //if the current cow is smaller than the previous cow..one of them is out of order
            if(cows[i] < cows[i-1]){
                //if the current cow is smaller than the succesive cow as well, then it is out of order
                if(i == cows.size() -1){//on last element
                    if(cows[i] < cows[i-1]){
                        bessie = cows[i];
                        smaller = false; //this is bessie and she needs to move to a smaller index, thus to minimize number of swaps we want the largest possible index
                        index1 = i; 
                    }
                }else{
                    if(cows[i-1] <= cows[i+1]){
                        bessie = cows[i];
                        smaller = false; //this is bessie and she needs to move to a smaller index, thus to minimize number of swaps we want the largest possible index
                        index1 = i;
                    }else{ // otherwise the previous cow is out of order
                        bessie = cows[i-1];
                        smaller = true;
                        index1 = i -1;
                    }
                }
            }
        }
    }
    int ans;

    sort(cows.begin(), cows.end()); //sort cows
    if(index1 != -1){
        index2 = find(cows.begin(), cows.end(), bessie) - cows.begin(); //find bessie in the sorted order

        //if more than 1 height tyoe other than bessie, use smaller
        /*if(count(cows.begin(), cows.end(), bessie) > 1){ //if bessie was moving from larger to smaller index, and there is another cow with her sma eheight, her new position will be the larger of the two indexes
            if(!smaller){
            index2++;
            }
        }*/

        ans = abs(index1 - index2);
    }else{
        ans = 0;
    }

    cout << ans;
}