	public static void main(String[] args) {
		int a[] = new int[] { 1, 2, -1, 4, 5 };
		Stack<Integer> stk_ori = new Stack<Integer>();
		Stack<Integer> minStack = getMinStack(stk_ori, a);
		System.out.println(stk_ori.toString());
		System.out.println(minStack.toString());
		
	}
	
	public static Stack<Integer> getMinStack(Stack<Integer> ord,int[]elements){
		Stack<Integer> minStack = new Stack<Integer>();
		for(int i = 0; i < elements.length; i++){
			ord.add(elements[i]);
			if(minStack.empty()){
				minStack.add(elements[i]);
			} else {
				if(elements[i] < minStack.peek()){
					minStack.add(elements[i]);
				} else {
					minStack.add(minStack.peek());
				}
			}
			
		}
		
		
		return minStack;
	}
