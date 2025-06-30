/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int i = 0, j = 0, firstx = 0, lastx = m - 1, firsty = 0, lasty = n - 1;
        vector<vector<int>> v(m, vector<int>(n, -1));
        while (head && firstx <= lastx && firsty <= lasty) {
            while (head && j <= lasty) {
                v[i][j++] = head->val;
                head = head->next;
            }
            i++, j--;
            while (head && i <= lastx) {
                v[i++][j] = head->val;
                head = head->next;
            }
            i--, j--;
            while (head && firsty <= j) {
                v[i][j--] = head->val;
                head = head->next;
            }
            i--, j++;
            while (head && firstx < i) {
                v[i--][j] = head->val;
                head = head->next;
            }
            i++, j++;
            firstx++, lastx--;
            firsty++, lasty--;
        }
        return v;
    }
};