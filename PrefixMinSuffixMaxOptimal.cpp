#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> transform(vector<int>& nums){
    vector<int> result(nums.size(),0);
    int minPrefix = nums[0];
    int maxSuffix = nums[nums.size()-1];
    for (int i=0; i<nums.size()-1; i++){
        minPrefix = min(minPrefix,nums[i]);
        if (minPrefix == nums[i]){
            result[i] = 1;
        }
    }
    for (int i=nums.size()-1; i>-1; i--){
        maxSuffix = max(maxSuffix,nums[i]);
        if (maxSuffix == nums[i]){
            result[i] = 1;
        }
    }
    return result;
}

int main(){
    int testCases;
    int size;
    cin >> testCases;
    for (int i=0; i<testCases; i++){
        vector<int> nums = {};
        cin >> size;
        for (int j=0; j<size; j++){
            int element;
            cin >> element;
            nums.push_back(element);
        }
        vector<int> result = transform(nums);
        for (int k=0; k<result.size(); k++){
            cout << result[k];
        }
        cout << endl;
    }
    return 0;
}