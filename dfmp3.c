#include <stdio.h>

enum {junkdata,next,previous,tracknum,volumeup,volumedown,volumevalue,eq,playbackmode,playbacksource,standbymode,normalmode,reset,resume,pause,folder,volumegain,repeatplay};
void dfmp3(unsigned char menu,int value){
char para_hi,para_lo;

putchar(0x7e); //start
putchar(0xff); //ver
putchar(0x06); //length
    switch (menu){
    
    case next:{
    putchar(0x01); //command
    putchar(0x00); //feedback
    putchar(0x00); //parameter High byte
    putchar(0x00); //parameter low byte
    }break;
    
    case previous:{
    putchar(0x02); //command
    putchar(0x00); //feedback
    putchar(0x00); //parameter High byte
    putchar(0x00); //parameter low byte
    }break;
    
    case tracknum:{
    putchar(0x12); //command
    putchar(0x00); //feedback
    if(value>2999)value=2999;
    else if(value<0)value=0;
    para_hi=value>>8;
    para_lo=value&0xff;
    putchar(para_hi); //parameter High byte
    putchar(para_lo); //parameter low byte
    }break;
    
    case volumeup:{
    putchar(0x04); //command
    putchar(0x00); //feedback
    putchar(0x00); //parameter High byte
    putchar(0x00); //parameter low byte
    }break;
    
    case volumedown:{
    putchar(0x05); //command
    putchar(0x00); //feedback
    putchar(0x00); //parameter High byte
    putchar(0x00); //parameter low byte
    }break;
    
    case volumevalue:{
    putchar(0x06); //command
    putchar(0x00); //feedback
    if(value>30)value=30;
    else if(value<0)value=0;
    para_lo=value&0xff;
    putchar(0x00); //parameter High byte
    putchar(para_lo); //parameter low byte
    }break;
    
    case eq:{
    putchar(0x07); //command
    putchar(0x00); //feedback
    if(value>5)value=5;
    else if(value<0)value=0;
    para_lo=value&0xff;
    putchar(0x00); //parameter High byte
    putchar(para_lo); //parameter low byte
    }break;
    
    case playbackmode:{
    putchar(0x08); //command
    putchar(0x00); //feedback
    if(value>3)value=3;
    else if(value<0)value=0;
    para_lo=value&0xff;
    putchar(0x00); //parameter High byte
    putchar(para_lo); //parameter low byte
    }break;
    
    case playbacksource:{
    putchar(0x09); //command
    putchar(0x00); //feedback
    if(value>5)value=5;
    else if(value<0)value=0;
    para_lo=value&0xff;
    putchar(0x00); //parameter High byte
    putchar(para_lo); //parameter low byte
    }break;
    
    case standbymode:{
    putchar(0x0a); //command
    putchar(0x00); //feedback
    putchar(0x00); //parameter High byte
    putchar(0x00); //parameter low byte
    }break;
        
    case normalmode:{
    putchar(0x0b); //command
    putchar(0x00); //feedback
    putchar(0x00); //parameter High byte
    putchar(0x00); //parameter low byte
    }break;
    
    case reset:{
    putchar(0x0c); //command
    putchar(0x00); //feedback
    putchar(0x00); //parameter High byte
    putchar(0x00); //parameter low byte
    }break;
    
    case resume:{
    putchar(0x0d); //command
    putchar(0x00); //feedback
    putchar(0x00); //parameter High byte
    putchar(0x00); //parameter low byte
    }break;
    
    case pause:{
    putchar(0x0e); //command
    putchar(0x00); //feedback
    putchar(0x00); //parameter High byte
    putchar(0x00); //parameter low byte
    //putchar(0xfe); //checksum High byte
    //putchar(0xed); //checksum low byte
    }break;
    
    case volumegain:{
    putchar(0x10); //command
    putchar(0x00); //feedback
    if(value>0x1f)value=0x1f;
    else if(value<0)value=0;
    para_lo=value&0xff;
    putchar(0x00); //parameter High byte
    putchar(para_lo); //parameter low byte
    }break;
    }
putchar(0xef); //end byte
}
