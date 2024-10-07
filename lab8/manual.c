/*
 * Name:	Brian Jordan
 * Section:	1 (Monday/Wednesday @ 9:30am)
 * Lab:  	CIS2107_Lab08_Manual
 * Goal: 	To design and implement functions taking pointers as arguments
            to process characters and strings.
 */

#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define RAND_MIN 0
#define RAND_MAX 5

// functions prototypes
void *upperLower(const char *s);
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4);
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4);
void compareStr(const char *s1, const char *s2);
void comparePartialStr(const char *s1, const char *s2, int n);
void randomize(void);
int tokenizeTelNum(char *num);
void reverse(char *text);
int countSubstr(char *line, char *sub);
int countChar(char *line, char c);
int countWords(char *string);
void countAlpha(char *string);
void startsWithB(char *string[]);
void endsWithed(char *string[]);

int main()
{
    // random generator
    srand(time(NULL));

    // test for upperLower
    const char test[] = "This iS A Test";
    upperLower(test);

    // test for convertStrtoInt
    printf("\n\nThe sum of 4 strings is: %d\n", convertStrtoInt("3", "4", "5", "6"));

    // test for convertStrtoFloat
    printf("\n\nThe sum of 4 strings is: %.2f\n", convertStrtoFloat("3.5 ", "4.5", "5.5", "6.5"));

    // test for compareStr
    compareStr("Test2", "Test1");

    // test for comparePartialStr
    comparePartialStr("Tept1", "Test2", 4);

    // test for randomize
    randomize();

    // test for tokenize number
    puts(" ");
    char str[] = "(267) 436-6281";
    tokenizeTelNum(str);
    puts("");

    // test for reverse
    char line[] = "Hello world";
    reverse(line);

    // test for countSubstr
    char *line1 = "helloworldworld";
    char *substring = "world";
    printf("\n\nNumber of Substrings %s inside %s: %d\n", substring, line1, countSubstr(line1, substring));

    // test for countChar
    char w = 'w';
    printf("\nNumber of character %c inside %s: %d\n", w, line1, countChar(line1, w));

    // test for countAlpha
    char str1[] = "Hello it's me.";
    countAlpha(str1);

    // test for countWords
    char countstring[] = "hello world!";
    printf("\n\nNumber of words in string is: %d\n", countWords(countstring));

    // test for startsWithB
    char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};
    startsWithB(series);

    // test for endsWithed
    endsWithed(series);
}

// 1.(Displaying Strings in Uppercase and Lowercase)
void *upperLower(const char *s)
{
    puts("");

    int stringSize = 0;
    int charByte = sizeof(char);

    while (*s != '\0')
    {
        printf("%c", toupper(*s));
        stringSize += charByte;
        s++;
    }

    // printf("\nbytes in this word: %d", stringSize);
    puts("");

    s -= stringSize;
    while (*s != '\0')
    {
        printf("%c", tolower(*s));
        s++;
    }
    puts("");
}

// 2.(Converting Strings to Integers for Calculations)
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4)
{
    puts("");
    int total = 0;

    int asciiValues[4] = {};
    asciiValues[0] = (int)*s1;
    asciiValues[1] = (int)*s2;
    asciiValues[2] = (int)*s3;
    asciiValues[3] = (int)*s4;

    // printf("yerr: %d\n", asciiValues[0]);
    for (int i = 0; i < 4; i++)
    {
        int charValue = asciiValues[i] - 48; // 48 is ascii value for 0
        total += charValue;
    }

    return total;
}

// 3.(Converting Strings to Floating Point for Calculations)
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4)
{
    puts("");
    float total = 0;

    char *numbers[4] = {s1, s2, s3, s4};
    char *ptr = NULL;
    for (int i = 0; i < 4; i++)
    {
        ptr = numbers[i];

        int before = 0;          // number before decimal point
        float after = 0;         // number after decimal point
        before = (int)*ptr - 48; // 48 is ascii for 0
        ptr += 2;                // pointer skips over the decimal point
        after = ((float)((int)*ptr - 48)) / 10;

        total += before + after;
    }

    return total;
}

// 4.(Comparing Strings)
void compareStr(const char *s1, const char *s2)
{
    int result = strcmp(s1, s2);

    if (result == 0)
    {
        printf("%s = %s\n", s1, s2);
    }
    else if (result == -1)
    {
        printf("%s < %s\n", s1, s2);
    }
    else if (result == 1)
    {
        printf("%s > %s\n", s1, s2);
    }
}

// 5.(Comparing Portions of Strings)
void comparePartialStr(const char *s1, const char *s2, int n)
{
    int result = strncmp(s1, s2, n);

    if (result == 0)
    {
        printf("comparison of first %d characters: %s = %s\n", n, s1, s2);
    }
    else if (result < 0)
    {
        printf("comparison of first %d characters: %s < %s\n", n, s1, s2);
    }
    else if (result > 0)
    {
        printf("comparison of first %d characters: %s > %s\n", n, s1, s2);
    }
}

/*
The article array
should contain the articles "the", "a", "one", "some" and "any"; the noun array should contain the nouns "boy", "girl", "dog",
"town" and "car"; the verb array should contain the verbs "drove", "jumped", "ran", "walked" and "skipped"; the preposition
array should contain the prepositions "to", "from", "over", "under" and "on". After the preceding function is written and
working, modify it to produce a short story consisting of several of these sentences.


article, noun, verb, preposition, article and noun
*/

// 6.(Random Sentences)
void randomize(void)
{
    char *article1[] = {"The", "A", "One", "Some", "Any"};
    char *article2[] = {"the", "a", "one", "some", "any"};
    char *noun1[] = {"boy", "girl", "dog", "town", "car"};
    char *noun2[] = {"boy.", "girl.", "dog.", "town.", "car."};
    char *verbs[] = {"drove", "jumped", "ran", "walked", "skipped"};
    char *prepositions[] = {"to", "from", "over", "under", "on"};

    for (int i = 0; i < 20; i++)
    {
        printf("%s ", article1[rand() % 5]);
        printf("%s ", noun1[rand() % 5]);
        printf("%s ", verbs[rand() % 5]);
        printf("%s ", article2[rand() % 5]);
        printf("%s ", noun2[rand() % 5]);
        puts("");
    }
}

// 7.(Tokenizing Telephone Numbers)
int tokenizeTelNum(char *num)

{
    const char delim[] = " ()-";
    char *token = strtok(num, delim);

    printf("%s ", token);
    token = strtok(NULL, delim);
    printf("%s", token);
    token = strtok(NULL, delim);
    printf("%s", token);
}

// 8.(Displaying a Sentence with Its Words Reversed)
void reverse(char *text)
{
    char *words[100]; // Array to store pointers to words
    int count = 0;

    char *token = strtok(text, " ");

    while (token) // while token DOES NOT equal NULL
    {
        words[count++] = token; // Store the pointer to the token
        token = strtok(NULL, " ");
    }

    // Print the words in reverse order
    for (int i = count - 1; i >= 0; i--)
    {
        printf("%s ", words[i]);
    }
    printf("\n");
}

// 9.(Counting the Occurrences of a Substring)
int countSubstr(char *line, char *sub)
{
    puts("");
    int count = 0;
    char substring[strlen(sub)];

    for (int i = 0; i < strlen(line) - strlen(sub) + 1; i++)
    {
        for (int j = 0; j < strlen(sub); j++)
        {
            substring[j] = line[i + j];
        }
        substring[5] = '\0';
        if (strcmp(substring, sub) == 0)
        {
            count++;
        }
    }
    return count;
}

// 10.(Counting the Occurrences of a Character)
int countChar(char *line, char c)
{
    int count = 0;
    char *ptr = line; // the pointer starts at the beginning of the string

    while (*ptr != '\0')
    {
        if (*ptr == c)
        {
            count++;
        }
        ptr++; // moves to next char
    }

    return count;
}

// 11.(Counting the Letters of the Alphabet in a String)
void countAlpha(char *string)
{
    // int numOfLetters = 26;
    char letters[26] = "abcdefghijklmnopqrstuvwxyz";
    char frequency[26] = {};

    for (int i = 0; i < strlen(string); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (tolower(string[i]) == letters[j])
            {
                frequency[j]++;
            }
        }
    }
    for (int i = 0; i < 26; i++)
    {
        printf("%c, %c | %d\n", letters[i], toupper(letters[i]), frequency[i]);
    }
}

// 12.(Counting the Number of Words in a String)
int countWords(char *string)
{
    int wordCount = 0;
    char a;

    for (int i = 0; i < strlen(string); i++)
    {
        a = string[i];
        if (a == ' ')
        {
            wordCount++;
        }
    }
    return wordCount + 1;
}

// 13.(Strings Starting with "b")
void startsWithB(char *string[])
{
    for (int i = 0; i < 5; i++)
    {
        if (string[i][0] == 'b' || string[i][0] == 'B')
        {
            printf("%s\n", string[i]);
        }
    }
    puts("");
}

// 14.(Strings Ending with "ed")
void endsWithed(char *string[])
{
    for (int i = 0; i < 5; i++)
    {
        if (string[i][strlen(string[i]) - 2] == 'e' && string[i][strlen(string[i]) - 1] == 'd')
        {
            printf("%s\n", string[i]);
        }
    }
}