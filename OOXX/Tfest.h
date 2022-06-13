#include "position.h"
int TFset(int mx, int my, int k, int &x, int &y, int bigmap[3][3], int map[9][3][3]){
    if((mx > 0 && mx < 300 && my > 0 && my < 270 && bigmap[0][0] == 1) ||
    (mx > 300 && mx < 600 && my > 0 && my < 270 && bigmap[0][1] == 1) ||
    (mx > 600 && mx < 900 && my > 0 && my < 270 && bigmap[0][2] == 1) ||
    (mx > 0 && mx < 300 && my > 270 && my < 530 && bigmap[1][0] == 1) ||
    (mx > 300 && mx < 600 && my > 270 && my < 530 && bigmap[1][1] == 1) ||
    (mx > 600 && mx < 900 && my > 270 && my < 530 && bigmap[1][2] == 1) ||
    (mx > 0 && mx < 300 && my > 530 && my < 800 && bigmap[2][0] == 1) ||
    (mx > 300 && mx < 600 && my > 530 && my < 800 && bigmap[2][1] == 1) ||
    (mx > 600 && mx < 900 && my > 530 && my < 800 && bigmap[2][2] == 1)){
        return position(mx, my, k, x, y, bigmap, map);
    }else{
        return 0;
    }
}
