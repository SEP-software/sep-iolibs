/*
opensocketstream


USAGE
opensocketscr(streaminf *info)

DESCRIPTION
Opens up dataset of type STREAMSCR
*/
/*
*
 *
 Author : Biondo??
 Modified: Bob 7/97 Changed prototypes
 *
 */
#include <sepConfig.h>
#include <stdio.h>
#include <fcntl.h>

#include <assert.h>


#ifdef RS6000
#undef __STR__
#endif

#include <string.h>

#ifndef _NFILE
#if defined(vax) || defined(sun)
#include <sys/param.h>
#define _NFILE NOFILE
#endif
#if defined(CONVEX) 
#include <limits.h>
#define _NFILE OPEN_MAX
#endif
#endif

#if defined(HAVE_RPC_RPC_H) || defined(__APPLE__)
#include <rpc/types.h>
#endif

#if defined(HAVE_TIRPC_RPC_RPC_H) 
#include <tirpc/rpc/types.h>
#endif
`
#include "streamlist.h"
#include "sep_main_internal.h"




#if NeedFunctionPrototypes
_XFUNCPROTOBEGIN 
void open_scrstream( streaminf *info )
_XFUNCPROTOEND 
#else
void open_scrstream( info )
     streaminf* info;
#endif
{
    
   assert( info->entrytype == STREAMINOUT || info->entrytype == STREAMSCR );


  /* creating a new output, go and make up the name */
        outname( info );

    /* initialise the default I/O routines */
    init_io(info );

}
