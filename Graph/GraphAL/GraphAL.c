#include <stdio.h>
#include <stdlib.h>
#include "GraphAL.h"

struct edge           			  // use two vertices to define edge
{
	Vertex v;		          // vertex v
	Vertex w;			  // vertex w
};

struct node
{						// define linked list for every vertex
	Vertex v;				// current vertex
	struct node *next;			// linked next vertex
};

typedef struct node *vertexList;

struct graphal
{			        // define a struct for graph first
	int numberVertex;       // record the number of vertex
	int numberEdge;         // record the number of edge
	vertexList *edges;	// recore all the vertex linked list / edges
};

GraphAL newGraph(int numberVertex)
{
	GraphAL g = NULL;
	g = malloc(sizeof(struct graphal));// malloc memory for graph
	if (g == NULL){
		fprintf(stderr, "newGraph error: no memory\n");
		exit(1);
	}else{				  // malloc memory for every linked list / vertex
		g->edges = malloc(sizeof(vertexList) * numberVertex);
		if (g->edges == NULL){
			fprintf(stderr, "newGraph error: no memory\n");
			exit(1);
		}
		int v = 0;
		for (v = 0; v < numberVertex; v++)
		{
			g->edges[v] = NULL;// we insert the head of the linked list
		}		           // so when we initialize the linked list this should be null
		g->numberVertex = numberVertex;
		g->numberEdge = 0;
	}
}

void showGraph(GraphAL g)
{
	if (g == NULL){
		printf("NULL graph\n");
	}else{
		printf("number of Vertex: %d, number of edges: %d\n", g->numberVertex, g->numberEdge);
		for (int v = 0; v < g->numberVertex; v++)
		{
			int nshown = 0;
			vertexList listV = g->edges[v];	// we start at the first nodes
			while (listV != NULL)
			{
				printf("<%d %d> ", v, listV->v);
				nshown++;
				listV = listV->next;
			}
			if (nshown > 0){
				putchar('\n');
			}
		}
	}
	return;
}

Edge newEdge(Vertex v, Vertex w)
{
	Edge e = NULL;
	e = malloc(sizeof(struct edge));// malloc memory for edge struct
	if (e == NULL){
		fprintf(stderr, "newEdge error: no memory\n");
		exit(1);
	}else{
		e->v = v;		// assign new vertex v
		e->w = w;		// assign new vertex w
	}
	return e;
}

void insertEdge(GraphAL g, Edge e)
{
	if (g == NULL){
		fprintf(stderr, "insertEdge error: graph not initialised\n");
	}else{
		if (!validV(g, e->v) || !validV(g, e->w)){// we need to check the vertex is valid
			fprintf(stderr, "insertEdge error: invalid vertices\n");
		}else{
			if (isEdge(g, e) == 0){		 // malloc memory for 2 vertex nodes
				vertexList n1 = malloc(sizeof(struct node));
				vertexList n2 = malloc(sizeof(struct node));
				if (n1 == NULL || n2 == NULL){ // malloc fail, prompt error message
					fprintf(stderr, "insertEdge error: no memory\n");
					exit(1);
				}
				n1->v = e->w;			// now we put w into v's linked list
				n1->next = g->edges[e->v];	// we put the new join vertex at the head
				g->edges[e->v] = n1;            // update g->edges[v]

				n2->v = e->v;  			// now we put v into w's linked list
				n2->next = g->edges[e->w];      // we put the new join vertex at the head
				g->edges[e->w] = n2;            // update g->edges[w]

				g->numberEdge++;                // update the number of edges
			}
		}
	}
}

void removeEdge(GraphAL g, Edge e)
{
	if (g == NULL){					       // null graph
		fprintf(stderr, "NULL graph\n");
	}else{
		if (!validV(g, e->v) || !validV(g, e->w)){
			fprintf(stderr, "removeEdge error: invalid vertex\n");
		}else{
			if (removeV(g, e->w, e->v) == 1){ // we need to check the edge exits or not
				g->numberEdge--;	  // if success then decrease the number of edge
				removeV(g, e->v, e->w);
			}
		}
	}
	return;
}

int isEdge(GraphAL g, Edge e)
{
	int edgeInGraphOne = 0, edgeInGraphtwo = 0;
	if(!validV(g, e->v) || !validV(g, e->w)){	  // check the vertex is valid or not
		fprintf(stderr, "isEdge error: vertex invalid\n");
		exit(EXIT_FAILURE);
	}else{
		if (g == NULL){				 // check the graph is null or not
			fprintf(stderr, "isEdge error: NULL graph\n");
			exit(EXIT_FAILURE);
		}
		vertexList listV = g->edges[e->v]; // now we check w is in v or not
		while (listV != NULL)
		{
			if (listV->v == e->w){	   // we find w in v
				edgeInGraphOne = 1;// set edgeInGrapfOne 1
				break;		   // stop loop
			}
			listV = listV->next;
		}
		vertexList listW = g->edges[e->w];// now we check v is in w or not
		while (listW != NULL)
		{
			if (listW->v = e->v){
				edgeInGraphtwo = 1;
				break;
			}
			listW = listW->next;
		}
	}

	return (edgeInGraphOne == 1 && edgeInGraphtwo == 1);
}

int validV(GraphAL g, Vertex v)
{
	int valid = 0;
	if (g == NULL){
		fprintf(stderr, "validV error: NULL graph\n");
		exit(0);
	}else{
		if (v >= 0 && v < g->numberVertex){
			valid = 1;
		}
	}
	return valid;
}

int removeV(GraphAL g, Vertex v, Vertex w)
{
	int success = 0;
	if (g == NULL){
		fprintf(stderr, "removeV error: NULL graph\n");
	}else{
		vertexList listV = g->edges[v], temp = NULL, preNode = NULL;
		while (listV->v != w && listV != NULL)
		{					    // firstly we need to find w in list v
			preNode = listV;		    // record the previous node of delete node
			listV =  listV->next;
		}
		if (listV != NULL && preNode != NULL){      // this means target node is the head
			temp = listV;
			preNode->next = listV->next;
			success = 1;
		}else if(listV != NULL && preNode == NULL){ // this means target node is the head
			g->edges[v] = listV->next;	    // new head
			success = 1;
		}
	}

	return success;
}
