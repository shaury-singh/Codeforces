#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;

string lastKStanding(vector<int>& players,int i ,int k){
    int check = players[i-1];
    unordered_set<int> strengthSet = {};
    priority_queue<int,vector<int>,greater<>> pq = {};
    for (int strength : players){
        strengthSet.insert(strength);
        if (pq.size() < k){
            pq.push(strength);
        } else if (strength > pq.top()){
            pq.pop();
            pq.push(strength);
        }
    }
    while (!pq.empty()){
        if (check == pq.top()){
            return "YES";
        }
        pq.pop();
    }
    return "NO";
}

int main(){
    int testCases;
    cin >> testCases;
    for (int i=0; i<testCases; i++){
        vector<int> players = {};
        int n;
        int j;
        int k;
        cin >> n;
        cin >> j;
        cin >> k;
        for (int j=0; j<n; j++){
            int strength;
            cin >> strength;
            players.push_back(strength);
        }
        cout << lastKStanding(players,j,k) << endl;
    }
    return 0;
}