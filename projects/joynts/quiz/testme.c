#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // return a character that is within the character ascii charater set.
    int min = 32;
    int max = 127;
    
    // randomly select a character
    char ascii_random = min + rand() % (max - min + 1);
    
    // return that character
    return ascii_random;
}

char *inputString()
{
    // create the memory space for the string
    char *random_string = malloc(sizeof(char) * 6);
    
    // create the pool of characters
    char character_pool[4] = {'r', 'e', 's', 't'};
    
    // randomely generate the string
    int i = 0;
    for (i = 0; i < 5; i++){
        random_string[i] = character_pool[rand() % 4];
    }
    
    // asign the string return
    random_string[5] = '\0';
    
    return random_string;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
