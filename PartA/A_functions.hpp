#include <bits/stdc++.h>   
using namespace std;

/**
 * ind - index varible;
 * postfix - a string to hold the postfix noation of given string;
 */
int ind = 0;
string postfix;

/**
 * The following function checks if the given character is a an Operator, i.e, (^, V, >, ~) 
 */
int isOperator(char x)                                                     
{
    return (x == '~' || x == 'V' || x == '^' || x == '>');
}

/**
 * This function generates the postfix notation of the given infix string 
 */
void GetPostfix(string infix, int l)
{
    /**
     * stk - Stack of characters to store operators;
     * bracket - Variable to keep a count of the barckets;
     */
    stack<char> stk;                                                
    int bracket = 0;       
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
     */
    for(auto it : infix)
    {
        if(it == '(')                                         
            bracket++;                                                                                        
        else if(isalpha(it) && it != 'V')               
            postfix += it;                                    
        else if(isOperator(it))                               
            stk.push(it);                                     
        else if(it == ')')                                    
        {
            bracket--;                                              
            postfix += stk.top(); 
            stk.pop();                                 
        }  
    }
}


