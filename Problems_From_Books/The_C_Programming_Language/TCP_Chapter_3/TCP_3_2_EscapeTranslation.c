#include "../TCP_reuse.h"

int escape(char s[], char t[])
{
    // We copy from t, to s, while expanding escape sequences to actual text.
    // We assume that s has more memory than t, to fit the new characters.

    int i_t; // iterator for t
    int i_s = 0; // iterator for s
    for(i_t = 0; t[i_t] != '\0'; i_t++)
    {
        // We use a switch statement to check for the escape sequences
        switch(t[i_t])
        {
            // Note that we use the postfix variant of ++, to make sure that
            // we place elements in the arrays before incrementing i_s
            case '\t' : s[i_s++] = '\\'; s[i_s++] = 't'; break;
            case '\b' : s[i_s++] = '\\'; s[i_s++] = 'b'; break;
            case '\n' : s[i_s++] = '\\'; s[i_s++] = 'n'; break;
            case '\?' : s[i_s++] = '\\'; s[i_s++] = '\?'; break;
            default : s[i_s++] = t[i_t];
        }
    }

    s[i_s] = '\0';
    return i_s;
}

int reverseEscape(char s[], char t[])
{
    // Time to go the other way
    // Assume that t has a bunch of escape sequences:

    int i_t;
    int i_s = 0;
    for(i_t = 0; t[i_t] != '\0'; i_t++)
    {
        // If we find a backslash, we have a sequence
        if(t[i_t] == '\\')
        {
            // We increment i_t, and check the next element in the array
            switch(t[++i_t])
            {
                case 't' : s[i_s++] = '\t'; break;
                case 'b' : s[i_s++] = '\b'; break;
                case 'n' : s[i_s++] = '\n'; break;
                case '\?' : s[i_s++] = '\?'; break;
                // This next case is for the situation where the final element in the array is a backslash
                case '\0' : s[i_s++] = '\\'; i_t--; break;
                // Then finally the default
                default : s[i_s++] = '\\'; break;
            }
        }
        else
        {
            s[i_s++] = t[i_t];
        }
    }

    return i_s;
}

void main()
{
    char s[100];
    char t[] = "Hello world\? \nSomething's \t up here...";
    int l = escape(s,t);
    
    printf("\nPrinting line normally:\n");
    writeString(t);
    printf("\n\nPrinting string with escapes:\n");
    writeString(s);
    printf("\n");

    // Going the other way
    char s_2[100];
    int l_2 = reverseEscape(s_2,s);
    printf("\n");
    writeString(s_2);
}