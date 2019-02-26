/* ******************************************************************** */
/*                                                                      */
/* Set.c --- this is the .c file associated with the (major 2) Set      */
/*           implementation used in Spring 2012's CSCE 1040 class.      */
/*                                                                      */
/*           This assignment includes 10 functions to be implemented    */
/*           in Set.c, namely                                           */
/*                                                                      */
/*                 clearSet                                             */
/*                 add2Set                                              */
/*                 deleteFromSet                                        */
/*                 isMember                                             */
/*                 printSet                                             */
/*                 setUnion                                             */
/*                 setIntersection                                      */
/*                                                                      */
/*  Author:  Philip Sweany                                              */
/*  No rights reserved                                                  */
/*                                                                      */
/* ******************************************************************** */

#include "set.h"


void setUnion(Set set1, Set set2, Set result)
{
    int i;
    for( i = 0; i < SET_SIZE; i++ )
        result[i] = set1[i] | set2[i];
    return;
}

void setIntersection(Set set1, Set set2, Set result)
{
    int i;
    for( i = 0; i < SET_SIZE; i++ )
        result[i] = set1[i] & set2[i];
    return;
}

void copySet(Set dest, Set src)
{
    int i;
    for( i = 0; i < SET_SIZE; i++ )
        dest[i] = src[i];
}

void clearSet(Set set)
{
    int i;
    for( i = 0; i < SET_SIZE; i++ )
        set[i] = 0;
}

void add2Set(Set set, int value)
{
    int word; 
    unsigned int mask;

    assert( value >= 0 && value <= 319 );
    mask = 1 << value % 32;
    word = value / 32;
    set[word] |= mask;
}

void deleteFromSet(Set set, int value)
{
    int word; 
    unsigned int mask;

    assert( value >= 0 && value <= 319 );
    mask = 1 << value % 32;
    word = value / 32;
    set[word] |= mask;
    set[word] ^= mask;
}

int isMember(Set set, int element)
{
    int word; 
    unsigned int mask;

    assert( element >= 0 && element <= 319 );
    mask = 1 << element % 32;
    word = element / 32;
    return set[word] & mask;
}

void printSet(Set set)
{
    int i;
//    printf("{ \n");
    printf("{");

    for( i = 0; i < 32 * SET_SIZE; i++ )
        if( isMember(set,i) )
        {
               printf("%4d",i);
               if( (i % 18) == 17 )
                   printf("\n");
        }
    printf("}\n");

}


int isEqual(Set src1, Set src2)
{
    int i;
    for( i = 0; i < SET_SIZE; i++ )
        if( src1[i] != src2[i] )
            return 0;  // FALSE
    return 1;  // TRUE
}
