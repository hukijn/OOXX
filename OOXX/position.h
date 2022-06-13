int position(int mx, int my, int k, int &x, int &y, int bigmap[3][3],int map[9][3][3]){
    if(mx > 0 && mx < 100 && my > 0 && my < 90 && map[0][0][0] == 0){
        map[0][0][0] = k;
        bigmap[0][0] = 0;
        bigmap[0][0] = 1;
        x = 0;
        y = 0;
        return 1;
    }else if(mx > 100 && mx < 200 && my > 0 && my < 90 && map[0][0][1] == 0){
        map[0][0][1] = k;
        bigmap[0][0] = 0;
        bigmap[0][1] = 1;
        x = 105;
        y = 0;
        return 1;
    }else if(mx > 200 && mx < 300 && my > 0 && my < 90 && map[0][0][2] == 0){
        map[0][0][2] = k;
        bigmap[0][0] = 0;
        bigmap[0][2] = 1;
        x = 202;
        y = 0;
        return 1;
    }else if(mx > 300 && mx < 400 && my > 0 && my < 90 && map[0][1][0] == 0){
        map[0][1][0] = k;
        bigmap[0][1] = 0;
        bigmap[0][0] = 1;
        x = 305;
        y = 0;
        return 2;
    }else if(mx > 400 && mx < 500 && my > 0 && my < 90 && map[0][1][1] == 0){
        map[0][1][1] = k;
        bigmap[0][1] = 0;
        bigmap[0][1] = 1;
        x = 405;
        y = 0;
        return 2;
    }else if(mx>500&&mx<600&&my>0&&my<90&&map[0][1][2]==0){
        map[0][1][2]=k;
        bigmap[0][1]=0;
        bigmap[0][2]=1;
        x=505;
        y=0;
        return 2;
    }else if(mx>600&&mx<700&&my>0&&my<90&&map[0][2][0]==0){
        map[0][2][0]=k;
        bigmap[0][2]=0;
        bigmap[0][0]=1;
        x=602;
        y=0;
        return 3;
    }else if(mx>700&&mx<800&&my>0&&my<90&&map[0][2][1]==0){
        map[0][2][1]=k;
        bigmap[0][2]=0;
        bigmap[0][1]=1;
        x=700;
        y=0;
        return 3;
    }else if(mx>800&&mx<900&&my>0&&my<90&&map[0][2][2]==0){
        map[0][2][2]=k;
        bigmap[0][2]=0;
        bigmap[0][2]=1;
        x=805;
        y=0;
        return 3;
    }else if(mx>0&&mx<100&&my>90&&my<180&&map[1][0][0]==0){
        map[1][0][0]=k;
        bigmap[0][0]=0;
        bigmap[1][0]=1;
        x=0;
        y=90;
        return 1;
    }else if(mx>100&&mx<200&&my>90&&my<180&&map[1][0][1]==0){
        map[1][0][1]=k;
        bigmap[0][0]=0;
        bigmap[1][1]=1;
        x=105;
        y=90;
        return 1;
    }else if(mx>200&&mx<300&&my>90&&my<180&&map[1][0][2]==0){
        map[1][0][2]=k;
        bigmap[0][0]=0;
        bigmap[1][2]=1;
        x=205;
        y=90;
        return 1;
    }else if(mx>300&&mx<400&&my>90&&my<180&&map[1][1][0]==0){
        map[1][1][0]=k;
        bigmap[0][1]=0;
        bigmap[1][0]=1;
        x=305;
        y=90;
        return 2;
    }else if(mx>400&&mx<500&&my>90&&my<180&&map[1][1][1]==0){
        map[1][1][1]=k;
        bigmap[0][1]=0;
        bigmap[1][1]=1;
        x=405;
        y=90;
        return 2;
    }else if(mx>500&&mx<600&&my>90&&my<180&&map[1][1][2]==0){
        map[1][1][2]=k;
        bigmap[0][1]=0;
        bigmap[1][2]=1;
        x=505;
        y=90;
        return 2;
    }else if(mx>600&&mx<700&&my>90&&my<180&&map[1][2][0]==0){
        map[1][2][0]=k;
        bigmap[0][2]=0;
        bigmap[1][0]=1;
        x=602;
        y=90;
        return 3;
    }else if(mx>700&&mx<800&&my>90&&my<180&&map[1][2][1]==0){
        map[1][2][1]=k;
        bigmap[0][2]=0;
        bigmap[1][1]=1;
        x=700;
        y=90;
        return 3;
    }else if(mx>800&&mx<900&&my>90&&my<180&&map[1][2][2]==0){
        map[1][2][2]=k;
        bigmap[0][2]=0;
        bigmap[1][2]=1;
        x=805;
        y=90;
        return 3;
    }else if(mx>0&&mx<100&&my>180&&my<270&&map[2][0][0]==0){
        map[2][0][0]=k;
        bigmap[0][0]=0;
        bigmap[2][0]=1;
        x=0;
        y=182;
        return 1;
    }else if(mx>100&&mx<200&&my>180&&my<270&&map[2][0][1]==0){
        map[2][0][1]=k;
        bigmap[0][0]=0;
        bigmap[2][1]=1;
        x=105;
        y=182;
        return 1;
    }else if(mx>200&&mx<300&&my>180&&my<270&&map[2][0][2]==0){
        map[2][0][2]=k;
        bigmap[0][0]=0;
        bigmap[2][2]=1;
        x=205;
        y=182;
        return 1;
    }else if(mx>300&&mx<400&&my>180&&my<270&&map[2][1][0]==0){
        map[2][1][0]=k;
        bigmap[0][1]=0;
        bigmap[2][0]=1;
        x=305;
        y=182;
        return 2;
    }else if(mx>400&&mx<500&&my>180&&my<270&&map[2][1][1]==0){
        map[2][1][1]=k;
        bigmap[0][1]=0;
        bigmap[2][1]=1;
        x=405;
        y=182;
        return 2;
    }else if(mx>500&&mx<600&&my>180&&my<270&&map[2][1][2]==0){
        map[2][1][2]=k;
        bigmap[0][1]=0;
        bigmap[2][2]=1;
        x=505;
        y=182;
        return 2;
    }else if(mx>600&&mx<700&&my>180&&my<270&&map[2][2][0]==0){
        map[2][2][0]=k;
        bigmap[0][2]=0;
        bigmap[2][0]=1;
        x=602;
        y=182;
        return 3;
    }else if(mx>700&&mx<800&&my>180&&my<270&&map[2][2][1]==0){
        map[2][2][1]=k;
        bigmap[0][2]=0;
        bigmap[2][1]=1;
        x=700;
        y=182;
        return 3;
    }else if(mx>800&&mx<900&&my>180&&my<270&&map[2][2][2]==0){
        map[2][2][2]=k;
        bigmap[0][2]=0;
        bigmap[2][2]=1;
        x=805;
        y=182;
        return 3;
    }else if(mx>0&&mx<100&&my>270&&my<350&&map[3][0][0]==0){
        map[3][0][0]=k;
        bigmap[1][0]=0;
        bigmap[0][0]=1;
        x=0;
        y=270;
        return 4;
    }else if(mx>100&&mx<200&&my>270&&my<350&&map[3][0][1]==0){
        map[3][0][1]=k;
        bigmap[1][0]=0;
        bigmap[0][1]=1;
        x=105;
        y=270;
        return 4;
    }else if(mx>200&&mx<300&&my>270&&my<350&&map[3][0][2]==0){
        map[3][0][2]=k;
        bigmap[1][0]=0;
        bigmap[0][2]=1;
        x=205;
        y=270;
        return 4;
    }else if(mx>300&&mx<400&&my>270&&my<350&&map[3][1][0]==0){
        map[3][1][0]=k;
        bigmap[1][1]=0;
        bigmap[0][0]=1;
        x=305;
        y=270;
        return 5;
    }else if(mx>400&&mx<500&&my>270&&my<350&&map[3][1][1]==0){
        map[3][1][1]=k;
        bigmap[1][1]=0;
        bigmap[0][1]=1;
        x=405;
        y=270;
        return 5;
    }else if(mx>500&&mx<600&&my>270&&my<350&&map[3][1][2]==0){
        map[3][1][2]=k;
        bigmap[1][1]=0;
        bigmap[0][2]=1;
        x=505;
        y=270;
        return 5;
    }else if(mx>600&&mx<700&&my>270&&my<350&&map[3][2][0]==0){
        map[3][2][0]=k;
        bigmap[1][2]=0;
        bigmap[0][0]=1;
        x=602;
        y=270;
        return 6;
    }else if(mx>700&&mx<800&&my>270&&my<350&&map[3][2][1]==0){
        map[3][2][1]=k;
        bigmap[1][2]=0;
        bigmap[0][1]=1;
        x=700;
        y=270;
        return 6;
    }else if(mx>800&&mx<900&&my>270&&my<350&&map[3][2][2]==0){
        map[3][2][2]=k;
        bigmap[1][2]=0;
        bigmap[0][2]=1;
        x=805;
        y=270;
        return 6;
    }else if(mx>0&&mx<100&&my>350&&my<440&&map[4][0][0]==0){
        map[4][0][0]=k;
        bigmap[1][0]=0;
        bigmap[1][0]=1;
        x=0;
        y=355;
        return 4;
    }else if(mx>100&&mx<200&&my>350&&my<440&&map[4][0][1]==0){
        map[4][0][1]=k;
        bigmap[1][0]=0;
        bigmap[1][1]=1;
        x=105;
        y=355;
        return 4;
    }else if(mx>200&&mx<300&&my>350&&my<440&&map[4][0][2]==0){
        map[4][0][2]=k;
        bigmap[1][0]=0;
        bigmap[1][2]=1;
        x=205;
        y=355;
        return 4;
    }else if(mx>300&&mx<400&&my>350&&my<440&&map[4][1][0]==0){
        map[4][1][0]=k;
        bigmap[1][1]=0;
        bigmap[1][0]=1;
        x=305;
        y=355;
        return 5;
    }else if(mx>400&&mx<500&&my>350&&my<440&&map[4][1][1]==0){
        map[4][1][1]=k;
        bigmap[1][1]=0;
        bigmap[1][1]=1;
        x=405;
        y=355;
        return 5;
    }else if(mx>500&&mx<600&&my>350&&my<440&&map[4][1][2]==0){
        map[4][1][2]=k;
        bigmap[1][1]=0;
        bigmap[1][2]=1;
        x=505;
        y=355;
        return 5;
    }else if(mx>600&&mx<700&&my>350&&my<440&&map[4][2][0]==0){
        map[4][2][0]=k;
        bigmap[1][2]=0;
        bigmap[1][0]=1;
        x=602;
        y=355;
        return 6;
    }else if(mx>700&&mx<800&&my>350&&my<440&&map[4][2][1]==0){
        map[4][2][1]=k;
        bigmap[1][2]=0;
        bigmap[1][1]=1;
        x=700;
        y=355;
        return 6;
    }else if(mx>800&&mx<900&&my>350&&my<440&&map[4][2][2]==0){
        map[4][2][2]=k;
        bigmap[1][2]=0;
        bigmap[1][2]=1;
        x=805;
        y=355;
        return 6;
    }else if(mx>0&&mx<100&&my>440&&my<530&&map[5][0][0]==0){
        map[5][0][0]=k;
        bigmap[1][0]=0;
        bigmap[2][0]=1;
        x=0;
        y=445;
        return 4;
    }else if(mx>100&&mx<200&&my>440&&my<530&&map[5][0][1]==0){
        map[5][0][1]=k;
        bigmap[1][0]=0;
        bigmap[2][1]=1;
        x=105;
        y=445;
        return 4;
    }else if(mx>200&&mx<300&&my>440&&my<530&&map[5][0][2]==0){
        map[5][0][2]=k;
        bigmap[1][0]=0;
        bigmap[2][2]=1;
        x=205;
        y=445;
        return 4;
    }else if(mx>300&&mx<400&&my>440&&my<530&&map[5][1][0]==0){
        map[5][1][0]=k;
        bigmap[1][1]=0;
        bigmap[2][0]=1;
        x=305;
        y=445;
        return 5;
    }else if(mx>400&&mx<500&&my>440&&my<530&&map[5][1][1]==0){
        map[5][1][1]=k;
        bigmap[1][1]=0;
        bigmap[2][1]=1;
        x=405;
        y=445;
        return 5;
    }else if(mx>500&&mx<600&&my>440&&my<530&&map[5][1][2]==0){
        map[5][1][2]=k;
        bigmap[1][1]=0;
        bigmap[2][2]=1;
        x=505;
        y=445;
        return 5;
    }else if(mx>600&&mx<700&&my>440&&my<530&&map[5][2][0]==0){
        map[5][2][0]=k;
        bigmap[1][2]=0;
        bigmap[2][0]=1;
        x=602;
        y=445;
        return 6;
    }else if(mx>700&&mx<800&&my>440&&my<530&&map[5][2][1]==0){
        map[5][2][1]=k;
        bigmap[1][2]=0;
        bigmap[2][1]=1;
        x=700;
        y=445;
        return 6;
    }else if(mx>800&&mx<900&&my>440&&my<530&&map[5][2][2]==0){
        map[5][2][2]=k;
        bigmap[1][2]=0;
        bigmap[2][2]=1;
        x=805;
        y=445;
        return 6;
    }else if(mx>0&&mx<100&&my>530&&my<620&&map[6][0][0]==0){
        map[6][0][0]=k;
        bigmap[2][0]=0;
        bigmap[0][0]=1;
        x=0;
        y=535;
        return 7;
    }else if(mx>100&&mx<200&&my>530&&my<620&&map[6][0][1]==0){
        map[6][0][1]=k;
        bigmap[2][0]=0;
        bigmap[0][1]=1;
        x=105;
        y=535;
        return 7;
    }else if(mx>200&&mx<300&&my>530&&my<620&&map[6][0][2]==0){
        map[6][0][2]=k;
        bigmap[2][0]=0;
        bigmap[0][2]=1;
        x=205;
        y=535;
        return 7;
    }else if(mx>300&&mx<400&&my>530&&my<620&&map[6][1][0]==0){
        map[6][1][0]=k;
        bigmap[2][1]=0;
        bigmap[0][0]=1;
        x=305;
        y=535;
        return 8;
    }else if(mx>400&&mx<500&&my>530&&my<620&&map[6][1][1]==0){
        map[6][1][1]=k;
        bigmap[2][1]=0;
        bigmap[0][1]=1;
        x=405;
        y=535;
        return 8;
    }else if(mx>500&&mx<600&&my>530&&my<620&&map[6][1][2]==0){
        map[6][1][2]=k;
        bigmap[2][1]=0;
        bigmap[0][2]=1;
        x=505;
        y=535;
        return 8;
    }else if(mx>600&&mx<700&&my>530&&my<620&&map[6][2][0]==0){
        map[6][2][0]=k;
        bigmap[2][2]=0;
        bigmap[0][0]=1;
        x=602;
        y=535;
        return 9;
    }else if(mx>700&&mx<800&&my>530&&my<620&&map[6][2][1]==0){
        map[6][2][1]=k;
        bigmap[2][2]=0;
        bigmap[0][1]=1;
        x=700;
        y=535;
        return 9;
    }else if(mx>800&&mx<900&&my>530&&my<620&&map[6][2][2]==0){
        map[6][2][2]=k;
        bigmap[2][2]=0;
        bigmap[0][2]=1;
        x=805;
        y=535;
        return 9;
    }else if(mx>0&&mx<100&&my>620&&my<710&&map[7][0][0]==0){
        map[7][0][0]=k;
        bigmap[2][0]=0;
        bigmap[1][0]=1;
        x=0;
        y=624;
        return 7;
    }else if(mx>100&&mx<200&&my>620&&my<710&&map[7][0][1]==0){
        map[7][0][1]=k;
        bigmap[2][0]=0;
        bigmap[1][1]=1;
        x=105;
        y=624;
        return 7;
    }else if(mx>200&&mx<300&&my>620&&my<710&&map[7][0][2]==0){
        map[7][0][2]=k;
        bigmap[2][0]=0;
        bigmap[1][2]=1;
        x=205;
        y=624;
        return 7;
    }else if(mx>300&&mx<400&&my>620&&my<710&&map[7][1][0]==0){
        map[7][1][0]=k;
        bigmap[2][1]=0;
        bigmap[1][0]=1;
        x=305;
        y=624;
        return 8;
    }else if(mx>400&&mx<500&&my>620&&my<710&&map[7][1][1]==0){
        map[7][1][1]=k;
        bigmap[2][1]=0;
        bigmap[1][1]=1;
        x=405;
        y=624;
        return 8;
    }else if(mx>500&&mx<600&&my>620&&my<710&&map[7][1][2]==0){
        map[7][1][2]=k;
        bigmap[2][1]=0;
        bigmap[1][2]=1;
        x=505;
        y=624;
        return 8;
    }else if(mx>600&&mx<700&&my>620&&my<710&&map[7][2][0]==0){
        map[7][2][0]=k;
        bigmap[2][2]=0;
        bigmap[1][0]=1;
        x=602;
        y=624;
        return 9;
    }else if(mx>700&&mx<800&&my>620&&my<710&&map[7][2][1]==0){
        map[7][2][1]=k;
        bigmap[2][2]=0;
        bigmap[1][1]=1;
        x=700;
        y=624;
        return 9;
    }else if(mx>800&&mx<900&&my>620&&my<710&&map[7][2][2]==0){
        map[7][2][2]=k;
        bigmap[2][2]=0;
        bigmap[1][2]=1;
        x=805;
        y=624;
        return 9;
    }else if(mx>0&&mx<100&&my>710&&my<800&&map[8][0][0]==0){
        map[8][0][0]=k;
        bigmap[2][0]=0;
        bigmap[2][0]=1;
        x=0;
        y=715;
        return 7;
    }else if(mx>100&&mx<200&&my>710&&my<800&&map[8][0][1]==0){
        map[8][0][1]=k;
        bigmap[2][0]=0;
        bigmap[2][1]=1;
        x=105;
        y=715;
        return 7;
    }else if(mx>200&&mx<300&&my>710&&my<800&&map[8][0][2]==0){
        map[8][0][2]=k;
        bigmap[2][0]=0;
        bigmap[2][2]=1;
        x=205;
        y=715;
        return 7;
    }else if(mx>300&&mx<400&&my>710&&my<800&&map[8][1][0]==0){
        map[8][1][0]=k;
        bigmap[2][1]=0;
        bigmap[2][0]=1;
        x=305;
        y=715;
        return 8;
    }else if(mx>400&&mx<500&&my>710&&my<800&&map[8][1][1]==0){
        map[8][1][1]=k;
        bigmap[2][1]=0;
        bigmap[2][1]=1;
        x=405;
        y=715;
        return 8;
    }else if(mx>500&&mx<600&&my>710&&my<800&&map[8][1][2]==0){
        map[8][1][2]=k;
        bigmap[2][1]=0;
        bigmap[2][2]=1;
        x=505;
        y=715;
        return 8;
    }else if(mx>600&&mx<700&&my>710&&my<800&&map[8][2][0]==0){
        map[8][2][0]=k;
        bigmap[2][2]=0;
        bigmap[2][0]=1;
        x=602;
        y=715;
        return 9;
    }else if(mx>700&&mx<800&&my>710&&my<800&&map[8][2][1]==0){
        map[8][2][1]=k;
        bigmap[2][2]=0;
        bigmap[2][1]=1;
        x=700;
        y=715;
        return 9;
    }else if(mx>800&&mx<900&&my>710&&my<800&&map[8][2][2]==0){
        map[8][2][2]=k;
        bigmap[2][2]=0;
        bigmap[2][2]=1;
        x=805;
        y=715;
        return 9;
    }else{
        return 0;
    }
}
