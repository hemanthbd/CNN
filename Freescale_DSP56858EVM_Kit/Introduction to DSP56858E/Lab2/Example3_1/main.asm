



; metrowerks sample code



	section rtlib
	org	p:

	global	Fmain

	SUBROUTINE "Fmain",Fmain,FmainEND-Fmain

; assembly level entry point
Fmain:
	MOVE.L #100000, A 	;load accumulator A with 32-bit decimal 100000 
	MOVE.W #%1010, B	;load accumulator B with 16-bit binary 0000000000001010 
	MOVE.L #$A, C		;load accumulator C with 32-bit ;hexadecimal $0000000A
	rts
FmainEND:

	endsec	

	end
