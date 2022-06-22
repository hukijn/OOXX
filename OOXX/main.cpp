#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "winner.h"
#include "Tfset.h"
#include "slicemap.h"
using namespace std;
using namespace sf;
Sprite s[13], f[81];
Sprite Learn(int x, int y){
    if(x <= 200 && x >= 30 && y >= 650 && y <= 850){//Step1
        return s[4];
    }else if(x <= 400 && x >= 201 && y >= 650 && y <= 850){//Step2
        return s[5];
    }else if(x <= 620 && x >=401 && y >= 650 && y <= 850){//Step3
        return s[6];
    }else if(x <= 890 && x >= 621 && y >= 650 && y <= 850){//goal
        return s[7];
    }else{
        return s[8];
    }
}
int main(){
    int bigmap[3][3] = {0}, lmap[3][3] = {0}, Map[9][3][3] = {0},
    d = 0, k = 1, TFSet = 0, n = 0, m = 0, learn = 0, x, y, nx, ny;
    bool mapover = false;
    srand(time(NULL));
    RenderWindow window(VideoMode(900, 800), "game");
    Texture t[13];
    t[0].loadFromFile("C:/Users/USER/OneDrive/桌面/images/map.png");
    t[1].loadFromFile("C:/Users/USER/OneDrive/桌面/images/X.png");
    t[2].loadFromFile("C:/Users/USER/OneDrive/桌面/images/O.png");
    t[3].loadFromFile("C:/Users/USER/OneDrive/桌面/images/start.png");
    t[4].loadFromFile("C:/Users/USER/OneDrive/桌面/images/step1.png");
    t[5].loadFromFile("C:/Users/USER/OneDrive/桌面/images/step2.png");
    t[6].loadFromFile("C:/Users/USER/OneDrive/桌面/images/step3.png");
    t[7].loadFromFile("C:/Users/USER/OneDrive/桌面/images/step4.png");
    t[8].loadFromFile("C:/Users/USER/OneDrive/桌面/images/step5.png");
    t[9].loadFromFile("C:/Users/USER/OneDrive/桌面/images/XW.png");
    t[10].loadFromFile("C:/Users/USER/OneDrive/桌面/images/OW.png");
    t[11].loadFromFile("C:/Users/USER/OneDrive/桌面/images/tie.png");
    t[12].loadFromFile("C:/Users/USER/OneDrive/桌面/images/single player.png");
    for(int i = 0; i < 13; i++){
        s[i].setTexture(t[i]);
        s[i].setScale(0.75f, 1.13f);
    }
    s[0].setScale(1.05f, 1.05f);
    s[3].setScale(0.95f, 1.5f);
    while(window.isOpen()){
        Event e;
        Vector2i localPosition = Mouse::getPosition(window);
        while(window.pollEvent(e)){
            if(e.type == Event::Closed)window.close();
        }
        if(d % 2 == 1){
            f[d].setTexture(t[1]);
            f[d].setScale(0.41f, 0.372f);
            k = 1;
        }else{
            f[d].setTexture(t[2]);
            f[d].setScale(0.34f,0.452f);
            k = 2;
        }
        window.clear();
        if(Mouse::isButtonPressed(Mouse::Left) && n == 0 && m == 0 &&
        winner(lmap) != true && mapover != true){
        	if(localPosition.x <= 490 && localPosition.x >= 400 &&
            localPosition.y >= 350 && localPosition.y <= 430){//單人選項
            	n = 3;
            	window.draw(s[12]);
            	window.display();
            	Sleep(300);
            	continue;
        	}
        	if(localPosition.x <= 490 && localPosition.x >= 400 &&
            localPosition.y >= 470 && localPosition.y <= 540){//多人選項
            	m = 1;
            	window.draw(s[0]);
            	window.display();
            	Sleep(300);
            	continue;
        	}
        	if(localPosition.x <= 490 && localPosition.x >= 400 &&
            localPosition.y >= 580 && localPosition.y <= 660){//教學選項
        		learn++;
        	}
    	}
        if(n != 0){
			if(n == 3){
                window.draw(s[12]);
                if(Mouse::isButtonPressed(Mouse::Left)){
                    if(localPosition.x > 190 && localPosition.x < 420 &&
                    localPosition.y > 440 &&localPosition.y < 620){
                        n = 2;
                    }
                    if(localPosition.x > 510 && localPosition.x < 740 &&
                    localPosition.y > 440 &&localPosition.y < 620){
                        n = 1;
                    }
                    window.draw(s[0]);
                    window.display();
                    Sleep(300);
                    continue;
                }
			}else{
                window.draw(s[0]);
			}
		}else if(m != 0){
		    window.draw(s[0]);
        }else if(learn != 0){//教學圖片A
            window.draw(Learn(localPosition.x, localPosition.y));
            if(Keyboard::isKeyPressed(Keyboard::Up)){
                learn = 0;
            }
        }else if(winner(lmap) != true && mapover != true){
		    window.draw(s[3]);
        }
        if(Mouse::isButtonPressed(Mouse::Left) || n == 2){
            if(n == 1 || n == 2){
                if(n == 1){
                    nx = localPosition.x;
                    ny = localPosition.y;
                }else{
                    nx = rand() % 901;
                    ny = rand() % 801;
                }
                if(d == 0){
                    TFSet = position(nx, ny, k, x, y, bigmap, Map);
                }else{
                    TFSet = TFset(nx, ny, k, x, y, bigmap, Map);
                }
            }
            if(m != 0){
                if(d == 0){
                    TFSet = position(localPosition.x, localPosition.y, k,
                    x, y, bigmap, Map);
                }else{
                    TFSet = TFset(localPosition.x, localPosition.y, k, x,
                    y, bigmap, Map);
                }
            }
        }
        if(TFSet != 0){
            f[d].setPosition(x, y);
            d++;
            slicemap(Map, lmap, TFSet);
            if(n == 1){
                n = 2;
            }else if(n == 2){
                Sleep(1000);
                n = 1;
            }
        }
        mapover = true;
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 3; j++)
                for(int a = 0; a < 3; a++)
                    if(Map[i][j][a] == 0)mapover = false;
        if(winner(lmap) == true || mapover == true){
            if(mapover == true){
                window.draw(s[11]);//和局
            }else if(k == 2){
                window.draw(s[10]);//圈圈贏
            }else{
                window.draw(s[9]);//叉叉贏
            }
            if(n != 0 || m != 0){
                d--;
                Sleep(300);
            }
            n = 0;
            m = 0;
            if(Mouse::isButtonPressed(Mouse::Left)){
                memset(bigmap, 0, sizeof(bigmap[0][0]) * 3 * 3);
                memset(lmap, 0, sizeof(lmap[0][0]) * 3 * 3);
                memset(Map, 0, sizeof(Map[0][0]) * 9 * 3 * 3);
                d = 0;
                Sleep(300);
            }
    	}else{
            for(int i = 0; i < d; i++){
                window.draw(f[i]);
            }
		}
		window.display();
		TFSet = 0;
    }
}
