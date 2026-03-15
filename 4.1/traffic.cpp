#include<iostream>
#include<vector> 
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int x , n;

    cin >> x >> n;

    multiset<int> lengths;
    set<int> lights;

    lights.insert(0); 
    lights.insert(x);
    lengths.insert(x-0);

    int pos;
    for(int i = 0; i < n; i++){
       //cout << "\n iteration " << i << " \n";
        cin >> pos;

       //cout << "\nvalue of pos: " << pos;
        lights.insert(pos);
        auto hi = lights.upper_bound(pos);
        auto lo = prev(hi, 2);

        //get coordinates of the interval range the new set of traffic lights fall between
        int right = *hi;
        int left = *lo;

       //cout << "\nvalue of right: " << right;
       //cout << "\nvalue of left: " << left;

       //cout << "\n\nover and out \n\n";

        lengths.erase(lengths.find(right-left));// erase by iterator to only erase 1 intance of the elemnt, erasing by value will remove all values of that element, no this is 
        //I think the previous line is causing TLE
        lengths.insert(right-pos);
        lengths.insert(pos-left);

       cout << *prev(lengths.end()) << " ";
    }
}
