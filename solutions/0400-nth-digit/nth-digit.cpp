// Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 
//
// Note:
// n is positive and will fit within the range of a 32-bit signed integer (n < 231).
//
//
// Example 1:
//
// Input:
// 3
//
// Output:
// 3
//
//
//
// Example 2:
//
// Input:
// 11
//
// Output:
// 0
//
// Explanation:
// The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
//
//


class Solution {
public:
    int findNthDigit(int n) { 
        int d=0;//number of digits per number in range
        long long m=n;
        while(m>0) // find range
            m-=9*pow(10,d)*++d;
        int i=pow(10,d)-1+m/d;m%=d;//get exact number
        while(m++)i/=10;//shift to exact digit
        return i%10;//return digit
    }
};
