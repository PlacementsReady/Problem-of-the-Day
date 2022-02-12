vector<int> largestValues(Node* root)
    {
        vector<int>ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int curr = INT_MIN;
            int size = q.size();
            for(int i=1;i<=size;i++){
                root = q.front();
                q.pop();
                
                curr = max(curr,root->data);
                
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            ans.push_back(curr);
        }
        return ans;
    }
