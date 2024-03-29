// TIME = O(N * N), SPACE = O(N * N)

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
        int nax = -1;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                if(nums1[i - 1] == nums2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = 0;
                nax = max(nax, dp[i][j]);
            }
        }
        return nax;
    }
};

// TIME = O(N * N), SPACE = O(2 * N) ~ O(N).

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int>prev(m + 1, 0), curr(m + 1, 0);
        int nax = -1;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                if(nums1[i - 1] == nums2[j - 1]) curr[j] = 1 + prev[j - 1];
                else curr[j] = 0;
                nax = max(nax, curr[j]);
            }
            prev = curr;
        }
        return nax;
    }
};