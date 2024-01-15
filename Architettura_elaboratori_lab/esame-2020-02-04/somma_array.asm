; author: Rivolta Luca

	.orig x3000
	
	LEA R0, A0
	LEA R1, A1
	LEA R2, A2
	JSR somma_array

stop	BR stop ; halt execution


; *** DATA SECTION ***

A0	.fill 32760
	.fill 7
	.fill -32760
	.fill 8
	.fill 0

A1	.fill 8
	.fill 17
	.fill -9
	.fill -9
	.fill 0

A2	.blkw 5

; *** SUBPROGRAM ***
; @param R0 -> indirizzo array A0
; @param R1 -> indirizzo array A1
; @param R2 -> indirizzo array A2
; 
; @returns R0 -> numero di traboccamenti verificatisi

somma_array
	
	; salvataggio registri
	ST R3, svr3
	ST R4, svr4
	ST R5, svr5
	ST R6, svr6

	AND R6, R6, #0  ; inizializzo counter dei traboccamenti

loop	LDR R3, R0, #0  ; R3 = A0[i]
	BRZ end 	; se A0[i] = 0 ho finito di scorrere (assumendo dall'esempio che anche A1[i] = 0)
	
	LDR R4, R1, #0	; R4 = A1[i]
	ADD R5, R3, R4  ; R5 = R3 + R4 ( A0[i] + A1[i] )

	AND R3, R3, R3	; prendo il segno di R3 ( A0[i] )
	BRZP pos1	; A0[i] positivo
	BR neg1		; A0[i] negativo

	; se anche A1[i] é positivo possible overflow
pos1	AND R4, R4, R4 	; prendo il segno di R4 ( A1[i] )
	BRZP pospos	; possibile overflow ( entrambi positivi )
	BR endlp	; overflow impossibile, salto a fine ciclo

	; se anche A1[i] é negativo possibile underflow 
neg1	AND R4, R4, R4	; prendo il segno di R4 ( A1[i] )
	BRN negneg	; possibile underflow (entrambi negativi) !!!
	BR endlp	; underflow impossibile, salto a fine ciclo

	; sia A0[i] che A1[i] sono positivi -> possibile overflow
pospos	AND R5, R5, R5 	; prendo il segno di R5 ( A0[i] + A1[i] )
	BRN trb 	; OVERFLOW
	BR endlp	; no overflow, salto a fine ciclo

	; sia A0[i] che A1[i] sono negativi -> possibile underflow
negneg	AND R5, R5, R5 	; prendo il segno di R5 ( A0[i] + A1[i] )
	BRZP trb	; UNDERFLOW
	BR endlp	; no underflow, salto a fine ciclo	

	; TRABOCCAMENTO verificatosi
trb	ADD R6, R6, #1
	BR endlp	

	; passaggi finiali del loop da eseguire sempre
endlp	STR R5, R2, #0	; scrivo A2[i] = R5 in memoria
	ADD R0, R0, #1 	; incremento contatore A0
	ADD R1, R1, #1	; incremento contatore A1
	ADD R2, R2, #1	; incremento contatore A2
	BR loop		; ricomincio ciclo

end	AND R0, R0, #0
	ADD R0, R0, R6	; scrivo output in R0

	; ripristino registri utilizzati
	LD R3, svr3
	LD R4, svr4
	LD R5, svr5
	LD R6, svr6
	RET

; *** SUBPROGRAM DATA SECTION ***

svr3	.blkw 1
svr4	.blkw 1
svr5	.blkw 1
svr6	.blkw 1

; *** END SUBPROGRAM ***

	.end