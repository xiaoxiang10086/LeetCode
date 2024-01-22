class Solution {
public:
    string printMinNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            auto as = to_string(a), bs = to_string(b);
            return as + bs < bs + as;
        });
        string res;
        for (auto num: nums) res += to_string(num);
        return res;
    }
};
