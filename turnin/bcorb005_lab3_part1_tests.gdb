# Test file for "Lab3_BitManip"


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

# Example test:
test "PINA: 0x00, PINB: 0x00 => PORTC: 0x00"
# Set inputs
setPINA 0x00
setPINB 0x00
# Continue for several ticks
continue 2
# Set expect values
expectPORTC 0x00
# Check pass/fail
checkResult

# Add tests below
test "PINA: 0x3B, PINB: 0xF0 => PORTC: 0x09"
setPINA 0x3B # 5 pins
setPINB 0xF0 # 4 pins
continue 2
expectPORTC 0x09 # 9 pins
checkResult

test "PINA: 0xFF, PINB: 0xFF => PORTC: 0x10"
setPINA 0xFF # 8 pin
setPINB 0xFF # 8 pin
continue 2
expectPORTC 0x10 # 16 pin
checkResult

test "PINA: 0x01, PINB: 0x00 => PORTC: 0x01"
setPINA 0x01 # 1 pin
setPINB 0x00 # 0 pin
continue 2
expectPORTC 0x01 # 1pin
checkResult

test "PINA: 0x00, PINB: 0x01 => PORTC: 0x01"
setPINA 0x00 # 0 pin
setPINB 0x01 # 1 pin
continue 2
expectPORTC 0x01 # 1 pin
checkResult

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
