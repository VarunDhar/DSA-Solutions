class Solution {
public:
    static bool comp(pair<int,int> &a, pair<int,int> &b)
    {
        if(a.first < b.first) return true;
        else if(a.first == b.first)
        {
            return a.second < b.second?true:false;
        }
        return false;
    }
    void fun(TreeNode* root, int row,int col,vector<vector<pair<int,int>>> &vec)//vector<vector<pair<int,int>>> &vec)
    {
        if(root==nullptr) return;
        vec[col+1000].push_back({row,root->val}); // adding thousand to make it easier to store negative indexes in array
        fun(root->left,row+1,col-1,vec);
        fun(root->right,row+1,col+1,vec);
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<pair<int,int>>> vec(2002); //as given, max number of nodes is 1000, so, if in worst case tree is skewed(left side)
                                                 //then the value of col (column) can go to -1000, so we will add 1000 to it, to help us with indexing
        vector<vector<int>> ans;
        fun(root,0,0,vec);
        for(int i=0;i<2002;i++)
        {
            if(vec[i].size()!=0)
            {
                vector<int> v;
                sort(vec[i].begin(),vec[i].end(),comp);
                for(int j=0;j<vec[i].size();j++)
                    v.push_back(vec[i][j].second);
                ans.push_back(v);
            }
        }
        return ans;
    }
};
