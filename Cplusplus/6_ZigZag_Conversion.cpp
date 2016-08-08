/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/


class Solution {
public:
    string convert(string s, int numRows) {
        int slen = s.length();
        int glen = numRows * 2 - 2;
        int clen = numRows - 1;
        string c(slen, '0');
        
        if ((slen <= numRows) || (numRows == 1))
        {
            return s;
        }
        
        int k = 0;
        for (int i = 0; i < slen; i = i + glen)
        {
            c[k] = s[i];
            k++;
        }
        
        for (int r = 1; r < numRows - 1; r++)
        {
            for (int i = r; i < slen; i = i + glen)
            {
                c[k] = s[i];
                k++;
                if (i + glen - 2 * r < slen)
                {
                    c[k] = s[i + glen - 2 * r];
                    k++;
                }
            }
        }
        
        for (int i = numRows - 1; i < slen; i = i + glen)
        {
            c[k] = s[i];
            k++;
        }
        
        return c;
    }
};
