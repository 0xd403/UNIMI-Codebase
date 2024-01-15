; author: Luca Rivolta 

	.orig x3000

	LEA R0, str1
	JSR minusc_ini
	
	LEA R0, str2
	JSR minusc_ini

stop 	BR stop

; *** DATA SECTION ***

str1	.stringz "Oggi e' il 13 Settembre 2022"
str2	.stringz "Zio Pera"

; *** SUBPROGRAM ***
; @notice la stringa si considera finita quando trovo il terminatore ( 0 )
; @notice il sottoprogramma deve convertire in minuscole i caratteri iniziali di ogni parola
; @param R0 -> primo indirizzo della stringa

minusc_ini
	
	; salvataggio dei registri 
	ST R1, svr1
	ST R2, svr2
	ST R6, svr6
	
	AND R6, R6, #0	; flag inizio parola (la imposto a 1 quando trovo uno spazio)
	ADD R6, R6, #1	; ovviamente parte da 1 perché devo convertire la parola iniziale

	LDR R1, R0, #0
	BR stwrd

loop	LDR R1, R0, #0	; R1 = str[i]
	BRZ end		; se str[i] = 0 array finito

	; @dev controllo se str[i] é uno spazio, in caso setto R6 a 1
	LD R2, mgcnb	; R2 = 32
	NOT R2, R2
	ADD R2, R2, #1	; R2 = -32
	ADD R2, R2, R1	; se 0 str[i] é uno spazio
	BRZ ststwd	; set R6 = 1
	BR rsstwd	; reset R6 to 0
	
	AND R6, R6, R6	; aggiorno i CC al contenuto di R6 (flag inizio parola)
	BRP stwrd	; se positivo possibile modifica lettera
	
endlp	ADD R0, R0, #1	; incremento il contatore della posizione nella stringa
	BR loop		; ricomincio il ciclo

	; @dev qui mi trovo all'inizio di una parola
stwrd	LD R2, lwbnd	; R2 = -65
	ADD R2, R2, R1	; str[i] - 65
	BRN endlp	; non é maiuscola, salto a fine ciclo
	
	LD R2, uppbnd	; R2 = -90
	ADD R2, R2, R1	; str[i] - 90
	BRN endlp	; non é maiuscola, salto a fine ciclo
	

	; @dev qui sono sicuro che str[i] sia maiuscola
	LD R2, mgcnb	; R2 = 32 (differenza tra maiuscola e minuscola in ASCII codes)
	ADD R1, R1, R2	; str[i] convertita a minuscola
	STR R1, R0, #0	; scrivo str[i] convertita in memoria
	BR endlp	

	; @dev setta R6 a 1 (segnala che il prossimo carattere é inizio di una parola)
ststwd	AND R6, R6, #0
	ADD R6, R6, #1
	BR endlp

	; @dev setta R6 a 0 (segnale che il prossimo carattere é interno ad una parola)
rsstwd	AND R6, R6, #0	
	BR endlp
	
	; ripristino dei registri
end	LD R1, svr1
	LD R2, svr2
	LD R6, svr6
	RET

; *** SUBPROGRAM DATA SECTION ***

svr1	.blkw 1
svr2	.blkw 1
svr6	.blkw 1
lwbnd	.fill -65
uppbnd	.fill -90
mgcnb	.fill 32

; *** END SUBPROGRAM ***	

	.end