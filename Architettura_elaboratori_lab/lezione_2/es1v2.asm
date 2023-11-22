	.orig x3000

	LEA R0,vect
	LEA R1,endv
	LEA R2,trg1
	LDR R2,R2,#0
	JSR sr ; risultato 4

	LEA R0,vect
	LEA R1,endv
	LEA R2,trg2
	LDR R2,R2,#0
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
endv	.fill 56

	;***** END DATA SECTION *****

	;*****   SUBPROGRAM   *****
	
sr	ST R3,svr3 ; save R3
	ST R4,svr4 ; save R4
	ST R5,svr5 ; save R5
	AND R3,R3,#0
	ADD R3,R3,#1 ; init counter

loop	LDR R4,R0,#0 ; R4 = vect[i]
	NOT R5,R0 ; R5 = -R0
	ADD R5,R1,R5 ; R5 = R1-R5 (check if R0 points to endv)
	BRZ vend ; vect ended
	
	ADD R0,R0,#1 ; R0 points to next element
	NOT R4,R4 ; R4 = notR4
	ADD R4,R4,#1 ; R4 = -R4
	ADD R4,R2,R4 ; if 0 target found
	BRZ found
	ADD R3,R3 #1 ; R3++
	BR loop

vend	AND R0,R0,#0
	BR exitsr
	
found	AND R0,R0,#0
	ADD R0,R0,R3
	BR exitsr

exitsr	LD R3,svr3
	LD R4,svr4
	LD R5,svr5
	RET

	; SUBPROGRAM DATA SECTION

svr3	.blkw 1
svr4	.blkw 1
svr5	.blkw 1

	;***** END SUBPROGRAM *****

	
	.end