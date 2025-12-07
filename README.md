# TUI
Tangent UI system, a WIP graphics engine that will be integrated with tangent

## How can I use Tui?
Tui, is a collection of many tools including a tml parser (tml is my own markup language similar to HTML), and a whole bunch of other stuff like printing, drawing, various shapes and some math stuff.

## How can I build Tui?
Ha!
Good luck, but you need to place the dcl and trg file supplied in /lapis into the respective folder on your lexide omega installation, the rest of the files can just go into an empty project.
Once that is done, just press the build button, and it should generate a .HEX file in the /Release folder (I put a prebuilt one there)

## How can I run Tui?
Use a tool like hex2bin or your own tool to convert the .HEX file into a .bin file, and use [CasioEmuMSVC](https://github.com/telecomadm1145/CasioEmuMsvc) to run it, I can't supply the model here, but it should be easy to find.

## Why is the code a mess?
It's a WIP, you can contribute to fix it.

## Why don't you use a GPU?
It is designed for a calculator, it does not have a 5090...

# Stuff
Here is an example on how to use it.
```c
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
	parse_tml(test, sizeof(test));
	render_buffer();
	return 0;
}
```

Currently this is the only way to write TML data, eventually, the Tangent SDK will provide tools to convert it easily.

## Supported TML elements
```
TML_TEXT
TML_BUTTON
TML_DIV
TML_INPUT
TML_CHECKBOX
TML_RADIO
TML_LINE
```

## Supported TML element fields
```
E_FIELD_ID
E_FIELD_X
E_FIELD_X0
E_FIELD_X
E_FIELD_Y
E_FIELD_Y0
E_FIELD_Y
E_FIELD_WIDTH
E_FIELD_X1
E_FIELD_WIDTH
E_FIELD_HEIGHT
E_FIELD_Y1
E_FIELD_HEIGHT
E_FIELD_ANCHOR_X
E_FIELD_ANCHOR_Y
E_FIELD_COLOUR
E_FIELD_BORDER_COLOUR
E_FIELD_COLOUR
E_FIELD_STYLE,
E_FIELD_BORDER_STYLE
E_FIELD_STYLE
E_FIELD_ALIGN
E_FIELD_TEXT_ALIGN
E_FIELD_BORDER_THICKNESS
E_FIELD_TEXT_COLOUR
E_FIELD_FONT_SIZE
E_FIELD_VALUE
E_FIELD_CHECKED
E_FIELD_VALUE
E_FIELD_ROTATION
E_FIELD_TEXT
```

## Supported TML align values

```
ALIGN_LEFT
ALIGN_TOP_LEFT
ALIGN_LEFT
ALIGN_CENTER_LEFT
ALIGN_BOTTOM_LEFT
ALIGN_RIGHT
ALIGN_TOP_RIGHT
ALIGN_RIGHT
ALIGN_CENTER_RIGHT
ALIGN_BOTTOM_RIGHT
ALIGN_CENTER
ALIGN_TOP_CENTER
ALIGN_CENTER
ALIGN_BOTTOM_CENTER
ALIGN_MIDDLE_CENTE
```

Note: `ALIGN_CENTER` is the same as `ALIGN_TOP_CENTER` as all are aligned to top unless specified otherwise.

## Supported font sizes
```
FONT_SIZE_6x7
FONT_SIZE_6x8
FONT_SIZE_6x10
FONT_SIZE_7x10
FONT_SIZE_8x8
FONT_SIZE_8x12
FONT_SIZE_12x16
```

## Supported line styles
```
LINE_STYLE_NONE
LINE_STYLE_SOLID
LINE_STYLE_DOTTED
LINE_STYLE_DASHED
```

Note: line styles are just patterns for the line, eg `LINE_STYLE_DASHED` = `0xF8` (`11111000`), so you can supply your own patterns if you want.

## Supported colours
```
COLOUR_WHITE
COLOUR_LIGHT_GREY
COLOUR_DARK_GREY
COLOUR_BLACK
COLOUR_IMAGE
```

Note: how colours work is that white, lgrey, dgrey and black are self explanitory, but `COLOUR_IMAGE` means that it is for bitmaps with colour (basically 2 bitmaps next to each other, one being light and one dark, and when a dark and a light are overlayed it makes black, effectivly making all of the 4 colours of the rainbow).

## That is all, please contribute 🙏🙏🙏
