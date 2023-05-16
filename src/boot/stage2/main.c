#include "stdint.h"
#include "stdio.h"
#include "disk.h"
#include "fat.h"
#include "memory.h"
#include "string.h"

#define cmds_size 3


void far* g_data = (void far*)0x00500200;


DISK disk;
char buffer[1024];
char cwd[256];





char* token_hunter(char* buffer, int token){ //put what token you want 0-whatever
	char* token_prey = &buffer[0];
	int cur_token=0;
	while(1){
		if(*buffer=='\0'){
			cur_token++; //okay very close just need to make sure to get passed a bunch of \0
			if(cur_token>token){
				return token_prey;
			}
			//cant assume there will be only one null terminator
			while(*(buffer+1)=='\0'){
				buffer++;
			}	
			token_prey = (buffer + 1);
		}
		buffer++;
	}
}





void ls(){
//printf("\r\nran ls\r\n");
	    
FAT_File far* fd = FAT_Open(&disk, cwd);
    FAT_DirectoryEntry entry;
    printf("\r\n");
    int i = 0;
    while (FAT_ReadEntry(&disk, fd, &entry) && i++ < 5)
    {
        printf("  ");
        for (int i = 0; i < 11; i++)
            putc(entry.Name[i]);
        printf("\r\n");
    }
    FAT_Close(fd);

    }


void help(){
	printf("\r\nBrenner Os literally has two commands help and ls good luck\r\n");
}
void (*command_table[50])(void) = 
{
	&ls,
	&help,
};



char *cmds[cmds_size] = 
{
	"ls",
	"help",
};


void handle_buffer(char* buff){
        for(int i=0; i<cmds_size;i++){
                if(strcmp(cmds[i], token_hunter(buff, 0))==0){
			//printf("cmds[i]: %d, token: %d\r\n", cmds[i], token_hunter(buff, 0));
				command_table[i]();
				return;
	}	//memset(buff, '\0', 1024);
	}
	printf("\r\n");
}

void handle_character(char chr, char* buff, int* index){
        switch(chr){
                case 13:
			strtok(buff, ' ');
                        handle_buffer(buff);
			memset(buff, '\0', 1024);
			*index = 0;
			break;
                default:
			printf("%c", chr);
			break;
        }
}



void _cdecl cstart_(uint16_t bootDrive)
{
    buffer[1023] = '\0';
	int buffer_index = 0;
	char character;
    //DISK diisk;

    if (!DISK_Initialize(&disk, bootDrive))
    {
        printf("Disk init error\r\n");
       // goto end;
    }

    DISK_ReadSectors(&disk, 19, 1, g_data);
	//reading rootdirectory

    if (!FAT_Initialize(&disk))
    {
        printf("FAT init error\r\n");
       // goto end;
    }
/*
    // browse files in root
    FAT_File far* fd = FAT_Open(&disk, "/");
    FAT_DirectoryEntry entry;
    int i = 0;
    while (FAT_ReadEntry(&disk, fd, &entry) && i++ < 5)
    {
        printf("  ");
        for (int i = 0; i < 11; i++)
            putc(entry.Name[i]);
        printf("\r\n");
    }
    FAT_Close(fd);
*/	
    printf("%d\r\n", strcmp(cmds[1], "help"));
    printf("%d\r\n", strcmp(cmds[1], "ls"));
	while(true){
		character = getc();
		buffer[buffer_index] = character;
		buffer_index++;
		handle_character(character, buffer, &buffer_index);		
	}

    for(;;);
}
