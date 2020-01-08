#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

// considerando 2 dígitos + 0x0A + 0x00
#define LINE_SIZE	4

#define IS_VALID(val) ((val >= 1 && val <= 40) ? true : false)

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
    	
    	if (IS_VALID(pressao_motorista) && IS_VALID(pressao_bomba)) {
    		printf("%d", pressao_motorista - pressao_bomba);
		}
    }

    fclose(fp);

    return (0);
}


