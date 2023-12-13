; CONTA_DOPPIE: data una stringa restituisce il numero di doppie (due lettere uguali di fila)
; R0 -> primo indirizzo stringa
; R1 -> ultimo carattere stringa

	.orig x3000
	LEA R0, str1
	LEA R1, str1lst
	ADD R1,R1,#-2
	JSR conta_doppie

stop	BR stop

str1	.stringz "nel mezzo del cammin di nostra vita mi ritrovai per una selva oscura che' la diritta via era smarrita."
str1lst .fill xFFFF

; *** SUBPROGRAM
; R2 = carattere precedente
; R3 = numero doppie trovate
; R4 = appoggio

conta_doppie
	
	ST R2, svr2
	ST R3, svr3
	ST R4, svr4
	AND R3,R3,#0

loop	NOT R4,R1
	ADD R4,R4,#1
	ADD R4,R4,R0	
	BRZ done	; controllo se R0 punta a r1 (iterazione finita)		
	
	LDR R2,R0,#0	; carattere precedente
	ADD R0,R0,#1	; punto al prossimo carattere
	LDR R4,R0,#0	; carattere attuale
	NOT R4,R4
	ADD R4,R4,#1
	ADD R4,R4,R2	; se carattere attuale != carattere precedente
	BRNP loop
	ADD R3,R3,#1
	BR loop
	
done	AND R0,R0,#0
	ADD R0,R0,R3
	LD R2, svr2
	LD R3, svr3
	LD R4, svr4
	RET

svr2	.blkw 1
svr3	.blkw 1
svr4	.blkw 1

; *** END SUBPROGRAM

	.end