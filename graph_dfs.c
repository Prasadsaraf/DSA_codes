#include <stdio.h>
#include <stdlib.h>

struct Node {
  int vertex;
  struct Node* next;
};

struct Node* createNode(int v);

struct Graph {
  int numVertices;
  int* visited;
  struct Node** adjacencyLists;
};

void depthFirstSearch(struct Graph* graph, int vertex)
{
  struct Node* adjList = graph->adjacencyLists[vertex];
  struct Node* temp = adjList;

  graph->visited[vertex] = 1;
  printf("Visited %d \n", vertex);

  while (temp != NULL) {
    int connectedVertex = temp->vertex;

    if (graph->visited[connectedVertex] == 0) {
      depthFirstSearch(graph, connectedVertex);
    }
    temp = temp->next;
  }
}

struct Node* createNode(int v)
{
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

struct Graph* createGraph(int numVertices)
{
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = numVertices;

  graph->adjacencyLists = malloc(numVertices * sizeof(struct Node*));

  graph->visited = malloc(numVertices * sizeof(int));

  int i;
  for (i = 0; i < numVertices; i++) {
    graph->adjacencyLists[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
  struct Node* newNode = createNode(dest);
  newNode->next = graph->adjacencyLists[src];
  graph->adjacencyLists[src] = newNode;
  newNode = createNode(src);
  newNode->next = graph->adjacencyLists[dest];
  graph->adjacencyLists[dest] = newNode;
}

void printGraph(struct Graph* graph)
{
  int v;
  for (v = 0; v < graph->numVertices; v++) {
    struct Node* temp = graph->adjacencyLists[v];
    printf("\n Adjacency list of vertex %d\n ", v);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}

int main() {
  struct Graph* graph = createGraph(4);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);

  printGraph(graph);

  depthFirstSearch(graph, 2);

  return 0;
}
