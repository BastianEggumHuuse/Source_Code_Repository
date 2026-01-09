# include "../TCP_reuse.h" // This has <stdio.h> in it!!!

int squeezeEntireString(char s1[],char s2[])
{
    // We will return the new length of s1,
    // and keep s1 as the array (write the new array into it)

    int i; // First index (loops over s1)
    int j; // Second index (keeps track of where we are with all s2 chars removed)
    for(i = j = 0; s1[i] != '\0'; i++)
    {
        // checking if the current character exists within s2, and proceeding if it doesn't.
        if(!charInString(s1[i],s2))
        {
            s1[j++] = s1[i];
        } 
    }

    s1[j] = '\0';

    return j;
}

void main()
{
    char s1[] = "Hello world!";
    char s2[] = "Hlo";

    int l1 = squeezeEntireString(s1,s2);
    writeString(s1);
}