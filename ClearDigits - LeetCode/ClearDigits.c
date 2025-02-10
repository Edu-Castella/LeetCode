char* clearDigits(char* s) {
    for (int i = 0; i < strlen(s); i++){
        if(isdigit(s[i])){
            for(int j = i; j < strlen(s); j++){
                s[j-1] = s[j+1];
            }
            i = -1;
        }
    }
    return s;
}
