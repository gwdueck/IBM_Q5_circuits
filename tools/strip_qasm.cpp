//
//  strip_qasm.cpp
//  
//
//  Created by Gerhard Dueck on 2017-11-03.
//
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost;


int main(int, char**)
{
    string text;
    
    const char *kw[] = {"cx", "h", "s", "t", "x", "y", "z", "sdg", "tdg"};
    vector<string> key_words( kw, end(kw));
    string *key;
    
    while ( getline( cin, text ) ){
        char_separator<char> sep(",[]; ");
        tokenizer< char_separator<char> > tokens(text, sep);
        tokenizer< char_separator<char> >::iterator tok = tokens.begin();
        if(find(key_words.begin(), key_words.end(), *tok ) != key_words.end() )
        {
            bool two_qubits = tok->compare("cx") == 0;
            cout << *tok;
            tok++;
            cout << " "<< *(++tok);
            if( two_qubits )
            {
                tok++;
                cout << " "<< *(++tok);
            }
            cout << endl;

        }
    }
}
