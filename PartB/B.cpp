#include "B_classes.hpp"
#include "Validity_Support_Functions.hpp"
#include "Line_Validity.hpp"

/**
 * input number of arguments;
 * define array of strings to store them and their operator parts;
 * input each argument;
 * and convert it into postfix;
 * for each argument, check its validity;
 * even if one argument is not valid, display "INVALID"
 * else if all statements are valid, display "VALID";
 */
int main()
{
    int m; 
    cin >> m;                                                    
    string tmp, args[m], op[m];                                         
    for(int i = 0; i < m; i++)
    {
        cin >> tmp;                                                     
        GetPostfix(tmp, &args[i], &op[i], tmp.length());                
    }
    
    for(int i = 0; i < m; i++)                                          
        if(!LineValidity(args, op[i], i))                              
        {
            cout << "NOT VALID!" << '\n';
            return 0;
        }
    
    cout << "VALID!" << '\n';
    return 0;
}

/****************************************************************END_OF_PROGRAM********************************************************************/
