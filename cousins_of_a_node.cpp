class Solution
{
    public:
    struct node{
        Node*root;
        Node*par;
        int level;
    };
    vector<int> printCousins(Node* root, Node* node_to_find)
    {
        int level_of_node_to_find;
        Node* par_of_node_to_find;
        //node,parent,level
        queue<node>q;
        vector<vector<node>>levels;
        q.push({root,NULL,1});
        
        while(!q.empty()){
            int size = q.size();
            vector<node>elementsAtSameLevel;
            for(int i=0;i<size;i++){
                node curr_node = q.front();
                q.pop();
                
                
                root = curr_node.root;
                
                if(root == node_to_find){
                    level_of_node_to_find = curr_node.level;
                    par_of_node_to_find = curr_node.par;
                }
                
                int curr_level = curr_node.level;
                
                elementsAtSameLevel.push_back({root,curr_node.par,curr_level});
                
                if(root->left){
                    q.push({root->left,root,curr_level+1});
                }
                
                if(root->right){
                    q.push({root->right,root,curr_level+1});
                }
            }
            levels.push_back(elementsAtSameLevel);
        }
        
        vector<int>ans;
        
        for(auto x : levels[level_of_node_to_find-1]){
            if(x.par != par_of_node_to_find){
                ans.push_back(x.root->data);
            }
        }
        
        //if cousin doesnt exist
        if(ans.size() == 0){
            ans.push_back(-1);
        }
        
        return ans;
    }
    
};
