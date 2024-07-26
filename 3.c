// #include <stdio.h>
#define MAX 20

int a[MAX][MAX], visited[MAX], reached[MAX], n;
int q[MAX], front = -1, rear = -1; 

void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (a[v][i] && !visited[i]) {
            printf("%d -> %d\n", v, i);
            dfs(i);
        }
    }
}

void bfs(int v) {
    front = rear = 0; 
    q[rear++] = v;
    reached[v] = 1;

    while (front < rear) {
        int current = q[front++];
        for (int i = 0; i < n; i++) {
            if (a[current][i] && !reached[i]) {
                q[rear++] = i;
                reached[i] = 1;
                printf("%d -> %d\n", current, i);
            }
        }
    }
}

int main() {
    int start;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        visited[i] = reached[i] = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the starting node: ");
    scanf("%d", &start);

    printf("\nDFS Traversal:\n");
    dfs(start);

    printf("\nBFS Traversal:\n");
    bfs(start);

    return 0;
}
