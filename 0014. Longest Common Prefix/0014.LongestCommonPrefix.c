

/*

14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".


Example 1:
    Input: strs = ["flower","flow","flight"]
    Output: "fl"

Example 2:
    Input: strs = ["dog","racecar","car"]
    Output: ""
    Explanation: There is no common prefix among the input strings.


Constraints:
    - 1 <= strs.length <= 200
    - 0 <= strs[i].length <= 200
    - strs[i] consists of only lowercase English letters if it is non-empty.


    
*/



int getMinLen(char** strs, int strsSize){
    int minLen = 1000;
    for(int i = 0; i < strsSize; i++){
        if(strlen(strs[i]) < minLen) minLen = strlen(strs[i]);
    }
    return minLen;
}

char* longestCommonPrefix(char** strs, int strsSize) {    
    int minLen = getMinLen(strs, strsSize);
    char* res = calloc(minLen + 1, sizeof(char));
    char actualChar;
    char coin = 1;
    int index = 0;
    
    if(minLen < 1){
        return "";
    }
    
    for(int i = 0; i < minLen; i++){
        actualChar = strs[0][i];
        coin = 1;
        for(int j = 0; j < strsSize; j++){
            if(actualChar != strs[j][i]) coin = 0;
        }
        if(coin){
            res[i] = actualChar;
        } 
        index = i;
    }
    res[index + 1] = '\0';
    
    return res;
}