main()
{
    long i;
    int j;
    printf("Please input number:");
    scanf("%ld",&i);
    for(j=999;j>=100;j--)
        if(i%j==0){
            printf("The max factor with 3 digits in %ld is:%d.\n",i,j);
            break;
        }
}
