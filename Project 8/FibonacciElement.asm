//bootstrap code
@256
D = A
@SP
M = D
@LCL
M = D
@ARG
M = D
@THIS
M = D
@THAT
M = D
@bootstrap.0
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
@Sys.init
0; JMP
(bootstrap.0)
//end of bootstrap
(Sys.init)
@R13
M = 0
(LOOP.Sys.0)
@0
D = A
@R13
D = D - M
@END.Sys.0
D; JEQ
@SP
AM = M + 1
A = A - 1
M = 0
@R13
M = M + 1
@LOOP.Sys.0
0; JMP
(END.Sys.0)
@4
D = A
@SP
AM = M + 1
A = A - 1
M = D
@Sys.2
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
@Main.fibonacci
0; JMP
(Sys.2)
(WHILE.Sys)
@WHILE.Sys
0; JMP
(Main.fibonacci)
@R13
M = 0
(LOOP.Main.0)
@0
D = A
@R13
D = D - M
@END.Main.0
D; JEQ
@SP
AM = M + 1
A = A - 1
M = 0
@R13
M = M + 1
@LOOP.Main.0
0; JMP
(END.Main.0)
@0
D = A
@ARG
A = M + D
D = M
@SP
AM = M + 1
A = A - 1
M = D
@2
D = A
@SP
AM = M + 1
A = A - 1
M = D
@SP
AM = M - 1
D = M
A = A - 1
D = M - D
M = -1
@Main.END3
D; JLT
@SP
A = M - 1
M = 0
(Main.END3)
@SP
AM = M - 1
D = M
@IF_TRUE.Main
D; JNE
@IF_FALSE.Main
0; JMP
(IF_TRUE.Main)
@0
D = A
@ARG
A = M + D
D = M
@SP
AM = M + 1
A = A - 1
M = D
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
(IF_FALSE.Main)
@0
D = A
@ARG
A = M + D
D = M
@SP
AM = M + 1
A = A - 1
M = D
@2
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
@Main.13
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
@Main.fibonacci
0; JMP
(Main.13)
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
@Main.17
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
@Main.fibonacci
0; JMP
(Main.17)
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
