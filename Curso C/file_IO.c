#include <stdio.h>
#include <stdlib.h>

#define SAMPLES_LEN 100 
#define DOWNSAMPLE_K 10

void program_failure(char str[]){ //função que fará o error handling do código
    perror(str); //printamos o erro
    exit(EXIT_FAILURE); //quitamos do programa com um exit failure
}

int main()
{
    //Criando e populando uma array
    double samples[SAMPLES_LEN];
    for (int i = 0; i < SAMPLES_LEN; i++){
        samples[i] = (i+1)/10.0; //colocando a casa decimal no dez, forçamos a divisão a resultar uma double
        printf("%.1f, ", samples[i]);
    }
    printf("\n-----\n");

    //Vamos agora escrever os samples num arquivo
    //abrindo um arquivo em binary write mode, veja que neste modo, caso o arquivo não exista, ele será criado.
    FILE *fp = fopen("samples.bin","wb");

    if(!fp){ //error handling
        program_failure("File opening error");
    }
    
    //escrevendo no arquivo, fwrite(buffer, size, count, stream)
    size_t written_count = fwrite(samples, sizeof(samples[0]),SAMPLES_LEN,fp); 
    //verificando se a quantidade de elementos escritos é igual ao tamanho da array
    //Se não for, temos algum erro
    if (written_count != SAMPLES_LEN){ 
        program_failure("File writing failed");
    }

    fclose(fp); //fechando a stream

    //vamos agora ler o arquivo, mas vamos pegar somente os itens dos indexes multiplos de 10, então:
    //10,20... Na prática, como a array começa em 0, serão 9,19...
    double sam_k[SAMPLES_LEN/DOWNSAMPLE_K]; //iniciando a array onde teremos os valores
    fp = fopen("samples.bin", "rb");//iniciando o arquivo binário em modo de leitura

    //lendo o bendito do arquivo já nos índices que queremos
    for (int i = 0; i < SAMPLES_LEN/DOWNSAMPLE_K ; i++){
        int offset = (DOWNSAMPLE_K-1) * sizeof(sam_k[0]);
        if(fseek(fp,offset,SEEK_CUR) != 0){
            program_failure("File seeking failure");
        }
        //lendo de fato o arquivo
        size_t count = fread(&sam_k[i], sizeof(sam_k[0]), 1, fp);
        //error handling
        if (count != 1){
            if(feof(fp)){
                program_failure("Unexpected end of file");
            }
            else{
                program_failure("Eror reading file");
            }
        }
        //printando os elementos
        printf("%.1f, ", sam_k[i]);
    }
    return EXIT_SUCCESS;
}
