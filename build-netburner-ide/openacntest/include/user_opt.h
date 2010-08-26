/*--------------------------------------------------------------------*/
/*
Copyright (c) 2007, Engineering Arts (UK)

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

 * Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
 * Neither the name of Engineering Arts nor the names of its
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
/*--------------------------------------------------------------------*/
#ifndef __user_opt_h__
#define __user_opt_h__ 1

/*
Protocols and conformance
*/
#define CONFIG_DMP   0

/*
Architecture
*/
#define BYTE_ORDER BIG_ENDIAN

#define CONFIG_STACK_NETBURNER 1

#define USER_DEFINE_INTTYPES   1	/* Define our own types */

/*
Memory
*/
#define CONFIG_MEM MEM_STATIC

#define MAX_RXGROUPS    22
#define MAX_RLP_SOCKETS  4     /* need 2 for sdt */
#define MAX_LISTENERS   22     /* need 2 for sdt plus one for each component */
                               /* that wants to join us: 20 bytes each       */

#define MAX_TXBUFS                  20
#define MAX_NSK_SOCKETS              6
#define DMP_MAX_SUBSCRIPTIONS       10

#define SDT_MAX_COMPONENTS          20
#define SDT_MAX_CHANNELS            20
#define SDT_MAX_MEMBERS             40

/*
Logging
*/
#define CONFIG_ACNLOG ACNLOG_STDOUT

/* see everything */
#define CONFIG_LOGLEVEL LOG_DEBUG

/* but only these categories */
#define LOG_RLP    LOG_LOCAL0
#define LOG_RLPM   LOG_LOCAL0
#define LOG_SDT    LOG_LOCAL0
#define LOG_SDTM   LOG_LOCAL0
#define LOG_NSK    LOG_LOCAL0
#define LOG_NETX   LOG_LOCAL0
#define LOG_SLP    LOG_LOCAL0
#define LOG_DISC   LOG_LOCAL0
#define LOG_STAT   LOG_LOCAL0

#define CONFIG_RLP_SINGLE_CLIENT   1
#define CONFIG_RLP_CLIENTPROTO     PROTO_SDT

#endif
