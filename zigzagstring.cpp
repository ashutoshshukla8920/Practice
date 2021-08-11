/*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);*/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) {
            return s;
        }
        
        string arr[numRows];
        int row = 0;
        bool down;
        
        for(int i = 0; i<s.length() ; i++) {
            arr[row].push_back(s[i]);
            
            if(row == numRows-1) 
                down = false;
            if(row == 0)
                down = true;
            
            down ? row++:row--;
        }
        string res;
        for (int i = 0 ; i<numRows ; i++) {
            res += arr[i];
        }
        return res;
    }
};
