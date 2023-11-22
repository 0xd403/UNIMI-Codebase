; Dati in ingresso due numeri nei registri R0 e R1 determinare se la loro somma genera overflow o underflow
; Output nel registro R0:
; 1 se overflow
; 0 se ok
; -1 se underflow

	.orig x3000
	
	; caso pos + pos no overflow
	LEA R0, p1
	LDR R0,R0,#0
	LEA R1, p2
	LDR R1,R1,#0	
	JSR sr ; risultato: 0

	; caso neg + neg no underflow
	LEA R0, n1
	LDR R0,R0,#0
	LEA R1, n2
	LDR R1,R1,#0	
	JSR sr ; risultato: 0

	; caso pos + pos con underflow
	LEA R0, mxp
	LDR R0,R0,#0
	LEA R1, p1
	LDR R1,R1,#0	
	JSR sr ; risultato: 1

	; caso neg + neg con underflow
	LEA R0, mxn
	LDR R0,R0,#0
	LEA R1, n1
	LDR R1,R1,#0	
	JSR sr ; risultato: -1

	; caso 0 + 0
	LEA R0, zz
	LDR R0,R0,#0
	LEA R1, zz
	LDR R1,R1,#0	
	JSR sr ; risultato: 0

stop	BR stop


; ***** DATA SECTION *****

mxp	.fill 32767
mxn	.fill -32768
p1	.fill 40
p2	.fill 20
n1	.fill -50
n2	.fill -1
zz	.fill 0

; ***** END DATA SECTION *****


; ***** SUBPROGRAM *****

sr	AND R0,R0,R0
	BRZP n1pos
	BRN n1neg

n1pos	AND R1,R1,R1
	BRP concpos

n1neg	AND R1,R1,R1
	BRN concneg

concpos ADD R1,R0,R1
	BRN over
	BR noerr

concneg ADD R1,R0,R1
	BRP under
	BR noerr

disc	BR noerr

over	AND R0,R0,#0
	ADD R0,R0,#1
	RET

noerr	AND R0,R0,#0
	RET

under	AND R0,R0,#0
	ADD R0,R0,#-1
	RET

; ***** END SUBPROGRAM ***** 

	.end