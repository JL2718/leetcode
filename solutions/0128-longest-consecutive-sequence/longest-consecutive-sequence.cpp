// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//
// Your algorithm should run in O(n) complexity.
//
// Example:
//
//
// Input: [100, 4, 200, 1, 3, 2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
//
//


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,pair<int,int>> m;
        int r=0;
        for (auto n:nums) 
            m[n]=make_pair(n-1,n+1);
        for (auto kv:m){
            int k,b,f;
            pair<int,int> v;
            tie(k,v)=kv;
            tie(b,f)=v;
            #printf("%d %d %d\n",k,b,f);
            if(m.count(b))
                get<1>(m[b])=f;
            if(m.count(f)) 
                get<0>(m[f])=b;
            r = max(r,f-b-1);
                
        }
        return r; 
    }
};


