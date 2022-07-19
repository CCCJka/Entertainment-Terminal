#ifndef _PROJECT_H_
#define _PROJECT_H_ //防止头文件冲突

/*存放头文件*/
#include <stdio.h>   //printf函数、scanf函数
#include <error.h>   //标准出错头文件
#include <string.h>  //memset函数、strlen函数的头文件
#include <stdlib.h>
#include <unistd.h>   //read、write函数
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h> //mmap函数
#include <linux/input.h> //Linux下的输入子系统
#include <pthread.h>  //线程API接口头文件

// 宏和全局变量结构体
#define _GEC_LCD_PATH_     "/dev/fb0"              //lcd屏的路径
#define _GEC_TS_PATH_   "/dev/input/event0"      //触摸屏文件的路径
#define _MMAP_LCD_SIZE_     800*480*4              //映射地址大小

struct Pro_Info
{
    int lcd_fd; /*LCD屏*/
    int ts_fd;  /*触摸屏*/
    int *mmap_addr; /*映射内存的首地址*/
    int Ts_x,Ts_y; /*触摸屏的坐标*/
    pthread_t pid1,pid2; /*线程ID号*/
    
}PI;
struct input_event Xy; //存放放触摸屏数据的结构体
//函数的声明

/*priject_ctrl.c 控制模块*/

/*******************************************************
 *   作者：xxxx
 **  日期：2022.1.5
 **
 **             @函数名：         ProjectInit
 **             @函数功能：       项目的初始化
 **             @函数的参数：         无
 **             @函数的返回值：  成功：0 表示初始化成功
 **                             失败：-1 表示初始化失败
 *              @函数说明：           无
*********************************************************
*/
int ProjectInit();

/*******************************************************
 *   作者：xxxx
 **  日期：2022.1.5
 **
 **             @函数名：         ProjectFree
 **             @函数功能：       回收项目的资源
 **             @函数的参数：          无
 **             @函数的返回值：  成功：0 表示回收成功
 **                             失败：-1 表示回收失败
 *              @函数说明：           无
*********************************************************
*/
int ProjectFree();

/*******************************************************
 *   作者：xxxx
 **  日期：2022.1.5
 **
 **              @函数名：          Get_Xy
 **             @函数功能：    实现获取触摸屏的坐标
 **             @函数的参数：         无
 **             @函数的返回值：     成功：0
 **                                失败：-1
 *              @函数说明：           无
*********************************************************
*/
int Get_Xy(); //获取触摸屏坐标

/*******************************************************
 *   作者：xxx
 **  日期：2022.1.6
 **
 **             @函数名：          ShowBmp
 **             @函数功能：    实现在开发板显示图片
 **             @函数的参数：         
 **                               s_x：    显示图片位置的X轴坐标
 **                               s_y：    显示图片位置的Y轴坐标
 **                               picName：图片的路径
 **             @函数的返回值：     成功：0
 **                                失败：-1
 *              @函数说明：          无
*********************************************************
*/
int ShowBmp(int s_x, int s_y, const char *picName);

/*******************************************************
 *   作者：xxx
 **  日期：2022.1.6
 **
 **             @函数名：         ControlMianUI
 **             @函数功能：      控制主界面个个模块
 **             @函数的参数：           无                  
 **             @函数的返回值：      成功：0
 **                                 失败：-1
 *              @函数说明：             无
*********************************************************
*/
int ControlMianUI(); //控制模块

/*******************************************************
 *   作者：xxx
 **  日期：2022.1.6
 **
 **             @函数名：           LoadingPic
 **             @函数功能：        加载进度条图片
 **             @函数的参数：           无                  
 **             @函数的返回值：      成功：0
 **                                 失败：-1
 *              @函数说明：             无
*********************************************************
*/
void* LoadingPic();

/*******************************************************
 *   作者：xxx
 **  日期：2022.1.5
 **
 **             @函数名：            loadig
 **             @函数功能：          加载进度条
 **             @函数的参数：           无                  
 **             @函数的返回值：       成功：0
 **                                  失败：-1
 *              @函数说明：            无
*********************************************************
*/
int Loadig();


/******************游戏模块*****************************/

/*******************************************************
 *   作者：xxxx
 **  日期：2022.1.6
 **
 **             @函数名：          GameInit
 **             @函数功能：     实现游戏模块的初始化
 **             @函数的参数：         无
 **             @函数的返回值：      成功：0
 **                                 失败：-1
 *              @函数说明：           无
*********************************************************
*/
int GameInit(); //游戏模块的初始化

/*******************************************************
 *   作者：xxxx
 **  日期：2022.1.6
 **
 **             @函数名：          GameFree
 **             @函数功能：       实现游戏结束
 **             @函数的参数：         无
 **             @函数的返回值：      成功：0
 **                                 失败：-1
 *              @函数说明：           无
*********************************************************
*/
int GameFree(); //游戏结束

/*******************************************************
 *   作者：xxxx
 **  日期：2022.1.6
 **
 **             @函数名：        CountGameScore
 **             @函数功能：       实现游戏的积分
 **             @函数的参数：      score: 分数
 **             @函数的返回值：      成功：0
 **                                 失败：-1
 *              @函数说明：           无
*********************************************************
*/
int CountGameScore(int score); //积分器

/*******************************************************
 *   作者：xxxx
 **  日期：2022.1.6
 **
 **             @函数名：          MoveBall
 **             @函数功能：      实现球的随机运动
 **             @函数的参数：         void*
 **             @函数的返回值：      成功：(void*)0
 **                                 失败：(void*)-1
 *              @函数说明：           无
*********************************************************
*/
void* MoveBall(void *arg); //画球

/*******************************************************
 *   作者：xxxx
 **  日期：2022.1.6
 **
 **             @函数名：         DrawPlate
 **             @函数功能：        绘制木板
 **             @函数的参数：         无
 **             @函数的返回值：      成功：0
 **                                 失败：-1
 *              @函数说明：           无
*********************************************************
*/
int DrawPlate();//画板

/*******************************************************
 *   作者：xxxx
 **  日期：2022.1.6
 **
 **             @函数名：          StartGame
 **             @函数功能：       启动游戏模块
 **             @函数的参数：         无
 **             @函数的返回值：      成功：0
 **                                 失败：-1
 *              @函数说明：           无
*********************************************************
*/
int StartGame(); //启动游戏模块的


/*******************************************************
 *   作者：xxxx
 **  日期：2022.1.6
 **
 **             @函数名：        TouchControlPlate
 **             @函数功能：        控制木板
 **             @函数的参数：      任意类型
 **             @函数的返回值：      成功：（void*）0
 **                                 失败：(void* )-1
 *              @函数说明：           无
*********************************************************
*/
void* TouchControlPlate(void *arg); //控制木板


                 /*音乐模块*/
/*******************************************************
 *   作者：xxxx
 **  日期：2022.1.6
 **
 **             @函数名：          StartMusic
 **             @函数功能：      启动启动音乐模块
 **             @函数的参数：         无
 **             @函数的返回值：      成功：0
 **                                 失败：-1
 *              @函数说明：           无
*********************************************************
*/
int StartMusic();


               /*视频模块*/

/*******************************************************
 *   作者：xxxx
 **  日期：2022.1.6
 **
 **             @函数名：           Video
 **             @函数功能：       启动视频模块
 **             @函数的参数：         无
 **             @函数的返回值：      成功：0
 **                                 失败：-1
 *              @函数说明：           无
*********************************************************
*/
int StartVideo();

/*******************************************************
 *   作者：xxxx
 **  日期：2022.1.6
 **
 **             @函数名：           VideoInit
 **             @函数功能：         视频模块初始化
 **             @函数的参数：         无
 **             @函数的返回值：      成功：0
 **                                 失败：-1
 *              @函数说明：           无
*********************************************************
*/
int  VideoInit();

/*******************************************************
 *   作者：xxxx
 **  日期：2022.1.6
 **
 **             @函数名：          VideoFree
 **             @函数功能：        视频资源回收
 **             @函数的参数：         无
 **             @函数的返回值：      成功：0
 **                                 失败：-1
 *              @函数说明：           无
*********************************************************
*/
int  VideoFree();

/*******************************************************
 *   作者：xxxx
 **  日期：2022.1.6
 **
 **             @函数名：           SendCmd
 **             @函数功能：         发送命令
 **             @函数的参数：    cmd： 需要发送的命令
 **             @函数的返回值：      成功：0
 **                                 失败：-1
 *              @函数说明：           无
*********************************************************
*/
int  SendCmd(char *cmd);

#endif