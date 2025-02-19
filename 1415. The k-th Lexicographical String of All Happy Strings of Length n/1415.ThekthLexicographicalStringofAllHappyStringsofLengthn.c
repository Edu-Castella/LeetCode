
/*

1415. The k-th Lexicographical String of All Happy Strings of Length n

A happy string is a string that:

    - consists only of letters of the set ['a', 'b', 'c'].
    - s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).

For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.

Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.

Return the kth string of this list or return an empty string if there are less than k happy strings of length n.


Example 1:
    Input: n = 1, k = 3
    Output: "c"
    Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".

Example 2:
    Input: n = 1, k = 4
    Output: ""
    Explanation: There are only 3 happy strings of length 1.

Example 3:
    Input: n = 3, k = 9
    Output: "cab"
    Explanation: 
    There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. 
    You will find the 9th string = "cab"

Constraints:
    - 1 <= n <= 10
    - 1 <= k <= 100


*/



void backtracking(char** happy_strings, char* string, int* happy_index, int index, int n){
    if (index == n) {
        happy_strings[*happy_index] = strdup(string); 
        (*happy_index)++; 
        return;
    }

    for (char i = 'a'; i <= 'c'; i++) {
        if (index > 0 && string[index - 1] == i) continue;
        
        string[index] = i;
        string[index + 1] = '\0'; 
        backtracking(happy_strings, string, happy_index, index + 1, n);
    }
}

char* getHappyString(int n, int k) {
    int n_happy_strings = 3 * pow(2, n - 1);
    
    if (k > n_happy_strings) 
        return "";

    char* string = calloc(n + 1, sizeof(char));
    char** happy_strings = calloc(n_happy_strings, sizeof(char*));

    int happy_index = 0;
    
    backtracking(happy_strings, string, &happy_index, 0, n);

    char* res = strdup(happy_strings[k - 1]);

    for (int i = 0; i < n_happy_strings; i++) {
        free(happy_strings[i]);
    }
    free(happy_strings);
    free(string);
    
    return res;
}