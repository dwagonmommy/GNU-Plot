#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lboost_system -lboost_system.dll -lboost_atomic.dll -lboost_chrono -lboost_chrono.dll -lboost_container.dll -lboost_context.dll -lboost_coroutine.dll -lboost_date_time.dll -lboost_exception -lboost_filesystem.dll -lboost_graph.dll -lboost_iostreams.dll -lboost_locale.dll -lboost_log.dll -lboost_log_setup.dll -lboost_math_c99.dll -lboost_math_c99f.dll -lboost_math_c99l.dll -lboost_math_tr1.dll -lboost_math_tr1f.dll -lboost_math_tr1l.dll -lboost_prg_exec_monitor.dll -lboost_program_options.dll -lboost_python.dll -lboost_python3.dll -lboost_random.dll -lboost_regex.dll -lboost_serialization.dll -lboost_signals.dll -lboost_system -lboost_system.dll -lboost_test_exec_monitor -lboost_thread.dll -lboost_timer -lboost_timer.dll -lboost_type_erasure.dll -lboost_unit_test_framework.dll -lboost_wave.dll -lboost_wserialization.dll

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gnuplottest.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gnuplottest.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gnuplottest ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gnuplottest.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
