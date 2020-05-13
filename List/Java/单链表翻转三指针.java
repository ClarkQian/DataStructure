	public static Node reverse3(Node head) {

		Node p = head;
		Node q = head.next;
		p.next = null;
		while (q.next != null) {
			Node r = q.next;
			q.next = p;
			p = q;
			q = r;
		}
		q.next = p;
		return q;

	}
