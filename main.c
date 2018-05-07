#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"
#include "shortest_length_path.h"
#define inf 10000

int main(){
    int no_vertices;
    //int iterator_1;
    //int iterator_2;
    int start_node;
    int destination_node;
    int min;

    time_t t;

    srand((unsigned) time(&t));
    no_vertices = generate_number_of_vertices();
    printf("The number of vertices is: %d\n", no_vertices);

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
    printf("%d", destination_node);

    dijkstra(adjacency_matrix, matrix, no_vertices, start_node, destination_node);
    
    free(matrix);
    free(adjacency_matrix);
    return 0;
}
