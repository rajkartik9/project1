#include<stdio.h>
#include<stdlib.h>

#define N 5

int graph[N][N] = { {0,1,1,0,0},
				    {1,0,0,1,0},
					{1,0,0,0,1},
					{0,1,0,0,0},
					{0,0,1,0,0}};

/*int graph[N][N] = { {0,1,0,0,0,0,0,0},
				    {1,0,1,0,0,0,0,0},
					{0,1,0,0,0,0,0,0},
					{0,0,0,0,1,0,1,0},
					{0,0,0,1,0,1,0,0},
					{0,0,0,0,1,0,1,0},
					{0,0,0,1,0,1,0,0},
					{0,0,0,0,0,0,0,0},
					};

*/					
int visited[N] = {0};

struct stack{
	int v;
	struct stack *next;
};

struct stack *top = NULL, *temp = NULL;

int search(int v){
		
	temp = top;
	if(top != NULL){
			while(temp){
				if(temp->v == v)
				 return 1;	
				temp = temp->next;	
			}
			return 0;
	}
	else
		return 0;	
}
void push(int v){
		
		if(search(v) == 0){
				temp = (struct stack*)malloc(sizeof(struct stack));
				temp->v = v;
				temp->next = NULL;
				
				if(top == NULL){
					top = temp;				
				}
				else{
					temp->next = top;
					top = temp;
				}
		}



int pop(){
		int v;
		if(top == NULL)
			return -1;
		v = top->v;
		top = top->next;
		return v;
}

int main(){

	int s, i, j,cycle=0;
	printf("Enter the starting vertex: ");
	scanf("%d", &s);
	push(s);

	printf("\nDFS of the above graph is: ");
	while(top != NULL){
		s = pop();
		printf("%d,", s);
		visited[s] = 1;		
			
		for (i = N - 1; i >= 0; i--)
				if(graph[s][i] == 1 && visited[i] == 0){
		 		push(i);
		 		else if(search(i)==1){
		 			cylce=1;
		 			printf("cycle is present");
		 			exit(0);
		 			}
		 		else if(graph[s][i] == 1 && visited[i] == 1){
		 			cylce=1;
		 			printf("cycle is present");
		 			exit(0);
		 			}	
		 			
				}
	}
	
	
}