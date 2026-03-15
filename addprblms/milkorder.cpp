#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

int main(){
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    int N, M , K;
    cin >> N >> M >> K;

    vector<int> hierarchy;
    vector<int> ultimate(N);

    int input, index;
    for(int i = 0; i < M; i++){
        cin >> input;
        hierarchy.push_back(input);
    }

    for(int i =0; i < K; i++){
        cin >> input >> index;
        ultimate[index-1] = input;
    }

    int latestindex1 = N;
    int latestindex2 = -1;
    //for every cow in hierarchy from the reverse order
    if(find(hierarchy.begin(), hierarchy.end(), 1) == hierarchy.end()){//if 1 is not a hierachy cow, it must be placed such that all the other heirarchys are as low as possible
        for(int i = hierarchy.size() -1; i >=0; i--){
            //cout << "\n\non cow " << i << " in the hierarchy with value of: " << hierarchy[i];
            //cout << "\n value of latest index: " << latestindex1;
            int cowa = hierarchy[i];
            auto it = find(ultimate.begin(), ultimate.end(), cowa);
            if(it != ultimate.end()){//if the cow is already placed in ultimate(is also a index cow)
                latestindex1 = it - ultimate.begin(); //all remaining hierarchy cows must preceed it, so update the latest index to be the position of the latest cow
                //cout << "\ncow is already in the array, update latestindex1 to : " << latestindex1;
            }else{
            //starting at the latest index, iterating through ultimate from right to left, find the first spot that is vacant, or has value 0, this is where we will place our hierachy cow
            for(int j = latestindex1-1; j >=0; j--){
                if(ultimate[j] == 0){
                    ultimate[j] = cowa;
                    break;
                }
            }
    
            }
            
        }
    }else{//if 1 is a hierachy cow, it must be placed such that all the hierarchy cows are shifted up
        for(int i = 0; i < hierarchy.size(); i++){
            //cout << "\n\non cow " << i << " in the hierarchy with value of: " << hierarchy[i];
            //cout << "\n value of latest index: " << latestindex2;
            int cowa = hierarchy[i];
            auto it = find(ultimate.begin(), ultimate.end(), cowa);
            if(it != ultimate.end()){//if the cow is already placed in ultimate(is also a index cow)
                latestindex2 = it - ultimate.begin(); //all remaining hierarchy cows must preceed it, so update the latest index to be the position of the latest cow
                //cout << "\ncow is already in the array, update latestindex2 to : " << latestindex2;
            }else{
            //starting at the latest index, iterating through ultimate from right to left, find the first spot that is vacant, or has value 0, this is where we will place our hierachy cow
            for(int j = latestindex2+1; j < ultimate.size(); j++){
                if(ultimate[j] == 0){
                    ultimate[j] = cowa;
                    break;
                }
            }
    
            }
            
        }
    }
   

    //cout << "\ncontents of ultimate: ";
    for(int i = 0; i < N; i++){
        //cout << "\n index: " << i << " value: " << ultimate[i];
    }

    int ans;
    auto iter = find(ultimate.begin(), ultimate.end(), 1);
    if(iter != ultimate.end()){
        //cout << "\nflag1";
        ans = iter - ultimate.begin();
    }else{
        //cout << "\nflag2";
        for(int h = 0; h < N; h++){
            //cout << "\nultimate at " << h << " is " << ultimate[h];
            if(ultimate[h] == 0){
                ans = h;
                break;
                //cout << "\n VALUE OF ANS " << ans << " and h IS " << h;
            }
        }
    }

    cout << ans+1;
}