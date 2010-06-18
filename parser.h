/*
 * =====================================================================================
 *
 *       Filename:  parser.h
 *
 *    Description:  Well, this file does the actual parsing job. It doesn't
 *    work with files, but only with buffers. It detects the buffer types, get
 *    the proper parser and parses the file!
 *
 *        Version:  1.0
 *        Created:  18/06/2010 12:31:34
 *       Revision:  none
 *       Compiler:  clang/llvm
 *
 *         Author:  Jean-Nicolas Jolivet, 
 *
 * =====================================================================================
 */


#ifndef _PARSER_H_
#define _PARSER_H_

int parse(char *buf);

#endif
