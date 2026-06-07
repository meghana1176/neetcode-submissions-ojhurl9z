class Solution {
public:
    int uniquePaths(int m, int n) {
            int N = m+n-2;
            int x = max(m-1,n-1);
            int y=  min(m-1,n-1);
            long long ans = 1;
            for(int i=1;i<=x;i++){
                 ans = ans*(i+y)/i;

            }
            return int(ans);


    }
};
