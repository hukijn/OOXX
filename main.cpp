//�ӧQ��ܪ����� �A���`�C�����U�k��A�����e���ɡA�e�����|���Ͱ{�{�A�~�����e��
//���է令�HEnter�A�ӵ����e���C���e���|���"�L�^��" 
//�M���O�_���`�A�|���I�� 
//���L6/14(�G)�A�|�~��ո� 

#include <SFML/Graphics.hpp>
#include <iostream>
#include "D:\My project\winner.h"
#include "D:\My project\Tfest.h"
#include "D:\My project\slicemap.h"
using namespace std;
using namespace sf;
int main(){
    int bigmap[3][3] = {0}, lmap[3][3] = {0}, map[9][3][3] = {0},
    d = 0, k = 1, TFSet = 0, x, y, n = 0,learn=0;
    RenderWindow window(VideoMode(900, 800), "game");
    Texture t, t1, t2, t3, t4,t5,t6,t7,t8, t9, t10, t11;
    t.loadFromFile("D:/�j���e�e __/images/map.png");
    t1.loadFromFile("D:/�j���e�e __/images/b.jpg");
    t2.loadFromFile("D:/�j���e�e __/images/c.png");
    t3.loadFromFile("D:/�j���e�e __/images/d.png");
    t4.loadFromFile("D:/�j���e�e __/images/e.png");
    t5.loadFromFile("D:/�j���e�e __/images/f.png");
    t6.loadFromFile("D:/�j���e�e __/images/g.png");
    t7.loadFromFile("D:/�j���e�e __/images/h.png");
    t8.loadFromFile("D:/�j���e�e __/images/i.png");
    t9.loadFromFile("D:/�j���e�e __/images/bw.png");
    t10.loadFromFile("D:/�j���e�e __/images/cw.png");
    t11.loadFromFile("D:/�j���e�e __/images/tie.png");
    Sprite s(t);//�C���Ϥ� 
    Sprite m(t3);//�ʭ��Ϥ� 
    Sprite A(t4);//�оǹϤ� Step1
    Sprite B(t5);//�оǹϤ� Step2
    Sprite C(t6);//�оǹϤ� Step3
    Sprite D(t7);//�оǹϤ� goal
    Sprite E(t8);//�оǹϤ� �ʭ� 
    Sprite X(t9);//�ӧQ�Ϥ� 
	Sprite Y(t10);
	Sprite Z(t11);//�M���Ϥ� 
    Sprite f[81];
    s.setScale(1.05f, 1.05f);//�C���Ϥ� �վ��� 
    m.setScale(0.95f, 1.5f);//�ʭ��Ϥ� �վ��� 
    A.setScale(0.75f, 1.13f);//�оǹϤ� Step1 �վ��� 
    B.setScale(0.75f, 1.2f);//�оǹϤ� Step2 �վ��� 
    C.setScale(0.75f, 1.2f);//�оǹϤ� Step3 �վ��� 
    D.setScale(0.75f, 1.2f);//�оǹϤ� goal �վ��� 
    E.setScale(0.75f, 1.2f);//�оǹϤ� �ʭ� �վ���
    X.setScale(0.68f, 1.1f);
    Y.setScale(0.68f, 1.1f);
    Z.setScale(0.68f, 1.1f);
    while(window.isOpen()){
        Event e;
        Vector2i localPosition = Mouse::getPosition(window);
        while(window.pollEvent(e)){
            if(e.type == Event::Closed)window.close();
        }
        window.clear();
        if(Mouse::isButtonPressed(Mouse::Right) && n == 0){
        	if(localPosition.x<=490&&localPosition.x>=400&&localPosition.y>=350&&localPosition.y<=430){//��H�ﶵ 
            	n++;
        	}
        	if(localPosition.x<=490&&localPosition.x>=400&&localPosition.y>=470&&localPosition.y<=540){//�h�H�ﶵ 
            	n++;
        	}
        	if(localPosition.x<=490&&localPosition.x>=400&&localPosition.y>=580&&localPosition.y<=660){//�оǿﶵ 
        		learn++;
        	}
    	}
        if(n !=0){
			window.draw(s);//�C���Ϥ� 
		}
        else{
        	if(learn!=0){//�оǹϤ�A 
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
        if(winner(lmap) == true && k == 1 )//�e�eĹ 
		{
			while(true)
			{
        		window.clear();
    			window.draw(X);
    			window.display();
    			if(Mouse::isButtonPressed(Mouse::Right))break;
    		}
    	}
    	if(winner(lmap) == true && k == 2 ) //���Ĺ 
    	{
    		while(true)
    		{
				window.clear();
				window.draw(Y);
				window.display();
				if(Mouse::isButtonPressed(Mouse::Right))break;
			}
		}
        bool mapover = true;
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 3; j++)
                for(int a = 0; a < 3; a++)
                    if(map[i][j][a] == 0)mapover = false;
        if(mapover == true)//�M�� 
        {
			while(true)
			{
	        	window.clear();
	    		window.draw(Z);
	    		window.display();
	    		if(Mouse::isButtonPressed(Mouse::Right))break;
	    	}
		}
    }
}
