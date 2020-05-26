public static void levelTraverse(TreeNode<Integer> root) {

		LinkedList<TreeNode<Integer>> queue = new LinkedList<TreeNode<Integer>>();
		TreeNode<Integer> head = root;
		TreeNode<Integer> next = null;
		queue.add(root);
		while (!queue.isEmpty()) {
			TreeNode<Integer> tmp = queue.poll();
			System.out.printf(tmp.val+" ");
			if(tmp == root)
				System.out.println();
			if (tmp.children != null) {
				Boolean tag = false;
				if(tmp == head)
					tag = true;
				for (TreeNode<Integer> child : tmp.children) {
					queue.add(child);
					if(tag){
						next = child;
					}
				}
				tag = false;
				
			}

			if(tmp == next){
				System.out.println();
				head = next;
			}
			
		}
		return;
	}
