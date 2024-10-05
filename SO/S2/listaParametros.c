#include "my_functions.h"

void Usage()
{
	char buffer[128];
	sprintf(buffer, "Usage:listaParametros arg1 [arg2..argn]\nThis program writes in the standard output the arguments it receives\n");
	write(1, buffer, strlen(buffer));
}

int main(int argc,char *argv[])
{
	if (argc < 2) {
		Usage();
		return 0;
	}
	
	char buf[80];
	for (int i=0; i<argc; i++){
		if (i==0){
			sprintf(buf,"El argumento %d es %s (es el nombre del ejecutable)\n",i,argv[i]);
		}else{
			sprintf(buf,"El argumento %d es %s\n",i,argv[i]);
		}
		write(1,buf,strlen(buf));
	}
	return 0;
}
