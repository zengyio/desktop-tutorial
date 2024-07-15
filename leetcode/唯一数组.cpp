int only(int *n,int length){
    int *on=(int*)malloc(length*sizeof(int));
    int val=1;
    on[0]=n[0];
    for(int i=1;i<length;i++){
        int ok=1;
        for(int w=0;w<val;w++){
            if(n[i]==on[w])
            ok=0;   
        }
        if(ok==1)
        on[val++]=n[i];
    }
    for(int i=0;i<val;i++){
        n[i]=on[i];
    }
    free(on);
    return val;
}
