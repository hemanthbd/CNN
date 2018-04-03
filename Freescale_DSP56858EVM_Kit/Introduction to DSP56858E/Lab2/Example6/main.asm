



; metrowerks sample code



	section rtlib
	org	p:

	global	Fmain

	SUBROUTINE "Fmain",Fmain,FmainEND-Fmain

; assembly level entry point
Fmain:
	MOVE.W	#$FF0A, X:$0000 ;load data memory $0000 with $FF0A 
	MOVE.W	#$FF0B, X:$0001 ;load data memory $0001 with $FF0B 
	MOVE.L	#$0000, R0 		;store $0000 into R0  
	MOVE.W	X:(R0), X0 		;read data memory location pointed by R0 into internal register X0 
	ADDA  	#1, R0 			;Add 1 to R0 and store the result back in R0 
 	MOVE.W	X:(R0), Y0 		;read data memory $0001 and store result in Y0
	rts
FmainEND:

	endsec	

	end
