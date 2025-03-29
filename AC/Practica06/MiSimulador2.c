#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "CacheSim.h"

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */
#define NUM_LMC 128
unsigned int mem_etiquetas[NUM_LMC];
int mem_validez[NUM_LMC];
int dirty[NUM_LMC];

int n_hits = 0;
int n_miss = 0;
int n_total = 0;


/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comen�ar cada un dels tests.
 * */
void init_cache ()
{
	/* Escriu aqui el teu codi */
	for (int i = 0; i < NUM_LMC; ++i) {
		mem_validez[i] = false;
		dirty[i] = false;
	}
}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address, unsigned int LE)
{
	unsigned int byte;
	unsigned int bloque_m; 
	unsigned int linea_mc;
	unsigned int tag;
	unsigned int miss;
	unsigned int lec_mp;
	unsigned int mida_lec_mp;
	unsigned int esc_mp;
	unsigned int mida_esc_mp;
	unsigned int replacement;
	unsigned int tag_out;

	/* Escriu aqui el teu codi */
	byte = address & 0x1F;
	bloque_m = address >> 5;
	linea_mc = bloque_m & 0x7F;
	tag = bloque_m >> 7;

	int valido = mem_validez[linea_mc];
	miss = !valido || tag != mem_etiquetas[linea_mc];

	if (miss) n_miss++;
	else n_hits++;
	n_total++;

	lec_mp = false;
	esc_mp = false;
	replacement = false;
	if (miss) {
		// Si dirty, primero escribir el bloque anterior a MP
		if (dirty[linea_mc]) {
			esc_mp = true;
			mida_esc_mp = 32;
		}
		
		// Reemplazamos el bloque
		if (valido) {
			replacement = true;
			tag_out = mem_etiquetas[linea_mc];
		} else {
			mem_validez[linea_mc] = true;
		}
		mem_etiquetas[linea_mc] = tag;
		
		lec_mp = true;
		mida_lec_mp = 32;

		dirty[linea_mc] = LE; // Si es escritura, poner dirty, si no, quitar dirty
	} else {
		if (LE) dirty[linea_mc] = true; // Hit+escritura poner dirty
	}

	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual
	 * */
	test_and_print (address, LE, byte, bloque_m, linea_mc, tag,
			miss, lec_mp, mida_lec_mp, esc_mp, mida_esc_mp,
			replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
 	/* Escriu aqui el teu codi */
	char buf[64];
	sprintf(buf, "Hits: %d, Miss: %d, Total: %d\n", n_hits, n_miss, n_total);
	write(1, &buf, strlen(buf));
}
