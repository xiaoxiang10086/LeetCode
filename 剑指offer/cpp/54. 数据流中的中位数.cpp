// 同 「LeetCode 295. 数据流的中位数」
class Solution {
public:
    priority_queue<int> down;
    priority_queue<int, vector<int>, greater<int>> up;
    
    void insert(int x){
        if (down.empty() || x <= down.top()) down.push(x);
        else up.push(x);
        
        if (down.size() > up.size()+1) up.push(down.top()), down.pop();
        if (up.size() > down.size()) down.push(up.top()), up.pop();
    }

    double getMedian(){
        int tot = down.size() + up.size();
        if (tot % 2 == 1) {
            return down.top();
        } else {
            return (down.top() + up.top()) / 2.0;
        }
    }
};
