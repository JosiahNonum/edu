// Josiah Larimer
// COSC 2436
// program set 3


#include<iostream>
#include<vector>
#include<string>


using namespace std;

// from the textbook
struct TreeNode
{
	int value;
	TreeNode* left;
	TreeNode* right;

};


// inserts a node in the correct position
// from textbook
void insert(TreeNode* &nodePtr, TreeNode* &newNode)
{
	 if (nodePtr == nullptr)
		 nodePtr = newNode; // Insert the node.
		 else if (newNode->value < nodePtr->value)
			 insert(nodePtr->left, newNode); // Search the left branch.
		 else
			 insert(nodePtr->right, newNode); // Search the right branch.
}


// creates a node with an int value and then calls insert() to emplace it in the tree
// from textbook
 void insertNode(TreeNode*& nodePtr, int num)
 {
	 TreeNode * newNode = nullptr; // Pointer to a new node.
		
		 // Create a new node and store num in it.
		 newNode = new TreeNode;
		 newNode->value = num;
		 newNode->left = newNode->right = nullptr;
	
		 // Insert the node.
		 insert(nodePtr, newNode);
 }


 // tokenizes the inputed strings into int vectors
 void split(const string& s, char delim, vector<int>& tokens)
 {
	 size_t tokenStart = 0; // Starting position of the next token

		 // Find the first occurrence of the delimiter.
	 size_t delimPosition = s.find(delim);

	 // While we haven't run out of delimiters...
	 while (delimPosition != string::npos)
	 {
		 // Extract the token.
		 string tok = s.substr(tokenStart, delimPosition - tokenStart);

		 // Push the token onto the tokens vector.
		 tokens.push_back(atoi(tok.c_str()));

		 // Move delimPosition to the next character position.
		 delimPosition++;

		 // Move tokenStart to delimPosition.
		 tokenStart = delimPosition;

		 // Find the next occurrence of the delimiter.
		 delimPosition = s.find(delim, delimPosition);

		 // If no more delimiters, extract the last token.
		 if (delimPosition == string::npos)
		 {
			 // Extract the token.
			 string tok = s.substr(tokenStart, delimPosition - tokenStart);

			 // Push the token onto the vector.
			 tokens.push_back(atoi(tok.c_str()));
		 }
	 }
 }


 // compares the trees node by node to ensure they are the same structure
 bool compareBST(TreeNode*& root1, TreeNode*& root2)
 {
	 if (root1 == nullptr && root2 == nullptr)//if both branches terminate at the same time, all is good
		 return true;

	 if (root1 && root2)
	 {
		 // go one layer deeper
		 return (compareBST(root1->left, root2->left) && compareBST(root1->right, root2->right));
	 }

	 // only gets to this point if the trees aren't identical in structure
	 return false;
 }


int main() {


	bool cont = true;

	
	do
	{

		TreeNode* root1 = nullptr; // pointer to the root node
		TreeNode* root2 =  nullptr; // pointer to the root node


		// getting input
		string toBeInserted1 = "";
		string toBeInserted2 = "";
		cout << "Enter tree 1: ";
		getline(cin, toBeInserted1);
		cout << "Enter tree 2: ";
		getline(cin, toBeInserted2);

		// tokenizing the input and creating the trees
		vector<int> tokens1;
		split(toBeInserted1, ' ', tokens1);
		for (int i = 0; i < size(tokens1); i++)
		{
			insertNode(root1, int(tokens1[i]));
		}

		vector<int> tokens2;
		split(toBeInserted2, ' ', tokens2);
		for (int i = 0; i < size(tokens2); i++)
		{
			insertNode(root2, int(tokens2[i]));
		}

	
		// comparing the structures and outputing the result
		bool sameNode = compareBST(root1, root2);

		if (sameNode == true)
			cout << "\nSame structure.";
		else if (sameNode == false)
			cout << "\nNot same structure.";
		else
			cout << "derp";


		// asking the user whether they want to go again or not
		char contHold;
		cout << endl << endl << "Run Again (Y/N): ";
		cin >> contHold;

		if (contHold == 'y' || contHold == 'Y')
			cont = true;
		else
			cont = false;


		// clearing input buffer before proceeding
		cin.ignore(numeric_limits<streamsize>::max(), '\n');


	} while (cont == true);		// tests whether to continue outer do while loop
}