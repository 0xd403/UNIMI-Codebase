; author: Luca Rivolta
; il sottoprogramma riceve in inpu due numeri a 16 bit n1 e n2 in complemento a 2 rispettivamente nei registri R0 e R1 e deve restituire
; R0 -> 0 se concordi oppure 1 se discordi
; R1 -> 0 se abs(n1) >= abs(n2), altrimenti 1
; R2 -> 0 se n1+n2 non provoca traboccamenti, altrimenti 1

	.orig x3000

	LD R0, t1n1
	LD R1, t1n2
	JSR analizza_coppia
	
	LD R0, t2n1
	LD R1, t2n2
	JSR analizza_coppia

	LD R0, t3n1
	LD R1, t3n2
	JSR analizza_coppia

stop 	BRNZP stop

; **** DATA SECTION ****

t1n1 	.fill -16
t1n2	.fill 15
t2n1	.fill 3000
t2n2	.fill 2500
t3n1	.fill -16000
t3n2	.fill -20000

; **** SUBPROGRAM ****
analizza_coppia
	
	; concordi o discordi?
	LD R3, mn
	AND R3, R3, R0 ; estraggo il valore del primo bit di n1
	LD R4, mn
	AND R4, R4, R1 ; estraggo il valore del primo bit di n2
	NOT R3, R3
	ADD R3, R3, #1 ; R3=-R3
	ADD R3, R3, R4
	BRZ conc
	BRNZP disc 
	
	; confronto valori assoluti
pnt2	AND R3, R0, R0 ; segno di n1
	BRN n1neg
	AND R4, R1, R1 ; segno di n2
	BRN n2neg
	; qui entrambi pos
	NOT R3, R1
	ADD R3, R3, R0 ; R3 = abs(n1+n2)
	BRZP n1mg ; n1 >= n2
	BRNZP n2mg

pnt3	AND R5, R5, R5 ; controllo se sono concordi (possibile traboccamento) o discordi (traboccamento impossibile)
	BRZ cktrb      ; sono concordi quindi check se traboccano
	AND R2, R2, #0 ; non traboccano quindi scrivo 0 in R2
	BRNZP end      ; e termino

; qui n1 negativo ma non so n2
n1neg	AND R3, R1, R1 ; segno di n2
	BRZ n2negg
	ADD R3, R0, R1
	BRZP n2mg
	BRNZP n1mg

; qui n1 negativo e n2 negativo
n2negg	NOT R3, R0
	ADD R3, R3, #1
	ADD R3, R3, R1
	BRZP n1mg
	BRNZP n2mg

; qui n1 positivo ma n2 negativo
n2neg	ADD R3, R0, R1
	BRZP n1mg
	BRNZP n2mg
	

conc	AND R5, R5, #0
	BRNZP pnt2

disc	AND R5, R5, #0
	ADD R5, R5, #1
	BRNZP pnt2

n1mg	AND R6, R6, #0
	BRNZP pnt3

n2mg	AND R6, R6, #0
	ADD R6, R6, #1
	BRNZP pnt3

cktrb	AND R3, R0, R1 ; segno di R1
	BRN cktrbn     ; sono entrambi negativi, se la loro somma é positiva: underflow
	; qui sono entrambi positivi, se la loro somma é negativa: overflow
	ADD R3, R0, R1
	BRN trab ; overflow trovato
	AND R2, R2, #0 ; no overflow
	BRNZP end  ; termino

cktrbn  ADD R3, R0, R1
	BRZP trab ; underflow trovato
	AND R2, R2, #0 ; no underflow
	BRNZP end  ; termino

trab	AND R2, R2, #0
	ADD R2, R2, #1
	BRNZP end

end	AND R0, R0, #0
	ADD R0, R0, R5
	AND R1, R1, #0
	ADD R1, R1, R6
	RET

; SUBPROGRAM DATA SECTION

mn	.fill x8000  ; 1000 0000 0000 0000 (per scoprire il primo bit)

; **** END SUBPROGRAM ****

	.end