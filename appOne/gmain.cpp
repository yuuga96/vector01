#if 1

#include"libOne.h"
void gmain() {
    window(1000, 1000);
    int img = loadImage("assets\\unkoSonomono.png");
    struct UNKO {
        int hp = 0;
        float px = 0, py = 0, vx = 0, vy = 0, deg = 0;
    };
    const int num = 256;
    struct UNKO u[num];
    float deg = 0;
    float deg2 = 0;
    angleMode(DEGREES);
    rectMode(CENTER);
    while (notQuit) {
        if (isPress(MOUSE_LBUTTON)) {
            for (int i = 0; i < num; i++) {
                if (u[i].hp == 0) {
                    u[i].hp = 1;
                    u[i].px = mouseX + sin(deg) * 20;
                    u[i].py = mouseY;
                    u[i].vx = 0;
                    u[i].vy = 10;
                    deg += 6;
                    u[i].deg = 0;
                    i = num;
                }
            }
        }
        if (isPress(MOUSE_RBUTTON)) {
            for (int i = 0; i < num; i++) {
                if (u[i].hp == 0) {
                    u[i].hp = 1;
                    u[i].px = mouseX;
                    u[i].py = mouseY;
                    u[i].vx = sin(deg2) * 5;
                    u[i].vy = -cos(deg2) * 5;
                    u[i].deg = deg2;
                    deg2 += 25;
                    i = num;
                }
            }
        }
        for (int i = 0; i < num; i++) {
            if (u[i].hp == 1) {
                u[i].px += u[i].vx;
                u[i].py += u[i].vy;
                if (
                    u[i].py > height + 50 ||
                    u[i].py < -50 ||
                    u[i].py > width + 50 ||
                    u[i].py < -50
                    ) {
                    u[i].hp = 0;
                }
            }
        }
        clear(200, 200, 0);
        for (int i = 0; i < num; i++) {
            if (u[i].hp == 1) {
                image(img, u[i].px, u[i].py,u[i].deg);
            }
        }
    }
}

#else

#include"libOne.h"
void gmain() {
    window(1920, 1080, full);
    //�T�E���h
    int bgm = loadSound("assets\\bgm_battle02.wav");
    int onara = loadSound("assets\\onara.wav");
    playLoopSound(bgm);
    //���񂱃f�[�^
    int img = loadImage("assets\\unkoSonomono.png");
    struct UNKO {
        int hp=0;
        float px=0, py=0, vx=0, vy=0, deg=0;
    };
    const int num = 256;
    UNKO unko[num];
    //�ɂ��ɂ����񂱗p�f�[�^
    float deg = 0;
    float refPx=0;//�o����ƂȂ邘�ʒu
    //���ˏ󂤂񂱗p�f�[�^
    float deg2 = 0;
    bool flag = false;
    angleMode(DEGREES);
    rectMode(CENTER);
    ShowCursor(false);
    while (notQuit) {
        //�ɂ��ɂ�����
        if (isPress(KEY_Z)) {
            if (isTrigger(KEY_Z)) {
                playSound(onara);
                refPx = random(50.0f, width - 50);
            }
            //�������O��unko��T���Ĕ���
            for (int i = 0; i < num; i++) {
                if (unko[i].hp == 0) {
                    unko[i].px = refPx + sin(deg) * 20;
                    unko[i].py = -50;
                    unko[i].vx = 0;
                    unko[i].vy = 10;
                    unko[i].deg = 0;
                    unko[i].hp = 1;
                    deg += 6;
                    //���[�v���f
                    i = num;
                }
            }
        }
        //���ˏ󔭎˂Q
        if (isTrigger(KEY_X))flag = !flag;
        if (flag) {
            //�������O��unko��T���Ĕ���
            for (int i = 0; i < num; i++) {
                if (unko[i].hp == 0) {
                    unko[i].px = width / 2;
                    unko[i].py = height / 2;
                    unko[i].vx = sin(deg2) * 5;
                    unko[i].vy = -cos(deg2) * 5;
                    unko[i].deg = deg2;
                    unko[i].hp = 1;
                    deg2 += 25;
                    //���[�v���f
                    i = num;
                }
            }
        }
        //�ړ�
        for (int i = 0; i < num; i++) {
            if (unko[i].hp > 0) {
                unko[i].px += unko[i].vx;
                unko[i].py += unko[i].vy;
                //�E�B���h�E�̊O�ɏo�����񂱂̂������O�ɂ���
                if (unko[i].py <-50 || unko[i].py > height + 50 ||
                    unko[i].px > width + 50 || unko[i].px < -50 ) {
                    unko[i].hp = 0;
                }
            }
        }
        //�`��
        clear(200,200,0);
        imageColor(140, 100, 10);
        for (int i = 0; i < num; i++) {
            if (unko[i].hp > 0) {
                image(img, unko[i].px, unko[i].py, unko[i].deg);
            }
        }
    }
    ShowCursor(true);
}

#endif