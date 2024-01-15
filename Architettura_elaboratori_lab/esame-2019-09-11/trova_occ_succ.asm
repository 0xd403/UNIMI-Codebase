; author: Luca Rivolta

	.orig x3000

	LEA R0, str1
	LD R1, chr1
	LD R2, n1
	JSR trova_occ_succ ; R0: 11

	LEA R0, str1
	LD R1, chr1
	LD R2, n2
	JSR trova_occ_succ ; R0: 13

	LEA R0, str1
	LD R1, chr1
	LD R2, n3
	JSR trova_occ_succ ; R0: 27

	LEA R0, str1
	LD R1, chr1
	LD R2, n4
	JSR trova_occ_succ ; R0: 0
	
stop 	BR stop


; *** DATA SECTION ***


str1	.stringz "Le giornate estive sono spesso afose"

; @note spreco una cella con il terminatore ma non so come altro fare se non usando il codice ASCII (che non avró all'esame)
chr1	.stringz "e"  

n1	.fill 1
n2	.fill 2
n3	.fill 4
n4	.fill 25

; *** SUBPROGRAM ***
; @param R0: indirizzo prima cella di memoria di una stringa con terminatore 0
; @param R1: codice ASCII di un carattere C
; @param R2: numero intero N >= 1
; @returns la posizione dell'occorrenza N+1 del carattere C, 0 se non esiste
; @notice le posizioni della stringa sono 1-indexed


trova_occ_succ
	
	; cambio segno al carattere C (in R1) per poterlo poi confrontare
	NOT R1, R1
	ADD R1, R1, #1
	
	; @dev R6 contatore posizione 1-indexed da restituire
	AND R6, R6, #0
	ADD R6, R6, #0 ; inizializzato a 0
	
	; @dev R5 contatore occorrenza di C
	AND R5, R5, #0	; inizializzato a 0	

loop	LDR R3, R0, #0	; R3 = str[i]
	BRZ ntfnd	; se str[i] == 0 stringa terminata senza trovare l'occorrenza N+1 di C
	
	ADD R0, R0, #1	; incremento puntatore stringa	
	ADD R6, R6, #1	; incremento contatore posizione

	ADD R3, R3, R1	; str[i] - 'C' (confronto)
	BRZ fndocc	; occorrenza di C trovata	

endlp	BR loop		; ricomincia il ciclo
	
	; @dev se arrivo qui non ho trovato occorrenza N+1 -> ritornare 0 in R0
ntfnd	AND R0, R0, #0
	BR endsb	; salto a fine subroutine

	; @dev qui trovata occorrenza di C
fndocc	ADD R5, R5, #1	; incremento contatore occorrenze
	NOT R3, R5
	ADD R3, R3, #1	; R3 = -R5
	ADD R3, R2, R3	; R3 = R2 - R5
	BRN fndnn	; trovata occorrenza n + 1
	BR endlp	; salto a fine loop

	; @dev qui trovata occorrenza N+1 di C
fndnn	AND R0, R0, #0
	ADD R0, R0, R6
	BR endsb	; salto a fine subroutine

	; @dev endsubroutine contiene le istruzioni da eseguire prima di ritornare al chiamante
endsb 	RET

; *** SUBPROGRAM DATA SECTION ***



; *** END SUBPROGRAM ***

	.end