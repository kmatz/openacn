/*--------------------------------------------------------------------*/
/*
Copyright (c) 2008, Electronic Theatre Controls, Inc.

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

 * Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
 * Neither the name of Electronic Theatre Controls, Inc. nor the names of its
   contributors may be used to endorse or promote products derived from
   this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

  $Id$
*/
#ifndef MSLEEP_H_
#define MSLEEP_H_

/************************************************************************/
/*
Substitute a system function if we can
*/
#if CONFIG_STACK_WIN32
__inline void msleepex(int msecs)
{
  unsigned int t;
  t = GetTickCount();
  while (1) {
    if (GetTickCount() > t + msecs) {
      break;
    };
  }
}
#define msleep(msecs) Sleep(msecs)
#define HAVE_msleep 1

#elif (CONFIG_STACK_BSD || CONFIG_STACK_CYGWIN)

#include <unistd.h>
#define msleep(msecs) (void)usleep((msecs) * 1000)
#define HAVE_msleep 1

#elif CONFIG_STACK_NETBURNER

#include "constants.h"
#define msleep(msecs) OSTimeDly(msecs/(1000/TICKS_PER_SECOND))

#define HAVE_msleep 1

#else
void msleep(int mseconds);
#endif

#endif /* MSLEEP_H_ */
