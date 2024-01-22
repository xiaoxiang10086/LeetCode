class Solution {
public:
    bool searchArray(vector<vector<int>> array, int target) {
        int n = array.size();
        if (!n) return false;
        int m = array[0].size();
        int i = 0, j = m-1;
        while (i < n && j >= 0) {
            if (array[i][j] > target) j--;
            else if (array[i][j] < target) i++;
            else return true;
        }
        return false;
    }
};
