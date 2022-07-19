#include "Project.h"

int StartMusic() //启动音乐
{
    //显示音乐界面
    ShowBmp(0, 0, "./rec/music.bmp");
    while(1)
    {
        Get_Xy();//获取触摸屏的坐标
        if (PI.Ts_x > 0 && PI.Ts_x < 248 && PI.Ts_y > 0 && PI.Ts_y < 238) //播放按钮
        {
            printf("播放按钮！\n");
            system("madplay ./music/faded.mp3 &");
        }

        if (PI.Ts_x > 253 && PI.Ts_x < 545 && PI.Ts_y > 0 && PI.Ts_y < 238) //暂停按钮
        {
            printf("暂停按钮！\n");
            system("killall -19 madplay");
        }

        if (PI.Ts_x > 550 && PI.Ts_x < 800 && PI.Ts_y > 0 && PI.Ts_y < 480) //退出按钮
        {
            printf("退出按钮！\n");
            ShowBmp(0, 0, "./rec/main.bmp"); //显示主界面

            PI.Ts_x = -1;
            PI.Ts_y = -1;
            break;
        }

        if (PI.Ts_x > 0 && PI.Ts_x < 248 && PI.Ts_y > 245 && PI.Ts_y < 480) //停止按钮
        {
            printf("停止按钮！\n");
            system("killall -9 madplay");
        }

        if (PI.Ts_x > 255 && PI.Ts_x < 550 && PI.Ts_y > 245 && PI.Ts_y < 480) //继续按钮
        {
            printf("继续按钮！\n");
            system("killall -18 madplay");

        } 

    }
}

