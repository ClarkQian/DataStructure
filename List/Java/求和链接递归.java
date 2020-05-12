	public static void main(String[] args) {
		int a[] = new int[] { 7, 4, 0, 7, 5 };
		int b[] = new int[] { 2, 7, 2, 3, 4 };
		Node node1 = Load(a);
		Node node2 = Load(b);

		Node res = Sum3(node1, node2, 0);

		showLinkList(res);

	}

	public static Node Sum3(Node op1, Node op2, int carry) {
		if (op1 == null && op2 == null && carry == 0) {
			return null;
		}
		int value = carry;
		if (op1 != null) {
			value += op1.data;
		}
		if (op2 != null) {
			value += op2.data;
		}
		Node res = new Node(value % 10);

		res.next = Sum3(op1 == null ? null : op1.next, op2 == null ? null : op2.next,
				value >= 10 ? 1 : 0);

		return res;

	}
