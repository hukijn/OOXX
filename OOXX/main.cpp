#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include "winner.h"
#include "Tfest.h"
#include "slicemap.h"
using namespace std;
using namespace sf;
Sprite s[12], f[81];
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
    int bigmap[3][3] = {0}, lmap[3][3] = {0}, map[9][3][3] = {0},
    d = 0, k = 1, TFSet = 0, n = 0, m = 0, learn = 0, x, y;
    bool mapover = false;
    RenderWindow window(VideoMode(900, 800), "game");
    Texture t[12];
    t[0].loadFromFile("C:/Users/USER/OneDrive/桌面/images/map.png");
    t[1].loadFromFile("C:/Users/USER/OneDrive/桌面/images/X.jpg");
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
    for(int i = 0; i < 12; i++){
        s[i].setTexture(t[i]);
        s[i].setScale(0.75f, 1.13f);
    }
    s[0].setScale(1.05f, 1.05f);
    s[3].setScale(0.95f, 1.5f);
    while(window.isOpen()){
        Event e;
        Vector2i localPosition = Mouse::getPosition(window);
        cout<<localPosition.x<<' '<<localPosition.y<<endl;
        while(window.pollEvent(e)){
            if(e.type == Event::Closed)window.close();
        }
        window.clear();
        if(Mouse::isButtonPressed(Mouse::Left) && n == 0 && m == 0 &&
        winner(lmap) != true && mapover != true){
        	if(localPosition.x <= 490 &&localPosition.x >= 400 &&
            localPosition.y >= 350 && localPosition.y <= 430){//單人選項
            	n++;
            	window.draw(s[0]);
            	window.display();
            	Sleep(300);
            	continue;
        	}
        	if(localPosition.x <= 490 && localPosition.x >= 400 &&
            localPosition.y >= 470 && localPosition.y <= 540){//多人選項
            	m++;
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
        if(n != 0 || m != 0){
			window.draw(s[0]);//遊戲圖片
		}else if(learn != 0){//教學圖片A
            window.draw(Learn(localPosition.x, localPosition.y));
            if(Keyboard::isKeyPressed(Keyboard::Up)){
                learn = 0;
            }
        }else if(winner(lmap) != true && mapover != true){
		    window.draw(s[3]);
        }
        if(d % 2 == 0){
            f[d].setTexture(t[1]);
            k = 1;
            f[d].setScale(0.41f, 0.372f);
        }else{
            f[d].setTexture(t[2]);
            k = 2;
            f[d].setScale(0.34f,0.452f);
        }
        if(Mouse::isButtonPressed(Mouse::Left)){
            if(n != 0){
                if(d == 0){
                    TFSet = position(localPosition.x, localPosition.y, k,
                    x, y, bigmap, map);
                }else{
                    TFSet = TFset(localPosition.x, localPosition.y, k, x,
                    y, bigmap, map);
                }
            }
            /*if(m != 0){
                continue;
            }*/
        }
        if(TFSet != 0){
            f[d].setPosition(x, y);
            d++;
            slicemap(map, lmap, TFSet);
        }
        mapover = true;
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 3; j++)
                for(int a = 0; a < 3; a++)
                    if(map[i][j][a] == 0)mapover = false;
        if(winner(lmap) == true && k == 1){//叉叉贏
            window.draw(s[9]);
            d--;
            n = 0;
    	}else if(winner(lmap) == true){//圈圈贏
            window.draw(s[10]);
            d--;
            n = 0;
		}else if(mapover == true){//和局
            window.draw(s[11]);
            n = 0;
		}else{
            for(int i = 0; i < d; i++)window.draw(f[i]);
		}
		window.display();
    }
}
