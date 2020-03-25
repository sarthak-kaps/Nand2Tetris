(input.SimpleFunction.test)
@R13
M = 0
(LOOP.0)
@2
D = A
@R13
D = D - M
@END.0
D; JEQ
@SP
AM = M + 1
A = A - 1
M = 0
@R13
M = M + 1
@LOOP.0
0; JMP
(END.0)
@0
D = A
@LCL
A = M + D
D = M
@SP
AM = M + 1
A = A - 1
M = D
@1
D = A
@LCL
A = M + D
D = M
@SP
AM = M + 1
A = A - 1
M = D
@SP
AM = M - 1
D = M
A = A - 1
M = M + D
@SP
A = M - 1
M = !M
@0
D = A
@ARG
A = M + D
D = M
@SP
AM = M + 1
A = A - 1
M = D
@SP
AM = M - 1
D = M
A = A - 1
M = M + D
@1
D = A
@ARG
A = M + D
D = M
@SP
AM = M + 1
A = A - 1
M = D
@SP
AM = M - 1
D = M
A = A - 1
M = M - D
@5
D = A
@LCL
A = M - D
D = M
@R14
M = D
@SP
AM = M - 1
D = M
@ARG
A = M
M = D
@ARG
D = M
@R13
M = D
@LCL
D = M
@SP
M = D
@SP
AM = M - 1
D = M
@THAT
M = D
@SP
AM = M - 1
D = M
@THIS
M = D
@SP
AM = M - 1
D = M
@ARG
M = D
@SP
AM = M - 1
D = M
@LCL
M = D
@R13
D = M
@SP
M = D + 1
@R14
A = M
0; JMP
