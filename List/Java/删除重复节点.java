public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int[] a = new int[] { 1, 6, 7, 3, 6 };
		Node head = null;
		for (int i = 0; i < a.length; i++) {
			if (head == null) {
				head = new Node(a[i]);
				head.next = null;
			} else {
				Node p = head;
				while (p.next != null) {
					p = p.next;
				}
				p.next = new Node(a[i]);
			}
		}

		HashSet<Integer> hs = new HashSet<Integer>();
		Node p = head;
		Node b = p;
		while (p != null) {
			if (hs.contains(p.data)) {
				// delete it
				b.next = p.next;

			} else {
				hs.add(p.data);
			}
			b = p;
			p = p.next;

		}

		p = head;
		while (p != null) {
			System.out.println(p.data);
			p = p.next;
		}

	}

	private static class Node {
		int data;
		Node next;

		public Node(int data) {
			this.data = data;
			this.next = null;
		}

	}

}
