#include <vector>
#include <deque>
#include <queue>
using namespace std;

class Solution
{
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        size_t n = matrix.size();
        priority_queue<int,vector<int>, greater<int>> v;
        for (size_t i = 0; i < n; ++i)
        {
            for (size_t j = 0; j < n; ++j)
            {
                v.push(matrix[i][j]);
            }
        }
        for (size_t i = 0; i < k - 1; ++i)
        {
            v.pop();
        }
        return v.top();
    }
    void insert(deque<int> &v, int val)
    {
        size_t i;
        size_t size = v.size();
        v.push_back(-1);
        for (i = size; i / 2 > 0 && v[i / 2] > val; i /= 2)
        {
            v[i] = v[i / 2];
        }
        v[i] = val;
    }
    int removeMin(deque<int> &v)
    {
        size_t size = v.size();
        int last = v[size - 1];
        --size;
        int min = v[1];
        size_t child;
        size_t i;
        for (i = 1; i * 2 <= size; i = child)
        {
            child = i * 2;
            if (child != size && v[child] > v[child + 1])
                ++child;
            if (last > v[child])
                v[i] = v[child];
            else
                break;
        }
        v[i] = last;
        v.pop_back();
        return min;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v = {{5, 5, 10, 15}, {7, 10, 15, 20}, {10, 11, 16, 20}, {13, 18, 20, 23}}; //{{-5}};//{{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    int k = 7;
    auto res = s.kthSmallest(v, k);
    return 0;
}