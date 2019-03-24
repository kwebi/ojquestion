#include <vector>
using namespace std;
class Solution
{
  public:
    int numberOfArithmeticSlices(vector<int> &A)
    {
        long long count = 0;
        long long add = 0;
        for (long long i = 2; i < A.size(); ++i)
        {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
                count += ++add;
            else
                add = 0;
        }
        return count;
    }
};