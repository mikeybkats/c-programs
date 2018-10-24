# Questions

## What is pneumono-ultra-microscopic-silico-volcano-coniosis?
The maximum length for a word in our dictionary (45 characters_)

TODONE

## According to its man page, what does `getrusage` do?
allows the developer to return a digest of system resources that are being used.  

TODONE

## Per that same man page, how many members are in a variable of type `struct rusage`?
I count sixteen variables. If we dive into the timeval struct then there are two more in there.

TODONE

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?
Passing by reference allows us to go to the data directly. Passing by value requires making a copy of the data. In our speller.c example this will help us save system resources.

TODONE

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

TODO
// Usage: speller [dictionary] text

Line 20: When main is called it checks that arguments two and three exist. It goes on to create a couple of rusage structs before and after. These will be differenced with each other to calculate processing time. Some doubles are initialized. These will be used to store our print outs to the user. A terinary operater looks at the third argument of main. If the user supplied the third argument char *dictionary is initialized as the first argument. If not, the dictionary is defined as the default dictionary. 
Line 39: Next we call getrusage(). getrusage takes two parameters. The first parameter is entered as RUSAGESELF (predefined parameter == 1). The second parameter is the buffer that we store the output.We can store into &before and &after to calculate our difference. Using the & character tells the computer that we are pointing to the address of the variable and writing to its reference point. getrusage(RUSAGESELF, &Before) will calculate the system usage up until this point in the code. Next the dictionary is loaded into memory, then getrusage(RUSAGESELF, &after) is written into the after buffer. If the dictionary is not loaded successfully the speller program returns a 1. 
Line 51: calculate the difference between the two buffers to get the dictionary load time
Line 54: check for three args or two args // so we know which arg to use as text input 
Line 55: fopen the *text argc from line 54 and store into FILE *file so we can check that it is a valid file that we can run the file applications fget ect 
Line 71: finally to the loop. int c = fgetc(file). Loop through each letter of the input file with fgetc(), each time we call fgetc() we advance to the next character in the input, and when the end of file (EOF) is reached the loop ends.
Line 74: check that file input only accepts alphabetic characters. if true or if our file input equals apostrophe and our index is greater than zero append the character to our current index of the word variable. The word will continue to be copied letter by letter into the word variable until we reach the end of the word or if we hit a non letter character or if the word is too long (longest word in dictionary). When the loop is repeated and isalpha returns false on our c var we know we are at the end of the word because we've reached a space in the text stream.
Line 102: At this point if our index is greater than 0 it means our first two if statements have evaluated to false and we have found a whole word. 
Line 105: adding a '\0' completes the word.
Line 111: run getrusage before and after we check the spelling of the word and we can then calculate our time differences.
The rest of the file is pretty straightforward in calculating the time and printing the tallies.

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

TODONE
My first thought is that if we read whole words at a time it would be much harder or impossible to account for special characters like apostrophes. By scanning with fgetc we have a the advantage of scanning at a more granular level. 

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

TODONE
Because those variables will not change within the context of the application. Declaring them const will safeguard against their mutations.

