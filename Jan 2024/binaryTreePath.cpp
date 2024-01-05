/*Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

Example 1:


Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
Example 2:

Input: root = [1]
Output: ["1"]
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100*/

class Solution {
vector<string> res;
public:

    void helper(TreeNode* root,string s){
        if(!root){return;}
        if(s.empty()){s+=(to_string(root->val));}
        else{s=s+"->"+(to_string(root->val));}
        if(!root->left && !root->right){
            res.push_back(s);
        }
        helper(root->left,s);
        helper(root->right,s);
        // s.erase(s.end() - 3);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        helper(root,"");
        return res;
    }
};
