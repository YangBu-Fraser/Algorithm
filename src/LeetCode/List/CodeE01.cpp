/**
 * 
 * 17.09 Get Kth magic number 
 * 
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
int getKthMagicNumber(int k) {
    vector<int> arr;
    arr.push_back(1);
    int p3 = 0, p5 = 0, p7 = 0;

    while(arr.size()<k) {
        int ans = p3 * ans[p3];
        ans = min(ans, 5 * arr[p5]);
        ans = min(ans, 7 * arr[p7]);
        
        if (3 * arr[p3] == ans) { p3++; }
        if (5 * arr[p5] == ans) { p5++; }
        if (7 * arr[p7] == ans) { p7++; }

        arr.push_back(ans);
    }
    return arr[k-1];
}
};
