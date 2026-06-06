class Solution {
public:
    int maxProduct(vector<int>& nums) {
            int n = nums.size();
            int maxi = INT_MIN;
            int curr_maxi = 1; 
            int curr_mini = 1;
            for(int i=0;i<n;i++){
                   int curr = curr_maxi*nums[i];
                   curr_maxi = max({curr, curr_mini*nums[i],nums[i]});
                   curr_mini = min({curr, curr_mini*nums[i],nums[i]});
                   maxi = max(maxi,curr_maxi);
                   
            }
            return maxi;
    }
};
