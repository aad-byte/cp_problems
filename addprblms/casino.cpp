#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    long long n, m;
    long long total;
    long long input;
    vector<long long> ans;
    vector<vector<long long>> deck;

    for(int f = 0; f < t; f++){
        total = 0;
        cin >> n >> m;
        
        for(long long i =0; i < n; i++){
            vector<long long>temp;
            for(long long j = 0; j < m; j++){
                cin >> input;
                temp.push_back(input);
            }
            deck.push_back(temp);

    
        }

        for(long long i = 0; i < n; i++){
            for(long long j = i+1; j < n; j++){
                for(long long k = 0; k < m; k++){
                    int diff = abs(deck[i][k] - deck[j][k]);
                    total += diff;
                }
            }
        }

        cout << total << "\n";

        deck.clear();
    }
   
}