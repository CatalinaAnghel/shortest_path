#include <stdio.h>
#include <stdlib.h>

#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

int generate_number_of_vertices();
int generare_node(int no_vertices);
void build_adjacency_matrix(int *adjacency_matrix[], int no_vertices);
void build_cost_matrix(int *matrix[], int *adjacency_matrix[], int no_vertices);
void print_matrix(int *matrix[], int no_vertices);
void print_cost_matrix(int *matrix[], int no_vertices);

#endif // MATRIX_H_INCLUDED