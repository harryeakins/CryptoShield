class TextEditor {
private:
  int width;
  int height;
  char text[100];
  int cursor;
  static const int FONT_SIZE = 2;
  static const INT16U FONT_COLOR = BLACK;
  static const INT16U BG_COLOR = WHITE;
  static const int CELL_SIZE = 16;

public:
  TextEditor(int width, int height) : 
  height(height), width(width), cursor(0) {
    //text = (char *)calloc(width*height, 1);
  }
  
  void init() {
     Tft.fillRectangle(0, 0, width*CELL_SIZE, height*CELL_SIZE, BG_COLOR);
     renderCursor(cursor);
  }

  void typeChar(char ch) {
    switch(ch) {
    case '\n':
      renderCharacter(cursor);
      cursor = ((cursor/width)+1)*width;
      renderCursor(cursor);
      break;
    case '\b':
      renderCharacter(cursor);
      cursor--;
      text[cursor] = '\0';
      renderCharacter(cursor);
      renderCursor(cursor);
      break;
    default:
      text[cursor] = ch;
      renderCharacter(cursor);
      cursor++;
      renderCursor(cursor);
      break;
    }
  }

private:
  void renderCharacter(int pos) {
    int x = (pos % width);
    int y = (pos/width);
    Tft.fillRectangle(x*CELL_SIZE, y*CELL_SIZE, CELL_SIZE, CELL_SIZE, BG_COLOR);
    if(text[pos] != '\0') {
      Tft.drawChar(text[pos], x * CELL_SIZE, y * CELL_SIZE, FONT_SIZE, FONT_COLOR);
    }
  }
  void renderCursor(int pos) {
    int x = (pos % width);
    int y = (pos/width);
    Tft.fillRectangle(x*CELL_SIZE, (y+1)*CELL_SIZE-1, CELL_SIZE, 1, FONT_COLOR);
  }
};
