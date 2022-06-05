#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
//functions defined
string plainertext(void);
void clipertext(string key, string plaintext);

int main(int argc, string argv[])
{

    string key = argv[1];
    // check key is only alphabetic, of non repeative alphabets, has one argument, be 26 digits

    //exit the program if no. of arguments is less or greater than to 2

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //exit the program if key doesn't have exactly 26 alphabets

    else if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    //check if the key consists of only alphabets or not, if not exit the program
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must be alphabetic");
            return 1;
        }
    }

    //check whether the alphabets in key are repeated or not if repeated exit the program

    for (int i = 0; i < strlen(key); i++)
    {
        char firstchar = tolower(key[i]);
        for (int j = i + 1; j < strlen(key) - 1; j++)
        {
            char secondchar = tolower(key[j]);

            if (firstchar == secondchar)     //compares i letter and i+1 letter of key
            {
                printf("Dublicate char\n");
                return 1;
            }

        }
    }




    // take plaintext from user
    string plaintext = plainertext();

    //print cliper text encoded using key
    printf("ciphertext: ");
    clipertext(key, plaintext);

}




//Function to take plain text from user

string plainertext(void)
{
    string plaintext = get_string("plaintext: ");
    return plaintext;

}


//Function to encode plain text to get cliper text

void clipertext(string key, string plaintext)
{

    for (int i = 0; i < strlen(plaintext); i++)
    {
        char cliper_text;
        char alphabet = plaintext[i];
        int is_Capital = isupper(alphabet);  //0 for lower case and non zero for uppercase
        char word = tolower(alphabet);

        //if word is not an alphabets, cliper text is same as word
        cliper_text = word;

        //if word is alphabets, their position will be 0 to 26 if its value is subracted from ASCII value of 'a'
        int position = word - 'a';
        if (position >= 0 && position <= 26)
        {
            cliper_text = key[position];  //cliper text is position of word in key
        }

        //to keep the case of letter, if original word is lower(isupper =0), clipper text will be lower
        if (is_Capital == 0)
        {
            cliper_text = tolower(cliper_text);

        }
        else
        {
            cliper_text = toupper(cliper_text);
        }

        printf("%c", cliper_text);    //Print each clippertext in column to make it look like single word

    }
    printf("\n");
}
