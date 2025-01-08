/**
 * 202. Happy Number
 * Write an algorithm to determine if a number `n` is happy.
 * 
 * A happy number is a number defined by the following process:
 * 
 * Starting with any positive integer, replace the number by the sum of the squares of its digits.
 * Repeat the process until the number equals 1 (where it will stay), 
 * or it loops endlessly in a cycle which does not include 1.
 * Those numbers for which this process ends in 1 are happy.
 * Return `true` if `n` is a happy number, and `false` if not.
*/

class Solution {
public:
    int getNext(int n) {
        int z = 0;
        while(n) {
            z += (n % 10) * (n % 10);
            n /= 10;
        }
        return z;
    }
    bool isHappy(int n){
        int p = n, q = getNext(n);
        while (q != 1 && p != q){
            p = getNext(p);
            q = getNext(getNext(q));
        }
        return q == 1;
    }
};