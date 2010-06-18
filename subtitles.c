#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#include "parser.h"



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  readfile
 *  Description:  read the whole file into a buffer and parse it!
 * =====================================================================================
 */
int readfile (char *filepath)
{
    FILE *fp;
    long fz;
    char *buf;
    
    /* open the file and read the whole thing */
    fp = fopen(filepath, "r");
    if(!fp) {
        fprintf(stderr, "Couldn't open the file!\n");
        return 0;
    }
    fseek(fp, 0L, SEEK_END);
    fz = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    buf = (char *)malloc(fz);
    fread(buf, 1, fz, fp);
    
    parse(buf);

    return 1;

}		/* -----  end of function readfile  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  Well, this does the command line boring stuff...
 * =====================================================================================
 */

int main(int argc, char **argv)
{
    char *ovalue = NULL;
    char *infile = NULL;
    int c;

    opterr = 0;
    while((c = getopt(argc, argv, "o:")) != -1) {
        switch (c) {
            case 'o':
                ovalue = optarg;
                break;
            case '?':
                if(optopt == 'o')
                    fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                else if(isprint(optopt))
                    fprintf(stderr, "Unknown option -%c.\n", optopt);
                else
                    fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
                return 1;
            default:
                abort();
        }
    }
    
    if(argc != 4) {
        fprintf(stderr, "Usage: %s -o outfile infile.\n", argv[0]);
        return 1;
    }
    infile = argv[3];
    
    readfile(infile);
    

    return 0;
}

