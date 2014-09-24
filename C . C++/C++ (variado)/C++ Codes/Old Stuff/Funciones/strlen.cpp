int strlenn(char a[])
{
    int i(0);
    do 
    {i++;}
    while(a[i]);
    return i;
}

int strelem(char *a)
{
    int size = sizeof(a)/sizeof(char);
    return  size;
}

