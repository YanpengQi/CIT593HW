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

	;; main function
BODY
	CONST R0, #6      ; A = 6
	
	; check the input
	CMPI R0, #0       ; sets  NZP (A-0)
  BRn CHECK         ; tests NZP (was A-0 neg ?, if yes, goto CHECK)
	CMPI R0, #8       ; sets  NZP (A-8)
  BRp CHECK         ; tests NZP (was A-8 pos?, if yes, goto CHECK)
	
	ADD R1, R0, #0    ; B = A
	JSR SUB_FACTORIAL ; call to subroutine
	JMP END           ; jump over subroutine
	.FALIGN           ; aligns the subroutine
	
	;; this function is used to compute factorial
SUB_FACTORIAL       ; args: R0(A), R1(B), RET: R1(B)
LOOP                ; lable meaning we need a loop to do compution
  CMPI R0, #1       ; sets  NZP (A-1)
  BRnz END          ; tests NZP (was A-1 neg or zero?, if yes, goto RET)
  ADD R0, R0, #-1   ; A=A-1
  MUL R1, R1, R0    ; B=B*A
  BRnzp LOOP        ; always goto LOOP
RET                 ; end subroutine

	;; this is used to deal with some unsuitable input
CHECK               ; lable meaning we need to check the input
	CONST R1, #-1     ; if A < 0 or A > 8, B = -1

END