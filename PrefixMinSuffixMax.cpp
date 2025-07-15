#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> transform(vector<int>& nums){
    vector<int> result = {};
    for (int i=0; i<nums.size(); i++){
        int left = 0;
        bool s = false;
        bool p = false;
        int minPrefix = nums[0];
        int maxSuffix = nums[nums.size()-1];
        while (left < nums.size()){
            minPrefix = min(minPrefix,nums[left]);
            if (minPrefix == nums[i]){
                p = true;
                break;
            }
            left++;
        }
        for (int j=nums.size()-1; j>-1; j--){
            maxSuffix = max(maxSuffix,nums[j]);
            if (maxSuffix == nums[i]){
                s = true;
                break;
            }
        }
        if (s || p){
            result.push_back(1);
        } else {
            result.push_back(0);
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