#include "glib.h"

// Simple delay function using timer sfr
void delay(ushort after_ticks)
{
    if ((FCON & 2) != 0)
        FCON &= 0xfd;
    __DI();
    Timer0Interval = after_ticks;
    Timer0Counter = 0;
    Timer0Control = 0x0101;
    InterruptPending_W0 = 0;
    StopAcceptor = 0x50;
    StopAcceptor = 0xa0;
    StopControl = 2;
    __asm("nop");
    __asm("nop");
    __EI();
}

//just smth to let me know smth went bad
//it triggers when BRK instruciton is run
void custom_break() {
	while (1) {
		deref(0x9100) = 0xFF;
	}
}

// Example TML data for testing
const byte test[] = {
	'<',               // 0
		TML_TEXT,          // 1
		E_FIELD_X, 1,     // 2,3
		E_FIELD_Y, 2,
		E_FIELD_FONT_SIZE, FONT_SIZE_12x16,          // 12,13
		E_FIELD_COLOUR, COLOUR_BLACK,        // 14,15
		E_FIELD_TEXT,                        // 16
		'H','e','l','l', 0,                   // 17-21
		'<',
			TML_TEXT,
			E_FIELD_X, 15,
			E_FIELD_Y, 30,
			E_FIELD_FONT_SIZE, FONT_SIZE_8x12,
			E_FIELD_ROTATION, 15,
			E_FIELD_COLOUR, COLOUR_BLACK,
			E_FIELD_TEXT,
			'R','o','t','a','t','e','d',' ', '8','x','1','2',0,
		'>',
		'<',
			TML_TEXT,
			E_FIELD_Y, 16,
			E_FIELD_FONT_SIZE, FONT_SIZE_8x8,
			E_FIELD_COLOUR, COLOUR_BLACK,
			E_FIELD_TEXT,
			'F', 'o', 'n', 't', ':', ' ', '8','x','8',0,
		'>',
		'<',
			TML_TEXT,
			E_FIELD_Y, 15,
			E_FIELD_X, 96,
			E_FIELD_FONT_SIZE, FONT_SIZE_6x10,
			E_FIELD_COLOUR, COLOUR_DARK_GREY,
			E_FIELD_TEXT,
			'H', '-', '!', 0,
		'>',
		'<',
			TML_BUTTON,
			E_FIELD_X, 50,
			E_FIELD_Y, 2,
			E_FIELD_WIDTH, 90,
			E_FIELD_HEIGHT, 20,
			E_FIELD_BORDER_THICKNESS, 2,
			E_FIELD_BORDER_STYLE, LINE_STYLE_DASHED,
			E_FIELD_TEXT_ALIGN, ALIGN_MIDDLE_CENTER,
			E_FIELD_COLOUR, COLOUR_BLACK,
			E_FIELD_FONT_SIZE, FONT_SIZE_7x10,
			E_FIELD_TEXT,
			'B','u','t','t','o','n',0,
		'>',
		'<',
			TML_RADIO,
			E_FIELD_X, 160,
			E_FIELD_Y, 20,
			E_FIELD_WIDTH, 16,
			E_FIELD_COLOUR, COLOUR_BLACK,
			E_FIELD_BORDER_THICKNESS, 1,
		'>',
	'>'
};

int main() {
	Write2RealScreen = 0;
	clear_screen();
	parse_tml(test, sizeof(test)); //Idk
	render_buffer();

	return 0;
}
