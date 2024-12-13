class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int a_len = a.size();
        int b_len = b.size();
        int first, second;
        int i = 0, j = 0;
        int half = (a_len + b_len) / 2;
        first = INT_MIN;
        for (int k = 0; k <= half; k++)
        {
            if (i == a_len)
            {
                second = first;
                first = b[j++];
            }
            else if (j == b_len)
            {
                second = first;
                first = a[i++];
            }
            else {
                second = first;
                first = (a[i] > b[j]) ? b[j++] : a[i++];
            }
        }
        if ((a_len + b_len) % 2 == 1)
        {
            return first;
        }
        else
        {
            return ((float)first + second) / 2;
        }
    }

};
