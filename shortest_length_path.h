#include <stdio.h>
#include <stdlib.h>

#ifndef SHORTEST_LENGTH_PATH_H_INCLUDED
#define SHORTEST_LENGTH_PATH_H_INCLUDED

void dijkstra(int *adjacency_matrix[], int *cost_matrix[], int no_vertices, int start_node, int destination_node);
void Floyd_Warshall(int *cost_matrix[], int no_vertices, int start_node, int destination_node);
#endif // SHORTEST_LENGTH_PATH_H_INCLUDED