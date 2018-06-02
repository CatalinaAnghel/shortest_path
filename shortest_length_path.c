#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define inf 10000

struct g_node{
	int info;
	struct g_node *next;
};

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

//This is a function used to print the path in Floyd-Warshall Algorithm
void push_begining(struct g_node *head, int new_element_value){
    struct g_node *new_element;
    struct g_node *next_element;

    next_element = head->next;
    new_element = malloc(sizeof(struct g_node));
    new_element->info = new_element_value;
    new_element->next = head->next;
    head->next = new_element;
}

//This is a function used to build the path in Floyd-Warshall Algorithm
int pop_begining_list(struct g_node *head){
    struct g_node *deleted_element;
    int aux;

    if (head->next != NULL) {
        deleted_element = head->next;
        aux = deleted_element->info;
        head->next = deleted_element->next;
        free(deleted_element);
        return aux;
    }else{
        printf("\n The stack is empty");
        return -1;
    }
}

int read_first_element_added(struct g_node *head){
    //In a stack, the first element addded will be the last element printed
    struct g_node *iterator = head;
    while(iterator->next != NULL){
        iterator = iterator->next;
    }

    return iterator->info;
}

void Floyd_Warshall(int *cost_matrix[], int no_vertices, int start_node, int destination_node){
	int iterator_1;
	int iterator_2;
	int iterator_3;
	int iterator_4;
	int aux;
	int var;
	char answear[4];
	int distance[no_vertices][no_vertices];
	int path[no_vertices][no_vertices];
	struct g_node *head_stack;
    	struct g_node *iterator_stack = head_stack;

    	head_stack = calloc(1, sizeof(struct g_node));
    	head_stack->next = NULL;

	// Initialize the solution matrix same as input graph matrix and the path matrix with zero.
	for(iterator_1 = 0; iterator_1 < no_vertices; iterator_1++){
		for(iterator_2 = 0; iterator_2 < no_vertices; iterator_2++){
			//The path matrix will be initialized with -1 to help in the path's buid
			path[iterator_1][iterator_2] = -1;
			distance[iterator_1][iterator_2] = cost_matrix[iterator_1][iterator_2];
		}
	}

	//This varible (var) will show if the vertex has not any connections with the vertices
	var = 0;
    	for(iterator_1 = 0; iterator_1 < no_vertices; iterator_1++){
        	if(distance[start_node][iterator_1] == inf){
            		var = var + 0;
        	}else{
			 var = 1;
		}    
	}	
    	if(var == 0){
        	printf("\nThe start vertex has no connection with another vertex");
        	exit(1);
    	}	

 	//Add all vertices one by one to the set of intermediate vertices.
	for (iterator_3 = 0; iterator_3 < no_vertices; iterator_3++){
        	// Pick all vertices as source one by one
        	for (iterator_1 = start_node; iterator_1 < no_vertices; iterator_1++){
           		 // Pick all vertices as destination for the above picked source
            		for (iterator_2 = 0; iterator_2 < no_vertices; iterator_2++){
                		// If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
		 		 for(iterator_4 = 0; iterator_4 < no_vertices; iterator_4++){
                			if (distance[iterator_1][iterator_3] + distance[iterator_3][iterator_2] < distance[iterator_1][iterator_2]){
                    				distance[iterator_1][iterator_2] = distance[iterator_1][iterator_3] + distance[iterator_3][iterator_2];
                    				path[iterator_1][iterator_2] = iterator_3;
                			}
				  }
            		  }
     		   }
    	 }

	// Print the shortest distance between the vertices 
	printf("\nThe path between the start vertex and the destination vertex is: ");
    	iterator_1 = start_node;
    	iterator_2 = destination_node;
    	printf("%d ->", start_node);
    	while(iterator_1 != destination_node && path[iterator_1][destination_node] != -1){
        	push_begining(head_stack, path[iterator_1][destination_node]);
        	iterator_2 = path[iterator_1][destination_node];
        	aux = iterator_2;
        	while(path[iterator_1][iterator_2] != -1){
           		push_begining(head_stack, path[iterator_1][iterator_2]);
            		iterator_2 = path[iterator_1][iterator_2];
        	}
        	if(path[iterator_1][iterator_2] == -1){
            		iterator_1 = aux;
            		while(head_stack->next!=NULL){
                		printf(" %d -> ", pop_begining_list(head_stack));
            		}
            		iterator_2 = destination_node;
        	}
    	}
    	printf(" %d", destination_node);
	printf("\nDo you want to print the path matrix generated by The Floyd-Warshall Algorithm?");
	printf("\nAnswear with Yes or No.\n");
	scanf("%s", answear);
	if(strcmp(answear, "Yes") == 0){
		for(iterator_1 = 0; iterator_1 < no_vertices; iterator_1++){
        		for(iterator_2 = 0; iterator_2< no_vertices; iterator_2++){
              			printf("%d  ", path[iterator_1][iterator_2]);
        		}
            		printf("\n");
   		 }
	}

    	free(head_stack);
}