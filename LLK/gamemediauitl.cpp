#include"gamemediauitl.h"
GameMediaUitl::GameMediaUitl(){
 this->loadMediaBgmFile();
 this->loadMediaSongFile();
}
void GameMediaUitl::loadMediaSongFile(){
       if(songPlayer == NULL){
           songPlayer = new QMediaPlayer();
       }
       if(songPlayerList == NULL){
            songPlayerList = new QMediaPlaylist();
       }
       //获取背景音乐文件夹下的所有mp3文件
      this->songFilePath = this->getAllFilesInDir(QString("../MediaFile/song"));
      if(this->songFilePath == NULL){
          return;
      }
     //默认背景音乐
      this->songPlayerList->addMedia(QUrl::fromLocalFile(this->songFilePath->at(0)));
      this->songPlayerList->setCurrentIndex(0);
      this->songPlayer->setPlaylist(this->songPlayerList);
      this->isPlaySong = true;
}
QMediaPlayer* GameMediaUitl::getMediaSongPlayer(){
       return this->songPlayer;
   }
void GameMediaUitl::loadMediaBgmFile(){
    if(bgmPlayer == NULL){
        bgmPlayer = new QMediaPlayer();
    }
    if(bgmPlayerList == NULL){
         bgmPlayerList = new QMediaPlaylist();
    }
    //获取背景音效文件夹下的所有mp3文件
   this->bgmFilePath = this->getAllFilesInDir(QString("../MediaFile/bgm"));
   if(this->bgmFilePath == NULL){
       return;
   }
   //默认背景音乐
   this->bgmPlayerList->addMedia(QUrl::fromLocalFile(this->bgmFilePath->at(0)));
    this->bgmPlayerList->setCurrentIndex(0);
   this->bgmPlayer->setPlaylist(this->bgmPlayerList);
   this->isPlayBgm = true;
   }
QMediaPlayer* GameMediaUitl::getMediaBgmPlayer(){
       return this->bgmPlayer;
}
//获取指定文件夹下的所有文件
QStringList* GameMediaUitl::getAllFilesInDir( QString dirPath){
 if (dirPath.isEmpty()) return NULL;
       // 获取所有文件名
       QDir dir(dirPath);
     if (!dir.exists())return NULL;
       dir.setFilter(QDir::Files);
       dir.setSorting(QDir::Name);
       dir.setNameFilters(QString("*.mp3;").split(";"));
     QStringList*	mImgNames = new QStringList(dir.entryList());
     if(mImgNames == NULL){
         return NULL;
     }
     QStringList* filesPath = new QStringList();
     for (int i = 0; i < mImgNames->size(); ++i)
     {
         QString q(dirPath);
         q.append("/");
         q.append(mImgNames->at(i));
          filesPath->append(q);
     }
       return filesPath;
}
void  GameMediaUitl::setIsPlayBgm(bool isPlayBgm){
    this->isPlayBgm = isPlayBgm;
}

void  GameMediaUitl::setIsPlaySong(bool isPlaySong){
    if(this->songPlayer->state() == QMediaPlayer::PlayingState){
        this->songPlayer->stop();
    }
    this->isPlaySong = isPlaySong;
}
QStringList* GameMediaUitl::getBgmPlayerList(){
    return this->bgmFilePath;
}
QStringList* GameMediaUitl::getSongPlayerList(){

    return this->songFilePath;
}
bool GameMediaUitl::getIsPlayBgm(){
    return this->isPlayBgm;
}
bool GameMediaUitl::getIsPlaySong(){
    return this->isPlaySong;
}
void GameMediaUitl::setCurrBgmIndex(int index){
    if(index >= this->bgmFilePath->count()){
        return;
    }
    this->bgmPlayerList->clear();
   this->bgmPlayerList->addMedia(QUrl::fromLocalFile(this->bgmFilePath->at(index)));
   this->bgmPlayerList->setCurrentIndex(0);
}
void GameMediaUitl::setCurrSongIndex(int index){
    if(index >= this->songFilePath->count()){
        return;
    }
    this->songPlayerList->clear();
   this->songPlayerList->addMedia(QUrl::fromLocalFile(this->songFilePath->at(index)));
   this->songPlayerList->setCurrentIndex(0);
}
