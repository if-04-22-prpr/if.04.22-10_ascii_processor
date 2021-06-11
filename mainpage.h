/**
* @mainpage
* @section intro Introduction
*
* The implementation a text file processor.
* The files of a directory are printed and compressed using RLE.
* 
* @section objective Assignment Objective
*
* Working with directories, reading and writing text and binary files, 
* and compressing and expanding text files to binary files using RLE.
*
* @section assignment Assignment
*
* Implement an 'ASCII File Processor'.
* Although a few functions are pre-declared, it is perfectly fine to structure 
* the application in a different way. Files and functions may be added,
* pre-declared functions may be modified or removed as needed.
* It is, however, not allowed to put all code into `main` or antother single function.
* Design the application in a reasonable way, feel free to use function pointers or 
* other concepts, such as lists for chaching directory content.
*
* The is assignment comes without unit tests - the output is supposed to be sufficient 
* for testing the application. You are still welcome to add unit tests as required.
* If you need to test directory / file access, those function shall be mocked to
* allow reasonably tests.
*
* POSIX functions for processing directories and files shall be used.
* - Documentation for functions related to directories can be found at
*   https://pubs.opengroup.org/onlinepubs/009695399/functions/opendir.html
*   and linked pages.
* - Documentation for functions related to file processing can be found at
*   https://en.cppreference.com/w/c/io
* - See the technical notes in the header or `ascii_processor_app.c`.
*
* Because file may be rather large - too large to fit into available memory - 
* they shall be read and written in chunks of a few bytes (e.g. 32 bytes).
* The buffer shall then be process 'on the fly', e.g. printed or compressed.
* The result of a compression shall be either written into a small buffer or
* directly to the file.
*
* @subsection rle Run-Length Encoding (RLE):
* RLE is a very simple compression algorithm suitable for content with a lot of 
* repeating symbols (such as ASCII Arts).
* It actually counts the number of repetitions of a single symbol and replaces
* the repeating symbol sequence with the count and the symbol.
*
* E.g. the text `aaabbbbbbbc` is compressed to `a3b7c1`.
* The RLE encoded content shall be stored as binary file. 
*
* More than 256 repetitions of a symbol shall be broken in the multiple tokens,
* where each token codes at maximum 256 repetitions. 
* E.g. 258 'r's shall be encoded as `r256r2`. 
* This allows using an 8-bit unsigned integer type as counter.
*
* Although this simple approach could lead to even longer content (e.g. `abc` -> `a1b1c1`)
* it is sufficient for this assignment, because it simplifies the implementation
* of the RLE encoder (compression) and decoder (expander) significantly.
*
* A more advanced implementation of RLE may benefit from the limitied ASCII character range
* of 0 -127. Character codes could be negated (*-1) to use the MSB as flag for distinguishing
* between counter and symbol. Caution must be taken at the end of compressed buffers, since
* splitting of counter and symbol into different buffers of fixed sizes cannot be safely avoided.
*
* see also: https://de.wikipedia.org/wiki/Laufl%C3%A4ngenkodierung
*
* @section instructions Working Instructions
*
* -# Implement an application that lists the content of subdirectory `./ascii-art` 
* and produces the following output: 
* ~~~~
* Listing files of directory: ./ascii_art
*  - dilbert.txt (2259 B)
*  - car.txt (662 B)
*  - computer.txt (1007 B)
*  - pattern.txt (1152 B)
*  - astronaut.txt (3713 B)
* Directory listing completed successfully (files: 5)
* ~~~~
* The (relative) path of the directory, its files (!) including name and size and eventually the number of files shall be printed.
*   **--COMMIT--**
*
* **For each `*.txt` file in that directory:**
*
* -# Print the textual file content:
*   -# Print a headling containing the file path
*   -# Print the file content
*   -# Print a footer containing the number of read characters and again the file path
* ~~~~
* Content of file ./ascii_art/car.txt:
* 
*                               _.-="_-         _
*                          _.-="   _-          | ||"""""""---._______     __..
*              ___.===""""-.______-,,,,,,,,,,,,`-''----" """""       """""  __'
*       __.--""     __        ,'                   o \           __        [__|
*  __-""=======.--""  ""--.=================================.--""  ""--.=======:
* ]       [w] : /        \ : |========================|    : /        \ :  [w] :
* V___________:|          |: |========================|    :|          |:   _-"
*  V__________: \        / :_|=======================/_____: \        / :__-"
*  -----------'  "-____-"  `-------------------------------'  "-____-"
* Printed 662 characters from file ./ascii_art/car.txt
* ~~~~
*   **--COMMIT--**
*
* -# Compress the text file into a binary RLE encoded file:
*   -# Compress that file into a **binary** file with the same name but extension `.rle`.
*   -# Print the marker when the processing start naming the processed file
*   -# Print a status line that contains the number of uncompressed and compress bytes, the path
*      of the compressed file and the number of bytes written to the compressed file.
* ~~~~
* Compressing file ./ascii_art/car.txt ...
* Compressed 662 B in file ./ascii_art/car.txt to 396 B in file ./ascii_art/car.rle (40.2% smaller)
* ~~~~
*
* -# Read back the binary file, expand and print it
*   -# Read the compressed binary file (.rle) back, expand and print it on the fly.
*   -# Again print a header and a footer similar to step 1.
* ~~~~
* Printing compressed file ./ascii_art/car.rle:
* 
*                               _.-="_-         _
*                          _.-="   _-          | ||"""""""---._______     __..
*              ___.===""""-.______-,,,,,,,,,,,,`-''----" """""       """""  __'
*       __.--""     __        ,'                   o \           __        [__|
*  __-""=======.--""  ""--.=================================.--""  ""--.=======:
* ]       [w] : /        \ : |========================|    : /        \ :  [w] :
* V___________:|          |: |========================|    :|          |:   _-"
*  V__________: \        / :_|=======================/_____: \        / :__-"
*  -----------'  "-____-"  `-------------------------------'  "-____-
* Expanded 396 characters in file ./ascii_art/car.rle to 661 characters
* ~~~~
*   **--COMMIT--**
*
* -# Run the application. 
* 
*
* @section notes Notes
* -# `general.h` contains macros for finding the minimum, maximum, and absolute value 
* -# make cleantest: This new make target for clearing the console, building, and running unit test is available.
* -# Sometimes changes are not properly detected by incremental builds. If something very strange 
*    happens during compilation, try to run `make clean` followed by `make` to start a clean build.
*    This approach is also recommended after everthing is done, because some compiler warning appears
*    only in clean builds. 
*/