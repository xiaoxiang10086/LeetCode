class MedianFinder {
public:
    priority_queue<int> smaller; // 大根堆(下)
    priority_queue<int, vector<int>, greater<int>> greater; // 小根堆(上)

    MedianFinder() {

    }
    
    void addNum(int num) {
        if (smaller.empty() || num <= smaller.top()) smaller.push(num);
        else greater.push(num);
        
        if (smaller.size() > greater.size()+1) {
            greater.push(smaller.top()); smaller.pop();
        }
        if (greater.size() > smaller.size()) {
            smaller.push(greater.top()); greater.pop();
        }
    }
    
    double findMedian() {
        if ((smaller.size() + greater.size()) % 2 == 1) {
            return smaller.top();
        } else {
            return (smaller.top() + greater.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
