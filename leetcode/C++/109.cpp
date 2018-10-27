#include <climits>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(0) {}
};

class Solution
{
  public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        int length = 0;
        ListNode *node = head;
        while (node != NULL)
        {
            length++;
            node = node->next;
        }
        return insert(head, 0, length - 1);
    }
    TreeNode *insert(ListNode *&head, int beg, int end)
    {
        if (beg > end)
            return NULL;
        int mid = (end - beg) / 2 + beg;
        TreeNode *left = insert(head, beg, mid - 1);
        TreeNode *parent = new TreeNode(head->val);
        parent->left = left;
        head = head->next;
        TreeNode *right = insert(head, mid + 1, end);
        parent->right = right;
        return parent;
    }
};

int main()
{
    return 0;
}