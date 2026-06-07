class Solution {
public:
    unordered_map<string,int> maps;
    int rob(vector<int>& nums) {
            int n = nums.size();
            if(n==1) return nums[0];
            int case1 = dfs(0,n-2,true,nums);
            maps.clear();
            int case2 = dfs(1,n-1,true,nums);
            return max(case1,case2);
    }
    int dfs(int i,int end ,bool canrob, vector<int>& nums){
              if(i>end) return 0;
              string key = to_string(i)+ "-"+ to_string(end) + "-" + to_string(canrob);
              if(maps.find(key)!=maps.end()){
                   return maps[key];
              }
              if(canrob) maps[key] = max(dfs(i+2,end,true,nums)+nums[i],dfs(i+1,end,true,nums));
              else maps[key] = dfs(i+1,end,true,nums) ;
              return maps[key];
    }
};
