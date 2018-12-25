		.DATA
L2_problem4 		.FILL #73
		.FILL #32
		.FILL #76
		.FILL #79
		.FILL #86
		.FILL #69
		.FILL #32
		.FILL #67
		.FILL #73
		.FILL #84
		.FILL #53
		.FILL #57
		.FILL #51
		.FILL #0
;;;;;;;;;;;;;;;;;;;;;;;;;;;;main;;;;;;;;;;;;;;;;;;;;;;;;;;;;
		.CODE
		.FALIGN
main
	;; prologue
	STR R7, R6, #-2	;; save return address
	STR R5, R6, #-3	;; save base pointer
	ADD R6, R6, #-3
	ADD R5, R6, #0
	;; function body
	;; epilogue
	ADD R6, R5, #0	;; pop locals off stack
	ADD R6, R6, #3	;; free space for return address, base pointer, and return value
	STR R7, R6, #-1	;; store return value
	LDR R5, R6, #-3	;; restore base pointer
	LDR R7, R6, #-2	;; restore return address
	RET

