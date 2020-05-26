
	public static BTreeNode insert(BTreeNode root, int num) {

		BTreeNode p = null;
		BTreeNode cur = root;

		while (cur != null) {
			p = cur;
			if (num < cur.val) {
				cur = cur.left;
			} else if (num > cur.val) {
				cur = cur.right;
			} else {
				return root;
			}
		}
		
		cur = new BTreeNode(num);
		if(p == null){
			root = cur;
		} else if(num < p.val){
			p.left = cur;
		} else {
			p.right = cur;
		}
		return root;
	}
