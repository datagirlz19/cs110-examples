/*

A string is an array of characters (values of type char)

A string array is null-terminated, which means its last element is the null
character which is represented by a '\0'.

Only the characters before the first '\0' in the array are considered part of
the string. The length of the string is the number of characters before the
first '\0' in the array.

*/


#include <stdio.h>
#include <string.h>

/*
 * Given a string, modify the string so that it repeats itself.
 *
 * For example, "hello" will become "hellohello"
 *
 * The array containing the original string must be large enough to hold the
 * repeated string.
 */
void repeat_string(char string[]);

int main() {
    // Both of these initializations will create arrays with 6 elements. Using
    // double quotes as with "Hello" automatically puts the '\0' at the end
    // of the string
    char string1[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char string2[] = "Hello";

    printf("Here is string1: %s\n", string1);
    printf("Here is string2: %s\n", string2);

    // This creates an array with 100 elements, but only the first 8 will be
    // used to store the string. The remaining characters will be uninitialized,
    // but will be ignored by any functions dealing with strings because
    // everything after '\0' is ignored
    char oversized_string[100] = "Goodbye";

    printf("Here is the oversized string: %s\n", oversized_string);

    // This will change one of the elements of the array, but it will not change
    // the string, because it is inserted after the null character
    oversized_string[50] = 'Z';

    printf("Oversized string after modification: %s\n", oversized_string);

    // strlen() will get the length of a string up to, but not including, the
    // first null character in the array
    size_t string1_length = strlen(string1);

    printf("The length of string1 is %zu\n", string1_length);
    printf("The length of string2 is %zu\n", strlen(string2));
    printf("The length of oversized_string is %zu\n", strlen(oversized_string));

    char user_input[100];
    printf("Enter a string: ");
    // You do not need to use & when calling scanf() with strings, because
    // scanf() can modify the array that you pass it. scanf() will read up
    // to the first time it encounters whitespace (spaces, tabs, newlines)
    scanf("%s", user_input);

    printf("You entered \"%s\"\n", user_input);

    repeat_string(user_input);

    printf("Your string repeated is \"%s\"\n", user_input);

    return 0;
}

void repeat_string(char string[]) {
    size_t original_length = strlen(string);

    for (size_t i = 0; i < original_length; i++) {
        string[i + original_length] = string[i];
    }

    string[original_length * 2] = '\0';
}
