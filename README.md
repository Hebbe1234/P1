# P1 - A411

This is the repository for all software developed for the P1 project of group A411 of first semester at AAU during semester E19.

----------

## Coding conventions

- The code must clearly show that it has been developed through a paradigm of top-down programming med trinvis forfindelse
  - General code at the top of the file
  - More and more specific code as the file goes on´

- No actual execution of logic may take place in main().
  - main() is allowed to handle command line options (e.g --test and --silent).

- As a rule, the code should be formatted as shown here:

```C
    #include <stdio.h>

    #include "../headers/main.h"

    /**
     * A comment for doxygen explaining the implementation
     */
    int main(void) {

        example_function(1, 10);

        return 0;

    }

    /**
     * A comment for doxygen explaining the implementation
     */
    void example_function(int start, int limit) {

        int i = 0;

        for(i = start, i <= limit; i++) {
            printf("The current value of i is: %d", i);
        }

    }
```

- And each .c source file containing ANY function or procedure must have an associated .h header file

```C
    /**
     * A comment for doxygen explaing the thoughts of the function
     */
    void example_function(int start, int limit);

```

- There is reason for the use of "goto" in the code
  - If one wishes to use this structure in their code (looking at you Martin), its existence must be well argued in the pull request, since
     it will be put under a lot of scrutiny.

- Source files, header files and files containg tests are seperated into different directories to keep the project organized.
- Source files goes in the directory "source".
- Header files goes in the directory "headers".
  - These can be included in the source files by writing: `#include "../headers/example.h"`
- Test files goes in the directory "tests".

- In order to keep compilation easy and structured a Makefile has been created and MUST be updated, whenever new files are added to the project.
  - For a simple tutorial of the use of our Makefile see 

----------

## Conventions for use of git and GitHub

- The master branch of the repository is NEVER for development of new code.
  - The only way the master branch changes is through pull requests of tested code.

- A new branch should be created for each new feature.
- Remember to "git pull" at regular intervals, and at least every time you have been away from development.
- Each pull request should at least explain, what has been added or changed.
- Refactoring should in general not happen as part of development, but as a seperate *'feature'

- It is at the discretion of Rasmus, wheter or not a branch may be merged into the master.

----------

## Unit testing

- The testing framework in use is CuTest.
  - Easy to install and simple to use
  - Does not offer much advanced information (e. g. runtime and code coverage).
  - Does what it needs to do for this relatively simple piece of software

- All functions should be testable.
- All functions should be fully covered by unit tests.

