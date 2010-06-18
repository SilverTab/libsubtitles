/*
 * =====================================================================================
 *
 *       Filename:  subtimes.h
 *
 *    Description:  Various stuff related to subtitles timestamps
 *
 *        Version:  1.0
 *        Created:  15/06/2010 12:24:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jean-Nicolas Jolivet
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef _SUBTIMES_H_
#define _SUBTIMES_H_

/* #####   HEADER FILE INCLUDES   ################################################### */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


/* #####   EXPORTED TYPE DEFINITIONS   ############################################## */
typedef struct {
	int hours;
	int minutes;
	float seconds;
	
} subtime_t;

typedef float secondstamp_t;


/* #####   EXPORTED FUNCTION DECLARATIONS   ######################################### */
/* take a timestamp and return a formatted string */
char *subtime_to_srtstring(subtime_t timestamp);

/* The inverse method! Yay! */
subtime_t srtstring_to_subtime(char *timestamp, int *error);
secondstamp_t subtime_to_secondstamp(subtime_t timestamp);
int shift_subtime(subtime_t *t, float delay_seconds);
subtime_t secondstamp_to_subtime(secondstamp_t secs);

#endif