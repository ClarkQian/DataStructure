class Solution {

	public static class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;

		TreeNode(int x) {
			val = x;
		}
	}

	public static ArrayList<Integer> resCollection = new ArrayList<Integer>();
	public static int res = 0;

	public static void sumNumbers(TreeNode root) {

		res = res * 10 + root.val;
		if (root.left != null) {

			sumNumbers(root.left);
			res /= 10;
		}
		if (root.right != null) {

			sumNumbers(root.right);
			res /= 10;
		}

		if (root != null && root.left == null && root.right == null)
			resCollection.add(res);

	}

	public static void main(String[] args) {
		TreeNode root = new TreeNode(4);
		root.left = new TreeNode(9);
		root.right = new TreeNode(0);
		root.left.left = new TreeNode(5);
		root.left.right = new TreeNode(1);
		sumNumbers(root);
		System.out.println(resCollection);
	}

}
