class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> deque;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];

            while (!deque.empty() && deque.back() < num) {
                deque.pop_back();
            }
            deque.push_back(num);

            if (i >= k && nums[i - k] == deque.front()) {
                deque.pop_front();
            }

            if (i >= k - 1) {
                res.push_back(deque.front());
            }
        }

        return res;        
    }
};
