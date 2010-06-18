/*
 * =====================================================================================
 *
 *       Filename:  subtimes.c
 *
 *    Description:  Subtitle timestamp implementation... implements a bunch of
 *    useful features to deal with subtitles time (conversion between specific
 *    formats like srt, sub, etc. to subtime_t)
 *
 *        Version:  1.0
 *        Created:  15/06/2010 12:22:10
 *       Revision:  none
 *       Compiler:  clang/llvm
 *
 *         Author:  Jean-Nicolas Jolivet (jeannicolascocoa@gmail.com), 
 *
 * =====================================================================================
 */
#include "subtimes.h"




/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  srtstring_to_subtime
 *  Description: converts a subtime_t to a secondstamp_t 
 * =====================================================================================
 */
secondstamp_t subtime_to_secondstamp(subtime_t timestamp)
{
	secondstamp_t result = 0;
	result += timestamp.hours * (60 * 60);
	result += timestamp.minutes * 60;
	result += timestamp.seconds;
	return result;
	
}



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  srtstring_to_subtime
 *  Description:  converts a secondstamp_t to a subtime_t
 * =====================================================================================
 */
subtime_t secondstamp_to_subtime(secondstamp_t secs)
{
	float leftover = 0;
	int hours = 0;
	int minutes = 0;
	subtime_t ret_struct;
	/* first the hours... */
	if(secs >= 3600) {
		hours = floor(secs / 3600);
		leftover = secs - (hours * 3600);
	}
	else {
		leftover = secs;
	}
	
	/* Minutes... */
	if(leftover >= 60) {
		minutes = floor(leftover / 60);
		leftover -= minutes * 60;
	}
	
	ret_struct.hours = hours;
	ret_struct.minutes = minutes;
	ret_struct.seconds = leftover;
	
	return ret_struct;
	
}


