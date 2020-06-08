class Solution {
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[][]graph2 = new int[n][n];
        for(int i = 0 ;i < n; i++){
            for(int j = 0;j < graph[i].length;j++){

                graph2[i][graph[i][j]] = 1;
            }
        }
        int[]colors = new int[n];

        for(int i= 0 ; i < n; i++){
            if(colors[i] == 0){
                boolean res = dfs(graph2,colors,i,1);
                if(res == false)
                    return false;
            }
        }

        return true;
        
    }

    public boolean dfs(int[][]graph, int[]colors, int k, int c){//the k point
        colors[k] = c;
        for(int j = 0; j< graph.length; j++){
            if(graph[k][j] == 0)
                continue;
            if(colors[j] == c){
                return false;
            }
            if(colors[j] == 0){
                boolean res = dfs(graph,colors,j,-c);
                if(res == false)
                    return false;
            }             
        }
        return true;
    }

}
