; author: Rivolta Luca

	.orig x3000
	
	LEA R0, arr1
	LEA R1, earr1
	LD R2, t1
	JSR conta_over

	LEA R0, arr2
	LEA R1, earr2
	LD R2, t2
	JSR conta_over

stop	BR stop

; *** DATA SECTION ***

; test 1

t1	.fill 32760
t2	.fill 2

arr1	.fill -56
	.fill 7
	.fill 0
	.fill 8
earr1	.fill 10

arr2	.fill -56
	.fill 7
	.fill 0
	.fill 8
earr2	.fill 10

; *** SUBPROGRAM ***
conta_over
	
	ST R3, svr3
	ST R4, svr4
	ST R6, svr6

	AND R6, R6, #0 ; contatore di overflow trovati
	NOT R1, R1
	ADD R1, R1, #1 ; cambio segno a R1 per confrontarlo con R0

loop	ADD R3, R0, R1 ; R3 = R0-R1
	BRP end ; array finito
	
	LDR R3, R0, #0 ; R3 = arr[i]

	; controllo overflow
	AND R4, R3, R3 ; prendo segno di R3
	BRZP pospos ; positivo, possibile overflow
	BR contlp ; negativo, overflow impossibile

	; possibile overflow
pospos	ADD R3, R3, R2 ; R3 = arr[i] + R2
	AND R4, R3, R3 ; prendo segno di R3
	BRN ovflow
	BR contlpw ; continue loop without sum

ovflow	ADD R6, R6, #1 ; aggionro contatore overflow
	BR contlpw ; continue loop without sum

	; fasi finali del loop
contlp	ADD R3, R3, R2 ; R3 = arr[i] + R2
contlpw	STR R3, R0, #0 ; scrivo la somma in arr[i]
	ADD R0, R0, #1 ; incremento posizione array alla i+1
	BR loop ; ricomincia ciclo


end	AND R2, R2, #0
	ADD R2, R2, R6 ; R2 = R6

	; restore registers
	LD R3, svr3
	LD R4, svr4
	LD R6, svr6
	RET

; *** SUBPROGRAM DATA SECTION ***

svr3	.blkw 1
svr4	.blkw 1
svr6	.blkw 1

; *** END SUBPROGRAM ***

	.end