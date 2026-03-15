#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    long long t;
    cin >> t;
    long long n, m, input;
    long long total;
    vector<long long> ans;
    vector<vector<long long>> deck;

    for(long long i = 0; i < t; i++){
        total = 0;
        cin >> n >> m;
        deck.resize(m);
        for(long long j = 0; j< n; j++){
            for(long long k = 0; k < m; k++){
                cin >> input;
                deck[k].push_back(input);
            }
        }

        for(long long h = 0; h < m; h++){
            sort(deck[h].begin(), deck[h].end());
        }

        long long counter;
        for(long long j = 0; j< m; j++){
            counter = -1*(n-1);
            for(long long k = 0; k < n; k++){
                total += deck[j][k]*counter;
                counter += 2;
            }
        }
        ans.push_back(total);
        deck.clear();
    }

    for(long long i = 0; i < t; i++){
        cout << ans[i] << "\n";
    }


}