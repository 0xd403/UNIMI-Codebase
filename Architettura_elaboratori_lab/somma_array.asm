; l'array si considera finito quando trovo uno 0
; R0 -> puntatore alla prima cella di vect
; R2 -> somma risultante

	.orig x3000

	LEA R0,vect  	; carico in R0 l'indirizzo del primo elemento di vect
	AND R2,R2,#0 	; azzero R12

loop	LDR R1,R0,#0 	; carico in R1 elemento array a cui sono arrivato
	BRZ psum	; se R1 contiene 0 ho finito di scorrere vect
	ADD R2,R2,R1    ; sommo elemento corrente
	ADD R0,R0,#1    ; incremento l'indrizzo puntato da R0 al prossimo elemento di vect
	BR loop		; continuo il ciclo di lettura


psum    TRAP x25            ; HALT SUBROUTINE


vect	.fill 10
	.fill 20
	.fill 30
	.fill -10
	.fill 0


.end
