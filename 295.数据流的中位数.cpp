/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
class MedianFinder {
public:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> big ;
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        // add element to small first, never add to big
        small.push(num);
        
        // adjust size, keep size balance
        while(small.size() > big.size() + 1)
            big.push(small.top()); small.pop();
        
        // swap top element if neccessary
        if(big.size() > 0 && big.top() < small.top()){
            int tmp = small.top();
            small.pop();
            small.push(big.top());
            big.pop();
            big.push(tmp);
        }
    }
    
    double findMedian() {
        if(small.size() != big.size())
            return small.top();
        else return ((long long)(small.top())+big.top())*0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

