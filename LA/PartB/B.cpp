#include"B_classes.h"
#include"Validity_Support_Functions.h"
#include"Line_Validity.h"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

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
    IOS;
    int m; cin >> m;                                                    
    string tmp, args[m], op[m];                                         
    for(int i = 0; i < m; i++)
    {
        cin >> tmp;                                                     
        GetPostfix(tmp, &args[i], &op[i], tmp.length());                
    }
    
    for(int i = 0; i < m; i++)                                          
    {
        if(!LineValidity(args, op[i], i))                              
        {
            cout << "NOT VALID!" << endl;
            return 0;
        }
    }
    cout << "VALID!" << endl;
    return 0;
}

/****************************************************************END_OF_PROGRAM********************************************************************/