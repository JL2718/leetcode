// Given an array A of integers, we must modify the array in the following way: we choose an i and replace A[i] with -A[i], and we repeat this process K times in total.  (We may choose the same index i multiple times.)
//
// Return the largest possible sum of the array after modifying it in this way.
//
//  
//
// Example 1:
//
//
// Input: A = [4,2,3], K = 1
// Output: 5
// Explanation: Choose indices (1,) and A becomes [4,-2,3].
//
//
//
// Example 2:
//
//
// Input: A = [3,-1,0,2], K = 3
// Output: 6
// Explanation: Choose indices (1, 2, 2) and A becomes [3,1,0,2].
//
//
//
// Example 3:
//
//
// Input: A = [2,-3,-1,5,-4], K = 2
// Output: 13
// Explanation: Choose indices (1, 4) and A becomes [2,3,-1,5,4].
//
//
//
//
//  
//
// Note:
//
//
// 	1 <= A.length <= 10000
// 	1 <= K <= 10000
// 	-100 <= A[i] <= 100
//
//


class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        int nn=0;
        for(int a:A)if(a<0)nn++;
        if(K<nn)
            nth_element(begin(A),begin(A)+K-1,end(A));
        //for(int a:A)cout<<a<<" ";cout<<endl;
        int m = INT_MAX;
        int s = 0;
        for(auto ia=A.begin();ia!=A.end();++ia){
            int e=*ia;
            if(K){
                if(e<0){
                    e=-e;
                    --K;
                }
                m=min(m,e);
            }
            s+=e;
            //cout<<e<<' '<<s<<' '<<m<<' '<<K<<endl;
        }
        if(K) s+=m*pow(-1,K)-m;
        return s;
    }
};
