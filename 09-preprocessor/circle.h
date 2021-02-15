// This pattern of using preprocessor directives is called an include guard.
// If the preprocessor is including the contents of this file, first it checks
// to see if the identifier CIRCLE_H has not been defined. If it has not, it
// defines CIRCLE_H and the contents of the file are included. If CIRCLE_H is
// already defined, nothing will be included. This prevents header files from
// being included multiple times.
#ifndef CIRCLE_H
#define CIRCLE_H

// This preprocessor directive is a macro which replaces every instance of the
// identifier PI with 3.14159265
#define PI 3.14159265

double circle_area(double radius);

#endif
