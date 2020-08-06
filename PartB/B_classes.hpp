#include <bits/stdc++.h> 
#include "Postfix_Generator.hpp"
using namespace std;


/**
 * cnt - a variable to keep count of number of nodes on the left/right sub-tree;
 */
int cnt = 0;
class Node
{
    /**
     * Tree Node contains a character(data);
     * and two pointers which will point to the left and right sub-trees respectively;
     * Both pointers are initialized to null initially;
     */
    public:
        char data;                                                  
        Node* left, *right;                                         
        
        /**
         * Constructor
         */
        Node(char x)                                               
        { 
            data = x; 
            left = NULL; 
            right = NULL; 
        }                   
};


class Tree
{
    public:
        /**
         * The following function appends a new leaf(node) to the tree;
         * Parameters: data of the node(ch), address of a node(**pos), flag variable to check if a new node has been appended or not(appended);
         */
        void AppendLeaf(char ch, Node** pos, int* appended)                                 
        {
            /**
             * if the following pointer of a node(right or left) points to null;
             * create a new node at that location with data ch;
             * append that node to the tree, and flag varibale is made 1, i.e, the node has been appended;
             * else if the pointer points to a node with data '~';
             * the next node is appended only to its right, as it is a unary operator;
             * if it's a binary operator;
             * we try to append it to the right first;
             * but if the right sub-tree is already blocked, i.e, already contains a full formula, i.e, the node hasn't been appended to right sub-tree;
             * we try to append the leaf(node) to the left sub-tree;
             */
            if(*pos == NULL)                                                        
            {
                Node* tmp = new Node(ch);                                           
                *pos = tmp; *appended = 1;                                          
                return;
            }
            else
            {
                if((*pos) -> data == '~')                                          
                    AppendLeaf(ch, &((*pos) -> right), appended);                    

                else if((*pos) -> data  != '~' && isOperator((*pos) -> data))       
                {
                    AppendLeaf(ch, &((*pos) -> right), appended);                   
                    if(!(*appended))                                                
                        AppendLeaf(ch, &((*pos) -> left), appended);                
                }
            }
        }

        /**
         * The following functions gives us an in-order traversal of the tree
         * Parameters: Address of root node(**pos)
         */
        void Traversal(Node** pos)
        {
            /**
             * if a last leaf if encountered;
             * return back to previous leaf; 
             * first recursively traverse the left subtree completely till we hit the last node on the left side;
             * after returning, increment the count of nodes(which is initially zero);
             * then traverse the right sub-tree of that node;
             */
            if(*pos == NULL)                                                        
                return;                                                                                             
            else
            {
                Traversal(&((*pos) -> left));                                       
                cnt++;                                            
                Traversal(&((*pos) -> right));                                      
            }
        }
};

