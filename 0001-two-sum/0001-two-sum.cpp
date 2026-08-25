class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> newNums;
        for(int i=0; i<n; i++) {
            newNums.push_back({nums[i], i});
        }
        sort(newNums.begin(), newNums.end());
        int left = 0;
        int right = n-1;
        while(left < right) {
            int currSum = newNums[left][0] + newNums[right][0];
            if(currSum == target) break;
            else if(currSum < target) left++;
            else right--;
        }
        return {newNums[left][1], newNums[right][1]};
    }
};