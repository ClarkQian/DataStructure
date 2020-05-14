	//1. 如果比aux的Peek小的话，aux只要比他大的都回去，之后tmp也回stk
  //2. 如果比aux的Peek大的话，放入aux
  
  public static Stack<Integer> stackSort(Stack<Integer>stk){
		
		Stack<Integer> aux = new Stack<Integer>();
		
		while(!stk.empty()){
			if(aux.empty()){
				aux.add(stk.pop());
			} else {
				Integer tmp = stk.pop();
				if(tmp < aux.peek()){
					while(aux.peek()>= tmp){
						stk.add(aux.pop());
						if(aux.empty())
							break;
					}
					stk.add(tmp);
				} else {
					aux.add(tmp);
				}
			}
		}
		
		return aux;
		
	}
