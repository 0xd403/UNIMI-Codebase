; stampa a video di una stringa che si considera finita dal carattere terminatore x00
; R0 mi serve per stampare con TRAP
; R1 punta all'elemento di stringa da leggere


		.orig x3000
					
		LEA R1,stringa		; R1 contiene l'indirizzo del primo carattere di stringa
		
loop		LDR R0,R1,#0		; carico in R0 il carattere di stringa a cui sono arrivato
		BRZ haltprg		; se leggo il carattere terminatore termino il programma
		TRAP x21		; stampo a video il carattere appena letto in R0
		ADD R1,R1,x0001		; incremento R1 al prossimo carattere
		BR loop			; ricomincio il ciclo
		


haltprg		TRAP x25		; halt processor




stringa		.stringz "Ciao Mondo"


		.end