#include "CacheSim.h"

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */
#define NUM_LMC 128

unsigned int mem_etiquetas[NUM_LMC];
int mem_validez[NUM_LMC];



/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comen�ar cada un dels tests.
 * */
void init_cache ()
{
	// INICIALIZAR VARS GLOBABLES, CACHE VACIA
    totaltime=0.0;
	/* Escriu aqui el teu codi */
	for (int i = 0; i < NUM_LMC; ++i) {
		mem_validez[i] = false;
	}
}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address)
{
	// GENERAR VALOR CORRECTO DE LAS 7 VARIABLES LOCALES
	unsigned int byte;
	unsigned int bloque_m; 
	unsigned int linea_mc;
	unsigned int tag;
	unsigned int miss;	   // boolea que ens indica si es miss
	unsigned int replacement;  // boolea que indica si es reempla�a una linia valida
	unsigned int tag_out;	   // TAG de la linia reempla�ada
	float t1,t2;		// Variables per mesurar el temps (NO modificar)
	
	t1=GetTime();
	/* Escriu aqui el teu codi */
	byte = address & 0x1F;
	bloque_m = address >> 5;
	linea_mc = bloque_m & 0x7F;
	tag = bloque_m >> 7;

	int valido = mem_validez[linea_mc];
	miss = !valido || tag != mem_etiquetas[linea_mc];
	
	replacement = false;
	if (miss) {
		if (valido) {
			replacement = true;
			tag_out = mem_etiquetas[linea_mc];
		} else {
			mem_validez[linea_mc] = true;
		}
		mem_etiquetas[linea_mc] = tag;
	} 
	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual. Tamb� mesurem el temps d'execuci�
	 * */
	t2=GetTime();
	totaltime+=t2-t1;
	test_and_print (address, byte, bloque_m, linea_mc, tag, miss, replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
 	/* Escriu aqui el teu codi */ 
  
  
}
