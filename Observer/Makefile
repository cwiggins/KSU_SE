#============================================================================
# Observer

CPP          = g++
CPP_FLAGS    = -g
PROGS        = observer

TEST_PROG_DIR = ../../cs33901_shared/Observer/Cpp_Files/
TEST_IO_DIR   = ../../cs33901_shared/Observer/IO_Files/
OUT_DIR       = ./

INCLUDE_OPT     = -I . -I ${TEST_PROG_DIR}

ECHO = /bin/echo

#===============================================================================
# Grading
#TEST_PROG_DIR = ../../../cs33901_shared/Observer/Cpp_Files/
#TEST_IO_DIR   = ../../../cs33901_shared/Observer/IO_Files/
#RM_GRMF       = rm -f Makefile

#===============================================================================
help:
	@echo 'The following targets may be used: '
	@echo '     observer'
	@echo '     clean - Remove *.o, etc. '
	@echo '     help  - This message'

#===========================================================================
# Compile
prog: COMPILER_OUTFILE = compiler_output.txt
prog: C_OUT_1 = >& ${COMPILER_OUTFILE}
prog: C_OUT_2 = >> ${COMPILER_OUTFILE} 2>&1
prog: compiler_note ${PROGS}
	@${ECHO} '-----------------------------------------------------------------' ${C_OUT_2}
	@${ECHO} 'Done compiling: ' ${PROGS}

compiler_note:
	@${ECHO} 'Any output from the compiler is between the dashed lines.'         ${C_OUT_1}
	@${ECHO} 'There should not be any output from the compiler.'                 ${C_OUT_2}
	@${ECHO} 'If you have errors or warnings when writing your programs ask'     ${C_OUT_2}
	@${ECHO} 'your instructor for help.'                                         ${C_OUT_2}
	@${ECHO} 'Warnings should not be ignored, they indicate potential problems.' ${C_OUT_2}
	@${ECHO} '-----------------------------------------------------------------' ${C_OUT_2}

#===============================================================================
observer: monitor.o counting_observer.o accumulating_observer.o main.o
	$(CPP) $(CPP_FLAGS) monitor.o counting_observer.o accumulating_observer.o main.o -o observer   ${C_OUT_2}

main.o: counting_observer.h accumulating_observer.h ${TEST_PROG_DIR}main.cpp
	$(CPP) $(CPP_FLAGS) ${INCLUDE_OPT} -c ${TEST_PROG_DIR}main.cpp                                 ${C_OUT_2}

monitor.o: ${TEST_PROG_DIR}observable.h monitor.h monitor.cpp
	$(CPP) $(CPP_FLAGS) ${INCLUDE_OPT} -c monitor.cpp                                              ${C_OUT_2}

counting_observer.o: ${TEST_PROG_DIR}observer.h counting_observer.h counting_observer.cpp
	$(CPP) $(CPP_FLAGS) ${INCLUDE_OPT} -c counting_observer.cpp                                    ${C_OUT_2}

accumulating_observer.o: ${TEST_PROG_DIR}observer.h accumulating_observer.h accumulating_observer.cpp
	$(CPP) $(CPP_FLAGS) ${INCLUDE_OPT} -c accumulating_observer.cpp                                ${C_OUT_2}

#===============================================================================
runo: PROGRAM_OUTFILE = program_output.txt
runo: OUT_1 = >& ${PROGRAM_OUTFILE}
runo: OUT_2 = >> ${PROGRAM_OUTFILE} 2>&1
runo: run

run: INPUT = 'GoRxadE--  EmnTfooIbbbN3  21321G9  99SzzEmnp Astt RwwTbarH===L44I2dNwhyGz'
run: observer startrun observerrun finishrun
	@echo ''

startrun:
	@echo '===============================================================' ${OUT_1}
	@echo 'This file contains the output from running your programs.'       ${OUT_2}
	@echo 'Since input was redirected it does not appear in the output '    ${OUT_2}
	@echo 'as it does when you run your program and type the input '        ${OUT_2}
	@echo 'in the terminal window.'                                         ${OUT_2}
	@echo ''                                                                ${OUT_2}
	@echo 'There will be an error message if a program did not compile.'    ${OUT_2}
	@echo ''                                                                ${OUT_2}

observerrun:
	@echo '===============================================================' ${OUT_2}
	@echo "Input used: ${INPUT}"                                           ${OUT_2}
	@echo '---------------------------------------------------------------' ${OUT_2}
	@echo 'Program output:'                                                 ${OUT_2}
	@echo ${INPUT} | ./observer                                             ${OUT_2}

finishrun:
	@echo '===============================================================' ${OUT_2}

#===============================================================================
clean:
	rm -f  observer
	rm -f  *.o
	rm -f  a.out
	${RM_GRMF}

veryclean: clean
	rm -f program_output.txt

