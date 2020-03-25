// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.
@check
M = 0
(LOOP1) //LOOP1 IS INFINITE
	@KBD
	D = M
	@ELSEIF
	D; JEQ
	@check
	D = M
	@ELSEIF
	D; JNE
	//IF
		@SCREEN
		D = A
		@i
		M = D
		(LOOP2)//Darkens the screen
			@KBD
			D = A
			@i
			D = D - M
			@LOOP1
			D; JEQ
			@i
			A = M
			M = -1
			@i
			M = M + 1
			@check
			M = 1
			@LOOP2
			0; JEQ
	//ELSE IF
	(ELSEIF)
		@KBD
		D = M
		@LOOP1
		D; JNE
		@check
		D = M
		@LOOP1
		D; JEQ
		@SCREEN
		D = A
		@i
		M = D
		(LOOP3)//Whitens the screen
			@KBD
			D = A
			@i
			D = D - M
			@LOOP1
			D; JEQ
			@i
			A = M
			M = 0
			@i
			M = M + 1
			@check
			M = 0
			@LOOP3
			0; JEQ
	//END ELSE IF
//LOOP1 RUNS INFINTELY