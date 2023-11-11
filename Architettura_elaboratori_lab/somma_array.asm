; stampa a video di una stringa che si considera finita dal carattere terminatore x00

	.orig x3000
	
	
	and R0,R0,0




str	.stringz "Ciao Mondo"


	.end