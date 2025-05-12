/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void isvalid (TreeNode* root, long long l, long long r, bool &ok){
        if (root==NULL||ok==false){return;}
        if (root->val>l && root->val<r){
            isvalid(root->left,l,root->val,ok);
            isvalid(root->right,root->val,r,ok);
        }
        else {ok=false;}
    }
    bool isValidBST(TreeNode* root) {
        bool ok=true;
        isvalid(root,LLONG_MIN,LLONG_MAX,ok);
        return ok;
    }
};
