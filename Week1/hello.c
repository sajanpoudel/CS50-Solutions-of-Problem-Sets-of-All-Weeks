#include <stdio.h>
#include <cs50.h>
int main(void)
{
    //takes input from user
    string name = get_string("Enter your name: ");
    printf("hello, %s\n", name);
}
