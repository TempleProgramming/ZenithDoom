#include <stdio.h>
#include <stdlib.h>

/* Macro */
#define GR_WIDTH 640
#define GR_HEIGHT 480

/* Types */
// In ZenithOS, many of these are actually structs but for simplicity I'll 
// leave them out for now.
typedef void U0;
typedef unsigned char U8;
typedef signed char I8;
typedef unsigned short U16;
typedef short I16;
typedef unsigned int U32;
typedef int I32;
typedef unsigned long long U64;
typedef long long I64;

/* Rendering */
typedef struct {
	U8 b;
	U8 g;
	U8 r;
	U8 pad;
} CBGR24;

typedef struct {
	CBGR24* fb_alias;
} something;

/* Globals */
extern something text;	// This is so you can do text.fb_alias[pixel] = color;

/* Functions */
U8 *MAlloc(size_t size)
{
	return malloc(size);
}

U8 *CAlloc(size_t count, size_t size)
{
	return calloc(count, size);
}

U8 *FileRead(U8* fname);