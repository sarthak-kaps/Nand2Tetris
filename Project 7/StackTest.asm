@17
D = A
@SP
AM = M + 1
A = A - 1
M = D
@17
D = A
@SP
AM = M + 1
A = A - 1
M = D
@SP
AM = M - 1
D = M + 1
A = A - 1
MD = M - D
@input.END2
D + 1; JEQ
@SP
A = M - 1
M = 0
(input.END2)
@17
D = A
@SP
AM = M + 1
A = A - 1
M = D
@16
D = A
@SP
AM = M + 1
A = A - 1
M = D
@SP
AM = M - 1
D = M + 1
A = A - 1
MD = M - D
@input.END5
D + 1; JEQ
@SP
A = M - 1
M = 0
(input.END5)
@16
D = A
@SP
AM = M + 1
A = A - 1
M = D
@17
D = A
@SP
AM = M + 1
A = A - 1
M = D
@SP
AM = M - 1
D = M + 1
A = A - 1
MD = M - D
@input.END8
D + 1; JEQ
@SP
A = M - 1
M = 0
(input.END8)
@892
D = A
@SP
AM = M + 1
A = A - 1
M = D
@891
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
@input.END11
D; JLT
@SP
A = M - 1
M = 0
(input.END11)
@891
D = A
@SP
AM = M + 1
A = A - 1
M = D
@892
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
@input.END14
D; JLT
@SP
A = M - 1
M = 0
(input.END14)
@891
D = A
@SP
AM = M + 1
A = A - 1
M = D
@891
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
@input.END17
D; JLT
@SP
A = M - 1
M = 0
(input.END17)
@32767
D = A
@SP
AM = M + 1
A = A - 1
M = D
@32766
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
@input.END20
D; JGT
@SP
A = M - 1
M = 0
(input.END20)
@32766
D = A
@SP
AM = M + 1
A = A - 1
M = D
@32767
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
@input.END23
D; JGT
@SP
A = M - 1
M = 0
(input.END23)
@32766
D = A
@SP
AM = M + 1
A = A - 1
M = D
@32766
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
@input.END26
D; JGT
@SP
A = M - 1
M = 0
(input.END26)
@57
D = A
@SP
AM = M + 1
A = A - 1
M = D
@31
D = A
@SP
AM = M + 1
A = A - 1
M = D
@53
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
@112
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
A = M - 1
M = -M
@SP
AM = M - 1
D = M
A = A - 1
M = M & D
@82
D = A
@SP
AM = M + 1
A = A - 1
M = D
@SP
AM = M - 1
D = M
A = A - 1
M = M | D
@SP
A = M - 1
M = !M
