#include "Trie.hpp"

Vertex::Vertex(): words(0), prefixes(0)
{
}	


Trie::Trie(): root(new Vertex)
{
}	

Vertex* Trie::getRoot()
{
	return root;
}	


void Trie::insert(Vertex *v, string word)
{
	if(word.empty())
		v->words += 1;

	else
	{	
		v->prefixes += 1;
		char k = word[0];	
		if (v->edges.find(k) == v->edges.end())
		{
			/* Insert a new entry in 'edges' */
			v->edges[k] = new Vertex;
		}	

		insert(v->edges[k], word.substr(1));		
	}	
}	

/* return value: is a pair of boolean values: (found, del)
 * found => is true if the word to be removed exists in the dictionary (or trie) and false otherwise.
 * del => is true if the vertex 'v' passed to the remove() function was deleted from the trie as a consequence of the removal of a word. 
 */

pair<bool, bool> Trie::remove(Vertex *v, string word)
{
	if (word.empty())
	{
		if (v->words == 0)
			return pair<bool, bool> (false, false);
		
		else
		{	
			v->words -= 1;
			if (v->words == 0 && v->prefixes == 0)
			{
				delete v;
				return pair<bool, bool> (true, true);
			}	
			return pair<bool, bool> (true, false);
		}	
	}
	else
	{ 	
		char k = word[0];
		map<char, Vertex*>::iterator it = v->edges.find(k);
		if (it == v->edges.end())
		{
			return pair<bool,bool> (false, false);
		}
	
		pair<bool, bool> res;	
	       	res = remove(v->edges[k], word.substr(1));
		bool found = res.first, del = res.second;

		if (found)
		{
			v->prefixes -= 1;
			if (del)
				v->edges.erase(it);
				
			if (v->prefixes == 0 && v->words == 0)
			{
				delete v;
				return pair<bool, bool> (true, true);	
			}
			return pair<bool, bool> (true, false);
		}	
	
		return pair<bool, bool> (false, false);	
	}	
}

pair<bool, Vertex*> Trie::find(Vertex *v, string word)
{
	if (word.empty())
		return pair<bool, Vertex*> (true, v);
	else
	{
		char k = word[0];
		if ((v->edges).find(k) == (v->edges).end())
			return pair<bool, Vertex*> (false, NULL);
		return find(v->edges[k], word.substr(1)); 
	
	}	
}	


unsigned int Trie::countWords(Vertex *v, string word)
{
	pair<bool, Vertex*> res = find(v,word);
	if (res.first)
		return (res.second)->words;
	else
		return 0;	
}


unsigned int Trie::countPrefix(Vertex *v, string prefix)
{
	pair<bool, Vertex*> res = find(v,prefix);
	if (res.first)
		return (res.second)->prefixes;
	else
		return 0;	

}	


