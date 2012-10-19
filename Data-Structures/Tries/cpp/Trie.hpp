#include <string>
#include <map>
using namespace std;

/* Class Vertex
 * 
 * Member Description:
 * 
 * (1) edges	=> Transition edges from a vertex (or 'state' in view of an automaton).
 * (2) words    => Number of words associated with this vertex in the dictionary.
 * (3) prefixes => Number of words in the dictionary for which the node is a prefix.
 */

class Vertex
{
	private:
		map<char, Vertex*> edges;
		unsigned int words;		
		unsigned int prefixes;	
	public:
		friend class Trie;		/* Vertex declares Trie as a friend */
		Vertex();	

};

class Trie
{
	private:
		Vertex* root;

	public:
		Trie();
		Vertex* getRoot();
		void insert(Vertex *v, string word);
		pair<bool, bool> remove(Vertex *v, string word);
		pair<bool, Vertex*> find(Vertex *v, string word);
		unsigned int countWords(Vertex *v, string word);
		unsigned int countPrefix(Vertex *v, string prefix);
};
