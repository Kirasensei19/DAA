newsearch(A,p,n,x)
{
    if (a[p]==x)
    {
        return p;
    }
    else if (p<n)
    {
        return newsearch(A,p+1,n,x);
    }
    else
    {
        return -1;
    }

    
}