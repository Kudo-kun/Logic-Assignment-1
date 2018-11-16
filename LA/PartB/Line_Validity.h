#include<bits/stdc++.h> 
using namespace std;

/**
 * The following function checks the validity of a given input wrt to the argument list it has and the line number specified;
 * It can check the validity of ^i, ^e1, ^e2, Vi, >e, MT;
 * In every case, 'getOpPos' returns the number length of the first part of the argument;
 * Has pairs 'p', 'q', to store the line numbers which will be specified;
 */ 
int LineValidity(string args[], string op, int index)
{
    pair<int , int> p, q;
    /**
     * If the operator specified is a premise, then it is always true;
     */
    if(op[0] == 'P')
        return 1;

    /**
     * If operator is an 'and';
     */
    else if(op[0] == '^')
    {
        /**
         * and operation performed is an introduction;
         * we check if both the arguments specified are valid, and hence is the result(args[index]);
         */
        if(op[1] == 'i')             
        {   
        	getOpPos(args[index]);
            p = ConvertToDec(op, 3); q = ConvertToDec(op, p.first + 1);
            if((check(args[index], args[p.second - 1], 1) && (args[p.second - 1].length()==cnt)) && (check(args[index], args[q.second - 1], 2) && (args[q.second-1].length() == (args[index].length() - cnt - 1))))
                return 1;    
        }
        /**
         * and operation performed is an elimination;
         * for ^e1: we check if args[index](current argument), is completely matches up with the first part of the prev argument specified;
         * for ^e2: we check if args[index](current argument), is completely matches up with the second part of the prev argument specified;
         */
        else if(op[1] == 'e')        
        {
            p = ConvertToDec(op, 4);
            getOpPos(args[p.second - 1]);
            if((op[2] == '1' && check(args[p.second - 1], args[index], 1)&&(args[index].length()==cnt)) || (op[2] == '2' && check(args[p.second - 1], args[index], 2) && (args[index].length() == (args[p.second-1].length() - cnt- 1))))
                return 1;
        }
    }

    /**
     * if operator is 'or';
     * for Vi1: we check if args[index](current argument), is completely derived from the first part of the prev argument specified;
     * for Vi2: we check if args[index](current argument), is completely derived from the second part of the prev argument specified;
     */
    else if(op.substr(0, 2) == "Vi")
    {
        getOpPos(args[index]);
        p = ConvertToDec(op, 4);
        if((op[2] == '1' && check(args[index], args[p.second - 1], 1) && (args[p.second-1].length() == cnt)) || (op[2] == '2' && check(args[index], args[p.second - 1], 2) && (args[p.second - 1].length() == (args[index].length() - cnt - 1))))
                return 1;
    }

    /**
     * if operator is 'implication';
     * we check if the second prev argument matches up completely with the first part of the first prev argument and,
     * args[index](current argument) matches up completely with the second part of the first prev argument;
     */
    else if(op.substr(0, 2) == ">e")
    {	
        p = ConvertToDec(op, 3); q = ConvertToDec(op, p.first + 1);
        getOpPos(args[p.second - 1]);
        if(check(args[p.second - 1], args[q.second - 1], 1)&& (args[q.second - 1].length() == cnt) && check(args[p.second - 1], args[index], 2) &&(args[index].length() == args[p.second - 1].length() - cnt - 1))
            return 1;
    }
    /**
     * if operation is 'MT';
     * we first check if an implication is involved in the first prev argument;
     * if yes, we check if second prev argument is the negation of the second part of the implication;
     * and if args[index](current argument) is the negation of the first part of the implication;
     */
    else if(op.substr(0, 2) == "MT")                                                    
    {
        p = ConvertToDec(op, 3); q = ConvertToDec(op, p.first + 1);                     
        string s1 = args[p.second - 1], s2 = args[q.second - 1];                        
        getOpPos(args[p.second - 1]); 
        if(s1.back() == '>' && s2.back() == '~' && s2.length() <= s1.length() && (s2.substr(0, s2.length() - 1) == s1.substr(s1.length() - s2.length(), s2.length() - 1)) && (s2.length() - 1 == s1.length() - cnt - 1))
            if(args[index].back() == '~' && (args[index].substr(0, args[index].length() - 1) == s1.substr(0, args[index].length() - 1)) && args[index].length() - 1 == cnt)
                return 1;                                                               
    } 
    /**
     * Else false, if none of the cases work;
     */
    return 0;
}
