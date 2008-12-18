#
# Simple makefile to illustrate 
# how to build a project using RebeccaAIML
#


#
# Where the rebecca includes are
# if you installed this through
# the common makefiles
#
REBECCA_INCLUDES=../../../include

#
# Where the rebecca shared object is 
# and where the exeutable is to be
# placed
#
REBECCA_LIB=../../../bin/release

${REBECCA_LIB}/console: console.o
	${CXX} -o ${REBECCA_LIB}/console console.o -L${REBECCA_LIB} -lrebecca-mt -Wl,-rpath=./

console.o: 
	${CXX} -I${REBECCA_INCLUDES} -c console.cpp


clean:
	-rm console.o	
	-rm ${REBECCA_LIB}/console
