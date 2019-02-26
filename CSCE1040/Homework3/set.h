/* ******************************************************************** */
/*                                                                      */
/* Set.h --- this is the .h file associated with the (major 2) Set      */
/*           implementation used in Spring 2012's CSCE 1040 class.      */
/*                                                                      */
/*        10/24/2013,                                                   */
/*           It has been updated to include isEqual for the Fall        */
/*           2013 1040 class.                                           */
/*                                                                      */
/*           This assignment includes 10 functions to be implemented    */
/*           in Set.c, namely                                           */
/*                                                                      */
/*                 clearSet                                             */
/*                 add2Set                                              */
/*                 deleteFromSet                                        */
/*                 isMember                                             */
/*                 isEqual                                              */
/*                 printSet                                             */
/*                 setUnion                                             */
/*                 setIntersection                                      */
/*                 copySet                                              */
/*                                                                      */
/*  Author:  Philip Sweany                                              */
/*  No rights reserved                                                  */
/*                                                                      */
/* ******************************************************************** */
#ifndef SETH
#define SETH

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SET_SIZE 10
// defining new type(s)
typedef unsigned int Set[SET_SIZE];

// declaring global variable(s)
                               

extern void setUnion(Set set1, Set set2, Set result);
extern void setIntersection(Set set1, Set set2, Set result);
extern void clearSet(Set set);
extern void add2Set(Set set, int value);
extern void deleteFromSet(Set set, int value);
extern int isMember(Set set, int element);
extern int isEqual(Set src1, Set src2);
extern void copySet(Set dest, Set src);


extern void printSet(Set);		    // this time printSet should
					    // print the DBrecord rather 
					    // than just the integer values 
					    // of the bit position.

#endif
