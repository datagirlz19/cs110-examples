/*
    Style Demonstration

    This place would be where a heading comment might go to explain
    the program. I will NOT require header comments for this class,
    but you should be aware of the concept. Some larger projects
    also use this opportunity to list contributors or code licensing
    information at the top of the document.

    Pay attention to the horizontal and vertical spacing of the
    code. This helps a great deal with readability and in the case
    of the vertical text (new lines) can be used to indicate logical
    organization of related code.

    For the latest style guidelines and examples see the website:
    http://csweb.wooster.edu/dguarnera/cs110/resources/guides/style.html
*/
#include <stdio.h>

/* 
    You should have a line of spacing between your includes
    and the rest of your source code. The includes do not need
    to have spaces between them. Some styles ask that standard
    library includes (like stdio.h, stdbool.h, etc.) come first
    and then custom user created modules come separate with a
    space to separate them, but we do not need to worry about that.
*/
int main() {
    // Code for taking user input
    int shape_size;
    printf("Enter shape size: ");
    scanf("%u", &shape_size);

    // A newline to separate the code related to processing user input
    //    from the rest of the code above.
    for (int row = 0; row < shape_size; row++) {
        for (int column = 0; column < shape_size; column++) {
            if (row % 2 == 0) {
                printf("<");
            }
            else {
                printf(">");
            }
        }
        printf("\n");
    }

    // Another newline to indicate a logical separation between the input
    //    processing and other subsequent tasks the program will perform.
    return 0;
}
