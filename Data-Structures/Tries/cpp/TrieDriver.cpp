#include <iostream>
#include <string>
#include "Trie.hpp"
using namespace std;

void printOptions()
{
	cout << "1. Insertion: I" << endl;
	cout << "2. Search: S" << endl;
	cout << "3. Deletion D" << endl;
	cout << "4. Word count: W" << endl;
	cout << "5. Prefix count: P" << endl;	
	cout << "6. Exit: X" << endl;
}	

int main()
{
 	cout << "Trie Demonstration" << endl;
	char opt;	
	string word;
	Trie t;

	while (1)	
	{
		cout << endl;
		printOptions();	
		cin >> opt;

		switch(opt)
		{
			case 'I':
				{
		        		cout << "Enter the word to insert : ";
					cin >> word;
					t.insert(t.getRoot(), word);		
					break;
				}	
			case 'S':
				{
		        		cout << "Enter the word to search : ";
					cin >> word;
					pair<bool, Vertex*> res = t.find(t.getRoot(), word);
					if (res.first)
						cout << ".:: Found ::." << endl;
					else
						cout << ".:: Not Found ::." << endl;
					break;
				}
			case 'D':
				{
					cout << "Enter the word to delete :";
					cin >> word;
					t.remove(t.getRoot(), word);
					break;
				}	
			case 'W':
				{
		        		cout << "Enter the word to count : ";
					cin >> word;
					cout << endl << "Word count = " << t.countWords(t.getRoot(), word) << endl;	
					break;
				}
			case 'P':
				{
		        		cout << "Enter the prefix to count : ";
					cin >> word;
					cout << endl << "Prefix count = " << t.countPrefix(t.getRoot(), word) << endl;
					break;
				}	
		
			case 'X':	
				{
					return 0;
				}
			default:
				{
					cout << endl << "Invalid option" << endl;
				}
		}	
		
	}
}	
