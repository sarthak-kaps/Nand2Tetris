@0
D = A
@SP
AM = M + 1
A = A - 1
M = D
@SP
AM = M - 1
D = M
@R13
M = D
@0
D = A
@LCL
D = M + D
@R14
M = D
@R13
D = M
@R14
A = M
M = D
(LOOP_START.input)
@0
D = A
@ARG
A = M + D
D = M
@SP
AM = M + 1
A = A - 1
M = D
@0
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
AM = M - 1
D = M
@R13
M = D
@0
D = A
@LCL
D = M + D
@R14
M = D
@R13
D = M
@R14
A = M
M = D
@0
D = A
@ARG
A = M + D
D = M
@SP
AM = M + 1
A = A - 1
M = D
@1
D = A
@SP
AM = M + 1
A = A - 1
M = D
@SP
AM = M - 1
D = M
A = A - 1
M = M - D
@SP
AM = M - 1
D = M
@R13
M = D
@0
D = A
@ARG
D = M + D
@R14
M = D
@R13
D = M
@R14
A = M
M = D
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
@LOOP_START.input
D; JNE
@0
D = A
@LCL
A = M + D
D = M
@SP
AM = M + 1
A = A - 1
M = D
