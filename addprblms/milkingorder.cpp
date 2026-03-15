#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    int input1, input2, N, M, K;

    cin >> N >> M >> K;

    vector<int> hierarchy;
    map<int, int> prefrence; //order# is key, cow is value

    for(int i = 0; i < M; i++){
        cin >> input1;
        hierarchy.push_back(input1);
    }

    for(int i = 0; i < K; i++){
        cin >> input1 >> input2;
        prefrence[input2-1] = input1;
    }

    //iterate thorugh the intervals of preference cows, checking when the number of spots between then, is more of than the number of hierarchy cows 
    int counter = 0;
    int cow, spots, avaliable;
    int prev, position;
    int ans = 1;

    for(auto &p: prefrence){
        if(p.second == 1){
            cout << (p.first +1);
            return 0;
        }
    }
    for(auto &p : prefrence){
        
        position = p.first;
        //if on the last prefrence cow, the answr will just be the place right after the prefrence cow
        if(counter == prefrence.size() - 1){
            ans = position +2; 
            break;
        }

        //check how many spots are resrved for cows ahead in the hierarchy
        cow = p.second; //get the cow to check in the heiarchy
        spots = find(hierarchy.begin(), hierarchy.end(), cow) - hierarchy.begin();

        //remove the hierarchy cows in front
        //if cow found in hiearchy
        if(spots != hierarchy.size()){
            hierarchy.erase(hierarchy.begin(), hierarchy.begin() + spots +1);
        }else{
            spots = 0; //no hierarchy ciws need to preeced this prefence cow for the interval
        }

        if(counter == 0){
            avaliable = position;
            prev = position;
        }else{
            avaliable = (position - prev) -1;
            prev = position;
        }

        if(avaliable > spots){
            if(counter == 0){
                ans = 1;
            }else{
                ans = prev+2;
            }

            break;
        }

        counter++;
    }

    cout << ans;
 
}