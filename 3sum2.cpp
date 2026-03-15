#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    ll n, x;
    cin >> n >> x;

    map<ll, ll> data;
    vector<ll> blah;
    map<ll, vector<ll>> index;

    ll input;

    for(int i = 0; i < n; i++){
        cin >> input;
        data[input]++;
        blah.push_back(input);
        index[input].push_back(i+1);
    }

    sort(blah.begin(), blah.end()); 

    //cout << "\ntest1";

    ll *ptleft = blah.data();
    ll *ptright = blah.data() + n-1;
    
    ll value1, value2, value3;
    bool found = false;

    for(ll *ptleft = blah.data(); ptleft < n + blah.data() && !found; ptleft++){
        for(ll *ptright = ptleft+1; ptright < n + blah.data() &&!found; ptright++){
            //cout << "\ntest2";
            value1 = *ptleft;
            value2 = *ptright;

            data[value1]--;
            data[value2]--;

            value3 = x - (value1+value2);
            if(data[value3] != 0){
                //cout << "\ntest3";
                found = true; 
            }

            data[value1]++;
            data[value2]++;
        }
    }
    

    //cout << "\ntest6";

    if(found){
        //cout << "\ntest8";

        ll pos1, pos2, pos3;
        pos1 = index[value1][index[value1].size()-1];
        index[value1].pop_back();
        pos2 = index[value2][index[value2].size()-1];
        index[value2].pop_back();
        pos3 = index[value3][index[value3].size()-1];
        index[value3].pop_back();

        cout << pos1 << " " << pos2 << " " << pos3;
        
    }else{
        //cout << "\ntest7";
        cout << "IMPOSSIBLE";
    }

    

}