;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  file name   : factorial.asm                          ;
;  author      : 
;  description : LC4 Assembly program to compute the    ;
;                factorial of a number                  ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;
;;; pseudo-code of factorial algorithm
;
; A = 5 ;  // example to do 5!
; B = A ;  // B=A! when while loop completes
;
; while (A > 1) {
; 	A = A - 1 ;
; 	B = B * A ;
; }
;

;;; TO-DO: Implement the factorial algorithm above using LC4 Assembly instructions
; register allocation: R0=A, R1=B, R2=C

	;; This is the data section
	.DATA
	.ADDR x4020		; Start the data at address 0x4000
global_array
	.FILL #6
	.FILL #5
	.FILL #8
	.FILL #10
	.FILL #-5
	
	
	;; Start of the code section
	.CODE
	.ADDR 0x0000		; Start the code at address 0x0000
	
	;; initalize data value through getting data from data memory into register file
INIT
	LEA R2, global_array ; R2 contains the address of the data
	CONST R3, #5		     ; use R3 as a counter
	JMP TEST             ; test counter to judge whether we should jump to body
	
	;; main function, load data and use subroutine
BODY
	LDR R0, R2, #0    ; load data value from address(R2 + 0) into R0 (A)
	;; check whether the input is valid 
	CMPI R0, #0       ; sets  NZP (A-0)
  BRn CHECK         ; tests NZP (was A-0 neg ?, if yes, go to CHECK, otherwise get to next)
	CMPI R0, #8       ; sets  NZP (A-8)
  BRp CHECK         ; tests NZP (was A-8 pos?, if yes, go to CHECK, otherwise get to next)
	
	JSR SUB_FACTORIAL ; call to subroutine
	JMP TEST          ; just in case, jump to next test, to compute next value

	;; store data into memory address
STORE               ; lable which measn it is used to store data
	STR R1, R2, #0    ; store value of R1 into memory address(R2 + 0)
  ADD R2, R2, #1	  ; increase R2(address) by 1 to store the value of the next loop
  ADD R3, R3, #-1	  ; decrease R3(counnter) to count the current loop
	CONST R1, #0      ; clear the value of R1 to store data from next loop
	JMP TEST          ; end of this loop and test next address
	
	;; this function is used to compute factorial
SUB_FACTORIAL       ; args: R0(A), R1(B), RET: R1(B)
	ADD R1, R0, #0    ; B = A
LOOP                ; lable which means it is a lop
  CMPI R0, #1       ; sets  NZP (A-1)
  BRnz STORE        ; tests NZP (was A-1 neg or zero?, if yes, goto STORE)
  ADD R0, R0, #-1   ; A=A-1
  MUL R1, R1, R0    ; B=B*A
  BRnzp LOOP        ; always go to LOOP
RET                 ; end SUB_FACTORIAL and return

	;; this is used to deal with unsuitable input number
CHECK 				    ; when the input number is not suitable
  CONST R1, #-1		; set R1 as -1
  STR R1, R2, #0	; store R1 into address R2
  ADD R2, R2, #1	; increase R2(address) by 1 to store the value of the next loop
  ADD R3, R3, #-1	; decrease R3(counnter) to count the current loop

	;; this is to test whether there is no data memory we need to handle
TEST				    ; only when the counter is positive, jump to body
  CMPI R3, #0		; use R3 - 0 as comparator
  BRp BODY			; when R3 - 0 is pos, jump to body. otherwise, end
  
END