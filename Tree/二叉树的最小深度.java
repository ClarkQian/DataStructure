public int minDepth(TreeNode root){

  if(root == null){
    return 0;
  }
  
  int l = minDepth(root.left);
  int r = minDepth(root.right);
  
  if(l == 0 || r == 0)
    return 1 + r + l;
    
   return 1 + (l<r?l:r);
}
