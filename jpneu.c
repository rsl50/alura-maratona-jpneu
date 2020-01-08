#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// considerando 2 dígitos + 0x0A + 0x00
#define LINE_SIZE	4

int main () {
	FILE *fp;	
	fp = freopen("input1.txt", "r", stdin); 
	
    char buf[LINE_SIZE];    
    memset(buf, 0, LINE_SIZE);
	
	if (fp == NULL) {
    	printf("Erro ao abrir arquivo");
    	return(-1);
    }
    else {
    	fgets(buf, sizeof(buf), fp);
    	int pressao_motorista = strtol(buf, NULL, 10);
    	
    	fgets(buf, sizeof(buf), fp);
    	int pressao_bomba = strtol(buf, NULL, 10);
    	
    	printf("%d", pressao_motorista - pressao_bomba);
    }

    fclose(fp);

    return (0);
}


