//




class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    
     
    int toSumTree(Node *node)
    {
        // Your code here
        if(!node){
            return 0;
        }
        
        int leftptr = toSumTree(node -> left);
        int rightptr = toSumTree(node -> right);
        
        int head = node -> data;
        node -> data = leftptr + rightptr;
        
        return leftptr + rightptr +head;
        
        
    }
};
