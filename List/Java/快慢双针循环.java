	public static boolean isLoop(Node head){
		Node f = head;
		Node s = head;
		if(f.next == null || f.next.next == null){
			return false;
		}
		
		f = f.next.next;
		s = s.next;
		
		
		
		while(f != s){
			if(f.next == null||f.next.next == null){
				return false;
			}
			
			f = f.next.next;
			s = s.next;
			
		}
		
//		System.out.println(f.data);
		Node p = head;
		while(p != s){
			p = p.next;
			s = s.next;
		}
		
		System.out.println(p.data);
		return true;
		
	}
