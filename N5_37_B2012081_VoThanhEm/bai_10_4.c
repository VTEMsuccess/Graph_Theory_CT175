//Ma tr?n k?" d�ng d? luu tr? c�c d? th? c� hu?ng 
//(c� th? ch?a da cung v� ch?a khuy�n).
#include <stdio.h>
#define MAX_N 100

typedef struct {
	int n,m;
	int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG,int n) {
	int i,j;
	pG->n = n;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			pG->A[i][j] = 0;
	pG->m = 0;
}

void add_edge(Graph *pG,int u,int v) {
	pG->A[u][v]++;
	pG->m++;
}

// Bai 10_4  (1<= u <=n)
int outdegree(Graph *pG, int u) {
	int i,j,deg = 0;
	for(i=1;i<=pG->n;i++){
		// Cong bac ra
		if(pG->A[u][i] !=0 && u!=i)
			deg += pG->A[u][i];
		// Cong bac ra cua khuyen
		if(pG->A[u][i] != 0 && u==i){
			for(j=1;j<=pG->A[u][i];j++)
				deg++;
		}
	}
	return deg;
} 
//

int main() {
	Graph G;
	int n,m;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	int i,j,u,v;
	for(i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	
	printf("Ma tran ke:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			printf("%d ",G.A[i][j]);
		printf("\n");
	}
	
	for(i=1;i<=n;i++){
		printf("deg_out(%d) = %d\n",i,outdegree(&G,i));
	}
	return 0;
}
