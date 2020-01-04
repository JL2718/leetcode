// Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.
//
// Example 1:
//
//
//
// Input: a = 2, b = [3]
// Output: 8
//
//
//
// Example 2:
//
//
// Input: a = 2, b = [1,0]
// Output: 1024
//
//
//


class Solution {
public:
    int superPow(int a, vector<int>& B) {
        int r=1;//result
        const int t = (7-1)*(191-1);//totient of 1337
        int e = 0,d=1;
        //find exponent % totient of 1337
        for(auto ib=rbegin(B);ib!=rend(B);++ib){
            e = (e+d*(*ib))%t;
            d = (d*10)%t;
        }
        //now apply exponent
        a = a%1337;
        while(e){
            if(e&1)r=(r*a)%1337;
            a=(a*a)%1337;
            e=e>>1;
        }
        return r;
    }
};
