#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define inf 100000

//This function generates randomly the number of vertices
int generate_number_of_vertices(){
    int no_vertices;
    time_t t;

    srand((unsigned) time(&t));

    no_vertices = rand()%10;

    return no_vertices;
}

/*A function that generates a random number for a start/destination node*/
int generate_node(int no_vertices){
    int no_node;
    time_t t;

    srand((unsigned) time(&t));

    no_node = rand()%no_vertices;

    return no_node;
}

//This function generates the adjacency matrix
void build_adjacency_matrix(int *adjacency_matrix[], int no_vertices){
    int iterator_1;
    int iterator_2;

    for( iterator_1 = 0; iterator_1 < no_vertices; iterator_1++ ){
        adjacency_matrix[iterator_1] = calloc(no_vertices, sizeof(int));
    }

    for(iterator_1 = 0; iterator_1 < no_vertices; iterator_1++){
        for(iterator_2 = iterator_1 + 1; iterator_2 < no_vertices; iterator_2++){
            adjacency_matrix[iterator_1][iterator_2] = rand()%2;
            if(adjacency_matrix[iterator_1][iterator_2] == 1){
                adjacency_matrix[iterator_2][iterator_1] = 0;
            }else{
                adjacency_matrix[iterator_2][iterator_1] = rand()%2;
	     }
        }
    }

    //return adjacency_matrix;
}

/*This function generates the cost matrix based on the adjacency matrix*/
void build_cost_matrix(int *matrix[], int *adjacency_matrix[], int no_vertices){
    int iterator_1;
    int iterator_2;

    for(iterator_1 = 0; iterator_1 < no_vertices; iterator_1++ ){
        matrix[iterator_1] = calloc(no_vertices, sizeof(int));
    }

    for(iterator_1 = 0; iterator_1 < no_vertices; iterator_1++){
        for(iterator_2 = 0; iterator_2 < no_vertices; iterator_2++){
            if(iterator_2 != iterator_1){
                if(adjacency_matrix[iterator_1][iterator_2] == 1){
                    matrix[iterator_1][iterator_2] = rand()%100;
                }else {
                    matrix[iterator_1][iterator_2] = inf;
                }
            }
        }
    }

    //return matrix;
}

//A function that prints the adjacency matrix
void print_matrix(int *matrix[], int no_vertices){
    int iterator_1;
    int iterator_2;

    if(no_vertices == 0){
        printf("\nThe number of vertices is zero and this means that we can not build a adjacency matrix. ");
        exit(1);
    }else{
        printf("\nThe adjacency matrix is: \n");
        for(iterator_1 = 0; iterator_1 < no_vertices; iterator_1++){
            for(iterator_2 = 0; iterator_2 < no_vertices; iterator_2++)
                printf(" %d ", matrix[iterator_1][iterator_2]);
            printf("\n");
        }
    }
}

//A functions that prints the cost matrix
void print_cost_matrix(int *matrix[], int no_vertices){
    int iterator_1;
    int iterator_2;

    if(no_vertices == 0){
        printf("\nThe number of vertices is zero and this means that we can not build a cost matrix.");
	  exit(1);
    }else{
        printf("\nThe cost matrix is: \n");
        for(iterator_1 = 0; iterator_1 < no_vertices; iterator_1++){
            for(iterator_2 = 0; iterator_2 < no_vertices; iterator_2++)
            if(matrix[iterator_1][iterator_2] == inf){
                printf(" inf ");
            }else
                printf(" %d ", matrix[iterator_1][iterator_2]);
            printf("\n");
        }
    }
}
