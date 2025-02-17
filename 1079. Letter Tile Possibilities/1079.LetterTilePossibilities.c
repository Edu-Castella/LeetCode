
/*

1079. Letter Tile Possibilities

You have n  tiles, where each tile has one letter tiles[i] printed on it.

Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.


Example 1:
    Input: tiles = "AAB"
    Output: 8
    Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".

Example 2:
    Input: tiles = "AAABBC"
    Output: 188

Example 3:
    Input: tiles = "V"
    Output: 1


Constraints:
    - 1 <= tiles.length <= 7
    - tiles consists of uppercase English letters.
    
*/


int backtracking(int *letters){
    int count = 0;

    for(int i = 0; i < 26; i++){

        if(letters[i] > 0){
            count++;
            letters[i]--;
            count += backtracking(letters);
            letters[i]++;
        }
    }
    return count;
}

int numTilePossibilities(char* tiles) {

    int * letters = calloc(26, sizeof(int));

    for(int i = 0; i < strlen(tiles); i++){
        letters[tiles[i] - 'A']++;
    }
    
    int res = backtracking(letters);

    free(letters);

    return res;
}