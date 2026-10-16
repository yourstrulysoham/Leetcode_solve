int lengthOfLastWord(char* s) {
    int count=0;
    int temp=0;
    int n=strlen(s);
    for(int i=0;i<n;i++){
        if(s[i]==' '){
            count=0;

        }
        else{
            count++;
        
                temp=count;
            
        }

    }
    return temp;
    
}