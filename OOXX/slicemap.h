void slicemap(int map[9][3][3], int lmap[3][3], int a){
    if(a == 1 || a == 2 || a == 3){
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                lmap[i][j] = map[i][a - 1][j];
    }else if(a == 4 || a == 5 || a == 6){
        for(int i = 3; i < 6; i++)
            for(int j = 0; j < 3; j++)
                lmap[i - 3][j] = map[i][a - 4][j];
    }else{
        for(int i = 6; i < 9; i++)
            for(int j = 0;j < 3; j++)
                lmap[i - 6][j] = map[i][a - 7][j];
    }
}
