#include <ascii_keyboard.h>
#include <keyboard_driver.h>
#include <types.h>
#define BUFFER_SIZE 2000 /* 2000 = 80 * 25 */

static byte buffer[BUFFER_SIZE];

static boolean ctrlPressed = false; /* flag that indicates if ctrl was pressed or not */
static boolean bloqMayusPressed = false; /* flag that indicates if bloqMayus was pressed or not */
static boolean shiftRPressed = false; /* flag that indicates if right shift was pressed or not */
static boolean shiftLPressed = false; /* flag that indicates if left shift was pressed or not */
static boolean altPressed = false; /* flag that indicates if alt was pressed or not */

static int index = 0; /* indicates the index */
static int bufferIndex = 0; /* indicates the index of the buffer */
 
extern byte _read_keyboard();

void keyboard_handler() {
	byte key = _read_keyboard();	
	update_buffer(key);
}

void update_buffer(unsigned char key){
	
	if (key == 0x1D || key==0X9D) {
        ctrlPressed = !ctrlPressed; 
        return;
    } else if(key==0x36 || key==0xB6){
        shiftRPressed =! shiftRPressed;
        return;
    }else if(key==0x2A || key==0XAA){
        shiftLPressed =! shiftLPressed;
        return;
    }else if(key==0x38 || key==0xB8){
        altPressed =! altPressed;
        return;
    }else if(key==0x3A){
        bloqMayusPressed =! bloqMayusPressed;
        return;
    }
    
    if(key&0X80)
    	return;

	
    if(ctrlPressed || altPressed)
    	return;
    if(!bloqMayusPressed && !shiftLPressed && !shiftRPressed){
		key=KEY_VALUE[key];
    }else{
		if(bloqMayusPressed && !shiftLPressed && !shiftRPressed){
			key=KEY_VALUE[key];
			if(key>='a'&& key<='z')
				key=key-'a'+'A';
		}
		else{	
			if((shiftLPressed|| shiftRPressed) && !bloqMayusPressed)
				key=SHIFT_KEY_VALUE[key];
			else{
					unsigned char aux=KEY_VALUE[key];
					if(aux<'a'|| aux>'z')
						key=SHIFT_KEY_VALUE[key];
					else
						key=KEY_VALUE[key];
			}
		}
	}
	
	buffer[bufferIndex] = key;
	bufferIndex = (bufferIndex+1)%BUFFER_SIZE;
	
		
}

char get_buffer(){
	
	if(index != bufferIndex){
		byte aux = buffer[index];
		index = (index+1)%BUFFER_SIZE;
		return aux;
	}

	return EOF;
}

void read_buffer(char* buff, int size){
    int i = 0;
    char c;

    while (i < (size - 1) && (c = get_buffer()) != EOF) {
        buff[i] = (char) c;
        i++;
    }

    buff[i] = 0;
    
}

void add_buffer(char *buffercopy){
	int x;	
	for(x = 0; buffercopy[x] != 0; x++){
		buffer[bufferIndex] = buffercopy[x];
		bufferIndex = (bufferIndex+1) % BUFFER_SIZE;
	}
}

