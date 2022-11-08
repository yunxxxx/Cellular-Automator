#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>

using namespace std;

char **gridCanvas(int height, int width, char fillChar);
void printGrid(char **grid, int height, int width);
bool XYchecker(int **grid, int X, int Y);
char **waterStart(int height, int width, char fillChar);
void waterFlow(char **array, int height, int width, char fillChar);
char **hackerStart(int height, int width);
char hackHelper();
void printHacker(char **grid, int height, int width);
void hackerFlow(char **array,int height, int width, char newChar);
void hackerGo(char **grid, int height, int width);
char **rugMaker(int height, int width);
void rugHelper(char **canvas, int height, int width);


int main(int argc, char **argv) {
    char **grid;
    int width, height, opp;
    char fillChar = '*';

    cout << "Enter the height of your grid: ";
    cin >> width;
    cout << "Enter the width of your grid ";
    cin >> height;

    cout << "Enter the animation " << endl;
    cout << "1.water " << endl;
    cout << "2.hacker" << endl;
    cout << "3.rugMaker" << endl;

    cin >> opp;

    if (opp == 1) {
        grid = waterStart(height, width, fillChar);
        int count = 0;
        while (count != 200) {
            waterFlow(grid, height, width, fillChar);
            printGrid(grid, height, width);
            count++;
        }
    }

    if (opp == 2) {
    grid = hackerStart(height, width);
    int count = 0;
        while (count != 10) {
            hackerGo(grid, height, width);
            count++;
        }
        cout << "\x1B[31mERROR!!!!!ERROR!!!!!\033[0m" << endl;
    }

    if (opp == 3) {
    grid = rugMaker(height, width);
    int count = 0;
        while (count != 10) {
            hackerGo(grid, height, width);
            count++;
        }
        cout << "\x1B[31mERROR!!!!!ERROR!!!!!\033[0m" << endl;
    }





    //delete the array before end the function.
    for (int i = 0; i < width; i++) {
        delete[] grid[i];
    }
    delete[] grid;
    //function end
    return 0;
}

// gridCanvas will use the height and width user given to system crate an 2D int array.
char **gridCanvas(int height, int width, char fillChar) {
    char **canvas = new char *[width];
    for (int i = 0; i < width; i++) {
        canvas[i] = new char[height];
    }
    for (int y = 0; y < width; y++) {
        for (int x = 0; x < height; x++) {
            canvas[y][x] = fillChar;
        }
    }
    return canvas;
}

//the printGrid will take the 2D array(the grid), the height of the array, width of the array and the char user want to fill in.
void printGrid(char **array, int height, int width) {
    //clear the canvas before everytime print a new grid.
    std::this_thread::sleep_for(100ms);
    system("clear");
    //checking every unit of the array, if the number is 0, print a space shows there are nothing here. if is 1, print # as an impassible unit. if is 2, print the char user want fill it.
    for (int y = 0; y < width; y++) {
        for (int x = 0; x < height; x++) {
            cout << array[y][x];
        }
        cout << endl;
    }
}

//check is X and Y already have some value.
bool XYchecker(int **grid, int X, int Y) {
    if (grid[Y][X] == 1) {
        return false;
    }
    return true;
}

// gridCanvas will use the height and width user given to system crate an 2D int array.
char **waterStart(int height, int width, char fillChar) {
    char **canvas = new char *[width];
    for (int i = 0; i < width; i++) {
        canvas[i] = new char[height];
    }
    for (int x = 0; x < height; x++) {
        if (x % 2 == 0) {
            canvas[0][x] = fillChar;
        }
        else {
            canvas[0][x] = ' ';
        }
    }

    for (int y = 1; y < width; y++) {
        printGrid(canvas, height, y);
        for (int x = 0; x < height; x++) {
            if (canvas[y - 1][x] == ' ') {
                canvas[y][x] = fillChar;
            }
            else {
                canvas[y][x] = ' ';
            }
        }
    }
    return canvas;
}

void waterFlow(char **array, int height, int width, char fillChar) {
    for (int y = 0; y < width; y++) {
        for (int x = 0; x < height; x++) {
            if (array[y][x] == ' ') {
                array[y][x] = fillChar;
            }
            else {
                array[y][x] = ' ';
            }

        }
    }
}

char **rugMaker(int height, int width) {
    char **canvas = new char *[width];
    for (int i = 0; i < width; i++) {
        canvas[i] = new char[height];
    }
    for (int x = 0; x < height; x++) {
        rugHelper(canvas, 0, x);
        x++;
        x++;
    }
    for (int y = 1; y < width; y++) {
        printGrid(canvas, height, y);
        for (int x = 0; x < height; x++) {
            
            int next = 0;
            if (canvas[y - 1][x] == '#' && canvas[y - 1][x + 1] == '#' && canvas[y - 1][x + 2] == '#') {
                next = 1;
            }
            if (canvas[y - 1][x] == '#' && canvas[y - 1][x + 1] == ' ' && canvas[y - 1][x + 2] == ' ') {
                next = 2;
            }
            if (canvas[y - 1][x] == ' ' && canvas[y - 1][x + 1] == '#' && canvas[y - 1][x + 2] == '#') {
                next = 3;
            }
            if (canvas[y - 1][x] == '#' && canvas[y - 1][x + 1] == ' ' && canvas[y - 1][x + 2] == '#') {
                next = 4;
            }
            if (canvas[y - 1][x] == ' ' && canvas[y - 1][x + 1] == '#' && canvas[y - 1][x + 2] == ' ') {
                next = 5;
            }
            if (canvas[y - 1][x] == ' ' && canvas[y - 1][x + 1] == ' ' && canvas[y - 1][x + 2] == '#') {
                next = 6;
            }
            switch (next) {
                case 6:
                    canvas[y][x] = '#';
                    canvas[y][x + 1] = '#';
                    canvas[y][x+ 2] = '#';
                    break;
                case 1:
                    canvas[y][x] = '#';
                    canvas[y][x + 1] = ' ';
                    canvas[y][x+ 2] = ' ';
                    break;
                case 2:
                    canvas[y][x] = ' ';
                    canvas[y][x + 1] = '#';
                    canvas[y][x+ 2] = '#';
                    break;
                case 3:
                    canvas[y][x] = '#';
                    canvas[y][x + 1] = ' ';
                    canvas[y][x+ 2] = '#';
                    break;
                case 4:
                    canvas[y][x] = ' ';
                    canvas[y][x + 1] = '#';
                    canvas[y][x+ 2] = ' ';
                    break;
                case 5:
                    canvas[y][x] = ' ';
                    canvas[y][x + 1] = ' ';
                    canvas[y][x + 2] = '#';
                    break;
                default:
                    canvas[y][x] = ' ';
                    canvas[y][x + 1] = ' ';
                    canvas[y][x + 2] = ' ' ;
                }
            x++;
            x++;
        }
    }
    return canvas;
}

void rugHelper(char **canvas, int height, int width) {
    int random;
    //srand(time(0));
    random = rand() % 6 + 1;
    switch (random) {
        case 1:
            canvas[height][width] = '#';
            canvas[height][width + 1] = '#';
            canvas[height][width+ 2] = '#';
            break;
        case 2:
            canvas[height][width] = '#';
            canvas[height][width + 1] = ' ';
            canvas[height][width+ 2] = ' ';
            break;
        case 3:
            canvas[height][width] = ' ';
            canvas[height][width + 1] = '#';
            canvas[height][width+ 2] = '#';
            break;
        case 4:
            canvas[height][width] = '#';
            canvas[height][width + 1] = ' ';
            canvas[height][width+ 2] = '#';
            break;
        case 5:
            canvas[height][width] = ' ';
            canvas[height][width + 1] = '#';
            canvas[height][width+ 2] = ' ';
            break;
        case 6:
            canvas[height][width] = ' ';
            canvas[height][width + 1] = ' ';
            canvas[height][width+ 2] = '#';
            break;
    }
}

char **hackerStart(int height, int width) {
    int random;
    char **canvas = new char *[width];
    for (int i = 0; i < width; i++) {
        canvas[i] = new char[height];
    }
    for (int x = 0; x < height; x++) {
        canvas[0][x] = hackHelper();
    }

    for (int y = 1; y < width; y++) {
        printHacker(canvas, height, y);
        for (int x = 0; x < height; x++) {
            random = rand() % 15 + 1;
            switch (canvas[0][x]) {
                case ' ':
                    if (random == 1) {
                        hackerFlow(canvas ,x , y , hackHelper());
                    }
                    else {
                        hackerFlow(canvas ,x , y , ' ');
                    }
                    break;
                case '2':
                        hackerFlow(canvas ,x , y , '$');
                    break;
                case '4':
                        hackerFlow(canvas ,x , y , '%');
                    break;
                case '6':
                        hackerFlow(canvas ,x , y , '&');
                    break;
                default:
                    hackerFlow(canvas, x,  y, ' ');
                    break;
                }
        }
    }
    return canvas;
}
void hackerFlow(char **canvas,int height, int width, char newChar) {
    char saver, saver2;
    saver = canvas[0][height];
    canvas[0][height] = newChar;

    for (int y = 1; y < width; y++) {
        saver2 = saver;
        saver = canvas[y][height];
        canvas[y][height] = saver2;
    }
}

void hackerGo(char **canvas, int height, int width) {
    int random;
    for (int y = 1; y < width; y++) {
        printHacker(canvas, height, width);
        for (int x = 0; x < height; x++) {
            random = rand() % 15 + 1;
            switch (canvas[0][x]) {
                case ' ':
                    if (random == 1) {
                        hackerFlow(canvas ,x , width , hackHelper());
                    }
                    else {
                        hackerFlow(canvas ,x , width , ' ');
                    }
                    break;
                case '2':
                        hackerFlow(canvas ,x , width , '$');
                    break;
                case '4':
                        hackerFlow(canvas ,x , width , '%');
                    break;
                case '6':
                        hackerFlow(canvas ,x , width , '&');
                    break;
                case '/':
                        hackerFlow(canvas,x, width , '*');
                    break;
                case '3':
                        hackerFlow(canvas, x, width, '+');
                    break;
                case '1':
                        hackerFlow(canvas, x, width, '-');
                    break;
                case '0':
                    hackerFlow(canvas, x, width, '/');
                    break;
                case '$':
                    hackerFlow(canvas, x, width, '0');
                    break;
                case '%':
                    hackerFlow(canvas, x,  width,  '1');
                    break;
                case '&':
                    hackerFlow(canvas, x,  width,  '2');
                    break;
                case '*':
                    hackerFlow(canvas, x,  width,  '3');
                    break;
                case '+':
                    hackerFlow(canvas, x,  width,  '4');
                    break;
                case '-':
                    hackerFlow(canvas, x,  width,  '5');
                    break;
                case '@':
                    hackerFlow(canvas, x,  width,  '6');
                    break;
                case '8':
                    hackerFlow(canvas, x,  width,  '7');
                    break;
                case '#':
                    hackerFlow(canvas, x,  width,  '8');
                    break;
                case '|':
                    hackerFlow(canvas, x,  width, '9');
                    break;
                case '9':
                    hackerFlow(canvas, x,  width, '@');
                    break;
                case '5':
                    hackerFlow(canvas, x,  width, '|');
                    break;
                default:
                    hackerFlow(canvas, x,  width, ' ');
                    break;
                }
        }
    }
}


void printHacker(char **array, int height, int width) {
    //clear the canvas before everytime print a new grid.
    std::this_thread::sleep_for(80ms);
    system("clear");
    //checking every unit of the array, if the number is 0, print a space shows there are nothing here. if is 1, print # as an impassible unit. if is 2, print the char user want fill it.
    for (int y = 0; y < width; y++) {
        for (int x = 0; x < height; x++) {
            printf("\x1B[32m%c\033[0m", array[y][x]);
        }
        cout << endl;
    }
}

char hackHelper() {
    int random;
    //srand(time(0));
    random = rand() % 150 + 1;
    switch (random) {
        case 11:
            return '#';
            break;
        case 12:
            return '$';
            break;
        case 13:
            return '%';
            break;
        case 14:
            return '&';
            break;
        case 15:
            return '*';
            break;
        case 16:
            return '+';
            break;
        case 17:
            return '-';
            break;
        case 18:
            return '/';
            break;
        case 19:
            return '0';
            break;
        case 20:
            return '1';
            break;
        case 21:
            return '2';
            break;
        case 22:
            return '3';
            break;
        case 23:
            return '4';
            break;
        case 24:
            return '5';
            break;
        case 25:
            return '6';
            break;
        case 26:
            return '7';
            break;
        case 27:
            return '8';
            break;
        case 28:
            return '9';
            break;
        case 29:
            return '@';
            break;
        case 30:
            return '|';
            break;
        default:
            return ' ';
        }
}