#ifndef KEYBOARD_H
#define KEYBOARD_H

void keyboard_init(void);
unsigned char ps2_to_ascii(unsigned char code);
void add_character_in_buffer(char character);
char read_character_in_buffer(void);

#endif
