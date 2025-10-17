#include <stdio.h>
#define MAX 100  

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int element) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = element;
}

int dequeue() {
    if (front == -1 || front > rear) {
        
        return -1;
    }
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void resetQueue() {
    front = rear = -1;
}

void bfs(int graph[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};  
    
    resetQueue();  
    
    enqueue(start);
    visited[start] = 1;
    
    printf("BFS traversal starting from node %d: ", start);
    
    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);
        
        
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n; 
    printf("Enter number of nodes in the graph (max %d): ", MAX);
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of nodes. Must be between 1 and %d.\n", MAX);
        return 1;
    }

    int graph[MAX][MAX];
    
    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            
        }
    }
    
    int start;
    printf("Enter starting node for BFS (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (start < 0 || start >= n) {
        printf("Invalid starting node. Must be between 0 and %d.\n", n - 1);
        return 1;
    }
    
    bfs(graph, n, start);
    
    return 0;
}
