//欧拉道路和欧拉回路的区分是（奇数度的个数是1，2 -> 有欧拉道路；否则没有）
package pblem;

public class EulerCircuit {
	
	public static int n = 4;
	public static int[][]graph = new int[][]{
		{0,1,2,1},
		{1,0,0,0},
		{2,0,0,1},
		{1,0,1,0}
	};
	public static int[][]visit = new int[n][n];
	
	public static void dfs(int v){
		//the other side is w
		
		for(int i = 0; i < n; i++){
			if(graph[v][i]>0 && visit[v][i] < graph[v][i]){
				visit[v][i]++;
				visit[i][v]++;
				dfs(i);
				System.out.printf("%c -> %c \n",(char)(97+v),(char)(97+i));
			}
		}
		
		
	}
	
	public static void main(String[] args) {
		dfs(1);
	}

}
