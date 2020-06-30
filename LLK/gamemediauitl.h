#ifndef GAMEMEDIAUITL_H
#define GAMEMEDIAUITL_H
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include<QFile>
#include<QUrl>
#include<QDir>
#include<QFileInfoList>
#include<QFileInfo>
#include<QStringList>
#include<QString>
class GameMediaUitl
{
public:
  GameMediaUitl();
  //获取音乐播放器
 QMediaPlayer* getMediaSongPlayer();
 //获取背景音乐播放器
 QMediaPlayer* getMediaBgmPlayer();
 //获取音乐的所有路径
  QStringList* getSongPlayerList();
//获取背景音乐的所有路径
  QStringList* getBgmPlayerList();
    //获取指定文件夹下的所有文件
 QStringList* getAllFilesInDir( QString dirPath);
 void setIsPlayBgm(bool isPlayBgm);
 void setIsPlaySong(bool isPlaySong);
 void setCurrSongIndex(int index);
 void setCurrBgmIndex(int index);
 bool getIsPlayBgm();
 bool getIsPlaySong();
private:
 void loadMediaSongFile();
 void loadMediaBgmFile();
private:
    //背景音多媒体播放器
     QMediaPlayer* bgmPlayer = NULL;
    //背景音多媒体列表
      QMediaPlaylist* bgmPlayerList = NULL;
    //歌曲多媒体播放器
     QMediaPlayer* songPlayer = NULL;
    //歌曲多媒体列表
      QMediaPlaylist* songPlayerList = NULL;
      //背景音乐的文件路径
      QStringList* bgmFilePath = NULL;
      //背景的文件路径
       QStringList* songFilePath = NULL;
      //是否播放背景音乐
       bool isPlaySong =false;
       //是否播放游戏音效
       bool isPlayBgm = false;
};

#endif // GAMEMEDIAUITL_H
