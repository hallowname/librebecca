#
# Simple makefile to illustrate
# how to build a project using RebeccaAIML
#

#
# Where the rebecca includes are
#
REBECCA_INCLUDES=../../../include

#
# Where the rebecca shared object and
# executable is to go
#
REBECCA_LIB=../../..

#
# List of all the objects 
# that are to go into the shared object
#
#
SHARED_OBJS=CustomAIML.o\
	        CustomTagsImpl.o\
			CustomTopic.o\
			Html.o\
			InnerTemplateAIMLTags.o\
			Links.o\
			sanitizeString.o\
			WebPage.o

all: ${REBECCA_LIB}/libcustomHtmlTagLayer.so ${REBECCA_LIB}/consoleAIMLHtmlConverter

${REBECCA_LIB}/libcustomHtmlTagLayer.so: ${SHARED_OBJS} 
	${CXX} -shared -Wl,-soname,libcustomHtmlTagLayer.so -o ${REBECCA_LIB}/libcustomHtmlTagLayer.so ${SHARED_OBJS}

CustomAIML.o:
	${CXX} -I${REBECCA_INCLUDES} -c -fPIC CustomAIML.cpp

CustomTagsImpl.o:
	${CXX} -I${REBECCA_INCLUDES} -c -fPIC CustomTagsImpl.cpp

CustomTopic.o:
	${CXX} -I${REBECCA_INCLUDES} -c -fPIC CustomTopic.cpp

Html.o:
	${CXX} -I${REBECCA_INCLUDES} -c -fPIC Html.cpp

InnerTemplateAIMLTags.o:
	${CXX} -I${REBECCA_INCLUDES} -c -fPIC InnerTemplateAIMLTags.cpp

Links.o:
	${CXX} -I${REBECCA_INCLUDES} -c -fPIC Links.cpp

sanitizeString.o:
	${CXX} -I${REBECCA_INCLUDES} -c -fPIC sanitizeString.cpp

WebPage.o:
	${CXX} -I${REBECCA_INCLUDES} -c -fPIC WebPage.cpp

${REBECCA_LIB}/consoleAIMLHtmlConverter: consoleAIMLHtmlConverter.o
	${CXX} -o ${REBECCA_LIB}/consoleAIMLHtmlConverter consoleAIMLHtmlConverter.o -L${REBECCA_LIB} -lrebecca-mt -Wl,-rpath=./

consoleAIMLHtmlConverter.o:
	${CXX} -I${REBECCA_INCLUDES} -c consoleAIMLHtmlConverter.cpp 

clean:
	-rm ${SHARED_OBJS}
	-rm ${REBECCA_LIB}/libcustomHtmlTagLayer.so
	-rm ${REBECCA_LIB}/consoleAIMLHtmlConverter

