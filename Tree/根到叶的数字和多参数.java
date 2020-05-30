public static void dfs(String pre, TreeNode root){
		
		if(root == null){
			return;
		} 
		
		pre += root.val;
		
		
		if(root.left != null){
			dfs(pre, root.left);
		}
		
		if(root.right != null){
			dfs(pre, root.right);
		}
		
		
		if(root.left == null && root.right == null){
			res2.add(pre);
		}
		
		
		
		
		
		
	}
