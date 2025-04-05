class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stack;

        for (int asteroid : asteroids) {
            bool alive = true;
            while (!stack.empty() && asteroid < 0 && stack.top() > 0) {
                if (stack.top() < -asteroid) {
                    stack.pop();
                    continue;
                } else if (stack.top() == -asteroid) {
                    stack.pop();
                }
                alive = false;
                break;
            }
            if (alive) {
                stack.push(asteroid);
            }
        }

        vector<int> res(stack.size());
        for (int i = res.size() - 1; i >= 0; i--) {
            res[i] = stack.top();
            stack.pop();
        }
        return res;
    }
};