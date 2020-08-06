#include "A_functions.hpp"
#include "A_classes.hpp" 

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
    Node* root = NULL;                                                      
    Tree* nt = new Tree();                                                  
    string infix;                                                           
    
    cin >> infix;                                                           
    GetPostfix(infix, infix.length());                                      
    cout << "Postfix of given string is: " << postfix << '\n';
     
    for(int i = postfix.length() - 1; i >= 0; i--)                          
    {
        int appended = 0;                                                     
        nt -> AppendLeaf(postfix[i], &root, &appended);                      
    }
    
    cout << "Inorder Traversal of the parse tree is: ";
    nt -> Traversal(&root); 
    cout << '\n';                                   
    return 0;
}

/*************************************************************END_OF_PROGRAM***************************************************************************/
