#include <stdio.h>
#include <cs50.h>

//Prototype kind of structure - informs the code about an existing code structure addition later in the code. Has to have a semicolon at the end.
void meow(int n);

int main(void)
{
    meow(7);
}

void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
    printf("meow\n");
    }
}