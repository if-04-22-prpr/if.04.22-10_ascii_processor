/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: S10
 * Author:			*/<your name>;/*
 *-----------------------------------------------------------------------------
 * Description:
 * The main application for text file printing and compressing.
 *-----------------------------------------------------------------------------
*/

#include "ascii_processor.h"

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

#define MAX_PATH_LEN 260

/**
 * Lists the content of subdirectory 'ascii-art' and
 * processes all *.txt' files contained in that directory
 * in the following way:
 * 
 * For each *.txt file:
 * 1) print the content of that file to stdout (console)
 * 2) compress the file using an RLE compression algorithm as a binary *.rle file
 *    This file shall be created in the same folder as the source .txt file.
 * 3) print the decompressed content of the compressed file, expand the content on the fly.
 * 
 * - Use paths RELATIVE to the working directory (this directory), e.g. "./ascii-art"!
 * 
 * - For the format of the output see index.html or mainpage.h
 * 
 * - The buffer size for paths is 'MAX_PATH_LEN' as defined above.
 * 
 * - Close all successfully opened directory and files.
 * 
 * - Print an error message for unsuccessful operations, e.g when a file cannot be opened.
 * 
 * - Feel free using command line arguments for root path.
 * 
 * Hints:
 * # use POSIX functions `opendir, readdir, stat, closedir, (rewinddir)
 *   for traversing through directories. API doc for these functions 
 *   can be found at: https://pubs.opengroup.org/onlinepubs/009695399/functions/opendir.html 
 *   and referenced files.
 * # filter out current and parent directory entries
 * # the name of file is retrieved via directory descriptor, the size of a file requires 'stat' function
 * 
 */

int main(int argc, char *argv[]) {
    char* root_path = "./ascii_art";
    /.../;
}