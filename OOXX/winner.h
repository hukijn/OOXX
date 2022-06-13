bool winner(int lmap[3][3]){
    for(int i = 0; i < 3; i++){
        if(lmap[i][0] != 0 && lmap[i][0] == lmap[i][1] && lmap[i][1] == lmap[i][2]){
            return true;
        }
    }
    for(int i = 0; i < 3; i++){
        if(lmap[0][i] != 0 && lmap[0][i] == lmap[1][i] && lmap[1][i] == lmap[2][i]){
            return true;
           }
    }
    if(lmap[0][0] != 0 && lmap[0][0] == lmap[1][1] && lmap[1][1] == lmap[2][2]){
        return true;
    }
    if(lmap[0][2] != 0 && lmap[0][2] == lmap[1][1] && lmap[1][1] == lmap[2][0]){
        return true;
    }
    return false;
}
