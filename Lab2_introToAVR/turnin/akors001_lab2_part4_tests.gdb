# Test file for "Lab2_introToAVR"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n


test "PINA: 0x55, PINB: 0x02, PINC: 0x03 => PORTD: 0x5A"
setPINA 0x55
setPINB 0x02
setPINC 0x03
continue 2
expectPORTD 0x5A
checkResult


test "PINA: 20; PINB 120; PINC 20  => PORTD: 0xA1 : 0b101000,01 : 160+-3,0b01 "
setPINA 0x14
setPINB 0x78
setPINC 0x14
continue 2
expectPORTD 0xA1
checkResult

test "PINA: 20; PINB 120; PINC 100  => PORTD: 0xF1 : 0b111100,01 : 240+-3,0b01 "
setPINA 0x14
setPINB 0x78
setPINC 0x64
continue 2
expectPORTD 0xF1
checkResult

test "PINA: 101; PINB 120; PINC 20  => PORTD: 0xF3 : 0b111100,11 : 240+-3,0b11 "
setPINA 0x65
setPINB 0x78
setPINC 0x14
continue 2
expectPORTD 0xF3
checkResult

test "PINA: 0; PINB 0; PINC 0  => PORTD: 0x00 : 0b000000,00, 0+-3,0b00 "
setPINA 0x0
setPINB 0x0
setPINC 0x0
continue 2
expectPORTD 0x00
checkResult



# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
