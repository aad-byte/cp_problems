#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include<cmath>
using namespace std;
typedef long long ll;

// USACO 2020 Open Contest, Silver, Problem 1
bool possible(vector<pair<ll, ll>> data, ll D, ll N){

    ll poll = data[0].first;
    ll agp = 0;
    ll cgp = 0;
    ll left = N-1;

    ll temp, temp2;

    while(left > 0 && agp < data.size()){
        temp = poll + D;
        if(temp > data[agp].second){
            agp++;
        }else{
            if(cgp == agp){
                poll += D;
            }else{
                temp2 = poll + D;

                if(temp2 < data[agp].first){
                    poll = data[agp].first;
                }else{
                    poll += D;
                }

                cgp = agp;
            }
    
            left--;
        }
    }

    if(agp < data.size()){
        return true;
    }else{
        return false;
    }
    
}

int main(){
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);

    ll N, M;
    cin >> N >> M;

    vector<pair<ll, ll>> data(M);
    ll smallest = pow(10, 18) +1;
    ll largest = -1;

    for(ll i = 0; i < M; i++){
        cin >> data[i].first;
        cin >> data[i].second;

        smallest = min(smallest, data[i].first);
        largest = max(data[i].second, largest);
        //cout << "blah\n";
    }

    sort(data.begin(), data.end());

    ll lo = 1;
    ll hi = largest - smallest +1;
    //cout << "\npotatoes\n";
    ll mid;
    bool trial;

    while(lo < hi){
        mid = ceil(((double)lo + (double)hi)/2.0);
        trial = possible(data, mid, N);
        //cout << "\n trial status: " << trial << " value: " << mid;
        if(trial == false){
            hi = mid - 1;
        }else{
            lo = mid;
        }
    }

    cout << lo;
    

}