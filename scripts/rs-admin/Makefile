#
# Simple makefile to illustrate 
# how to build a project using RebeccaAIML
#

#
# Where you installed the distribution
#
prefix=/usr/local 

#
# Where you wanted the the lib
# to be located.  This is usually
# the same place as the prefix.
#
exec_prefix=/usr/local

#
# Where the rebecca includes are
#
REBECCA_INCLUDES=/usr/local/include

#
# Where the rebecca shared object is 
#
REBECCA_LIB=/usr/local/lib

#
# Where to output the sample
#
REBECCA_OUTPUT=/usr/local/share/librebecca/bin


${REBECCA_OUTPUT}/rs-admin: rs-admin.o
	${CXX} -o ${REBECCA_OUTPUT}/rs-admin rs-admin.o -L${REBECCA_LIB} -lrebecca-network -Wl,-rpath=${REBECCA_LIB}

rs-admin.o: rs-admin.cpp
	${CXX} -I${REBECCA_INCLUDES} -I./ -c rs-admin.cpp


clean:
	-rm rs-admin.o	
	-rm ${REBECCA_OUTPUT}/rs-admin
