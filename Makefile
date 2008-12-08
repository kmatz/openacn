##########################################################################
# 
# Copyright (c) 2007, Pathway Connectivity Inc.
# 
# All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
# 
#  * Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#  * Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#  * Neither the name of Pathway Connectivity Inc. nor the names of its
#    contributors may be used to endorse or promote products derived from
#    this software without specific prior written permission.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
# IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
# PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
# OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
# PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
# LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
# NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
# 
# 	$Id$
# 
##########################################################################
#
# Makefile for top level ACN directory
# 
# Mostly this just jumps into the build directory (directories) and
# builds from there

ALLBUILDS:=${patsubst build-%,%,${wildcard build-*}}

ifeq "${ALLBUILDS}" ""
${error No build directories found}
endif

##########################################################################
# Default target is all build directories - not good unless they all work
# on a common development system.
.PHONY: all ${ALLBUILDS}

all : ${ALLBUILDS}

##########################################################################
# Generic rule for building

${ALLBUILDS}:
	${MAKE} -C build-$@

.PHONY : clean

CLEANBUILDS=${addsuffix _clean, ${ALLBUILDS}}

clean : ${CLEANBUILDS}

${CLEANBUILDS}:
	${MAKE} -C ${patsubst %_clean,build-%,$@} clean

.PHONY: ts

ts:
	@echo ${ALLBUILDS}
