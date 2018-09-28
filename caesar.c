#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int main (int argc, string argv[])
{
    //if the correct number of args are present, go ahead
    if (argc == 2)
    {
        int key = atoi(argv [1]);
        string plain = get_string("plaintext: ");
        int usefulkey = key;
        string cipher = plain;

        // 1. count the characters of the string
        int characters = strlen(plain);

        // 2. work through each letter
        for (int counter = 0; counter != characters; counter++)
        {
            int spell = (int) plain[counter];

            // 3. if it's upper case, do this:
            if (64 < spell && spell < 91)
            {

                while (spell + usefulkey < 65)
                {
                    usefulkey = usefulkey + 26;
                }

                while (spell + usefulkey > 90)
                {
                    usefulkey = usefulkey - 26;
                }

                spell = spell + usefulkey;
                char result = (char) spell;
                cipher [counter] = result;
            }

            //if it's lower case, do this:
            else if (96 < spell && spell < 123)
            {
               while (spell + usefulkey < 97)
               {
                    usefulkey = usefulkey + 26;
                }

                while (spell + usefulkey > 122)
                {
                 usefulkey = usefulkey - 26;
                }

                spell = spell + usefulkey;
                char result = (char) spell;
                cipher [counter] = result;
            }

            //if it's not an alpha character, do this
            else
            {
                char result = (char) spell;
                cipher [counter] = result;
            }
        }

        usefulkey = key;

        // 4. print the results
        printf("ciphertext: %s\n", cipher);
        printf("plaintext: %s\n",plain);
    }

    //if the correct number of args aren't present, tell the user
    else
    {
        printf("incorrect args\n");
        return 1;
    }
}

