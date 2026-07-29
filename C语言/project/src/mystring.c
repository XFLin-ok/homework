
extern char str;
void *mystring1(char *p1, char *p2)
{
    while (*p1 != '\0')
    {
        *p1 = *p2;
        p1++;
        p2++;
    }
}
void *mystring2(char *p1, char *p2)
{
    while (*p1 != '\0')
    {
        p1++;
    }

    while (*p2 != '\0')
    {
        *p1 = *p2;
        p1++;
        p2++;
    }
    *p1 = '\0';
}
void *mystring3(char *p1, char *p2)
{
}