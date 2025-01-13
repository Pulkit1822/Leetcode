/*
 * @lc app=leetcode id=2116 lang=cpp
 *
 * [2116] Check if a Parentheses String Can Be Valid
 */

// @lc code=start
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();

        //base case: odd length of string should return false
        if(n&1){
            return false;
        }

        //setting up counters for opening, closing and wild cards
        //I am using 2-pass method
        //(i) left to right iteration
        int openingBracket, closingBracket, wildCard = 0;
        for(int i=0; i<n; ++i){
            if(locked[i] == '0'){
                wildCard++;
            }
            else if(s[i] == '('){
                openingBracket++;
            }
            else{
                closingBracket++;
            }


            if(wildCard < (closingBracket-openingBracket)){// '(' is unbalanced
                return false;
            } 
        }


        //(ii) right to left iteration --- counter set to 0
        openingBracket, closingBracket, wildCard = 0;
        for(int i=n ; i>0;--i ){
            if(locked[i] == '0'){
                wildCard++;
            }
            else if(s[i] == '('){
                openingBracket++;
            }
            else{
                closingBracket++;
            }

            if(wildCard < (closingBracket-openingBracket)){// '(' is unbalanced
                return false;
            } 
        }
        return true;

    }
    
};
// @lc code=end

