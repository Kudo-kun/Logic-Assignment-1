#include"A_functions.h"
#include"A_classes.h" 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long int

/**
 * create a root node;
 * instantiate the tree class;
 * read the infix string;
 * generate its postfix notation and print it;
 * append the nodes with data as characters of the string(in reverse order);
 * flag variable(appended) is always intially zero, signifying that no node has been appended till now;
 * traversing the tree in an inorder fashion, to get required result;
 */
int main()
{
    IOS;        
    Node* root = NULL;                                                      
    Tree* nt = new Tree();                                                  
    string infix;                                                           
    
    cin >> infix;                                                           
    GetPostfix(infix, infix.length());                                      
    cout << "Postfix of given string is: " << postfix << endl;
     
    for(int i = postfix.length() - 1; i >= 0; i--)                          
    {
      int appended = 0;                                                     
      nt -> AppendLeaf(postfix[i], &root, &appended);                      
    }
    
    cout << "Inorder Traversal of the parse tree is: ";
    nt -> Traversal(&root); cout << endl;                                   
    return 0;
}

/*************************************************************END_OF_PROGRAM***************************************************************************/