# P1 - A411   

This is the repository for all software developed for the P1 project by group A411 of first semester at AAU during semester E19.

----------
![Master check](https://github.com/Hebbe1234/P1/workflows/Compilation/badge.svg)
----------

## Coding conventions

- The code must clearly show that it has been developed through a paradigm of top-down programming and stepwise improvement  
  - General code at the top of the file
  - More and more specific code as the file goes on´

- No actual execution of logic may take place in main().
  - main() is allowed to handle command line options (e.g --test and --silent).

- As a rule, the code should be formatted as shown here:

```C
    #include <stdio.h>

    #include "../headers/main.h"

    /* A description of the function */
    int main(void) {
        int i = 0;
      
        example_function(1, 10, &i);

        return 0;

    }

     /* A description of the function */
    void example_function(int start, int limit, int *pointer) {

        int i = 0;

        for (i = start, i <= limit; i++) {
            printf("The current value of i is: %d", i);
        }
        
        if (i == 10) {
           i = 11;
        } else {
           i = 12;
        }
    }
```

- And each .c source file containing ANY function or procedure must have an associated .h header file

```C
     /* A description of the function */
    void example_function(int start, int limit);

```

- There is no reason for the use of "goto" in the code
  - If one wishes to use this structure in their code (looking at you Martin), its existence must be well argued in the pull request, since it will be put under a lot of scrutiny.

- Source files, header files and files containg tests are seperated into different directories to keep the project organized.
- Source files goes in the directory "source".
- Header files goes in the directory "headers".
  - These can be included in the source files by writing: `#include "../headers/example.h"`
- Test files goes in the directory "tests".

- In order to keep compilation easy and structured a Makefile has been created and MUST be updated, whenever new files are added to the project.
  - For a simple tutorial of the use of our Makefile see [Kurt's video about Makefiles](https://laml.cs.aau.dk/cgi-bin/video2/get/show-video.cgi?video-id=video-make-rettet&course-id=impr&lecture-number=5&course-year=2019&video-width=640&lang=dk&user-name=rhebsg19&crypted-password=not-used&video-start-time=00:00&auto-play=0)

----------

## Conventions for use of git and GitHub

- For an introduction to GitHub see: [Brams file about GitHub](https://paper.dropbox.com/doc/Git-cheat-sheet-hRMHn3gcZbv485DFLHQap)
- The master branch of the repository is NEVER for development of new code.
  - The only way for the master branch to change, is through pull requests of tested code.

- A new branch should be created for each new feature.
- Remember to "git pull" at regular intervals, and at least every time you have been away from development.
- Each pull request should at least explain, what has been added or changed.
- Refactoring should in general not happen as part of development, but as a seperate 'feature'.

- It is at the discretion of Rasmus, whether or not a branch may be merged into the master.

----------

## Unit testing

- The testing framework in use is CuTest.
  - Easy to install and simple to use
  - Does not offer much advanced information (e. g. runtime and code coverage)
  - Does what it needs to do for this relatively simple piece of software

- All functions should be testable.
- All functions should be fully covered by unit tests.
