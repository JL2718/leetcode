// Given an integer array A, you partition the array into (contiguous) subarrays of length at most K.  After partitioning, each subarray has their values changed to become the maximum value of that subarray.
//
// Return the largest sum of the given array after partitioning.
//
//  
//
// Example 1:
//
//
// Input: A = [1,15,7,9,2,5,10], K = 3
// Output: 84
// Explanation: A becomes [15,15,15,9,10,10,10]
//
//  
//
// Note:
//
//
// 	1 <= K <= A.length <= 500
// 	0 <= A[i] <= 10^6
//
//


class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        vector<int> dp(size(A)+1,0);//max score possible prior to each point
        for(int i=0;i<size(A);++i){
            int m=0;//max val in interval
            for(int j=i;(j>=0) and (i-j<K);--j){
                m=max(m,A[j]);
                dp[i+1]=max(dp[i+1],dp[j]+m*(i-j+1));
                //cout<<j<<" "<<i<<" "<<m<<" "<<dp[i+1]<<endl;
            }
        }
        return dp.back();
    }
};
