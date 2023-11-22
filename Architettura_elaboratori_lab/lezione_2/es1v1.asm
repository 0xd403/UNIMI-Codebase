	.orig x3000

	LEA R0,vect
	LEA R1,trg1
	LDR R1,R1,#0	
	JSR sr ; risultato 4

	LEA R0,vect
	LEA R1,trg2
	LDR R1,R1,#0
	JSR sr ; risultato 0

stop	BR stop	
	
	;***** DATA SECTION *****

trg1	.fill 322
trg2	.fill 22

vect	.fill 10
	.fill -5
	.fill 30
	.fill 322
	.fill -95
	.fill 0

	;***** END DATA SECTION *****

	;*****   SUBPROGRAM   *****
	
sr	ST R2,svr2 ; save R2
	ST R3,svr3 ; save R3
	AND R2,R2,#0
	ADD R2,R2,#1 ; init counter

loop	LDR R3,R0,#0 ; R3 = vect[i]
	BRZ endv
	ADD R0,R0,#1 ; R0 points to next element
	NOT R3,R3
	ADD R3,R3,#1 ; R3 = -R3
	ADD R3,R1,R3 ; if 0 R3 = target
	BRZ found
	ADD R2,R2 #1 ; R2++
	BR loop

endv	AND R0,R0,#0
	BR exitsr
	
found	AND R0,R0,#0
	ADD R0,R0,R2
	BR exitsr

exitsr	LD R2,svr2
	LD R3,svr3
	RET

	; SUBPROGRAM DATA SECTION

svr2	.blkw 1
svr3	.blkw 1

	;***** END SUBPROGRAM *****

	
	.end