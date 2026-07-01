#define MAX 100001

void expand(char *s, int left, int right, int *start, int *max){
    while(left>=0 && right <=strlen(s)-1 && s[left]==s[right]){
        int len=right-left+1;
        if (len>*max) {
            *max=len;
            *start=left;
        }
        left--;
        right++;
    }
}

char* longestPalindrome(char* s) {
    int n=strlen(s);
    if(n==0){
        char *ans=malloc(1*sizeof(char));
        ans[0]='\0';
        return ans;
    }

    int start=0;
    int max=1;

    for(int i=0;i<n;i++){
        expand(s,i,i,&start,&max);
        expand(s,i,i+1,&start,&max);
    }
    char *ans = malloc(max+1*sizeof(char));

    for (int i=0;i<max;i++) {
        ans[i]=s[start+i];
    }
    ans[max] ='\0';
    return ans;
}