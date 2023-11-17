; R1 = num1
; R2 = num2
; R0 = num1 + num2
; Per la consegna, se uso registri non previsti dal testo, prima di ritornare devo riportali al loro valore iniziale (SEMPRE)

	.orig x3000
	
	LD R1, num1
	LD R2, num2	
	JSR sbinit	

stop	BR stop	
	
	;*****   SUBPROGRAM   *****

sbinit  ST R3,svr3
	AND R0,R0,#0
	NOT R2,R2
	ADD R2,R2,#1 ; R2 = -R2	
	ADD R3,R1,R2
	BRZ case1    ; R1 = R2	
	BRN case2    ; R2 > R1
	BR case3     ; R1 < R2		

case1	LD R3,svr3
	RET

case2	ADD R0,R0,#-1 ; R0 = -1
	LD R3,svr3
	RET

case3   ADD R0,R0,#1 ; R0 = 1
	LD R3,svr3
	RET

	; Subprogram Data Section

svr3	.blkw 1

	;***** END SUBPROGRAM *****
	
num1	.fill #-1
num2	.fill #-3

	.end