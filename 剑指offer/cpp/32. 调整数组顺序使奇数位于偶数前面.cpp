class Solution {
public:
    void reOrderArray(vector<int> &array) {
         int n = array.size();
         if (!n) return;
         int i = -1, j = n;
         while (i < j) {
             while (array[++ i] % 2 == 1);
             while (array[-- j] % 2 == 0);
             if (i < j) swap(array[i], array[j]);
         }
    }
};