/*
 * =====================================================================================
 *
 *       Filename:  subrip.h
 *
 *    Description:  The parser for subrip (*.srt) files...
 *
 *        Version:  1.0
 *        Created:  18/06/2010 10:52:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */



/* #####   HEADER FILE INCLUDES   ################################################### */
#include "../utils/subtimes.h"                  /* needed for subtime_t */


/* #####   EXPORTED FUNCTION DECLARATIONS   ######################################### */
int is_subrip(char *buf);
char *subtime_to_srtstring(subtime_t timestamp);
subtime_t srtstring_to_subtime(char *timestamp, int *error);
