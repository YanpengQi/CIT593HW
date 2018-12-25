;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  file name   : multiply.asm                           ;
;  author      : Thomas Farmer
;  description : LC4 Assembly program to multiply two   ;
;                integers using repeated addition       ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;
;;; pseudo-code of multiplication algorithm
;
; C = 0 ;
; while ( B > 0 )
; {
;    C = C + A ;
;    B = B - 1 ;
; }

; register allocation: R0=A, R1=B, R2=C
	  
  CONST R0, #2    ; A = 2
  CONST R1, #3    ; B = 3
  CONST R2, #0    ; C = 0
  
LOOP 
  CMPI R1, #0     ; sets  NZP (B-0)
  BRnz END        ; tests NZP (was B-0 neg or zero?, if yes, goto END)
  ADD R2, R2, R0  ; C=C+A
  ADD R1, R1, #-1 ; B=B-1
  BRnzp LOOP      ; always goto LOOP
END