#include <iostream>
#include <vector>

using namespace std;

vector<int> reverseArray(vector<int>& nums){
    int left = 0;
    int right = nums.size()-1;
    while (left < right){
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++;
        right--;
    }
    return nums;
}

vector<int> maxArray(vector<int>& nums){
    vector<int> maxedArray(nums.size(),-1);
    int maxTillNow = nums[0];
    for (int i=1; i<nums.size(); i++){
        maxTillNow = max(maxTillNow,nums[i]);
        maxedArray[i] = maxTillNow;
    }
    return maxedArray;
}

vector<int> suffixSum(vector<int>& nums){
    int sum = 0;
    for (int element : nums){
        sum += element;
    }
    return nums;
}

vector<int> moveToTheEnd(vector<int>& nums){
    vector<int> numsReverse = reverseArray(nums);
    return numsReverse;
}

int main(){
    vector<int> nums = {13,5,10,14,8,15,13};
    vector<int> result = moveToTheEnd(nums);
    vector<int> maxedResult = maxArray(result);
    for (int element : maxedResult){
        cout << element << endl;
    }
    return 0;
}