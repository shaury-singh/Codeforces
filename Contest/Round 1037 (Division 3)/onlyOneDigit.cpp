#include <iostream>
#include <vector>

using namespace std;

int onlyOneDigit(int n){
    vector<int> digits = {};
    while (n > 0){
        digits.push_back(n%10);
        n = n/10;
    }
    int smallest = INT_MAX;
    for (int digit : digits){
        if (digit < smallest){
            smallest = digit;
        }
    }
    return smallest;
}

int main(){
    int testCases;
    cin >> testCases;
    for (int i=0; i<testCases; i++){
        int n;
        cin >> n;
        cout << onlyOneDigit(n) << endl;;
    }
    return 0;
}