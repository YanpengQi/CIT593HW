;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  file name   : factorial_sub.asm                      ;
;  author      : 
;  description : LC4 Assembly subroutine to compute the ;
;                factorial of a number                  ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;

.FALIGN
SUB_FACTORIAL

	;; prologue
	STR R7, R6, #-2	;; save return address
	STR R5, R6, #-3	;; save base pointer
	ADD R6, R6, #-3
	ADD R5, R6, #0
	
	ADD R6, R6, #-1 ;; allocate space for local vars
	LDR R0, R5, #3  ;; R0 = 5
	STR R0, R5, #-1 ;; store R0 at x7FF5

	  CMPI R0, #0       ; sets  NZP (A-0)
	  BRn CHECK         ; tests NZP (was A-0 neg ?, if yes, goto CHECK)
	  CMPI R0, #8       ; sets  NZP (A-8)
	  BRp CHECK         ; tests NZP (was A-8 pos?, if yes, goto CHECK)

		ADD R1, R0, #0  ; B = A
		JMP FACTORIAL   ; call to subroutine
		JMP FINSH

		;; this function is used to compute factorial
	FACTORIAL           ; args: R0(A), R1(B), RET: R1(B)
	LOOP                ; lable meaning we need a loop to do compution
	  STR R1, R6, #3    ; each loop store value in return value space
	  CMPI R0, #1       ; sets  NZP (A-1)
	  BRnz EPILOGUE          ; tests NZP (was A-1 neg or zero?, if yes, goto RET)
	  ADD R0, R0, #-1   ; A=A-1
	  MUL R1, R1, R0    ; B=B*A
	  BRnzp LOOP        ; always goto LOOP

		;; this is used to deal with some unsuitable input
	CHECK               ; lable meaning we need to check the input
		CONST R1, #-1     ; if A < 0 or A > 8, B = -1
		STR R1, R6, #3    ; each loop store value in return value space
	FINSH
	
	;; epilogue
	EPILOGUE
		LDR R7, R6, #3  ;; store return value in R7
		ADD R6, R5, #0	;; pop locals off stack
		ADD R6, R6, #3	;; free space for return address, base pointer, and return value
		STR R7, R6, #-1 ;; local var = R7 = return value
		LDR R5, R6, #-3	;; restore return address
		LDR R7, R6, #-2 ;; restore R7 for RET, now PC = R7

	RET

