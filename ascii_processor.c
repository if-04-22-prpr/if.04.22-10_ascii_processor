/*----------------------------------------------------------
 *				HTBLA-Leonding
 * ---------------------------------------------------------
 * Title:			ASCII Processor
 * Author:			*/<your name>;/*
 * ----------------------------------------------------------
 * Description:
 * Implementation of ASCII Processor functions.
 * ----------------------------------------------------------
 */

#include "ascii_processor.h"
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

/* The size of the read buffer. Should be even 
   to ensure RLE tokens are not split into multiple buffers */
#define BUFFER_SIZE 32
