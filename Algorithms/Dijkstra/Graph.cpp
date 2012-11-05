#include "Graph.hpp"
Graph::Graph(enum representation_t _rep, distribution_t _dist, int _num_vertices):adj_matrix(NULL), adj_list(NULL),num_vertices(_num_vertices),rep(_rep), dist(_dist)
{

	if (rep == ADJ_LIST)
	{
		adj_matrix = NULL;
		adj_list = new std::forward_list<std::pair<int, int> >[num_vertices];
	}	
}


void Graph::insert_edge(int v1, int v2, int e_wt)
{
	(adj_list[v1]).push_front(std::make_pair(v2, e_wt));
}

const int Graph::size()
{
	return num_vertices;
}

std::forward_list <std::pair<int, int> >& Graph::get_neighbours(int v)
{
	return adj_list[v];	
}	
