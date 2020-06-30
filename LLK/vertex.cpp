#include "vertex.h"

Vertex::Vertex()
{

}
Vertex::Vertex(int row,int column,int imageNum)
{
    this->row = row;
    this->column = column;
    this->imageNum = imageNum;
}
void Vertex::setColor(int imageNum){
    this->imageNum = imageNum;
}
void Vertex::setColumn(int column){

}
void Vertex::setRow(int row){
    this->row =row;
}
int Vertex::getImageNum(){
    return this->imageNum;
}
int Vertex::getColumn(){
    return this->column;
}
int Vertex::getRow(){
    return this->row;
}
Vertex::~Vertex(){

}
