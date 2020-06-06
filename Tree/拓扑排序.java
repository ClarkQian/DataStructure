
	public static int n = 4;
	public static int[] visit = new int[n];
	public static int[] ToPo = new int[n];
	public static int t = n - 1;

	public static int[][] graph = { { 0, 1, 0, 0 }, { 0, 0, 0, 0 },
			{ 0, 1, 0, 0 }, { 0, 0, 1, 0 }, };


//只排序，不判断环
	public static void solve() {
		for (int i = 0; i < n; i++) {
			if (visit[i] == 0) {
				System.out.printf("%c\n",97+i);
				dfs(i);
			}
		}

	}
	//排序+判断环
	public static void solve2(){
		for(int i = 0; i < n; i++){
			if(visit[i] == 1)continue;
			boolean isLoop = dfs2(i);
			if(isLoop == false){
				System.out.println(false);
				return;
			}
			
		}
		for(int i = 0; i < n; i++){
			System.out.printf("%c ",ToPo[i]+97);
		}
		System.out.println();
		
	}
	
	public static boolean dfs2(int i){
		visit[i] = -1;
		for(int j = 0; j < n;j++){
			if(graph[i][j]> 0){
				if(visit[j] < 0) return false;
				if(visit[j] == 0 && dfs2(j) == false) return false;
			}
		}
		visit[i] = 1;
		ToPo[t--] = i;
		return true;
		
	}

	public static void dfs(int i) {

		for (int j = 0; j < n; j++) {
			if (graph[i][j] > 0 && visit[j]==0) {
				dfs(j);
			}
		}
		visit[i] = 1;
		ToPo[t--] = i;

	}
