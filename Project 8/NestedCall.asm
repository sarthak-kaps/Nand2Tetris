(input.Sys.init)
@R13
M = 0
(LOOP.0)
@0
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
@4000
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
@3
D = A + D
@R14
M = D
@R13
D = M
@R14
A = M
M = D
@5000
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
@1
D = A
@3
D = A + D
@R14
M = D
@R13
D = M
@R14
A = M
M = D
@input.5
D = A
@SP
AM = M + 1
A = A - 1
M = D
@LCL
D = M
@SP
AM = M + 1
A = A - 1
M = D
@ARG
D = M
@SP
AM = M + 1
A = A - 1
M = D
@THIS
D = M
@SP
AM = M + 1
A = A - 1
M = D
@THAT
D = M
@SP
AM = M + 1
A = A - 1
M = D
@SP
D = M
@LCL
M = D
@0
D = A
@5
D = D + A
@SP
D = M - D
@ARG
M = D
@input.Sys.main
0; JMP
(input.5)
@SP
AM = M - 1
D = M
@R13
M = D
@1
D = A
@5
D = A + D
@R14
M = D
@R13
D = M
@R14
A = M
M = D
(LOOP)
@LOOP
0; JMP
(input.Sys.main)
@R13
M = 0
(LOOP.9)
@5
D = A
@R13
D = D - M
@END.9
D; JEQ
@SP
AM = M + 1
A = A - 1
M = 0
@R13
M = M + 1
@LOOP.9
0; JMP
(END.9)
@4001
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
@3
D = A + D
@R14
M = D
@R13
D = M
@R14
A = M
M = D
@5001
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
@1
D = A
@3
D = A + D
@R14
M = D
@R13
D = M
@R14
A = M
M = D
@200
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
@1
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
@40
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
@2
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
@6
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
@3
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
@123
D = A
@SP
AM = M + 1
A = A - 1
M = D
@input.21
D = A
@SP
AM = M + 1
A = A - 1
M = D
@LCL
D = M
@SP
AM = M + 1
A = A - 1
M = D
@ARG
D = M
@SP
AM = M + 1
A = A - 1
M = D
@THIS
D = M
@SP
AM = M + 1
A = A - 1
M = D
@THAT
D = M
@SP
AM = M + 1
A = A - 1
M = D
@SP
D = M
@LCL
M = D
@1
D = A
@5
D = D + A
@SP
D = M - D
@ARG
M = D
@input.Sys.add12
0; JMP
(input.21)
@SP
AM = M - 1
D = M
@R13
M = D
@0
D = A
@5
D = A + D
@R14
M = D
@R13
D = M
@R14
A = M
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
@1
D = A
@LCL
A = M + D
D = M
@SP
AM = M + 1
A = A - 1
M = D
@2
D = A
@LCL
A = M + D
D = M
@SP
AM = M + 1
A = A - 1
M = D
@3
D = A
@LCL
A = M + D
D = M
@SP
AM = M + 1
A = A - 1
M = D
@4
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
A = A - 1
M = M + D
@SP
AM = M - 1
D = M
A = A - 1
M = M + D
@SP
AM = M - 1
D = M
A = A - 1
M = M + D
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
(input.Sys.add12)
@R13
M = 0
(LOOP.33)
@0
D = A
@R13
D = D - M
@END.33
D; JEQ
@SP
AM = M + 1
A = A - 1
M = 0
@R13
M = M + 1
@LOOP.33
0; JMP
(END.33)
@4002
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
@3
D = A + D
@R14
M = D
@R13
D = M
@R14
A = M
M = D
@5002
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
@1
D = A
@3
D = A + D
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
@12
D = A
@SP
AM = M + 1
A = A - 1
M = D
@SP
AM = M - 1
D = M
A = A - 1
M = M + D
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
