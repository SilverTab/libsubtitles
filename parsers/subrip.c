/*
 * =====================================================================================
 *
 *       Filename:  subrip.c
 *
 *    Description:  this is the subrip parser, it parses srt files into an
 *    array of subtitle_t objects
 *
 *        Version:  1.0
 *        Created:  18/06/2010 01:08:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jean-Nicolas Jolivet, 
 *
 * =====================================================================================
 */


/* #####   HEADER FILE INCLUDES   ################################################### */
#include <pcre.h> /* for regular expressions */
#include "../utils/subtimes.h"





/* #####   FUNCTION DEFINITIONS  -  EXPORTED FUNCTIONS   ############################ */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  is_subrip
 *  Description:  determines if the buffer passed is of subrip type...
 * =====================================================================================
 */
int is_subrip(char *buf)
{
    
    /* Test with a pattern... */
    return 0;
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  subtime_to_srtstring
 *  Description:  converts a subtime to a strstring format
 * =====================================================================================
 */
char *subtime_to_srtstring(subtime_t timestamp)
{
	char *ret_string = malloc(12); /* The result! */
	
	sprintf(ret_string, "%02d:%02d:%06.3f", timestamp.hours,
		timestamp.minutes, timestamp.seconds);
	
	ret_string[8] = ',';
	return ret_string;
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  srtstring_to_subtime
 *  Description:  converts an srt string timestamp to a subtime_t
 * =====================================================================================
 */
subtime_t srtstring_to_subtime(char *timestamp, int *error)
{
	char stampcpy[13];
	subtime_t ret_struct;
	int num_scan = 0;
	int shours, sminutes;
	float sseconds;
	
	*error = 0;
	/* We should copy the string so we can mess with it... */
	strlcpy(stampcpy, timestamp, 13);
	/* Is it the correct length? */
	if(strlen(timestamp) != 12) {
		*error = 1;
		return ret_struct;
	}
	stampcpy[8] = '.';
    printf("Cpy: %s\n", stampcpy);
	num_scan = sscanf(stampcpy, "%d:%d:%f", &shours, &sminutes, &sseconds);
	if(num_scan != 3) {
		*error = 1;
		return ret_struct;
	}
    printf("Second scanned: %f\n", sseconds);	
	ret_struct.hours = shours;
	ret_struct.minutes = sminutes;
	ret_struct.seconds = sseconds;
	
	return ret_struct;
}
