#include <SFML/Graphics.hpp>
#include <iostream>
#include "winner.h"
#include "Tfest.h"
#include "slicemap.h"
using namespace std;
using namespace sf;
int main(){
    int bigmap[3][3] = {0}, lmap[3][3] = {0}, map[9][3][3] = {0},
    d = 0, k = 1, TFSet = 0, x, y, n = 0, learn = 0;
    RenderWindow window(VideoMode(900, 800), "game");
    Texture t[9];
    t[0].loadFromFile("C:/Users/USER/OneDrive/桌面/images/map.png");
    t[1].loadFromFile("C:/Users/USER/OneDrive/桌面/images/X.jpg");
    t[2].loadFromFile("C:/Users/USER/OneDrive/桌面/images/O.png");
    t[3].loadFromFile("C:/Users/USER/OneDrive/桌面/images/start.png");
    t[4].loadFromFile("C:/Users/USER/OneDrive/桌面/images/step1.png");
    t[5].loadFromFile("C:/Users/USER/OneDrive/桌面/images/step2.png");
    t[6].loadFromFile("C:/Users/USER/OneDrive/桌面/images/step3.png");
    t[7].loadFromFile("C:/Users/USER/OneDrive/桌面/images/step4.png");
    t[8].loadFromFile("C:/Users/USER/OneDrive/桌面/images/step5.png");
    Sprite s[9], f[81];
    for(int i = 0; i < 9; i++){
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
        if(Mouse::isButtonPressed(Mouse::Left) && n == 0){
        	if(localPosition.x <= 490 &&localPosition.x >= 400 &&
            localPosition.y >= 350 && localPosition.y <= 430){//單人選項
            	n++;
        	}
        	if(localPosition.x <= 490 && localPosition.x >= 400 &&
            localPosition.y >= 470 && localPosition.y <= 540){//多人選項
            	n++;
        	}
        	if(localPosition.x <= 490 && localPosition.x >= 400 &&
            localPosition.y >= 580 && localPosition.y <= 660){//教學選項
        		learn++;
        	}
    	}
        if(n != 0){
			window.draw(s[0]);//遊戲圖片
		}else{
		    if(learn != 0){//教學圖片A
				window.draw(s[8]);
				if(localPosition.x <= 200 && localPosition.x >= 30 &&
                localPosition.y >= 650 && localPosition.y <= 850){//Step1
					window.draw(s[4]);
        		}
				if(localPosition.x <= 400 && localPosition.x >= 201 &&
                localPosition.y >= 650 && localPosition.y <= 850){//Step2
            		window.draw(s[5]);
        		}
        		if(localPosition.x <= 620 && localPosition.x >=401 &&
                localPosition.y>=650&&localPosition.y<=850){//Step3
            		window.draw(s[6]);
        		}
        		if(localPosition.x <= 890 && localPosition.x >= 621 &&
                localPosition.y>=650&&localPosition.y<=850){//goal
        			window.draw(s[7]);
        		}
        		if(Keyboard::isKeyPressed(Keyboard::Up)){
        			learn = 0;
				}
			}
		    else window.draw(s[3]);
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
        if(Mouse::isButtonPressed(Mouse::Left) && n != 0){
            if(d == 0){
                TFSet = position(localPosition.x, localPosition.y, k,
                x, y, bigmap, map);
            }
            else{
                TFSet = TFset(localPosition.x, localPosition.y, k, x,
                y, bigmap, map);
            }
        }
        if(TFSet != 0){
            f[d].setPosition(x, y);
            d++;
            slicemap(map, lmap, TFSet);
        }
        for(int i = 0; i < d; i++)window.draw(f[i]);
        window.display();
        if(winner(lmap) == true)break;
        bool mapover = true;
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 3; j++)
                for(int a = 0; a < 3; a++)
                    if(map[i][j][a] == 0)mapover = false;
        if(mapover == true)break;
    }
}
