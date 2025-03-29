#include "CacheSim.h"

/* Posa aqui les teves estructures de dades globals
* per mantenir la informacio necesaria de la cache
* */
	#define NUM_SETS 64
	#define NUM_WAYS 2

	unsigned int mem_etiquetas[NUM_SETS][NUM_WAYS];
	int mem_validez[NUM_SETS][NUM_WAYS];
	int mem_lru[NUM_SETS];


/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comen�ar cada un dels tests.
 * */
void init_cache ()
{
    totaltime=0.0;
	/* Escriu aqui el teu codi */
	for (int i = 0; i < NUM_SETS; ++i) {
		mem_lru[i] = 0;
		for (int j = 0; j < NUM_WAYS; ++j) {
			mem_validez[i][j] = false;
		}
	}
}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address)
{
	unsigned int byte;
	unsigned int bloque_m; 
	unsigned int conj_mc;
	unsigned int via_mc;
	unsigned int tag;
	unsigned int miss;	   // boolea que ens indica si es miss
	unsigned int replacement;  // boolea que indica si es reempla�a una linia valida
	unsigned int tag_out;	   // TAG de la linia reempla�ada
	float t1,t2;		// Variables per mesurar el temps (NO modificar)
	
	t1=GetTime();
	/* Escriu aqui el teu codi */
	byte = address && 0x1F;
	
	byte = address & 0x1F;
	bloque_m = address >> 5;
	conj_mc = bloque_m & 0x3F;
	tag = bloque_m >> 6;

	int hit_way[NUM_WAYS];

	hit_way[0] = mem_validez[conj_mc][0] && tag == mem_etiquetas[conj_mc][0];
	if (hit_way[0]) {
		mem_lru[conj_mc] = 1;
		via_mc = 0;
	} 
	
	else {
		hit_way[1] = mem_validez[conj_mc][1] && tag == mem_etiquetas[conj_mc][1];
		if (hit_way[1]) {
			mem_lru[conj_mc] = 0;
			via_mc = 1;
		} 
	}

	replacement = false;
	miss = !hit_way[0] && !hit_way[1];
	if (miss) {
		// via 0 no valida
		if (!mem_validez[conj_mc][0]) {
			via_mc = 0;
		}
		// via 1 no valida
		else if (!mem_validez[conj_mc][1]) {
			via_mc = 1;
		}
		// ambas validas 
		else {
			replacement = true;
			via_mc = mem_lru[conj_mc];
			tag_out = mem_etiquetas[conj_mc][via_mc];
		}
		// pone la otra via como LRU
		mem_lru[conj_mc] = !via_mc;
		
		mem_etiquetas[conj_mc][via_mc] = tag;
		mem_validez[conj_mc][via_mc] = true;
	}
	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual. Tamb� mesurem el temps d'execuci�
	 * */
	t2=GetTime();
	totaltime+=t2-t1;
	test_and_print2 (address, byte, bloque_m, conj_mc, via_mc, tag,
			miss, replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
 	/* Escriu aqui el teu codi */ 
  
  
}
