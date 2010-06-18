clang -O0 -std=c99 -pedantic-errors -Wall -o ./subtitles -ISource \
	libsubtitles.c \
	utils/subtimes.c