#ifndef VERTEX_H
#define VERTEX_H


class Vertex
{
public:
    Vertex();
    Vertex(int row,int column,int imageNum);
    void setRow(int row);
    void setColumn(int column);
    void setColor(int imageNum);
    int getRow();
    int getColumn();
    int getImageNum();
    ~Vertex();
  public:
    /*白色*/
    const static int COLOR_WHITE = 0;
    /*黑色*/
    const static int COLOR_BLACK = 1;
 private:
    //行号
    int row;
     //列号
    int column;
    //颜色0代表白板，1代表显示
    int imageNum;
};

#endif // VERTEX_H
