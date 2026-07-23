class Solution {
public:
    int lastRemaining(int n) {
        int h = 1;
        int step = 1;
        int remaining = n;
        bool leftToRight = true;
        while (remaining > 1) {
            if (leftToRight || remaining % 2 == 1) {
                h += step;
            }
            remaining /= 2;
            step *= 2;
            leftToRight = !leftToRight;
        }
        return h;
    }
};