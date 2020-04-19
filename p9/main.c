#include <stdio.h>
#include <stdlib.h>

#define MAXNUM_VERTICES 100
#define Inf 1000000000
int finis_time[MAXNUM_VERTICES];
int time = 0;

typedef struct
{
    int n_vertices;
    int n_edges;
    int adjacency_matrix[MAXNUM_VERTICES][MAXNUM_VERTICES];
} Graph;

typedef enum {WHITE, GRAY, BLACK} COLOR;

int compare ( const void *pa, const void *pb ) {
    const int (*a)[2] = pa;
    const int (*b)[2] = pb;
    return (*a)[0] - (*b)[0];
}

void inisialisasi_graph(Graph *g, int n_v, int n_e)
{
    int i,j;

    g->n_vertices = n_v;
    g->n_edges = n_e;

    for (i = 0; i < MAXNUM_VERTICES; i++)
    {
        for (j = 0; j < MAXNUM_VERTICES; j++)
        {
            if(i < n_v && j < n_v)
            {
                // 1.
                g->adjacency_matrix[i][j] = 0;
            }
            else
            {
                // 2.
                g->adjacency_matrix[i][j] = -1;
            }
            
        }
        
    }
    
}

void print_adjacency_matrix(Graph *g)
{
    int i,j;
    for (i = 0; i < g->n_vertices; i++)
    {
        printf("\t%d", i);
    }
    printf("\n");

    for (i = 0; i < g->n_vertices; i++)
    {
        printf("%d", i);
        for (j = 0; j < g->n_vertices; j++)
        {
            printf("\t%d", g->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
        
}

int DFS_visit(Graph *g, COLOR *vertex_colors, int v)
{
    int i, cycle = 0;

    printf("%d time - %d\n", v, time);

    vertex_colors[v] = GRAY;

    time++;

    for (i = 0; i < g->n_vertices; i++)
    {
        if(g->adjacency_matrix[v][i] && vertex_colors[i] == GRAY)
        {
            printf("Cycle! between node %d and %d\n", v, i);
            cycle = 1;
        }
        // 5.
        if(g->adjacency_matrix[v][i] && vertex_colors[i] == WHITE)
        {
            cycle = DFS_visit(g, vertex_colors, i) || cycle;
        }
    }

    vertex_colors[v] = BLACK;
    time++;
    finis_time[v] = time;

    return cycle;
}

int DFS(Graph *g)
{
    COLOR vertex_colors[MAXNUM_VERTICES];
    int i, cycle = 0;
    for (i = 0; i < g->n_vertices; i++)
    {
        vertex_colors[i] = WHITE;
        finis_time[i] = Inf;
    }

    for (i = 0; i < g->n_vertices; i++)
    {
        if(vertex_colors[i] == WHITE)
        {
            cycle = DFS_visit(g, vertex_colors, i) || cycle;
        }
    }
    
    printf("\n");
    return cycle;
}

int main()
{
    int n_v = 0;
    int n_e = 0;
    int i,j, undirected = 0;
    int finish_array[MAXNUM_VERTICES][2] = {{0,0}};
    scanf("%d %d", &n_v, &n_e);

    Graph g;
    inisialisasi_graph(&g, n_v, n_e);

    for (i = 0; i < n_e; i++)
    {
        int a,b;
        scanf("%d %d", &a, &b);
        // 3.
        g.adjacency_matrix[a][b] = 1;
        if(undirected)
            g.adjacency_matrix[b][a] = 1;
    }

    print_adjacency_matrix(&g);

    int cycle = DFS(&g);
    
    if(cycle)
    {
        printf("Cycle \n");
        return 0;
    }

    for (i = 0; i < g.n_vertices; i++)
    {
        finish_array[i][0] = finis_time[i];
        finish_array[i][1] = i;
    }

    qsort(finish_array, g.n_vertices, sizeof(finish_array[0]), compare);

    for (i = 0; i < g.n_vertices; i++)
    {
        printf("v = %d, finish = %d\n", finish_array[i][1], finish_array[i][0]);
    }

    return 0;
}