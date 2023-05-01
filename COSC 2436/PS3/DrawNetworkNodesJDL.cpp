// Josiah Larimer
// COSC 2436
// program set 3
//
// reference: https://www.youtube.com/watch?v=dhgKr8942rs


#include<iostream>
#include <string>
#include<unordered_map>
#include<list>

using namespace std;



struct Graph {
	int V;
	// array of lists
	unordered_map<char, list<char>> l;

	// constructor
	Graph(int V) {
		this->V = V;
	}

	// adds an edge
	void addEdge(char x, char y)
	{
		l[x].push_back(y);
		l[y].push_back(x);
	}

	// prints the network
	void drawNetwork() {

		cout << endl; 

		// iterate over all the vertices
		for (char i = 'A'; i < (V + 65); i++)
		{
			if ((l[i].empty()))
			{
				i++;
				V++;
			}
			cout << "Node " << i << "-> ";
			for (char nbr : l[i])
			{
				cout << nbr << ",";
			}
			cout << endl;
		}
	}

};


// gets the node pairs from the user and shoves them into the graph
void networkInstantiater(Graph &g)
{		
		char name1, name2;
		cin >> name1 >> name2;

		if (name1 == '~' || name2 == '~')
			return;
		name1 = toupper(name1);
		name2 = toupper(name2);

		g.addEdge(name1, name2);

		networkInstantiater(g);
}


int main() {


	bool cont = true;
	

	/*
	g.addEdge('E', 'C');
	g.addEdge('G', 'E');
	g.addEdge('A', 'B');
	g.addEdge('B', 'F');
	g.addEdge('B', 'C');
	g.addEdge('F', 'G');
	g.addEdge('C', 'D');
	g.addEdge('D', 'A');
	*/

	
	do
	{

		
		// getting input from the user
		int num_nodes;
		cout << "Enter number of nodes: ";
		cin >> num_nodes;
		Graph g(num_nodes);
		cout << "Submit ~~ to escape" << endl << "Enter node pairs (edges): " << endl;
	
		// instantiating the network
		networkInstantiater(g);
		
		// printing the network
		cout << "The network: ";
		g.drawNetwork();



		// asking the user whether they want to go again or not
		char contHold;
		cout << endl << endl << "Run Again (Y/N): ";
		cin >> contHold;

		if (contHold == 'y' || contHold == 'Y')
			cont = true;
		else
			cont = false;

	} while (cont == true);		// tests whether to continue outer do while loop

	
}