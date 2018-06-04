///\file main.c
///\brief It is an implementation used to call all of the functions like Dijkstra or Floyd-Warshall.
///
///Created by Anghel Florina-Catalina on 6/5/2018

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"
#include "shortest_length_path.h"
#define inf 10000
///\def #define inf 100000
///\brief Define the maximum number possible as 100000

int main(){
    	///\fn int main()
    	///\brief This is the main function used to call all of the functions.
    	///
    	int no_vertices;
    	int start_node;
    	int destination_node;
    	int min;

    	time_t t;

    	no_vertices = generate_number_of_vertices();
    	printf("The number of vertices is: %d\n", no_vertices);

    	if(no_vertices == 0){
		printf("\nThe number of vertices is zero.");
		return 1;
    	}

    	if(no_vertices == 1){
		printf("\nThe number of vertices is 1 and it is impossible to find the minimum path.");
		return 1;
    	}

    	int *adjacency_matrix[no_vertices];
    	build_adjacency_matrix(adjacency_matrix, no_vertices);
    	print_matrix(adjacency_matrix, no_vertices);

    	int *matrix[no_vertices];
    	build_cost_matrix(matrix, adjacency_matrix, no_vertices); 
    	print_cost_matrix(matrix, no_vertices);

    	printf("\nThe random generated start_node is: ");
    	start_node = generate_node(no_vertices);
    	printf("%d", start_node);

    	printf("\nThe random generated destination_node is: ");
    	destination_node = generate_node(no_vertices);
    
    	redraw:
    	srand((unsigned) time(&t));
    	if((start_node == destination_node) || (destination_node > no_vertices)||(destination_node < 0)){
		destination_node = destination_node + rand()%(no_vertices/2);
		goto redraw;
    	}
    	printf("%d", destination_node);

    	printf("\n========== The Dijksta's Algorithm ===========");
    	dijkstra(adjacency_matrix, matrix, no_vertices, start_node, destination_node);
    	printf("\n========== The Floyd-Warshall Algorithm ==========="); 
    	Floyd_Warshall(matrix, no_vertices, start_node, destination_node);
 
    	free(matrix);
    	free(adjacency_matrix);
    	return 0;
}
