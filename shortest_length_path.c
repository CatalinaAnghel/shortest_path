#include <stdio.h>
#include <stdlib.h>
#include "shortest_length_path.h"
#define inf 10000

void dijkstra(int *adjacency_matrix[], int *cost_matrix[], int no_vertices,int start_node, int destination_node){
    int distance[no_vertices];
    //to memorize the predecessor of the node
    int predecessor[no_vertices];
    //to mark the visited nodes
    int visited[no_vertices];
    //to count the number of visited nodes
    int count;
    int minimum_distance;
    int next_node;
    int iterator_1;
    int iterator_2;
    
    //put the cost in a vector
    for(iterator_1 = 0; iterator_1 < no_vertices; iterator_1++){
        distance[iterator_1] = cost_matrix[start_node][iterator_1];
        predecessor[iterator_1] = start_node;
        visited[iterator_1] = 0;
    }

    distance[start_node] = 0;
    visited[start_node] = 1;
    count = 1;

    while(count < no_vertices - 1){
        minimum_distance = inf;

        //nextnode gives the node at minimum distance
        for(iterator_1 = 0; iterator_1 < no_vertices; iterator_1++){
            if((distance[iterator_1] < minimum_distance) && (!visited[iterator_1])){
                minimum_distance = distance[iterator_1];
                next_node=iterator_1;
            }
    	   }

     	   //check if a better path exists through nextnode
        visited[next_node] = 1;
        for(iterator_1 = 0; iterator_1 < no_vertices; iterator_1++){
            if(!visited[iterator_1]){
                if(minimum_distance + cost_matrix[next_node][iterator_1] < distance[iterator_1]){
                    distance[iterator_1] = minimum_distance + cost_matrix[next_node][iterator_1];
                    predecessor[iterator_1]=next_node;
                }
            }
        }
        count++;
    }

    //print the path and distance
    for(iterator_1 = 0; iterator_1 < no_vertices; iterator_1++){
        if(iterator_1 != start_node){
            if(iterator_1 == destination_node){
                printf("\nThe distance between the source node and the node %d is %d ", iterator_1, distance[iterator_1]);
                printf("\nThe path is: %d", iterator_1);
                iterator_2 = iterator_1;
                do{
                    iterator_2 = predecessor[iterator_2];
                    printf(" <- %d", iterator_2);
                }while (iterator_2 != start_node);
            }
        }
    }
}

void Floyd_Warshall(int *cost_matrix[], int no_vertices, int start_node, int destination_node){
	int iterator_1;
	int iterator_2;
	int iterator_3;
	int iterator_4;
	int count[no_vertices][no_vertices];
	int distance[no_vertices][no_vertices];
	int predecessor[no_vertices][no_vertices][no_vertices];

	/* Initialize the solution matrix same as input graph matrix.*/
	for(iterator_1 = 0; iterator_1 < no_vertices; iterator_1++){
		for(iterator_2 = 0; iterator_2 < no_vertices; iterator_2++){
			distance[iterator_1][iterator_2] = cost_matrix[iterator_1][iterator_2];
		}
	}
	
	/* Add all vertices one by one to the set of intermediate vertices.*/
    for (iterator_3 = 0; iterator_3 < no_vertices; iterator_3++){
        // Pick all vertices as source one by one
        for (iterator_1 = start_node; iterator_1 < no_vertices; iterator_1++){
            // Pick all vertices as destination for the
            // above picked source
            for (iterator_2 = 0; iterator_2 < no_vertices; iterator_2++){
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
		  for(iterator_4 = 0; iterator_4 < no_vertices; iterator_4++){
                if (distance[iterator_1][iterator_3] + distance[iterator_3][iterator_2] < distance[iterator_1][iterator_2]){
			    count[iterator_1][iterator_2] += 1;
                    distance[iterator_1][iterator_2] = distance[iterator_1][iterator_3] + distance[iterator_3][iterator_2];
                    predecessor[iterator_1][iterator_2][iterator_4] = iterator_3;
                }
				else{
				predecessor[iterator_1][iterator_2][iterator_4] = iterator_2;
				count[iterator_1][iterator_2] += 1;
		}
		}
            }
        }
    }
	// Print the shortest distance between the vertices 
    printf("\nThe shortest path is:\n");
    for(iterator_2 = 0; iterator_2 < count[start_node][destination_node]; iterator_2++){
        printf(" %d ", predecessor[start_node][destination_node][iterator_2]);
	}
    printf("\n");
    printf("\nThe distance is: %d", distance[start_node][destination_node]);
}