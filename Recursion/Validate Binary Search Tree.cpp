class Solution {
public:
    int i = 1;
    tuple<bool, vector<int>> bstValid(TreeNode* node){
        bool cond = true;
        vector<int> res;
        vector<int> arr_l;
        vector<int> arr_r;
        if (node->left){
            cond = cond && ((node->left->val < node->val) ? true : false);
            if (cond) {
                bool bool_l;
                tie(bool_l, arr_l) = bstValid(node->left);
                cond = cond && bool_l;
            }
            i++;
        }
        if (node->right and cond){
            cond = cond && ((node->val < node->right->val) ? true : false);
            if (cond) {
                bool bool_r;
                tie(bool_r, arr_r) = bstValid(node->right);
                cond = cond && bool_r;
            }
        }
        if (!arr_l.empty()){
            if (*max_element(arr_l.begin(), arr_l.end()) >= node->val) cond = false;
        }
        if (!arr_r.empty()){
            if (*min_element(arr_r.begin(), arr_r.end()) <= node->val) cond = false;
        }
        if (!(arr_l.empty() or arr_r.empty())){
            if (!(*max_element(arr_l.begin(), arr_l.end()) < *min_element(arr_r.begin(), arr_r.end()))){
                cond = false;
            }
        }
        res.push_back(node->val);
        res.insert(res.end(), arr_l.begin(), arr_l.end());
        res.insert(res.end(), arr_r.begin(), arr_r.end());
        for (int i = 0; i < res.size(); i++){
            cout << res[i] << " " ;
        }
        cout << "-----" << endl;
        return make_tuple(cond, res);
    }
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        bool res;
        vector<int> _;
        tie(res, _) = bstValid(root);
        return res;
    }
};
/*
 *
 *Optimized Solution
 *
*/
class Solution {
public:
    bool isBSTUtil(TreeNode* root, TreeNode* min, TreeNode* max)
    {
        if(root == NULL)
            return true;
        if((min && root->val <= min->val) || (max && root->val >= max->val))
            return false;
        return isBSTUtil(root->left, min, root) && isBSTUtil(root->right, root, max);
    }
    bool isValidBST(TreeNode* root) {
        return isBSTUtil(root, NULL, NULL);
    }
};