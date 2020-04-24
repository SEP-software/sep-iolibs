/*$

=head1 NAME

separg - return the ith command linea argument

=head1 SYNOPSIS

C<ierr seperr(int iarg,char *arg)>

=head1 INPUT PARAMETERS

=over 4

=item	iarg -  int

      Argument number

=item	char* -  arg

     Arrgument

=back

=head1 RETURN VALUES

=over 4

=item	0 -  int

      Success

=item	1 -  int

     Requested an argument # greater than separgc

=item	-1 -  int

      Other failure

=back


=head1 DESCRIPTION

This function returns a command line argument by
number. It makes this assumption that the string
has been allocated.

=head1 KEYWORDS


=head1 LIBRARY

B<sep>

=cut



*/
/*
 * Written Bob: 030426
 */
#include "sepInternal.h"
#include <sepConfig.h>
#include <sep_main_external.h>
#include <stdio.h>
#include <string.h>
#if NeedFunctionPrototypes
_XFUNCPROTOBEGIN
int separg(int iarg, char *arg) _XFUNCPROTOEND
#else
/*VARARGS0*/
int separg(iarg, arg) int iarg;
char *arg;
#endif
{
  extern int sepxargc;
  extern char **sepxargv;
  if (getSepArgC() <= iarg)
    return (1);
  else
    strcpy(arg, getSepArgV()[iarg]);
  return 0;
}

#if NeedFunctionPrototypes
_XFUNCPROTOBEGIN
int sep_prog(char *arg) _XFUNCPROTOEND
#else
/*VARARGS0*/
int sep_prog(arg) char *arg;
#endif
{
  char *ourname;

  if (NULL == (ourname = strrchr(getSepArgV()[0], '/')))
    ourname = getSepArgV()[0];
  else
    ourname++;
  strcpy(arg, ourname);
  return 0;
}
