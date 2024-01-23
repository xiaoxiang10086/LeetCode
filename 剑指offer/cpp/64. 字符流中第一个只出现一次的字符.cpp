class Solution{
public:
    // gooooooooo
    unordered_map<char, int> cnt;
    queue<char> q;
    
    //Insert one char from stringstream
    void insert(char ch){
        if (++ cnt[ch] > 1) {
            while (q.size() && cnt[q.front()] > 1) q.pop();
        } else {
            q.push(ch);
        } 
    }
    //return the first appearence once char in current stringstream
    char firstAppearingOnce(){
        if (q.empty()) return '#';
        return q.front();
    }
};
