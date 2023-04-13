class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
      //O(n)
        //  stack<int> stack;
        // int j = 0;
        // for (int x : pushed) {
        //     stack.push(x);
        //     while (stack.size() && stack.top() == popped[j]) {
        //         stack.pop();
        //         j++;
        //     }
        // }
        // return stack.size() == 0;

       //O(1)
      //NON interviewer answer
        int i = 0, j = 0;
        for (int x : pushed) {
            pushed[i++] = x;
            while (i > 0 && pushed[i - 1] == popped[j])
                --i, ++j;
        }
        return i == 0;
    }
};
