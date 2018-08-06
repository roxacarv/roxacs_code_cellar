//to do:
//- add resizing for the vertices arrays
//- test different logic to use a single adjacency list inside vertices
//- change GraphT array to a linked-list
//- create a DataT struct to hold different types of data
//- test different implementation (eg. adjacency matrix)
//- clean code


#include <stdio.h>
#include <stdlib.h>

typedef struct VertexT {
	char tag;
	int data;
	int size;
	struct VertexT * vertices;
} Vertex;

typedef struct GraphT
{
	char * name;
	int main_size;
	int size;
	int type;
	struct VertexT * vertices;
} Graph;

struct GraphT * create_graph(char * name, int type);
void free_graph(struct GraphT * graph);
void add_vertex(struct GraphT * graph, int data, char tag);
void print_graph(struct GraphT * graph);
void add_edge(struct GraphT * graph, char tagA, char tagB);

struct GraphT * create_graph(char * name, int type)
{
	struct GraphT * new_graph;
	new_graph->main_size = 10;
	new_graph = (struct GraphT*)malloc(sizeof(struct GraphT));
	new_graph->name = name;
	new_graph->size = 0;
	new_graph->type = type;
	new_graph->vertices = (struct VertexT*)malloc(new_graph->main_size * sizeof(struct VertexT));
	return new_graph;
}

void free_graph(struct GraphT * graph)
{
    int i;
    for(i = 0; i < graph->size; i++)
    {
        free(graph->vertices[i].vertices);
    }
	free(graph);
}

void add_vertex(struct GraphT * graph, int data, char tag)
{
    struct VertexT new_vertex;
    new_vertex.tag = tag;
    new_vertex.size = 0;
    new_vertex.data = data;
    new_vertex.vertices = (struct VertexT*)malloc(graph->main_size * sizeof(struct VertexT));
	graph->vertices[graph->size] = new_vertex;
	graph->size++;
}

void add_edge(struct GraphT * graph, char tagA, char tagB)
{
	int i;
	int indexA, indexB;
	for(i = 0; i < graph->size; i++)
	{
		if(graph->vertices[i].tag == tagA)
			indexA = i;
		if(graph->vertices[i].tag == tagB)
			indexB = i;
	}
	if(graph->type == 0)
    {
        int sizeA = graph->vertices[indexA].size;
        int sizeB = graph->vertices[indexB].size;
        struct VertexT vertexA = graph->vertices[indexA];
        struct VertexT vertexB = graph->vertices[indexB];
        graph->vertices[indexA].vertices[sizeA] = vertexB;
        graph->vertices[indexA].size++;
        graph->vertices[indexB].vertices[sizeB] = vertexA;
        graph->vertices[indexB].size++;
    }
}

void print_graph(struct GraphT * graph)
{
	int i, j;
	for(i = 0; i < graph->size; i++)
	{
	    int vertex_size = graph->vertices[i].size;
		if(vertex_size > 0)
        {
            for(j = 0; j < vertex_size; j++)
                printf("%c connects to %c\n", graph->vertices[i].tag, graph->vertices[i].vertices[j].tag);

        }
	}
}

int main()
{
	struct GraphT * graph = create_graph("Graph 1", 0);
	add_vertex(graph, 0, 'R');
	add_vertex(graph, 1, 'A');
	add_vertex(graph, 2, 'B');
	add_vertex(graph, 3, 'C');
	add_vertex(graph, 4, 'D');
	print_graph(graph);
	add_edge(graph, 'R', 'A');
	add_edge(graph, 'R', 'B');
	add_edge(graph, 'R', 'C');
	add_edge(graph, 'R', 'D');
	add_edge(graph, 'B', 'C');
	print_graph(graph);
	free_graph(graph);
	return 0;
}
