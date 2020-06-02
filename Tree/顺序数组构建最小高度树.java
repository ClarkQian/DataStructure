	public static TreeNode f(int[] a, int l, int r) {
		
		
		if(l > r)
			return null;
		
		int mid = l + ((r - l) >> 1);
		TreeNode lTree = f(a, l, mid - 1);
		TreeNode rTree = f(a, mid + 1, r);
		
		TreeNode res = new TreeNode(a[mid]);
		res.left = lTree;
		res.right = rTree;

		
		return res;
		
		
		
	}
