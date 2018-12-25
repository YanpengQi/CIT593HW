;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  file name   : lc4_stdio.asm                          ;
;  author      : 
;  description : LC4 Assembly subroutines that call     ;
;                call the TRAPs in os.asm (the wrappers);
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;; WRAPPER SUBROUTINES FOLLOW ;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    
.CODE
.ADDR x0010    ;; this code should be loaded after line 10
               ;; this is done to preserve "USER_START"
               ;; subroutine that calls "main()"


;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;; TRAP_PUTC Wrapper ;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.FALIGN
lc4_putc

	;; PROLOGUE ;;
        STR R7, R6, #-2	;; save return address
		STR R5, R6, #-3	;; save base pointer
		ADD R6, R6, #-3 ;; update R6 to base pointer
		ADD R5, R6, #0  ;; update R5 = R6
		
		ADD R6, R6, #-1 ;; allocate space for local vars
		LDR R0, R5, #3  ;; get R0 from R5 + #3
		STR R0, R5, #-1 ;; store R0 into local space

	;; FUNCTION BODY ;;

		
	TRAP x01        ; R0 must be set before TRAP_PUTC is called
	
	;; EPILOGUE ;; 
		; TRAP_PUTC has no return value, so nothing to copy back to stack
	LDR R7, R5, #1  ;; restore R7 as its original address, now PC = R7
	RET

;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;; TRAP_GETC Wrapper ;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.FALIGN
lc4_getc

	;; PROLOGUE ;;
        STR R7, R6, #-2	;; save return address
		STR R5, R6, #-3	;; save base pointer
		ADD R6, R6, #-3 ;; update R6 to base pointer
		ADD R5, R6, #0  ;; update R5 = R6
		;; in this case, we do not need input, so there is no local variable
		
	;; FUNCTION BODY ;;
		
	TRAP x00        ; Call's TRAP_GETC 
                    ; R0 will contain ascii character from keyboard
                    ; you must copy this back to the stack
	
	;; EPILOGUE ;; 
		;; return value should be R0, so we need to store it into stack
		STR R0, R6, #2  ;; store return value to return value position(x7FF8)
		STR R0, R5, #-1 ;; store return value R0 into R5 - 1(x7FF5)
		ADD R6, R6, #3  ;; restore R6 to its original value in main(x7FF9)
		LDR R7, R5, #1  ;; restore R7 as its original address, now PC = R7
	RET

;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;; TRAP_PUTS Wrapper ;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.FALIGN
lc4_puts

	;; PROLOGUE ;;
        STR R7, R6, #-2	;; save return address
		STR R5, R6, #-3	;; save base pointer
		ADD R6, R6, #-3 ;; update R6 to base pointer
		ADD R5, R6, #0  ;; update R5 = R6
		
		ADD R6, R6, #-1 ;; allocate space for local vars
		LDR R0, R5, #3  ;; get R0 from R5 + #3
		
		ADD R0, R0, #-14 ;; we need give enough space, so R0 should be the start of string
		STR R0, R5, #-1 ;; store R0 into local space

	;; FUNCTION BODY ;;

		
	TRAP x03        ; R0 must be set before TRAP_PUTS is called
	
	;; EPILOGUE ;; 
		; TRAP_PUTS has no return value, so nothing to copy back to stack
	LDR R7, R5, #1  ;; restore R7 as its original address
	RET