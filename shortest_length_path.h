///\file shortest_length_path.h
///\brief C library for the shortest path determination.
///
///Created by Anghel Florina-Catalina on 06/04/18.
#include <stdio.h>
#include <stdlib.h>

#ifndef SHORTEST_LENGTH_PATH_H_INCLUDED
#define SHORTEST_LENGTH_PATH_H_INCLUDED

void dijkstra(int *adjacency_matrix[], int *cost_matrix[], int no_vertices, int start_node, int destination_node);
void Floyd_Warshall(int *cost_matrix[], int no_vertices, int start_node, int destination_node);
void push_beginning(struct g_node *head, int new_element_value);
int pop_beginning_list(struct g_node * head);
int read_first_element_added(struct g_node *head);
void deleteStack(struct g_node *head);
#endif // SHORTEST_LENGTH_PATH_H_INCLUDED