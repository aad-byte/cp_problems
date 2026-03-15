#include <iostream>
#include <map>
#include<vector>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    int n;
    cin >> n;

    multiset<pair<int, int>> data;

    int numroom = 0; 
    for(int i = 0; i < n; i++){
        //look inside data and see if there is any tuple with the first value that is less than given arival time
        int arrival;
        int departure;
        cin >> arrival >> departure;

        auto it = 
    }
}