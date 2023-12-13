; Scrivere un sottoprogramma che riceve un numero n in R0 e ritorna in R0 fibonacci(n)
; fibonacci(n) = 0 per n <= 0

	.orig x3000
	LD R0,t1
	JSR fib ; 0
	LD R0,t2
	JSR fib ; 0
	LD R0,t3
	JSR fib ; 1
	LD R0,t4
	JSR fib ; 1
	LD R0,t5
	JSR fib ; 55

stop	BR stop


; *** SUBPROGRAM
; R1 e R2 -> fib(n-2) e fib(n-1)
; R3 -> appoggio

fib	ST R1,svr1
	ST R2,svr2
	ST R3,svr3

	; N <= 0 -> ritorno 0
	AND R0,R0,R0
	BRNZ rtzr

	; N = [1,2] -> ritorno 1
	AND R3,R3,#0
	ADD R3,R3,#-2
	ADD R3,R3,R0
	BRNZ rtone

	; N > 2 quindi calcolo fib(N)
	AND R1,R1,#0
	ADD R1,R1,#1
	ADD R2,R1,#0
	
	AND R3,R3,#0
	ADD R3,R3,#-2
	ADD R0,R0,R3

loop	AND R0,R0,R0
	BRZ done ; se R0 = 0 ho finito
	
	; salvo r2 in r3
	AND R3,R3,#0
	ADD R3,R3,R2
	
	; r2 = r2 + r1 ( calcolo di fib(n+1) )
	ADD R2,R2,R1

	; metto r3 in r1
	AND R1,R1,#0
	ADD R1,R1,R3
		
	; decremento R0
	AND R3,R3,#0
	ADD R3,R3,#-1
	ADD R0,R0,R3

	BR loop
		

rtzr	AND R0,R0,#0
	BR retsb

rtone	AND R0,R0,#0
	ADD R0,R0,#1
	BR retsb

done	AND R0,R0,#0
	ADD R0,R0,R2
	BR retsb

retsb	LD R1,svr1
	LD R2,svr2
	LD R3,svr3
	RET

svr1 	.blkw 1
svr2	.blkw 1
svr3	.blkw 1

; *** END SUBPROGRAM

t1	.fill -4
t2	.fill 0
t3	.fill 1
t4	.fill 2
t5	.fill 10

	.end