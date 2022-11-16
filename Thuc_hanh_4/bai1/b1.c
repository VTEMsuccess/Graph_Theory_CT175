#include <stdio.h>
#define Max_N 100
typedef int ElementType;
int mark[Max_N];
typedef struct {
	int A[Max_N][Max_N];
	int n;
} Graph;

typedef struct {
	int data[Max_N];
	int size;
} List;

typedef struct {
	int data[Max_N];
	int front;
	int Rear;
} Queue;

// <!------ List -------!>
void make_null(List *pL) {
	pL->size = 0;
}

void push_back(List *pL,int x) {
	pL->data[pL->size] = x;
	pL->size++;
}

int element_at(List *pL,int p) {
	return pL->data[p-1];
}

// void printList(List *pL) {
// 	int i;
// 	for(i=0; i<pL->size; i++)
// 		printf("%d ",pL->data[i]);
// 	printf("\n");
// }
// <!------ List -------!>

// <!------ Queue -------!>
void make_null_queue(Queue *pQ) {
	pQ->front = 0;
	pQ->Rear = -1;
}

void enQueue(Queue *pQ,int u) {
	pQ->Rear++;
	pQ->data[pQ->Rear] = u;

}

void deQueue(Queue *pQ) {
	pQ->front++;
}

ElementType front(Queue *pQ) {
	return pQ->data[pQ->front];
}

int emptyQueue(Queue *pQ) {
	return pQ->front > pQ->Rear;
}
// <!------ Queue -------!>

// <!------ Graph -------!>
void init_graph(Graph *G,int n) {
	int i,j;
	G->n = n;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			G->A[i][j] = 0;
}

void add_edge(Graph *pG,int x,int y) {
	pG->A[x][y] = 1;
}

// void printGraph(Graph G) {
// 	int i,j;
// 	for(i=1; i<=G.n; i++) {
// 		for(j=1; j<=G.n; j++)
// 			printf("%d ",G.A[i][j]);
// 		printf("\n");
// 	}
// }

/* topo sort */

void topo_sort(Graph *pG,List *pL){
	int d[Max_N];
	int u,x,v;
	for(u=1;u<=pG->n;u++){
		d[u] = 0;
		for(x=1;x<=pG->n;x++)
			if(pG->A[x][u] != 0)
				d[u]++;
	}
	
	Queue Q;
	make_null_queue(&Q);
	for(u=1;u<=pG->n;u++){
		if(d[u] == 0)
			enQueue(&Q,u);
	}
	
	make_null(pL);
	
	while(!emptyQueue(&Q)){
		int u = front(&Q);
		deQueue(&Q);
		push_back(pL,u);
		for(v=1;v<=pG->n;v++){
			if(pG->A[u][v] != 0){
				d[v]--;
				if(d[v] == 0)
					enQueue(&Q,v);
			}	
		}
	}
}

int main() {
	Graph G;
	int n,m,u,v,i;
	List sort;
	make_null(&sort);
//	freopen("test.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(i=1; i<=m; i++) {
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
//	printGraph(G);
	topo_sort(&G,&sort);
	for(i=1; i<=sort.size; i++) {
		int u = element_at(&sort,i);
		printf("%d ",u);
	}
	return 0;
}
