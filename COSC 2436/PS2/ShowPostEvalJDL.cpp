// Josiah Larimer
// COSC 2436
// program set 2
//
// used a modification https://www.geeksforgeeks.org/print-stack-elements-from-bottom-to-top/ for the PrintStack function to print the stacks

#include<iostream>
#include<stack>
#include<string>
#include<string.h>


using namespace std;


// Recursive function to print stack elements
// from bottom to top without changing their order
// a modification of https://www.geeksforgeeks.org/print-stack-elements-from-bottom-to-top/
void PrintStack(stack<char> s)
{
	// If stack is empty then return
	if (s.empty())
		return;


	int x = s.top();

	// Pop the top element of the stack
	s.pop();

	// Recursively call the function PrintStack
	PrintStack(s);

	// Print the stack element starting from the bottom		
	cout << x << " ";		

	// Push the same element onto the stack to preserve the order
	s.push(x);
}


// does mathematical operations
int operationater(char op, char z, char y)
{
	switch (op)
	{
	case '+': return(y + z); break;
	case '-': return(y - z); break;
	case '*': return(y * z); break;
	case '/': return(y / z); break;
	}
}



int main() {


	bool cont = true;


	do
	{
		
		string equation;

		stack<char> original;		

		// getting input
		cout << endl << "Enter a postfix expression: ";
		getline(cin, equation);
		cout << endl << "Stack Contents:" << endl << endl;

		// evaluating and operating on the users equation
		for (int i = 0; i < equation.size() || (i + 1) < equation.size() ; i +=2)
		{
			if (equation[i] > '0' && equation[i] < '9')
			{
				original.push(equation[i] - '0');
				cout << "After push operation: ";
				PrintStack(original);
			}
			else
			{
				char op, y, z, result;
				cout << "After " << equation[i] << " operation: ";
				op = equation[i];
				y = original.top();
				original.pop();
				z = original.top();
				original.pop();

				result = operationater(op, y, z);
				original.push(result);
				PrintStack(original);
			}						
			cout << endl;
		}

		
		// printing final value
		cout << endl << "Final Value: ";
		PrintStack(original);


		// asking the user whether they want to go again or not
		char contHold;
		cout << endl << endl << "Run Again (Y/N): ";
		cin >> contHold;

		// clearing input buffer before proceeding
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (contHold == 'y' || contHold == 'Y')
			cont = true;
		else
			cont = false;

	} while (cont == true);		// tests whether to continue outer do while loop
}