int longestValidParentheses(char* s) {
    int len = strlen(s);
    int* stack = (int*)malloc(sizeof(int) * (len + 1));
    int top = -1, maxLen = 0, lastInvalid = -1;

    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else {
            if (top >= 0) {
                top--;
                if (top >= 0) maxLen = fmax(maxLen, i - stack[top]);
                else maxLen = fmax(maxLen, i - lastInvalid);
            } else {
                lastInvalid = i;
            }
        }
    }

    free(stack);
    return maxLen;
}
