/**
 * 969. Pancake Sorting
 * 
 * Given an array of integers arr, sort the array by performing a series of pancake flips.
 * 
 * In one pancake flip we do the following steps:
 * 
 * 1. Choose an integer k where 1 <= k <= arr.length.
 * 2. Reverse the sub-array arr[0...k-1] (0-indexed).
 * 
 * For example, if arr = [3,2,1,4] and we performed a pancake flip choosing k = 3, 
 * we reverse the sub-array [3,2,1], so arr = [1,2,3,4] after the pancake flip at k = 3.
 * 
 * Return an array of the k-values corresponding to a sequence of pancake flips that sort arr. 
 * Any valid answer that sorts the array within 10 * arr.length flips will be judged as correct.
 * 
 */

class Solution {
public:
    void reverse(vector<int> &arr, int n, vector<int> &ind){
        for(int i = 0, j = n- 1; i < j; i++, j--) {
            swap(arr[i], arr[j]);
            ind[arr[i]] = i;
            ind[arr[j]] = j;
        }
        return ;
    }
    
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> index(arr.size() + 1);
        vector<int> ret;

        for(int i = 0; i < arr.size(); i++) {
            index[arr[i]] = i;
        }

        for(int i = arr.size(); i >= 1; i--) {
            if(index[i] + 1 == 1) {
                ret.push_back(index[i] + 1);
                reverse(arr, index[i] + 1, index);
            }
            if(i == 1) {
                ret.push_back(i);
                reverse(arr, i, index);
            }
        }
        return ret;
    }
};