public static Stack<Node> stk = new Stack<Main.Node>();

	public static Node reverse(Node head) {

		while (head != null) {
			stk.add(head);
			head = head.next;
		}
		Node p = stk.pop();
		Node newHead = p;
		while (!stk.empty()) {
			Node node1 = stk.pop();
			p.next = node1;
			p = p.next;
		}
		p.next = null;
		return newHead;
	}
