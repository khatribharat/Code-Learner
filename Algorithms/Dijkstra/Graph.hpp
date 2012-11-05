#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <forward_list>
enum distribution_t {EDGE, VERTEX};			/* denotes whether the graph is edge-weighted or vertex-weighted. */
enum representation_t {ADJ_MATRIX, ADJ_LIST};		/* denotes the type of representation used to represent the graph. */

class Graph
{
	private:	
		enum distribution_t dist;
		enum representation_t rep;
		bool is_directed;
		const int num_vertices;

		int **adj_matrix;
		/* list of forward lists */
		std::forward_list<std::pair <int, int> > *adj_list;
	public:
		Graph(enum representation_t _rep, enum distribution_t _dist, int num_vertices);
		void insert_edge(int v1, int v2, int e_wt);
		const int size();
		std::forward_list <std::pair<int, int> >& get_neighbours(int v);
};

#endif
