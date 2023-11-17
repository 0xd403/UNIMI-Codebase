	
	.orig x3000
	
	LEA R1,num1
	LEA R2,num2
	JSR sbinit ; -1
	LEA R1,num1
	LEA R2,num1
	JSR sbinit ; 0
	LEA R1,num2
	LEA R2,num3
	JSR sbinit ; 1

stop	BR stop


;***** SUBPROGRAM *******

sbinit  AND R0,R0,#0
	LDR R1,R1,#0
	LDR R2,R2,#0
	NOT R2,R2
	ADD R2,R2,#1
	ADD R1,R1,R2	
	BRZ eq
	BRN less
	BR high	

eq	RET

less 	ADD R0,R0,#-1
	RET

high	ADD R0,R0,#1
	RET


;***** END SUBPROGRAM *******


num1	.fill 10
num2 	.fill 20
num3	.fill -30

	.end