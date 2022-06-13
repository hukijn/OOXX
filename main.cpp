#include <SFML/Graphics.hpp>
#include <iostream>
#include "c:\winner.h"
#include "c:\Tfest.h"
#include "c:\slicemap.h"
using namespace std;
using namespace sf;
int main(){
    int bigmap[3][3] = {0}, lmap[3][3] = {0}, map[9][3][3] = {0},
    d = 0, k = 1, TFSet = 0, x, y, n = 0,learn=0;
    RenderWindow window(VideoMode(900, 800), "game");
    Texture t, t1, t2, t3, t4,t5,t6,t7,t8;
    t.loadFromFile("/Users/USER/Desktop/map.png");
    t1.loadFromFile("/Users/USER/Desktop/b.jpg");
    t2.loadFromFile("/Users/USER/Desktop/c.png");
    t3.loadFromFile("/Users/USER/Desktop/d.png");
    t4.loadFromFile("/Users/USER/Desktop/e.png");
    t5.loadFromFile("/Users/USER/Desktop/f.png");
    t6.loadFromFile("/Users/USER/Desktop/g.png");
    t7.loadFromFile("/Users/USER/Desktop/h.png");
    t8.loadFromFile("/Users/USER/Desktop/i.png");
    Sprite s(t);//遊戲圖片 
    Sprite m(t3);//封面圖片 
    Sprite A(t4);//教學圖片 Step1
    Sprite B(t5);//教學圖片 Step2
    Sprite C(t6);//教學圖片 Step3
    Sprite D(t7);//教學圖片 goal
    Sprite E(t8);//教學圖片 封面 
    Sprite f[81];
    s.setScale(1.05f, 1.05f);//遊戲圖片 調整比例 
    m.setScale(0.95f, 1.5f);//封面圖片 調整比例 
    A.setScale(0.75f, 1.13f);//教學圖片 Step1 調整比例 
    B.setScale(0.75f, 1.2f);//教學圖片 Step2 調整比例 
    C.setScale(0.75f, 1.2f);//教學圖片 Step3 調整比例 
    D.setScale(0.75f, 1.2f);//教學圖片 goal 調整比例 
    E.setScale(0.75f, 1.2f);//教學圖片 封面 調整比例
    while(window.isOpen()){
        Event e;
        Vector2i localPosition = Mouse::getPosition(window);
        while(window.pollEvent(e)){
            if(e.type == Event::Closed)window.close();
        }
        window.clear();
        if(Mouse::isButtonPressed(Mouse::Right) && n == 0){
        	if(localPosition.x<=490&&localPosition.x>=400&&localPosition.y>=350&&localPosition.y<=430){//單人選項 
            	n++;
        	}
        	if(localPosition.x<=490&&localPosition.x>=400&&localPosition.y>=470&&localPosition.y<=540){//多人選項 
            	n++;
        	}
        	if(localPosition.x<=490&&localPosition.x>=400&&localPosition.y>=580&&localPosition.y<=660){//教學選項 
        		learn++;
        	}
    	}
        if(n !=0){
			window.draw(s);//遊戲圖片 
		}
        else{
        	if(learn!=0){//教學圖片A 
				window.draw(E);
				if(localPosition.x<=200&&localPosition.x>=30&&localPosition.y>=650&&localPosition.y<=850){//Step1 
					window.draw(A);
        		}
				if(localPosition.x<=400&&localPosition.x>=201&&localPosition.y>=650&&localPosition.y<=850){//Step2  
            		window.draw(B);
        		}
        		if(localPosition.x<=620&&localPosition.x>=401&&localPosition.y>=650&&localPosition.y<=850){//Step3  
            		window.draw(C);
        		}
        		if(localPosition.x<=890&&localPosition.x>=621&&localPosition.y>=650&&localPosition.y<=850){//goal 
        			window.draw(D);
        		}
        		if(Keyboard::isKeyPressed(Keyboard::Up)){
        			n++;
				}
			}
		    else window.draw(m);
		    }
        if(d % 2 == 0){
            f[d].setTexture(t1);
            k = 1;
            f[d].setScale(0.41f, 0.372f);
        }else{
            f[d].setTexture(t2);
            k = 2;
            f[d].setScale(0.34f,0.452f);
        }
        if(Mouse::isButtonPressed(Mouse::Left) && n != 0){
            if(d == 0){
                TFSet = position(localPosition.x, localPosition.y, k, x, y, bigmap, map);
            }
            else{
                TFSet = TFset(localPosition.x, localPosition.y, k, x, y, bigmap, map);
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
