#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>


// Function protoypes
/**
 * is_plaindrome
 * preconditions: 
 *   string: a character array that is null terminated and
 *           must contain AT LEAST ONE letter a-z or A-Z.
 * post-conditions:
 *   returns true if the string is a palindrome and false otherwise
 */
bool is_palindrome(const char *string);


int main(int argc, char **argv) {
    
    // Basic Input Validation
    //  Applicatin exits with a code of 1 if
    //  there are more than 2 command line arguements
    if (argc > 2) {
        printf("Invalid number of arguements\n");
        printf("Usage:\n");
        printf("<program name>\n");
        printf("OR\n");
        printf("<program name> <string>\n");
        return 1;
    }

    // Assume the string is NOT a palindrome
    bool palindrome = false;
    
    // Take the string from the command line argument string
    //   at argv[1]
    if (argc != 1) {
        palindrome = is_palindrome(argv[1]);
    }
    // There is no string on the command line
    //   process input from standard input.
    else {
        
        // Setup Dynamic Character Array
        size_t size = 0;
        size_t capacity = 1;
        char *string = malloc(capacity * sizeof(char));
        if (string == NULL) {
            return 1;
        }

        // Read all input from standard input into ch until
        //  EOF is reached (Ctrl + d) or happens automatically
        //  if input redirection is used: ./my_program < input.txt
        char ch;
        while ((ch = getchar()) != EOF) {
            if (size == capacity) {
                capacity *= 2;
                string = realloc(string, capacity * sizeof(char));
                if (string == NULL) {
                    return 1;
                }
            }
            string[size] = ch;
            ++size;
        }

        // DO NOT FORGET THE NULL TERMINATOR
        //  This makes is a valid "string".
        string[size] = '\0';
        palindrome = is_palindrome(string);

        // We have our answer, there is no need for the string
        //  anymore, so free up the memory.
        free(string);
    }

    // Check the result
    if (palindrome) {
        printf("Your string is a palindrome!\n");
    }
    else {
        printf("Your string is NOT a palindrome!\n");
    }

    return 0;
}


bool is_palindrome(const char *string) {
    size_t length = strlen(string);
    size_t start = 0;
    size_t end = length - 1;
    
    // We are using two variables to keep track of the
    //  beginning and the end of the string. If they meet up
    //  or pass each other, then we have checked all the characters
    //  in the string:
    //
    //   start --->              <---- end
    //  ['t', 'a', 'c', 'o', 'c', 'a', 't', '\0']

    while (start < end) {
        // Get start to a letter character (a-z)
        //  skiping spaces, numbers, and punctuations
        while (!isalpha(string[start])) {
            ++start;
        }
        // Get end to a letter character (a-z)
        //  skiping spaces, numbers, and punctuations
        while (!isalpha(string[end])) {
            --end;
        }
        // Compare the two characters
        //   If any characters are not the same it cannot be
        //   a palindrome
        if (tolower(string[start]) != tolower(string[end])) {
            return false;
        }
        
        // Move start and end or we will get and infinite loop!
        ++start;
        --end;
    }

    // If we made it all the way here, it must be a palindrome
    return true;
}
