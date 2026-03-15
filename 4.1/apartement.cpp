#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> desired(n);
    vector<int> apartments(m);

    for(auto &i: desired){
        cin >> i;
    }

    for(auto &i: apartments){
        cin >> i;
    }

    sort(desired.begin(), desired.end());
    sort(apartments.begin(), apartments.end());


    auto d = desired.begin();
    auto a = apartments.begin();

    int count = 0;

    while(d != desired.end() && a != apartments.end()){
        if (*a < *d - k){
            ++a;
        } else if (*a > *d + k){
            ++d;
        }else {
            count  ++;
            ++a;
            ++d;
        }
    }

    cout << count;

}
