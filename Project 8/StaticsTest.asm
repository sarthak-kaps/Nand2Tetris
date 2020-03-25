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
@6
D = A
@SP
AM = M + 1
A = A - 1
M = D
@8
D = A
@SP
AM = M + 1
A = A - 1
M = D
@Sys.3
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
@2
D = A
@5
D = D + A
@SP
D = M - D
@ARG
M = D
@Class1.set
0; JMP
(Sys.3)
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
@23
D = A
@SP
AM = M + 1
A = A - 1
M = D
@15
D = A
@SP
AM = M + 1
A = A - 1
M = D
@Sys.7
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
@2
D = A
@5
D = D + A
@SP
D = M - D
@ARG
M = D
@Class2.set
0; JMP
(Sys.7)
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
@Sys.9
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
@Class1.get
0; JMP
(Sys.9)
@Sys.10
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
@Class2.get
0; JMP
(Sys.10)
(WHILE.Sys)
@WHILE.Sys
0; JMP
(Class1.set)
@R13
M = 0
(LOOP.Class1.0)
@0
D = A
@R13
D = D - M
@END.Class1.0
D; JEQ
@SP
AM = M + 1
A = A - 1
M = 0
@R13
M = M + 1
@LOOP.Class1.0
0; JMP
(END.Class1.0)
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
@Class1.0
M = D
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
@Class1.1
M = D
@0
D = A
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
(Class1.get)
@R13
M = 0
(LOOP.Class1.7)
@0
D = A
@R13
D = D - M
@END.Class1.7
D; JEQ
@SP
AM = M + 1
A = A - 1
M = 0
@R13
M = M + 1
@LOOP.Class1.7
0; JMP
(END.Class1.7)
@Class1.0
D = M
@SP
AM = M + 1
A = A - 1
M = D
@Class1.1
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
(Class2.set)
@R13
M = 0
(LOOP.Class2.0)
@0
D = A
@R13
D = D - M
@END.Class2.0
D; JEQ
@SP
AM = M + 1
A = A - 1
M = 0
@R13
M = M + 1
@LOOP.Class2.0
0; JMP
(END.Class2.0)
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
@Class2.0
M = D
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
@Class2.1
M = D
@0
D = A
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
(Class2.get)
@R13
M = 0
(LOOP.Class2.7)
@0
D = A
@R13
D = D - M
@END.Class2.7
D; JEQ
@SP
AM = M + 1
A = A - 1
M = 0
@R13
M = M + 1
@LOOP.Class2.7
0; JMP
(END.Class2.7)
@Class2.0
D = M
@SP
AM = M + 1
A = A - 1
M = D
@Class2.1
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

