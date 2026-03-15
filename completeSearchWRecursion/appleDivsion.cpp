#include <iostream>
#include <vector>
using namespace std;

//get the index of the largest element in the list
int largest(vector<int> arr){ //pass in list

    if(arr.size() > 0){
        int largestIndex = 0; //initalize largestIndex to the first
        int largestNum = arr[0]; //initlaize largest value to the first 
        for(int i = 1; i < arr.size(); i++){ //iterate through the array
            if(arr[i] > largestNum){ //if an index found, holding a value greater than the current largest
                largestIndex = i; //update largest index and value
                largestNum = arr[i];
            }
        }
        return largestIndex; //return the largest index
        cout << "largest index " <<largestIndex;
    }else{
        return -1;
        cout << "No largest index";
    }
   
}


int main(){
    int n;
    cin >> n;
    vector<int> arr;

    //cout << "value of n " << n << "\n";

    int input;
    // cout << "working till here?" << endl;
    for(int i = 0; i < n; i++){
        cin >> input;
        arr.push_back(input);
        //cout << "index " << i <<"\n";
    }

//    cout << "array is filled" << endl;

    //create two varibles to repesent scales
    int grp1 = 0, grp2 = 0;

    
    while(arr.size() > 0){
        //search through largest item in the array
        int index = largest(arr);

        //append to coressponding group
        if(grp1 > grp2){
            grp2 += arr[index];
        }
        else{
            grp1 += arr[index];
        }

        //remove appeneded item from list 
        arr.erase(arr.begin() + index);

    }

    cout << abs(grp1 - grp2) << endl;

}

