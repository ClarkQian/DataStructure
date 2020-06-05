public static TreeNode lca(TreeNode root, TreeNode p1, TreeNode p2){
		
		
		if(root == p1 || root == p2)
			return root; 
		
		boolean isLeft = isContain(root.left, p1);
		boolean isRight = isContain(root.right, p2);
		if(isLeft == isRight){
			return root;
		} else if(isLeft == true){
//			System.out.println(2);
			return lca(root.left,p1,p2);
		} else {//both on the right
			return lca(root.right,p1,p2);
		}

		
		
	}
	
	public static boolean isContain(TreeNode root, TreeNode child){
		
		if(root == null)
			return false;
		
		if(child == root)
			return true;
		
		boolean left = isContain(root.left, child);
		boolean right = isContain(root.right, child);
		
		
		return (left||right);
		
		
		
	}
