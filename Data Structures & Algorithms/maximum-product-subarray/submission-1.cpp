class Solution {
public:
    int maxProduct(vector<int>& nums) {
            int n = nums.size();
            int maxi = INT_MIN;
            int maxi1 = 1;
            int maxi2 = 1;
            for(int i=0;i<n;i++){
                  maxi1 = nums[i]*(maxi1==0 ? 1 : maxi1);
                  maxi2 = nums[n-1-i]*(maxi2==0? 1: maxi2);
                  maxi = max(maxi,max(maxi1,maxi2));
            }
            return maxi;
            
    }
};
