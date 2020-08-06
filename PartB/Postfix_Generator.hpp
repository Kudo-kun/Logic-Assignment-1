#include <bits/stdc++.h> 
using namespace std;

/**
 * The following function checks if the given character is a an Operator, i.e, (^, V, >, ~) 
 */
int isOperator(char x)
{
    return (x == '~' || x == 'V' || x == '^' || x == '>');
}

/**
 * This function generates the postfix notation of the given infix string and also separates the operator part of it;
 */
void GetPostfix(string infix, string *postfix, string *op, int l)
{
    /**
     * stk - Stack of characters to store operators;
     * bracket - Variable to keep a count of the barckets;
     */
    stack<char> stk;
    int bracket = 0, i = 0;


    
    /**
     * if an opening parentheses is encountered;
     * increment bracket count; 
     * elseif it's a alphabet but not 'V';
     * append it into the postfix string;
     * elseif it's a operator;
     * add it to the stack;
     * if a closing bracket is encountered;
     * decrement the number of brackets and;
     * append the last operator form the stack; 
     * 
     * At the end, take in the operator part into the op string for future reference;
     */
    while(i < l && infix[i] != '/')
    {
        if(infix[i] == '(')
            bracket++;
        else if(isalpha(infix[i]) && infix[i] != 'V')
            *postfix += infix[i];
        else if(isOperator(infix[i]))
            stk.push(infix[i]);
        else if(infix[i] == ')')
        {
            bracket--;
            *postfix += stk.top(); 
            stk.pop();
        } 
        i++;
    }
    *op = infix.substr(i+1, l);
}
