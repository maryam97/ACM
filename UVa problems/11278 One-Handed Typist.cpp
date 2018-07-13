//
// Created by maryam on 9/6/17.
//
//#define Q11278
#ifdef Q11278

#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    string str;
    map<char,char> m;
    m['1'] = '1';
    m['2'] = '2';
    m['3'] = '3';
    m['4'] = 'q';
    m['5'] = 'j';
    m['6'] = 'l';
    m['7'] = 'm';
    m['8'] = 'f';
    m['9'] = 'p';
    m['0'] = '/';
    m['-'] = '[';
    m['='] = ']';
    m['q'] = '4';
    m['w'] = '5';
    m['e'] = '6';
    m['r'] = '.';
    m['t'] = 'o';
    m['y'] = 'r';
    m['u'] = 's';
    m['i'] = 'u';
    m['o'] = 'y';
    m['p'] = 'b';
    m['['] = ';';
    m[']'] = '=';
    m['a'] = '7';
    m['s'] = '8';
    m['d'] = '9';
    m['f'] = 'a';
    m['g'] = 'e';
    m['h'] = 'h';
    m['j'] = 't';
    m['k'] = 'd';
    m['l'] = 'c';
    m[';'] = 'k';
    m['\''] = '-';
    m['z'] = '0';
    m['x'] = 'z';
    m['c'] = 'x';
    m['v'] = ',';
    m['b'] = 'i';
    m['n'] = 'n';
    m['m'] = 'w';
    m[','] = 'v';
    m['.'] = 'g';
    m['/'] = '\'';
    m['$'] = 'Q';
    m['%'] = 'J';
    m['^'] = 'L';
    m['&'] = 'M';
    m['*'] = 'F';
    m['('] = 'P';
    m[')'] = '?';
    m['_'] = '{';
    m['+'] = '}';
    m['Q'] = '$';
    m['W'] = '%';
    m['E'] = '^';
    m['R'] = '>';
    m['T'] = 'O';
    m['Y'] = 'R';
    m['U'] = 'S';
    m['I'] = 'U';
    m['O'] = 'Y';
    m['P'] = 'B';
    m['{'] = ':';
    m['}'] = '+';
    m['A'] = '&';
    m['S'] = '*';
    m['D'] = '(';
    m['F'] = 'A';
    m['G'] = 'E';
    m['J'] = 'T';
    m['K'] = 'D';
    m['L'] = 'C';
    m[':'] = 'K';
    m['"'] = '_';
    m['Z'] = ')';
    m['X'] = 'Z';
    m['C'] = 'X';
    m['V'] = '<';
    m['B'] = 'I';
    m['N'] = 'N';
    m['M'] = 'W';
    m['<'] = 'V';
    m['>'] = 'G';
    m['?'] = '"';
    while(getline(cin, str)){
        for (int i = 0; i < str.size(); ++i) {
            if(m.find(str[i]) == m.end()) cout << str[i];
            else cout << m[str[i]];
        }cout << endl;
    }

    return 0;
}

#endif
