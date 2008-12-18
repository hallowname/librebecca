
cmake_minimum_required(VERSION 2.6)

#
# Project name of RebeccaAIML
#
project(librebecca)

#
# Set the variables for
# writing out config files
# such as Makefile's and 
# scripts as well as variables
# for use by us
#

# The root directory of rebecca source tree
# It is two up from this directory
set(ROOTDIR ${CMAKE_CURRENT_SOURCE_DIR})

# This is the build prefix which is 
# By default it is /usr/local 
set(BUILD_prefix ${CMAKE_INSTALL_PREFIX})

# This is the exec  prefix which is 
# By default it is /usr/local 
set(BUILD_exec_prefix ${CMAKE_INSTALL_PREFIX})

# This is where the include directory
# for the core engine's files are.  
# By default it is /usr/local/include
#
set(BUILD_includedir ${CMAKE_INSTALL_PREFIX}/include)

# This is where the lib directory
# containing the rebecca-mt.so is
# By default it is /usr/local/lib
set(BUILD_libdir ${CMAKE_INSTALL_PREFIX}/lib)

# This is where the bin directory
# containing sample executables 
# and shell scripts are going to 
# be.
# By default it is /usr/local/bin
set(BUILD_bindir ${CMAKE_INSTALL_PREFIX}/bin)

# This is where the data files 
# such as aiml files, configuration
# files etc all go.
# By default it is /usr/local/share
set(BUILD_datadir ${CMAKE_INSTALL_PREFIX}/share)

# Convience variable that 
# is used to put all data files
# into the build data dir "/" 
# Rebecca directory
# By default it is /usr/local/share/librebecca
#
set(REBECCA_DATADIR ${BUILD_datadir}/librebecca)

#
# Set the include files for 
# the core RebeccaAIML files
#
set(RebeccaAIML_INCLUDES ${ROOTDIR}/include)

#
# Core files for building the core library
# These depend on xercesc and berekely db
# being installed on the system
#
set(RebeccaAIML_SRCS
				${ROOTDIR}/src/rebecca/AimlFacade.cpp
				${ROOTDIR}/src/rebecca/GraphBuilder.cpp
				${ROOTDIR}/src/rebecca/StringPimpl.cpp
				${ROOTDIR}/src/rebecca/framework/AIML.cpp
				${ROOTDIR}/src/rebecca/framework/Bot.cpp
				${ROOTDIR}/src/rebecca/framework/Category.cpp
                ${ROOTDIR}/src/rebecca/framework/Condition.cpp
				${ROOTDIR}/src/rebecca/framework/Date.cpp
                ${ROOTDIR}/src/rebecca/framework/Formal.cpp
                ${ROOTDIR}/src/rebecca/framework/FrameworkFactory.cpp
                ${ROOTDIR}/src/rebecca/framework/Gender.cpp
                ${ROOTDIR}/src/rebecca/framework/Get.cpp
                ${ROOTDIR}/src/rebecca/framework/Gossip.cpp
                ${ROOTDIR}/src/rebecca/framework/GraphBuilderFramework.cpp
                ${ROOTDIR}/src/rebecca/framework/Id.cpp
                ${ROOTDIR}/src/rebecca/framework/IdentificationManager.cpp
                ${ROOTDIR}/src/rebecca/framework/InnerAIML.cpp
                ${ROOTDIR}/src/rebecca/framework/InnerCategory.cpp
                ${ROOTDIR}/src/rebecca/framework/InnerTemplaListImpl.cpp
                ${ROOTDIR}/src/rebecca/framework/InnerTemplate.cpp
                ${ROOTDIR}/src/rebecca/framework/InnerTopic.cpp
                ${ROOTDIR}/src/rebecca/framework/Input.cpp
                ${ROOTDIR}/src/rebecca/framework/Learn.cpp
                ${ROOTDIR}/src/rebecca/framework/Li.cpp
                ${ROOTDIR}/src/rebecca/framework/LowerCase.cpp
                ${ROOTDIR}/src/rebecca/framework/NonImplemented.cpp
                ${ROOTDIR}/src/rebecca/framework/Pattern.cpp
                ${ROOTDIR}/src/rebecca/framework/PatternSideThat.cpp
                ${ROOTDIR}/src/rebecca/framework/Person2.cpp
                ${ROOTDIR}/src/rebecca/framework/Person.cpp
                ${ROOTDIR}/src/rebecca/framework/PlainWord.cpp
                ${ROOTDIR}/src/rebecca/framework/Random.cpp
                ${ROOTDIR}/src/rebecca/framework/RemoveAIML.cpp
                ${ROOTDIR}/src/rebecca/framework/RemoveTopic.cpp
                ${ROOTDIR}/src/rebecca/framework/Sentence.cpp
                ${ROOTDIR}/src/rebecca/framework/Set.cpp
                ${ROOTDIR}/src/rebecca/framework/Size.cpp
                ${ROOTDIR}/src/rebecca/framework/Srai.cpp
                ${ROOTDIR}/src/rebecca/framework/Star.cpp
                ${ROOTDIR}/src/rebecca/framework/System.cpp
                ${ROOTDIR}/src/rebecca/framework/Tag.cpp
                ${ROOTDIR}/src/rebecca/framework/Template.cpp
                ${ROOTDIR}/src/rebecca/framework/TemplateSideThat.cpp
                ${ROOTDIR}/src/rebecca/framework/ThatStar.cpp
                ${ROOTDIR}/src/rebecca/framework/Think.cpp
                ${ROOTDIR}/src/rebecca/framework/Topic.cpp
                ${ROOTDIR}/src/rebecca/framework/TopicStar.cpp
                ${ROOTDIR}/src/rebecca/framework/UpperCase.cpp
                ${ROOTDIR}/src/rebecca/framework/Version.cpp
                ${ROOTDIR}/src/rebecca/impl/ConfigurationHandler.cpp
                ${ROOTDIR}/src/rebecca/impl/ConfigurationHandlerError.cpp
                ${ROOTDIR}/src/rebecca/impl/CustomTagWithDelete.cpp
                ${ROOTDIR}/src/rebecca/impl/DatabaseManager.cpp
                ${ROOTDIR}/src/rebecca/impl/Factory.cpp
                ${ROOTDIR}/src/rebecca/impl/getStringFromSentence.cpp
                ${ROOTDIR}/src/rebecca/impl/GraphBuilderAIML.cpp
                ${ROOTDIR}/src/rebecca/impl/GraphBuilderInternal.cpp
                ${ROOTDIR}/src/rebecca/impl/GraphHandler.cpp
                ${ROOTDIR}/src/rebecca/impl/GraphHandlerError.cpp
                ${ROOTDIR}/src/rebecca/impl/NodeMapper.cpp
                ${ROOTDIR}/src/rebecca/impl/PredicateManager.cpp
                ${ROOTDIR}/src/rebecca/impl/PreviousResponsesManager.cpp
                ${ROOTDIR}/src/rebecca/impl/RemoveGraphHandler.cpp
                ${ROOTDIR}/src/rebecca/impl/ScopedTransaction.cpp
                ${ROOTDIR}/src/rebecca/impl/StarsManager.cpp
                ${ROOTDIR}/src/rebecca/impl/TemplateParser.cpp
                ${ROOTDIR}/src/rebecca/impl/XercesSAXXMLManager.cpp
                ${ROOTDIR}/src/rebecca/impl/utils/Transcode.cpp
			   )
#
# The include directories of RebeccaAIML
# for building core
#
include_directories(${RebeccaAIML_INCLUDES})

# Create shared library
add_library(rebecca-mt SHARED ${RebeccaAIML_SRCS})

# Link external libs for rebecca-mt core
# These are required for the core
# -- also note dependecy to stldb4 or libdb++
target_link_libraries(rebecca-mt xerces-c)
target_link_libraries(rebecca-mt db_cxx)
target_link_libraries(rebecca-mt boost_filesystem)
target_link_libraries(rebecca-mt dl)
target_link_libraries(rebecca-mt boost_thread)
target_link_libraries(rebecca-mt boost_date_time)
target_link_libraries(rebecca-mt boost_regex)

# Set where to install everything
# for the console 
# By default it will install everything
# to
# /usr/local/lib
# /usr/local/bin
install (
	TARGETS rebecca-mt
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib	
)


# Install the root files
install (
	FILES ${ROOTDIR}/INSTALL
		  ${ROOTDIR}/README
		  ${ROOTDIR}/copyright
		  ${ROOTDIR}/TODO
	DESTINATION ${BUILD_datadir}/doc/librebecca
)

install (
	DIRECTORY ${ROOTDIR}/doc/userGuide
	DESTINATION ${BUILD_datadir}/doc/librebecca
	PATTERN "CVS" EXCLUDE
)

install (
	DIRECTORY ${ROOTDIR}/doc/web
	DESTINATION ${BUILD_datadir}/doc/librebecca
	PATTERN "CVS" EXCLUDE
)

# Install the header files
# of the core shared object
install (
	DIRECTORY ${ROOTDIR}/include/rebecca
	DESTINATION ${BUILD_includedir}
	PATTERN "CVS" EXCLUDE
)

# Install the AIML files
install (
	DIRECTORY ${ROOTDIR}/aiml/annotated_alice
	DESTINATION ${REBECCA_DATADIR}/aiml
	PATTERN "CVS" EXCLUDE
)

# Install the conf files
install (
	DIRECTORY ${ROOTDIR}/conf
	DESTINATION ${REBECCA_DATADIR}
	PATTERN "CVS" EXCLUDE
	PATTERN "serverconfig.properties" EXCLUDE
)

# Install the resources files
install (
	DIRECTORY ${ROOTDIR}/resources
	DESTINATION ${REBECCA_DATADIR}
	PATTERN "CVS" EXCLUDE
)

# Find doxygen and if found 
# Generate the doxygen and install
# it
FIND_PACKAGE(Doxygen)
IF(DOXYGEN_FOUND)

    #
    # Custom command to build the C++ api
    #
	ADD_CUSTOM_COMMAND (
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/doc/api/html/index.html
		COMMAND ${CMAKE_COMMAND} -E echo_append "Building API Documentation..."
		COMMAND ${DOXYGEN_EXECUTABLE} ${ROOTDIR}/doc/doxygen/Doxyfile_api
		COMMAND ${CMAKE_COMMAND} -E echo "Done."
	)
	
   	ADD_CUSTOM_TARGET (
        api_doc ALL DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/doc/api/html/index.html
	)

    #
    # Custom command to build the C++ api+framework
    #
	ADD_CUSTOM_COMMAND (
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/doc/api+framework/html/index.html
		COMMAND ${CMAKE_COMMAND} -E echo_append "Building API+framework Documentation..."
		COMMAND ${DOXYGEN_EXECUTABLE} ${ROOTDIR}/doc/doxygen/Doxyfile_api+framework
		COMMAND ${CMAKE_COMMAND} -E echo "Done."
	)
	
   	ADD_CUSTOM_TARGET (
        api_framework_doc ALL DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/doc/api+framework/html/index.html
	)

    #
    # Custom command to build the C++ api+framework+samples
    #
	ADD_CUSTOM_COMMAND (
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/doc/api+framework+samples/html/index.html
		COMMAND ${CMAKE_COMMAND} -E echo_append "Building API+framework+samples Documentation..."
		COMMAND ${DOXYGEN_EXECUTABLE} ${ROOTDIR}/doc/doxygen/Doxyfile_api+framework+samples
		COMMAND ${CMAKE_COMMAND} -E echo "Done."
	)
	
   	ADD_CUSTOM_TARGET (
        api_framework_samples_doc ALL DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/doc/api+framework+samples/html/index.html
	)

    #
    # Custom command to build the C++ api+samples
    #
	ADD_CUSTOM_COMMAND (
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/doc/api+samples/html/index.html
		COMMAND ${CMAKE_COMMAND} -E echo_append "Building API+samples Documentation..."
		COMMAND ${DOXYGEN_EXECUTABLE} ${ROOTDIR}/doc/doxygen/Doxyfile_api+samples
		COMMAND ${CMAKE_COMMAND} -E echo "Done."
	)
	
   	ADD_CUSTOM_TARGET (
        api_samples_doc ALL DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/doc/api+samples/html/index.html
	)

    #
    # Custom command to build the csharp api
    #
	ADD_CUSTOM_COMMAND (
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/doc/csharp_api/html/index.html
		COMMAND ${CMAKE_COMMAND} -E echo_append "Building csharp api Documentation..."
		COMMAND ${DOXYGEN_EXECUTABLE} ${ROOTDIR}/doc/doxygen/Doxyfile_csharp_api
		COMMAND ${CMAKE_COMMAND} -E echo "Done."
	)
	
   	ADD_CUSTOM_TARGET (
        api_csharp_doc ALL DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/doc/csharp_api/html/index.html
	)

    #
    # Custom command to build the java api
    #
	ADD_CUSTOM_COMMAND (
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/doc/java_api/html/index.html
		COMMAND ${CMAKE_COMMAND} -E echo_append "Building java api Documentation..."
		COMMAND ${DOXYGEN_EXECUTABLE} ${ROOTDIR}/doc/doxygen/Doxyfile_java_api
		COMMAND ${CMAKE_COMMAND} -E echo "Done."
	)
	
   	ADD_CUSTOM_TARGET (
        api_java_doc ALL DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/doc/java_api/html/index.html
	)

    #
    # Custom command to build the python api
    #
	ADD_CUSTOM_COMMAND (
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/doc/python_api/html/index.html
		COMMAND ${CMAKE_COMMAND} -E echo_append "Building python api Documentation..."
		COMMAND ${DOXYGEN_EXECUTABLE} ${ROOTDIR}/doc/doxygen/Doxyfile_python_api
		COMMAND ${CMAKE_COMMAND} -E echo "Done."
	)
	
   	ADD_CUSTOM_TARGET (
        api_python_doc ALL DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/doc/python_api/html/index.html
	)

# 	# Install the api docs
 	install (
 		DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doc/api
 		DESTINATION ${BUILD_prefix}/share/doc/librebecca
 		PATTERN "CVS" EXCLUDE
         PATTERN "delme.txt" EXCLUDE
 	)
 
 	# Install the api+framework docs
 	install (
 		DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doc/api+framework
 		DESTINATION ${BUILD_prefix}/share/doc/librebecca
 		PATTERN "CVS" EXCLUDE
         PATTERN "delme.txt" EXCLUDE
 	)
 
 	# Install the api+framework+samples docs
 	install (
 		DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doc/api+framework+samples
 		DESTINATION ${BUILD_prefix}/share/doc/librebecca
 		PATTERN "CVS" EXCLUDE
         PATTERN "delme.txt" EXCLUDE
 	)
 
 	# Install the api+samples docs
 	install (
 		DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doc/api+samples
 		DESTINATION ${BUILD_prefix}/share/doc/librebecca
 		PATTERN "CVS" EXCLUDE
         PATTERN "delme.txt" EXCLUDE
 	)
 
 	# Install the java docs
 	install (
 		DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doc/java_api
 		DESTINATION ${BUILD_prefix}/share/doc/librebecca
 		PATTERN "CVS" EXCLUDE
         PATTERN "delme.txt" EXCLUDE
 	)
 
 	# Install the csharp docs
 	install (
 		DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doc/csharp_api
 		DESTINATION ${BUILD_prefix}/share/doc/librebecca
 		PATTERN "CVS" EXCLUDE
         PATTERN "delme.txt" EXCLUDE
 	)
 
 	# Install the python docs
 	install (
 		DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doc/python_api
 		DESTINATION ${BUILD_prefix}/share/doc/librebecca
 		PATTERN "CVS" EXCLUDE
         PATTERN "delme.txt" EXCLUDE
 	)
ENDIF(DOXYGEN_FOUND)

############################################
# Console sample executable (console)
############################################

# Set the source code of the console sample
set(console_SRCS ${ROOTDIR}/src/samples/console/console.cpp)

# Create console sample executable
add_executable(console ${console_SRCS})

# Link rebecca aiml library to the executable
target_link_libraries(console rebecca-mt)

#
# Write out all the configuration files 
# substituting the variables for their 
# values
#

# Write out console sample's Makefile
configure_file (
		${CMAKE_CURRENT_SOURCE_DIR}/scripts/console/Makefile.in
		${CMAKE_CURRENT_SOURCE_DIR}/scripts/console/Makefile
        @ONLY
)

# Write out console sample's console.sh
# shell script
configure_file (
		${CMAKE_CURRENT_SOURCE_DIR}/scripts/console/console.in
		${CMAKE_CURRENT_SOURCE_DIR}/scripts/console/console
)

# install the console sample's Makefile
# as well as the c++ files
install (
	FILES ${CMAKE_CURRENT_SOURCE_DIR}/scripts/console/Makefile
          ${ROOTDIR}/src/samples/console/console.cpp
	DESTINATION ${REBECCA_DATADIR}/src/samples/console
)

#setup scripts

install (
	FILES ${CMAKE_CURRENT_SOURCE_DIR}/scripts/console/console
	PERMISSIONS OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_READ GROUP_EXECUTE WORLD_READ
	WORLD_EXECUTE
	DESTINATION ${BUILD_bindir}
)

# Set where to install everything
# for the console
# By default it will install everything
# to
# /usr/local/lib
# /usr/local/bin
install (
	TARGETS console
	RUNTIME DESTINATION ${REBECCA_DATADIR}/bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)

############################################
# html converter sample library (libcustomHtmlTagLayer.so)
############################################

# Set the source code of the console AIML Html converter sample
set(customHtmlTagLayer_SRCS
	   	${ROOTDIR}/src/samples/consoleHtmlConverter_tag_layer/CustomAIML.cpp
	   	${ROOTDIR}/src/samples/consoleHtmlConverter_tag_layer/CustomTagsImpl.cpp
	   	${ROOTDIR}/src/samples/consoleHtmlConverter_tag_layer/CustomTopic.cpp
	   	${ROOTDIR}/src/samples/consoleHtmlConverter_tag_layer/Html.cpp
	   	${ROOTDIR}/src/samples/consoleHtmlConverter_tag_layer/InnerTemplateAIMLTags.cpp
	   	${ROOTDIR}/src/samples/consoleHtmlConverter_tag_layer/Links.cpp
	   	${ROOTDIR}/src/samples/consoleHtmlConverter_tag_layer/sanitizeString.cpp
	   	${ROOTDIR}/src/samples/consoleHtmlConverter_tag_layer/WebPage.cpp
)

# Create console AIML Html converter sample executable
add_library(customHtmlTagLayer SHARED ${customHtmlTagLayer_SRCS})

# Link the customHtmlTagLayer library to the executable
target_link_libraries(customHtmlTagLayer rebecca-mt)

# Set where to install everything
# for the console
# By default it will install everything
# to
# /usr/local/lib
# /usr/local/bin
install (
	TARGETS customHtmlTagLayer
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)

############################################
# html converter sample executable (consoleAIMLHtmlConverter)
############################################

# Set the source code of the console AIML Html converter sample
set(consoleAIMLHtmlConverter_SRCS
	   	${ROOTDIR}/src/samples/consoleHtmlConverter_tag_layer/consoleAIMLHtmlConverter.cpp
)

# Create console AIML Html converter sample executable
add_executable(consoleAIMLHtmlConverter ${consoleAIMLHtmlConverter_SRCS})

# Link the customHtmlTagLayer library to the executable
target_link_libraries(consoleAIMLHtmlConverter customHtmlTagLayer)

# Write out console AIML Html sample's Makefile
configure_file (
		${CMAKE_CURRENT_SOURCE_DIR}/scripts/consoleAIMLHtmlConverter/Makefile.in
		${CMAKE_CURRENT_SOURCE_DIR}/scripts/consoleAIMLHtmlConverter/Makefile
        @ONLY
)

# Write out console AIML Html sample's console.sh
# shell script
configure_file (
		${CMAKE_CURRENT_SOURCE_DIR}/scripts/consoleAIMLHtmlConverter/consoleAIMLHtmlConverter.in
		${CMAKE_CURRENT_SOURCE_DIR}/scripts/consoleAIMLHtmlConverter/consoleAIMLHtmlConverter
)

# install the console AIML Html sample's Makefile
# as well as the c++ files
install (
	FILES ${CMAKE_CURRENT_SOURCE_DIR}/scripts/consoleAIMLHtmlConverter/Makefile
          ${ROOTDIR}/src/samples/consoleHtmlConverter_tag_layer/consoleAIMLHtmlConverter.cpp
          ${ROOTDIR}/src/samples/consoleHtmlConverter_tag_layer/CustomAIML.cpp
          ${ROOTDIR}/src/samples/consoleHtmlConverter_tag_layer/CustomAIML.h
          ${ROOTDIR}/src/samples/consoleHtmlConverter_tag_layer/CustomTagsImpl.cpp
          ${ROOTDIR}/src/samples/consoleHtmlConverter_tag_layer/CustomTagsImpl.h
          ${ROOTDIR}/src/samples/consoleHtmlConverter_tag_layer/CustomTopic.cpp
          ${ROOTDIR}/src/samples/consoleHtmlConverter_tag_layer/CustomTopic.h
          ${ROOTDIR}/src/samples/consoleHtmlConverter_tag_layer/exports.h
          ${ROOTDIR}/src/samples/consoleHtmlConverter_tag_layer/HtmlConverterInternalProgrammerErrorException.h
          ${ROOTDIR}/src/samples/consoleHtmlConverter_tag_layer/Html.cpp
          ${ROOTDIR}/src/samples/consoleHtmlConverter_tag_layer/Html.h
          ${ROOTDIR}/src/samples/consoleHtmlConverter_tag_layer/InnerTemplateAIMLTags.cpp
          ${ROOTDIR}/src/samples/consoleHtmlConverter_tag_layer/InnerTemplateAIMLTags.h
          ${ROOTDIR}/src/samples/consoleHtmlConverter_tag_layer/Links.cpp
          ${ROOTDIR}/src/samples/consoleHtmlConverter_tag_layer/Links.h
          ${ROOTDIR}/src/samples/consoleHtmlConverter_tag_layer/sanitizeString.cpp
          ${ROOTDIR}/src/samples/consoleHtmlConverter_tag_layer/sanitizeString.h
          ${ROOTDIR}/src/samples/consoleHtmlConverter_tag_layer/typedefs.h
          ${ROOTDIR}/src/samples/consoleHtmlConverter_tag_layer/WebPage.cpp
          ${ROOTDIR}/src/samples/consoleHtmlConverter_tag_layer/WebPage.h
	DESTINATION ${REBECCA_DATADIR}/src/samples/consoleHtmlConverter_tag_layer
)

# install the console sample's console script
install (
	FILES ${CMAKE_CURRENT_SOURCE_DIR}/scripts/consoleAIMLHtmlConverter/consoleAIMLHtmlConverter
	PERMISSIONS OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_READ GROUP_EXECUTE WORLD_READ
	WORLD_EXECUTE
	DESTINATION ${BUILD_bindir}
)

# Set where to install everything
# for the console
# By default it will install everything
# to
# /usr/local/lib
# /usr/local/bin
install (
	TARGETS consoleAIMLHtmlConverter
	RUNTIME DESTINATION ${REBECCA_DATADIR}/bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)

############################################
# regression executable (regression)
############################################

# Set the source code of regression
set(regression_SRCS 
		${ROOTDIR}/src/tests/regression/main.cpp
		${ROOTDIR}/src/tests/regression/TestCases.cpp
		${ROOTDIR}/src/tests/regression/TestCasesHandler.cpp
)

# Add the include files for regression
include_directories(${ROOTDIR}/src/tests/regression/include)

# Create regression executable
add_executable(regression ${regression_SRCS})

# Link rebecca aiml library to regression
target_link_libraries(regression rebecca-mt)

#
# Write out all the configuration files 
# substituting the variables for their 
# values
#

# Write out regression's 
# shell script
configure_file (
		${CMAKE_CURRENT_SOURCE_DIR}/scripts/regression/regression.in
		${CMAKE_CURRENT_SOURCE_DIR}/scripts/regression/regression
)

# install the regression's shell script
install (
	FILES ${CMAKE_CURRENT_SOURCE_DIR}/scripts/regression/regression
	PERMISSIONS OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_READ GROUP_EXECUTE WORLD_READ
	WORLD_EXECUTE
	DESTINATION ${BUILD_bindir}
)

# Set where to install everything
# for regression
# By default it will install everything
# to
# /usr/local/lib
# /usr/local/bin
install (
	TARGETS regression
	RUNTIME DESTINATION ${REBECCA_DATADIR}/bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)


# ############################################
# # ICE c++ server executable (rebecca-server)
# ############################################
# 
# # Set the source code of the server
# set(rebecca_server_SRCS 
# 		${ROOTDIR}/src/ice/server/cpp/rebecca/impl/network.cpp
# 		${ROOTDIR}/src/ice/server/cpp/main.cpp
# )
# 
# # Add the include files for ICE
# include_directories(${ROOTDIR}/src/ice/server/cpp/)
# 
# # Create the server executable
# add_executable(rebecca-server ${rebecca_server_SRCS})
# 
# # Link to the ICE libraries
# target_link_libraries(rebecca-server Ice)
# 
# # Link to the ICE libraries
# target_link_libraries(rebecca-server rebecca-mt)
# 
# # Write out server's 
# # shell script
# configure_file (
# 		${CMAKE_CURRENT_SOURCE_DIR}/scripts/rebecca-server/rebecca-server.in
# 		${CMAKE_CURRENT_SOURCE_DIR}/scripts/rebecca-server/rebecca-server
# )
# 
# # Write out server's 
# # serverconfig.properties file
# configure_file (
# 		${CMAKE_CURRENT_SOURCE_DIR}/scripts/rebecca-server/serverconfig.in
# 		${CMAKE_CURRENT_SOURCE_DIR}/scripts/rebecca-server/serverconfig.properties
# )
# 
# # install rebecca server's script that calls its executable
# install (
# 	FILES ${CMAKE_CURRENT_SOURCE_DIR}/scripts/rebecca-server/rebecca-server
# 	PERMISSIONS OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_READ GROUP_EXECUTE WORLD_READ
# 	WORLD_EXECUTE
# 	DESTINATION ${BUILD_bindir}
# )
# 
# # install the serverconfig properties file
# # install rebecca server's script that calls its executable
# install (
# 	FILES ${CMAKE_CURRENT_SOURCE_DIR}/scripts/rebecca-server/serverconfig.properties
# 	DESTINATION ${REBECCA_DATADIR}/conf
# )
# 
# # Set where to install everything
# # for the server (rebecca-server)
# # By default it will install the
# # the library to /usr/local/lib
# install (
# 	TARGETS rebecca-server
# 	RUNTIME DESTINATION ${REBECCA_DATADIR}/bin
# 	LIBRARY DESTINATION lib
# 	ARCHIVE DESTINATION lib
# )
# 
# ############################################
# # ICE c++ client dll (rebecca-network.so)
# ############################################
# 
# # Set the source code of the console sample
# set(cpp_ice_client_SRCS 
# 		${ROOTDIR}/src/ice/clients/cpp/rebecca/NetworkAimlFacade.cpp
# 		${ROOTDIR}/src/ice/clients/cpp/rebecca/NetworkGraphBuilder.cpp
# 		${ROOTDIR}/src/ice/clients/cpp/rebecca/impl/network.cpp
#         ${ROOTDIR}/src/ice/clients/cpp/rebecca/impl/NetworkGraphBuilderAIML.cpp
# )
# 
# # Add the include files for ICE
# include_directories(${ROOTDIR}/src/ice/clients/cpp)
# 
# # Create shared library
# add_library(rebecca-network SHARED ${cpp_ice_client_SRCS})
# 
# # Link to the ICE libraries
# target_link_libraries(rebecca-network Ice)
# 
# # Link to the rebecca aiml mt library
# target_link_libraries(rebecca-network rebecca-mt)
# 
# # Set where to install everything
# # for the rebecca-network
# # By default it will install the
# # the library to /usr/local/lib
# install (
# 	TARGETS rebecca-network
# 	RUNTIME DESTINATION bin
# 	LIBRARY DESTINATION lib
# 	ARCHIVE DESTINATION lib
# )
# 
# ############################################
# # Console network sample executable (console-network)
# ############################################
# 
# # Set the source code of the console network sample
# set(console_network_SRCS ${ROOTDIR}/src/samples/network/cpp/console/console-network.cpp)
# 
# # Create console network sample executable
# add_executable(console-network ${console_network_SRCS})
# 
# # Link rebecca network library to the executable
# target_link_libraries(console-network rebecca-network)
# 
# # Write out console sample's Makefile
# configure_file (
# 		${CMAKE_CURRENT_SOURCE_DIR}/scripts/console-network/Makefile.in
# 		${CMAKE_CURRENT_SOURCE_DIR}/scripts/console-network/Makefile
#         @ONLY
# )
# 
# # Write out console sample's console.sh
# # shell script
# configure_file (
# 		${CMAKE_CURRENT_SOURCE_DIR}/scripts/console-network/console-network.in
# 		${CMAKE_CURRENT_SOURCE_DIR}/scripts/console-network/console-network
# )
# 
# # install the console sample's Makefile
# # as well as the c++ files
# install (
# 	FILES ${CMAKE_CURRENT_SOURCE_DIR}/scripts/console-network/Makefile
#           ${ROOTDIR}/src/samples/network/cpp/console/console-network.cpp
# 	DESTINATION ${REBECCA_DATADIR}/src/samples/network/cpp/console
# ) 
# 
# # install the console sample's console script
# install (
# 	FILES ${CMAKE_CURRENT_SOURCE_DIR}/scripts/console-network/console-network
# 	PERMISSIONS OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_READ GROUP_EXECUTE WORLD_READ
# 	WORLD_EXECUTE
# 	DESTINATION ${BUILD_bindir}
# )
# 
# # Set where to install everything
# # for the rebecca-console-network
# # By default it will install the
# # the library to /usr/local/lib
# install (
# 	TARGETS console-network
# 	RUNTIME DESTINATION ${REBECCA_DATADIR}/bin
# 	LIBRARY DESTINATION lib
# 	ARCHIVE DESTINATION lib
# )
# 
# ############################################
# # rebecca server sample executable (rs-admin)
# ############################################
# 
# # Set the source code of the rs-admin sample
# set(rs_admin_SRCS ${ROOTDIR}/src/samples/network/cpp/rs-admin/rs-admin.cpp)
# 
# # Add the include files for regression
# include_directories(${ROOTDIR}/src/samples/network/cpp/rs-admin)
# 
# # Create console network sample executable
# add_executable(rs-admin ${rs_admin_SRCS})
# 
# # Link rebecca network library to the executable
# target_link_libraries(rs-admin rebecca-network)
# 
# # Write out rs-admin's Makefile
# configure_file (
# 		${CMAKE_CURRENT_SOURCE_DIR}/scripts/rs-admin/Makefile.in
# 		${CMAKE_CURRENT_SOURCE_DIR}/scripts/rs-admin/Makefile
#         @ONLY
# )
# 
# # Write out rs-admin's sample's 
# # shell script
# configure_file (
# 		${CMAKE_CURRENT_SOURCE_DIR}/scripts/rs-admin/rs-admin.in
# 		${CMAKE_CURRENT_SOURCE_DIR}/scripts/rs-admin/rs-admin
# )
# 
# # install rs-admin sample's Makefile
# # as well as the c++ files
# install (
# 	FILES ${CMAKE_CURRENT_SOURCE_DIR}/scripts/rs-admin/Makefile
#           ${ROOTDIR}/src/samples/network/cpp/rs-admin/rs-admin.cpp
# 		  ${ROOTDIR}/src/samples/network/cpp/rs-admin/resource.h
# 		  ${ROOTDIR}/src/samples/network/cpp/rs-admin/usages.h
# 	DESTINATION ${REBECCA_DATADIR}/src/samples/network/cpp/rs-admin
# ) 
# 
# # install rs-admin sample's console script
# install (
# 	FILES ${CMAKE_CURRENT_SOURCE_DIR}/scripts/rs-admin/rs-admin
# 	PERMISSIONS OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_READ GROUP_EXECUTE WORLD_READ
# 	WORLD_EXECUTE
# 	DESTINATION ${BUILD_bindir}
# )
# 
# # Set where to install everything
# # for the rebecca-console-network
# # By default it will install the
# # the library to /usr/local/lib
# install (
# 	TARGETS rs-admin
# 	RUNTIME DESTINATION ${REBECCA_DATADIR}/bin
# 	LIBRARY DESTINATION lib
# 	ARCHIVE DESTINATION lib
# )

############################################
# QT sample executable (qtgui)
############################################

# Find doxygen and if found 
# Generate the doxygen and install
# it
FIND_PACKAGE(Qt4)
IF(QT4_FOUND)

	# Set the source code of the qt sample
	set(qtgui_SRCS 
			${ROOTDIR}/src/samples/qtgui/AIMLEngine.cpp
			${ROOTDIR}/src/samples/qtgui/AIMLEngineThread.cpp
			${ROOTDIR}/src/samples/qtgui/MainWindow.cpp
			${ROOTDIR}/src/samples/qtgui/main.cpp
	)

    # Header files to moc
    QT_WRAP_CPP(qtgui qtgui_moc ${ROOTDIR}/src/samples/qtgui/AIMLEngine.h
			                    ${ROOTDIR}/src/samples/qtgui/AIMLEngineThread.h
			                    ${ROOTDIR}/src/samples/qtgui/MainWindow.h
								${ROOTDIR}/src/samples/qtgui/QtGuiCallBacks.h)

    # include directory of QT sample
    include_directories(${ROOTDIR}/src/samples/qtgui)

    # include directory of QT
	include_directories(${QT_INCLUDES})

	# Create qt sample executable
	add_executable(qtgui ${qtgui_SRCS} ${qtgui_moc})

	target_link_libraries(qtgui c)

	# Link rebecca aiml library to the executable
	target_link_libraries(qtgui rebecca-mt)

	# Link the QT core library to the executable
	target_link_libraries(qtgui ${QT_QTCORE_LIBRARY})

	# Link the QT gui library to the executable
	target_link_libraries(qtgui ${QT_QTGUI_LIBRARY})

	#
	# Write out all the configuration files 
	# substituting the variables for their 
	# values
	#

	# Write out qtgui sample's .pro file
	configure_file (
			${CMAKE_CURRENT_SOURCE_DIR}/scripts/qtgui/qtgui.pro.in
			${CMAKE_CURRENT_SOURCE_DIR}/scripts/qtgui/qtgui.pro
        	@ONLY
	)

	# Write out qtgui sample's qtgui
	# shell script
	configure_file (
			${CMAKE_CURRENT_SOURCE_DIR}/scripts/qtgui/qtgui.in
			${CMAKE_CURRENT_SOURCE_DIR}/scripts/qtgui/qtgui
	)

	# install qtgui sample's .pro file
	# as well as the c++ files
	install (
		FILES ${CMAKE_CURRENT_SOURCE_DIR}/scripts/qtgui/qtgui.pro
		DESTINATION ${REBECCA_DATADIR}/src/samples/qtgui
	)

	# install qtgui sample's script
	install (
		FILES ${CMAKE_CURRENT_SOURCE_DIR}/scripts/qtgui/qtgui
		PERMISSIONS OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_READ GROUP_EXECUTE WORLD_READ
		WORLD_EXECUTE
		DESTINATION ${BUILD_bindir}
	)

	# Set where to install everything
	# for qtgui
	# By default it will install everything
	# to
	# /usr/local/lib
	# /usr/local/bin
	install (
		TARGETS qtgui
		RUNTIME DESTINATION ${REBECCA_DATADIR}/bin
		LIBRARY DESTINATION lib
		ARCHIVE DESTINATION lib
	)

ENDIF(QT4_FOUND)
