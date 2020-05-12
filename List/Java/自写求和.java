package ds;

import java.util.ArrayList;
import java.util.HashSet;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		int a[] = new int[]{7,4,0,7,3};
		int b[] = new int[]{2,7,2,3,4};
		Node node1 = Load(a);
		Node node2 = Load(b);
		
		Sum(node1, node2,0);
		
		showLinkList(head);
		
		
	}
	public static Node head = new Node(0);
	public static Node p = head;
	public static Node pb = head;
	public static void Sum(Node op1, Node op2, int carry){
		if(op1 == null && op2 == null){
			if(carry == 1){
				p.data = 1;
			} else{
				pb.next = null;
			}
			return;
		}
		
		
		int tmp = op1.data + op2.data+carry;
		carry = 0;
		if (tmp >= 10){
			carry++;
			tmp -= 10;
		}
		
		p.data = tmp;
		p.next = new Node(0);
		pb = p;
		p = p.next;
		
		
		Sum(op1.next, op2.next, carry);
		

	}
	public static Node Sum2(Node op1, Node op2){
		Node res = new Node(op1.data+op2.data);
		Node op1_1 = op1.next;
		Node op2_1 = op2.next;
		Node p = res;
		while(op1_1 != null && op2_1 != null){
			p.next = new Node(op1_1.data + op2_1.data);
			p = p.next;
			op1_1 = op1_1.next;
			op2_1 = op2_1.next;
		}
		
		
		return res;
	}
	
	public static Node Load(int[]a){
		Node head = new Node(a[0]);
		int count = 1;
		Node p = head;
		while(count < a.length){
			p.next = new Node(a[count++]);
			p = p.next;
		}
		return head;
	}
	public static void showLinkList(Node head){
		
		while(head != null){
			System.out.println(head.data);
			
			head = head.next;
		}

		
	}

	public static class Node{
		public int data;
		public Node next;
		
		public Node(int data){
			this.data = data;
			this.next = null;
		}
		
	}
}
