	public static Node reverse2(Node head, Node before){
		
		if(head == null){
			return before;
		}
		Node p = head.next;
		head.next = before;
		return reverse2(p,head);
		
	}
