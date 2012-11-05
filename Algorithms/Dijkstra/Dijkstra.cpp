#include "Graph.hpp"
#include <iostream>
#include <fstream>
#include <vector>

#define INT_MAX 1024*1024
using namespace std;

template <class T>
void copy_vector(vector<T> &src, vector<T> &dest)
{
	class vector<T>::iterator its, itd;
	for(its = src.begin(), itd = dest.begin(); its != src.end(); its++, itd++)
	{
		*itd = *its;
	}	
}	


/* check if 'old_v' and 'new_v' are different. */
template <class T>
bool isChange(vector<T> &old_v, vector<T> &new_v)
{
	class vector<T>::iterator ito, itn;
	for (ito = old_v.begin(), itn = new_v.begin(); ito != old_v.end(); ito++, itn++)
	{
		if (*ito != *itn)
			return true;
	}	
	return false;
}

/* print the 'distances' table used in the Dijkstra's algorithm. */
template <class T>
void print_table(vector<T> &v)
{
	char dummy;
	cout << "				TABLE 				" << endl;
	cout << "------------------------------------------------------------------" << endl;	
	class vector<T>::iterator it;
	for (it = v.begin(); it < v.end(); it++)
		cout << *it << "\t";
	cout << endl << "------------------------------------------------------------------" << endl;	
	cout << "continue(y/n): ";
	cin >> dummy;
	if (dummy == 'n')
		exit(1);
}	


/* find the smallest element in the 'distances' vector that has NOT be used before. */
void find_smallest(vector<int> distances, vector<bool> uncolored, int &next_src, int num_vertices)
{
	vector<int>::iterator it;
	int cur_src = -1;
	for(int i = 0; i < num_vertices; i++)
	{
		if (cur_src == -1 && uncolored[i])
			cur_src = i;
		else if ((distances[i] < distances[cur_src]) && uncolored[i])
			cur_src = i;
	}	
	next_src = cur_src;
}

/* Find the shortest path from 'src' and 'dest'. */
/* 'src' and 'dest' should be between 0 and num_vertices - 1. */
int Dijkstra(Graph &g, int src, int dest)
{
	int neighbour, edge_wt;
	int num_vertices = g.size();
	vector<int> distances(num_vertices, INT_MAX), old_distances(num_vertices, INT_MAX);
	vector<bool> uncolored(num_vertices, true);
	forward_list<pair<int, int> >::iterator it;

	int next_src = src;
	uncolored[next_src] = false;
	distances[next_src] = 0;						/* Not to *forget* this initialization. */
	forward_list<pair<int, int> > neighbours = g.get_neighbours(next_src);

	/* choose the next source and go for updating the vertices */
	do 
	{
		/* UNCOMMENT the line below to print the distance table at each step. */
		// print_table(distances); 
		
		/* copy 'distances' to 'old_distances' before going for the updation. */ 
		copy_vector<int>(distances, old_distances);
		
		for(it = neighbours.begin(); it != neighbours.end(); it++)
		{
			neighbour = (*it).first;
			edge_wt   = (*it).second;
		       	if (distances[neighbour] > distances[next_src] + edge_wt)			/* updation */
				distances[neighbour] = distances[next_src] + edge_wt;
		}

		find_smallest(distances, uncolored, next_src, num_vertices);
		if (next_src == -1)
		{	
			cerr << "No vertex left to be considered as a source." << endl;
			break;
		}	
		uncolored[next_src] = false;
		neighbours = g.get_neighbours(next_src);
	
	} while(isChange<int>(distances, old_distances));

	return distances[dest];
}


int main()
{
	int N,M, v, src, dest, e_wt, T;
	cout << "Dijkstra's Algorithm: ";
	ifstream input;
	input.open("input");
	if (input.is_open())
	{
		input >> T;
		while(T--)
		{
			/* take input */
			input >> N;
			Graph *g = new Graph(ADJ_LIST, EDGE, N);
			input >> src;
			input >> dest;
			for(int i = 0; i < N; i++)		/* take input for the neighbours of each vertex */
			{
				input >> M;
				for(int j = 0; j < M; j++)	/* take input for the jth neighbour of the ith vertex. */
				{
					input >> v;
				       	input >> e_wt;
					g->insert_edge(i, v, e_wt);		
				}	
			}
			/* take input */

			int distance = Dijkstra(*g, src, dest);
			if ( distance == INT_MAX )
				cout << "No path possible" << endl;
			else
				cout << "shortest path from " << src << " to " << dest << " is " << distance;
			delete g;
		}	
	
	}	
	input.close();	
	return 0;
}	
