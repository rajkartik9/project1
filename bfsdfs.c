#include<stdio.h>
#include<stdlib.h>
int main(){
	int v;
	printf("\nenter the total no of vetices in the graph");
	scanf("%d",&v);
	int stack[v];
	int visited[v];
	int unvisited[v];
	int adj[v+1][v+1];
	printf("\nenter the vertices adjacent to each vertice");
for(int i=0;i<v;i++){
	int j;
	printf("\nenter no of vertices adjacent to %d:",i);
	scanf("%d",&j);
	printf("\nenter the vertices adjacent to %d:",i);
	int k;
	for(int k=0;k<=j;k++){
		if(k==0){
		 	adj[i][0]=i;
		 	k++;
		 	continue;
		 }	
		printf("\nenter vertex:");
		scanf("%d",&adj[i][k]);
		if(k==j)
			adj[i][j+1]=-1;
	}
}
printf("the graph you have entered is:\n");

for(int i=0;i<v;i++){
	int j=0;
	while(adj[i][j]!=-1){
	printf("%3d",adj[i][j]);
	printf("->");
	j++;
	}
	printf("\n");
}			
			
}		
			
