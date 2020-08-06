#include <bits/stdc++.h> 
using namespace std;

/**
 * This funtion returns a pair of numbers,
 * first: the first line integer, second: the index where that number was encountered;
 */
pair<int, int> ConvertToDec(string s, int i)
{
    int t = 0;
    while(isdigit(s[i]))
    {
        t *= 10; 
        t += (s[i] - 48);
        i++;
    }
    return make_pair(i, t);
}

/**
 *This function checks if a part of the argument string matches the current string;
 *if parameter v = 1, it matches the first part;
 * else if matches the sencond part;
 */
int check(string args, string curr, int v)
{
    if(v == 1)
        return (curr == args.substr(0, curr.length()));
    else
        return (curr == args.substr(args.length()-curr.length()-1, curr.length()));
}

/**
 * This function creates a parse tree of the given argument;
 * varibale 'cnt' refers to the number of nodes on the left sub-tree; 
 * Once all leafs are appended;
 * an inorder traversal is made and all the nodes in the left sub-tree are counted;
 * and that value is returned;
 */ 
int getOpPos(string postfix)
{	
    
	Node* root = NULL;
	Tree* nt = new Tree(); cnt = 0;
	
	for(int i = postfix.length() - 1; i >= 0; i--)
    {
      	int appended = 0;
      	nt -> AppendLeaf(postfix[i], &root, &appended);
    }
    
    nt -> Traversal(&(root->left));
    return cnt;
}
    
