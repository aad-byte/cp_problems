#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//USACO 2017 January Contest, Silver, Problem 1

int timetakes(vector<int> data, int K){

    priority_queue<int, vector<int>, greater<int>> pq;

    int global_add = 0;
    int counter = 0;
    //push inital K elements in the que
    for(int i =0; i < K; i++){
        pq.push(data[counter]);
        counter++;
    }


    while(counter < data.size()){
        //retrive smallest element 
        int smallest = pq.top() + global_add;
        global_add -= smallest;
        pq.pop(); // remove smallest element
        pq.push(data[counter] - global_add);
        counter++;

    }

    for(int i = 1; i < K; i++){
        pq.pop();
    }

    int lastcow = pq.top() + global_add;
    global_add -= lastcow;

    K = -global_add;
    return K;

}

int main(){
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    int N, T;

    cin >> N >> T;
    vector<int> data(N);

    for(auto &i: data){
        cin >> i;
    }

   int right = N;
   int left = 0;
   int mid;

   int time;

   while(left < right){
    //cout << "\nleft" << left;
    //cout << "\nright" << right;
    mid = (right + left)/2;

    //cout << "\nmid" << mid;

    time = timetakes(data, mid);
    //cout << "\ntime: " << time;

    if(time > T){
        //cout << "\n time too big";
        left = mid +1;  
    }else{
        //cout << "\n time less than or equal too";
        right = mid;
    }

}

cout << left; 

}