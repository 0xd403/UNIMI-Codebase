; author: Rivolta Luca
; Il sottoprogramma deve cercare nella stringa ogni occorrenza della coppia di caratteri adiacenti C1C2, sostituirla con la coppia C2C1 e restituire nel registro R0 il numero di coppie sostituite.

	.orig x3000
	
	; TEST #1 -> R0 = 1
	LEA R0, str1
	LD R1, chv
	LD R2, cha
	JSR scambia_coppie

	; TEST #2 -> R0 = 2
	LEA R0, str1
	LD R1, chm
	LD R2, cha
	JSR scambia_coppie

	; TEST #3 -> R0 = 0
	LEA R0, str1
	LD R1, chv
	LD R2, che
	JSR scambia_coppie

stop 	BR stop


; *** MAINPROGRAM DATA SECTION ***

str1	.stringz "Viva la mamma"
chv	.fill 118
cha	.fill 97
chm 	.fill 109
che 	.fill 101

; *** START SUBPROGRAM ***
; R3: contatore scambi effettuati
; R4: flag c1 found
; R5 e R6: appoggi

scambia_coppie
	
	; salvataggio registri
	ST R3, svr3
	ST R4, svr4
	ST R5, svr5
	ST R6, svr6

	AND R3, R3, #0 ; inizializzo il contatore di scambi
	AND R4, R4, #0 ; inizializzo R4 a 0 (c1 not found)
	
loop	LDR R5, R0, #0 ; R5 = str[i]
	BRZ retsb ; se trovo 0 ho finito la stringa
	
	AND R4, R4, R4 ; se c1 giá trovato
	BRP chkc2 ; controlla se str[i] == c2
	
	; qui controllo se str[i] == c1 con flag a false
	NOT R6, R5
	ADD R6, R6, #1 ; R6 = - R5
	ADD R6, R6, R1 ; R6 == C1 ?
	BRZ c1fnd ; setto flag R4 a true
	
endlp	ADD R0, R0, #1 ; istruzione finale di ogni loop
	BR loop

c1fnd	ADD R4, R4, #1
	BR endlp

chkc2	NOT R6, R5
	ADD R6, R6, #1 ; R6 = -R5
	ADD R6, R6, R2 ; controllo se str[i] == c2
	BRZ fnd
	AND R4, R4, #0
	BR endlp

fnd	ADD R3, R3, #1 ; aggiorno il contatore
	
	; scambio str[i] con str[i-1]
	ADD R5, R0, #-1
	STR R2, R5, #0
	STR R1, R5, #1
	
	BR endlp

retsb	AND R0, R0, #0
	ADD R0, R0, R3 ; R0 = R3
	LD R3, svr3
	LD R4, svr4
	LD R5, svr5
	LD R6, svr6
	RET

; *** SUBPROGRAM DATA SECTION ***

svr3 .blkw 1
svr4 .blkw 1
svr5 .blkw 1
svr6 .blkw 1

; *** END SUBPROGRAM ***

	.end
