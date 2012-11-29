#############################################################################
# Refactoring

PROG = rent
ECHO = /bin/echo

#----------------------------------------------------------------------------
CXX      = g++
FLAGS    = -g

#===============================================================================
help:
	@echo 'The following targets may be used: '
	@echo '     rent'
	@echo '     clean - Remove *.o, etc. '
	@echo '     help  - This message'

#============================================================================
#prog: rent
#	@echo ''
#
#----------------------------------------------------------------------------
rent: movie.o rental.o customer.o main.o
	$(CXX) movie.o rental.o main.o customer.o -o rent   ${C_OUT_2}

#----------------------------------------------------------------------------
movie.o: movie.h movie.cpp
	$(CXX) $(FLAGS) -c movie.cpp                        ${C_OUT_2}

#----------------------------------------------------------------------------
rental.o: rental.h rental.cpp
	$(CXX) $(FLAGS) -c rental.cpp                       ${C_OUT_2}

#----------------------------------------------------------------------------
customer.o: customer.h customer.cpp
	$(CXX) $(FLAGS) -c customer.cpp                     ${C_OUT_2}

#----------------------------------------------------------------------------
main.o: movie.h rental.h main.cpp
	$(CXX) $(FLAGS) -c main.cpp                         ${C_OUT_2}

#===========================================================================
# Compile
prog: COMPILER_OUTFILE = compiler_output.txt
prog: C_OUT_1 = >& ${COMPILER_OUTFILE}
prog: C_OUT_2 = >> ${COMPILER_OUTFILE} 2>&1
prog: compiler_note ${PROG}
	@${ECHO} '-----------------------------------------------------------------' ${C_OUT_2}
	@${ECHO} 'Done compiling: ' ${PROG}

compiler_note:
	@${ECHO} 'Any output from the compiler is between the dashed lines.'         ${C_OUT_1}
	@${ECHO} 'There should not be any output from the compiler.'                 ${C_OUT_2}
	@${ECHO} 'If you have errors or warnings when writing your programs ask'     ${C_OUT_2}
	@${ECHO} 'your instructor for help.'                                         ${C_OUT_2}
	@${ECHO} 'Warnings should not be ignored, they indicate potential problems.' ${C_OUT_2}
	@${ECHO} '-----------------------------------------------------------------' ${C_OUT_2}

#===============================================================================
runo: PROGRAM_OUTFILE = program_output.txt
runo: OUT_1 = >& ${PROGRAM_OUTFILE}
runo: OUT_2 = >> ${PROGRAM_OUTFILE} 2>&1
runo: run

run: rent startrun rentrun finishrun
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

rentrun:
	@echo '===============================================================' ${OUT_2}
	@echo 'Program output:'                                                 ${OUT_2}
	@echo ''                                                                ${OUT_2}
	@./rent                                                                 ${OUT_2}
	@echo ''                                                                ${OUT_2}

finishrun:
	@echo '===============================================================' ${OUT_2}

#============================================================================
clean:
	rm -f rent  *.o 
	rm -f a.out core*

veryclean: clean
	rm -f program_output.txt
	rm -f compiler_output.txt
	rm -f log_messages.txt


