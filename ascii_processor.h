/*----------------------------------------------------------
 *				HTBLA-Leonding
 * ---------------------------------------------------------
 * Title:			ASCII Processor
 * Author:			*/<your name>;/*
 * ----------------------------------------------------------
 * Description:
 * Declaration of functions for ASCII Processor.
 * ----------------------------------------------------------
 */

#ifndef ___ASCII_PROCESSOR__H
#define ___ASCII_PROCESSOR__H

#include <stddef.h>

/**
 * Prints the content of the text file addressed by the given path
 * to stdout (console). Closes the file after it was successfully opened.
 * 
 * Because files may be very large, they are read in chunks.
 * 
 * @param path The path of the text file print.
 */
void print_text_file(char* path);

/**
 * Reads the content of the text file addressed by `src_path`,
 * compresses it using RLE compression algorithm, and writes it
 * to the (new) file address by `dst_path`.
 * 
 * Because files may be very large, they are read and written in chunks
 * and compressed on the fly to avoid large buffers.
 * 
 * @param src_path The path of the text file to compress.
 * @param dst_path The path of the compressed binary file.
 */
void compress_text_file(char* src_path, char* dst_path);

/**
 * Reads the content of the RLE compressed binary file addressed by `path`,
 * expands and prints it on the fly to stdout.
 * 
 * Because files may be very large, they are read in chunks.
 * 
 * @param path The path of the compressed binary file print.
 */
void print_compressed_file(char* path);

#endif
