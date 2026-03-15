#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<iterator>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    multiset<int> ticket;
    vector<int> customer(m);

    int input; 
    for(int i = 0; i < n; i++){
        cin >> input;
        ticket.insert(input);
    }

    
    int ans;
    for(int i =0; i < m; i++){
        cin >> input;

        auto index = ticket.upper_bound(input);

        if(index == ticket.end()){
            //do nothing unless the largest element is still smaller than this one
            if(ticket.size() > 0 && *(prev(index)) <= input){
                ans = *prev(index);
                ticket.erase(prev(index));
               
            }else{
                ans = -1;
            }
        }else{
            if(index != ticket.begin()){ //make sure there exists a ticket smaller or equal to the price they offer, otherwise you cannot acess --index
                ans = *(prev(index));
                ticket.erase(prev(index));// erasing by iterator only erases that value once
               
            }else{
                ans = -1;
            }
            
        }

        cout << ans << "\n";

    }

    

}